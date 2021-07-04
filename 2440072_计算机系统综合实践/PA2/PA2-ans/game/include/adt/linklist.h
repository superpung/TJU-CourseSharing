#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include "debug.h"

/* Usage:
 *   my_list.h:
 *     LINKLIST_DEF(list_name)
 *         int data;
 *         void *ptr;  // arbitrary data fields
 *     LINKLIST_DEF_FI(list_name)
 *   my_list.c:
 *     #include "my_list.h"
 *     LINKLIST_IMPL(list_name, pool_size)
 *
 * this will create an list implementation:
 *   1. my_list_t is a pointer to the structure containing all fields
 *      between LINKLIST_DEF and LINKLIST_DEF_FI
 *   2. a static memory pool of (pool_size) elements are created
 *   3. my_list_new() will return a free element int the pool, while
 *      my_list_free() will put an object to free
 *   4. my_list_prev(), my_list_next(), my_list_insert() and
 *      my_list_remove() are used for linked list manipuliation
 */

/* first part of list definition */
#define LINKLIST_DEF(NAME) \
struct NAME##_t {

/* second part of list definition */
#define LINKLIST_DEF_FI(NAME) \
	struct NAME##_t *_prev, *_next; \
}; \
typedef struct NAME##_t *NAME##_t; \
NAME##_t NAME##_prev(NAME##_t node); \
NAME##_t NAME##_next(NAME##_t node); \
void NAME##_remove(NAME##_t node); \
void NAME##_insert(NAME##_t prev, NAME##_t next, NAME##_t obj); \
NAME##_t NAME##_new(); \
void NAME##_free(NAME##_t node); 

/* list implementation */
#define LINKLIST_IMPL(NAME, SIZE) \
static struct NAME##_t NAME##_pool[(SIZE) + 1]; \
static NAME##_t NAME##_free_head = NULL; \
NAME##_t NAME##_new() { \
	NAME##_t ret, free_head = NAME##_free_head; \
	struct NAME##_t *pool = NAME##_pool; \
	if (free_head == NULL) { \
		int i; \
		for (i = 1; i <= SIZE; i ++) { \
			pool[i - 1]._next = pool + i; \
		} \
		free_head = pool; \
	} \
	assert(free_head->_next != NULL); \
	ret = free_head; \
	NAME##_free_head = free_head->_next; \
	ret->_prev = ret->_next = NULL; \
	return ret; \
} \
NAME##_t NAME##_prev(NAME##_t node) { \
	assert(node != NULL); \
	return node->_prev; \
} \
NAME##_t NAME##_next(NAME##_t node) { \
	assert(node != NULL); \
	return node->_next; \
} \
void NAME##_insert(NAME##_t prev, NAME##_t next, NAME##_t obj) { \
	assert(prev != NULL || next != NULL); \
	obj->_prev = prev; \
	obj->_next = next; \
	if (prev != NULL) prev->_next = obj; \
	if (next != NULL) next->_prev = obj; \
} \
void NAME##_remove(NAME##_t node) { \
	NAME##_t prev = node->_prev, next = node->_next; \
	assert(node != NULL); \
	if (prev != NULL) prev->_next = next; \
	if (next != NULL) next->_prev = prev; \
} \
void NAME##_free(NAME##_t node) { \
	node->_next = NAME##_free_head; \
	NAME##_free_head = node; \
} \

#endif
