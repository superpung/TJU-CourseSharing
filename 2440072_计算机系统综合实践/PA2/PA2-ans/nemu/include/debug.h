#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>
#include <assert.h>

extern FILE* log_fp;

#ifdef LOG_FILE
#	define Log_write(format, ...) fprintf(log_fp, format, ## __VA_ARGS__), fflush(log_fp)
#else
#	define Log_write(format, ...)
#endif

#define Log(format, ...) \
	do { \
		fprintf(stdout, "\33[1;34m[%s,%d,%s] " format "\33[0m\n", \
				__FILE__, __LINE__, __func__, ## __VA_ARGS__); \
		fflush(stdout); \
		Log_write("[%s,%d,%s] " format "\n", \
				__FILE__, __LINE__, __func__, ## __VA_ARGS__); \
	} while(0)

#define Assert(cond, ...) \
	do { \
		if(!(cond)) { \
			fflush(stdout); \
			fprintf(stderr, "\33[1;31m"); \
			fprintf(stderr, __VA_ARGS__); \
			fprintf(stderr, "\33[0m\n"); \
			assert(cond); \
		} \
	} while(0)

#define panic(format, ...) \
	Assert(0, format, ## __VA_ARGS__)

#endif
