#include "monitor/monitor.h"
#include "monitor/expr.h"
#include "monitor/watchpoint.h"
#include "nemu.h"

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void cpu_exec(uint32_t);
void display_reg();

/* We use the `readline' library to provide more flexibility to read from stdin. */
char* rl_gets() {
	static char *line_read = NULL;

	if (line_read) {
		free(line_read);
		line_read = NULL;
	}

	line_read = readline("(nemu) ");

	if (line_read && *line_read) {
		add_history(line_read);
	}

	return line_read;
}

/* TODO: Add single step */
static int cmd_si(char *args) {
	char *arg = strtok(NULL, " ");
	int i = 1;

	if(arg != NULL) {
		sscanf(arg, "%d", &i);
	}
	cpu_exec(i);
	return 0;
}

/* TODO: Add info command */
static int cmd_info(char *args) {
	char *arg = strtok(NULL, " ");

	if(arg != NULL) {
		if(strcmp(arg, "r") == 0) {
			display_reg();
		}
		else if(strcmp(arg, "w") == 0) {
			list_watchpoint();
		}
	}
	return 0;
}

/* Add examine memory */
static int cmd_x(char *args) {
	char *arg = strtok(NULL, " ");
	int n;
	swaddr_t addr;
	int i;

	if(arg != NULL) {
		sscanf(arg, "%d", &n);

		bool success;
		addr = expr(arg + strlen(arg) + 1, &success);
		if(success) { 
			for(i = 0; i < n; i ++) {
				if(i % 4 == 0) {
					printf("0x%08x: ", addr);
				}

				printf("0x%08x ", swaddr_read(addr, 4));
				addr += 4;
				if(i % 4 == 3) {
					printf("\n");
				}
			}
			printf("\n");
		}
		else { printf("Bad expression\n"); }

	}
	return 0;
}

/* Add expression evaluation  */
static int cmd_p(char *args) {
	bool success;

	if(args) {
		uint32_t r = expr(args, &success);
		if(success) { printf("0x%08x(%d)\n", r, r); }
		else { printf("Bad expression\n"); }
	}
	return 0;
}

/* Add set watchpoint  */
static int cmd_w(char *args) {
	if(args) {
		int NO = set_watchpoint(args);
		if(NO != -1) { printf("Set watchpoint #%d\n", NO); }
		else { printf("Bad expression\n"); }
	}
	return 0;
}

/* Add delete watchpoint */
static int cmd_d(char *args) {
	int NO;
	sscanf(args, "%d", &NO);
	if(!delete_watchpoint(NO)) {
		printf("Watchpoint #%d does not exist\n", NO);
	}

	return 0;
}

/* Add display backtrace */
static int cmd_bt(char *args) {
	const char* find_fun_name(uint32_t eip);
	struct {
		swaddr_t prev_ebp;
		swaddr_t ret_addr;
		uint32_t args[4];
	} sf;

	uint32_t ebp = cpu.ebp;
	uint32_t eip = cpu.eip;
	int i = 0;
	while(ebp != 0) {
		sf.args[0] = swaddr_read(ebp + 8, 4);
		sf.args[1] = swaddr_read(ebp + 12, 4);
		sf.args[2] = swaddr_read(ebp + 16, 4);
		sf.args[3] = swaddr_read(ebp + 20, 4);

		printf("#%d 0x%08x in %s (0x%08x 0x%08x 0x%08x 0x%08x)\n", i, eip, find_fun_name(eip), sf.args[0], sf.args[1], sf.args[2], sf.args[3]);
		i ++;
		eip = swaddr_read(ebp + 4, 4);
		ebp = swaddr_read(ebp, 4);
	}
	return 0;
}


static int cmd_c(char *args) {
	cpu_exec(-1);
	return 0;
}

static int cmd_q(char *args) {
	return -1;
}

static int cmd_help(char *args);

static struct {
	char *name;
	char *description;
	int (*handler) (char *);
} cmd_table [] = {
	{ "help", "Display informations about all supported commands", cmd_help },
	{ "c", "Continue the execution of the program", cmd_c },
	{ "q", "Exit NEMU", cmd_q }, 

	/* TODO: Add more commands */
        { "si", "Single step", cmd_si },
        { "info", "info r - print register values; info w - show watch point state", cmd_info },
	{ "x", "Examine memory", cmd_x },
        { "p", "Evaluate the value of expression", cmd_p },
	{ "w", "Set watchpoint", cmd_w },
	{ "d", "Delete watchpoint", cmd_d },
	{ "bt", "Display backtrace", cmd_bt }

};

#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))

static int cmd_help(char *args) {
	/* extract the first argument */
	char *arg = strtok(NULL, " ");
	int i;

	if(arg == NULL) {
		/* no argument given */
		for(i = 0; i < NR_CMD; i ++) {
			printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
		}
	}
	else {
		for(i = 0; i < NR_CMD; i ++) {
			if(strcmp(arg, cmd_table[i].name) == 0) {
				printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
				return 0;
			}
		}
		printf("Unknown command '%s'\n", arg);
	}
	return 0;
}

void ui_mainloop() {
	while(1) {
		char *str = rl_gets();
		char *str_end = str + strlen(str);

		/* extract the first token as the command */
		char *cmd = strtok(str, " ");
		if(cmd == NULL) { continue; }

		/* treat the remaining string as the arguments,
		 * which may need further parsing
		 */
		char *args = cmd + strlen(cmd) + 1;
		if(args >= str_end) {
			args = NULL;
		}

#ifdef HAS_DEVICE
		extern void sdl_clear_event_queue(void);
		sdl_clear_event_queue();
#endif

		int i;
		for(i = 0; i < NR_CMD; i ++) {
			if(strcmp(cmd, cmd_table[i].name) == 0) {
				if(cmd_table[i].handler(args) < 0) { return; }
				break;
			}
		}

		if(i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
	}
}
