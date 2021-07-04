#include "common.h"
#include "adt/linklist.h"
#include "FLOAT.h"

#define HZ 100

/* 按键相关 */
void press_key(int scan_code);
void release_key(int ch);
bool query_key(int ch);
int last_key_code(void);

/* 定义fly_t链表 */
LINKLIST_DEF(fly)
	FLOAT x;
	int y;
	int text;
	FLOAT v;
LINKLIST_DEF_FI(fly)

/* 游戏逻辑相关 */
void create_new_letter(void);
void update_letter_pos(void);
bool update_keypress(void);

int get_hit(void);
int get_miss(void);
int get_fps(void);
void set_fps(int fps);
fly_t characters(void);

void redraw_screen(void);

