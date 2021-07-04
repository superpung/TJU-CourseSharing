#include "common.h"
#include "game.h"
#include "adt/linklist.h"
#include "device/video.h"
#include "x86.h"
#include "FLOAT.h"

#include <string.h>
#include <stdlib.h>

LINKLIST_IMPL(fly, 1000)

static fly_t head = NULL;
static int hit = 0, miss = 0;

int
get_hit(void) {
	return hit;
}

int
get_miss(void) {
	return miss;
}

fly_t
characters(void) {
	return head;
}

/* 在屏幕上创建一个新的字母 */
void
create_new_letter(void) {
	if (head == NULL) {
		head = fly_new(); /* 当前没有任何字母，创建新链表 */
	} else {
		fly_t now = fly_new();
		fly_insert(NULL, head, now); /* 插入到链表的头部 */
		head = now;
	}
	/* 字母、初始位置、掉落速度均为随机设定 */
	head->x = 0;
	head->y = rand() % (SCR_WIDTH / 8 - 2) * 8 + 8;
	head->v = F_div_F(int2F(rand() % 1000), int2F(2000)) + f2F(0.5);
	head->text = rand() % 26;
	release_key(head->text); /* 清除过往的按键 */
}

/* 逻辑时钟前进1单位 */
void
update_letter_pos(void) {
	fly_t it;
	for (it = head; it != NULL; ) {
		fly_t next = it->_next;
		it->x += it->v; /* 根据速度更新位置 */
		if (it->x < 0 || it->x + f2F(7.9) > int2F(SCR_HEIGHT)) {
			if (it->x < 0) hit ++; /* 从上部飞出屏幕 */
			else miss ++; /* 从下部飞出屏幕 */
			fly_remove(it);
			fly_free(it);
			if (it == head) head = next; /* 更新链表 */
		}
		it = next;
	}
}

/* 更新按键 */
bool
update_keypress(void) {
	fly_t it, target = NULL;
	FLOAT min = -int2F(100);

	cli();
	/* 寻找相应键已被按下、最底部且未被击中的字符 */
	for (it = head; it != NULL; it = it->_next) {
		assert(it->text >= 0 && it->text < 26);
		if (it->v > 0 && it->x > min && query_key(it->text)) {
			min = it->x;
			target = it;
		}
	}
	/* 如果找到则更新相应数据 */
	if (target != NULL) {
		release_key(target->text);
		target->v = -int2F(3); /* 速度改为向上 */
		return true;
	}
	sti();

	return false;
}

