#include "common.h"
#include "x86.h"

/* a-z对应的键盘扫描码 */
static int letter_code[] = {
	30, 48, 46, 32, 18, 33, 34, 35, 23, 36,
	37, 38, 50, 49, 24, 25, 16, 19, 31, 20,
	22, 47, 17, 45, 21, 44
};
/* 对应键按下的标志位 */
static bool letter_pressed[26];

void
press_key(int scan_code) {
	int i;
	for (i = 0; i < 26; i ++) {
		if (letter_code[i] == scan_code) {
			letter_pressed[i] = true;
		}
	}
}

void
release_key(int index) {
	assert(0 <= index && index < 26);
	letter_pressed[index] = false;
}

bool
query_key(int index) {
	assert(0 <= index && index < 26);
	return letter_pressed[index];
}

/* key_code保存了上一次键盘事件中的扫描码 */
static volatile int key_code = 0;

int last_key_code(void) {
	return key_code;
}

void
keyboard_event() {
	key_code = in_byte(0x60);
	press_key(key_code);
}

