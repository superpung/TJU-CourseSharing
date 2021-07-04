#include "nemu.h"

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <sys/types.h>
#include <regex.h>
#include <stdlib.h>

uint32_t look_up_symtab(char *, bool *);

enum {
	NOTYPE = 256, EQ

	/* TODO: Add more token types */

	, NEQ, OR, AND, NUM, REG, ID, REF, NEG
};

static struct rule {
	char *regex;
	int token_type;
} rules[] = {

	/* TODO: Add more rules.
	 * Pay attention to the precedence level of different rules.
	 */

	{" +",	NOTYPE},				// spaces
	{"\\+", '+'},					// plus
	{"==", EQ},						// equal
	{"0x[0-9a-fA-F]{1,8}", NUM},			// hex
	{"[0-9]{1,10}", NUM},					// dec
	{"\\$[a-z]{1,31}", REG},				// register names
	{"[a-zA-Z_]{1,31}", ID},				// identifiers 
	{"\\+", '+'},
	{"-", '-'},
	{"\\*", '*'},
	{"/", '/'},
	{"%", '%'},
	{"==", EQ},
	{"!=", NEQ},
	{"&&", AND},
	{"\\|\\|", OR},
	{"!", '!'},
	{"\\(", '('},
	{"\\)", ')'}
};

#define NR_REGEX (sizeof(rules) / sizeof(rules[0]) )

static regex_t re[NR_REGEX];

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
	int i;
	char error_msg[128];
	int ret;

	for(i = 0; i < NR_REGEX; i ++) {
		ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
		if(ret != 0) {
			regerror(ret, &re[i], error_msg, 128);
			Assert(ret == 0, "regex compilation failed: %s\n%s", error_msg, rules[i].regex);
		}
	}
}

typedef struct token {
	int type;
	char str[32];
} Token;

Token tokens[32];
int nr_token;

static bool make_token(char *e) {
	int position = 0;
	int i;
	regmatch_t pmatch;
	
	nr_token = 0;

	while(e[position] != '\0') {
		/* Try all rules one by one. */
		for(i = 0; i < NR_REGEX; i ++) {
			if(regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
				char *substr_start = e + position;
				int substr_len = pmatch.rm_eo;

				position += substr_len;

				/* TODO: Now a new token is recognized with rules[i]. Add codes
				 * to record the token in the array ``tokens''. For certain 
				 * types of tokens, some extra actions should be performed.
				 */

				switch(rules[i].token_type) {
					case NOTYPE: break;
					case NUM:
					case ID:
					case REG: sprintf(tokens[nr_token].str, "%.*s", substr_len, substr_start);
					default: tokens[nr_token].type = rules[i].token_type;
							 nr_token ++;
				}

				break;
			}
		}

		if(i == NR_REGEX) {
			printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
			return false;
		}
	}

	return true; 
}

static int op_prec(int t) {
	switch(t) {
		case '!': case NEG: case REF: return 0;
		case '*': case '/': case '%': return 1;
		case '+': case '-': return 2;
		case EQ: case NEQ: return 4;
		case AND: return 8;
		case OR: return 9;
		default: assert(0);
	}
}

static inline int op_prec_cmp(int t1, int t2) {
	return op_prec(t1) - op_prec(t2);
}

static int find_dominated_op(int s, int e, bool *success) {
	int i;
	int bracket_level = 0;
	int dominated_op = -1;
	for(i = s; i <= e; i ++) {
		switch(tokens[i].type) {
			case REG: case NUM: case ID: break;

			case '(': 
				bracket_level ++; 
				break;

			case ')': 
				bracket_level --; 
				if(bracket_level < 0) {
					*success = false;
					return 0;
				}
				break;

			default:
				if(bracket_level == 0) {
					if(dominated_op == -1 || 
							op_prec_cmp(tokens[dominated_op].type, tokens[i].type) < 0 ||
							(op_prec_cmp(tokens[dominated_op].type, tokens[i].type) == 0 && 
							 tokens[i].type != '!' && tokens[i].type != '~' &&
							 tokens[i].type != NEG && tokens[i].type != REF) ) {
						dominated_op = i;
					}
				}
				break;
		}
	}

	*success = (dominated_op != -1);
	return dominated_op;
}

uint32_t get_reg_val(const char*, bool *);

static uint32_t eval(int s, int e, bool *success) {
	if(s > e) {
		// bad expression
		*success = false;
		return 0;
	}
	else if(s == e) {
		// single token
		uint32_t val;
		switch(tokens[s].type) {
			case REG: val = get_reg_val(tokens[s].str + 1, success);	// +1 to skip '$'
					  if(!*success) { return 0; }
					  break;

			case NUM: val = strtol(tokens[s].str, NULL, 0); break;
			case ID: val = look_up_symtab(tokens[s].str, success);
					 if(!*success) { return 0; }
					 break;

			default: assert(0);
		}

		*success = true;
		return val;
	}
	else if(tokens[s].type == '(' && tokens[e].type == ')') {
		return eval(s + 1, e - 1, success);
	}
	else {
		int dominated_op = find_dominated_op(s, e, success);
		if(!*success) { return 0; }

		int op_type = tokens[dominated_op].type;
		if(op_type == '!' || op_type == NEG || op_type == REF) {
			uint32_t val = eval(dominated_op + 1, e, success);
			if(!*success) { return 0; }

			switch(op_type) {
				case '!': return !val;
				case NEG: return -val;
				case REF: return swaddr_read(val, 4);
				default: assert(0);
			}
		}

		uint32_t val1 = eval(s, dominated_op - 1, success);
		if(!*success) { return 0; }
		uint32_t val2 = eval(dominated_op + 1, e, success);
		if(!*success) { return 0; }

		switch(op_type) {
			case '+': return val1 + val2;
			case '-': return val1 - val2;
			case '*': return val1 * val2;
			case '/': return val1 / val2;
			case '%': return val1 % val2;
			case EQ: return val1 == val2;
			case NEQ: return val1 != val2;
			case AND: return val1 && val2;
			case OR: return val1 || val2;
			default: assert(0);
		}
	}
}

uint32_t expr(char *e, bool *success) {
	if(!make_token(e)) {
		*success = false;
		return 0;
	}

	/* Detect REF and NEG tokens */
	int i;
	int prev_type;
	for(i = 0; i < nr_token; i ++) {
		if(tokens[i].type == '-') {
			if(i == 0) {
				tokens[i].type = NEG;
				continue;
			}

			prev_type = tokens[i - 1].type;
			if( !(prev_type == ')' || prev_type == ID || prev_type == NUM || 
						prev_type == REG) ) {
				tokens[i].type = NEG;
			}
		}

		else if(tokens[i].type == '*') {
			if(i == 0) {
				tokens[i].type = REF;
				continue;
			}

			prev_type = tokens[i - 1].type;
			if( !(prev_type == ')' || prev_type == ID || prev_type == NUM || 
						prev_type == REG) ) {
				tokens[i].type = REF;
			}
		}
	}

	return eval(0, nr_token - 1, success);
}
