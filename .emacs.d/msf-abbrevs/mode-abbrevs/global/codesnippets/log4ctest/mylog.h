#ifndef _MYLOG_H_
#define _MYLOG_H_

#include <string.h>
#include <stdlib.h>
#include "log4c.h"
#define MYLOG_CATEGORY_NAME "log4ctest"
#define MYLOG_PRIORITY LOG4C_PRIORITY_WARN

//1.LOG4C_PRIORITY_ERROR
//2.LOG4C_PRIORITY_WARN
//3.LOG4C_PRIORITY_NOTICE
//4.LOG4C_PRIORITY_DEBUG
//5.LOG4C_PRIORITY_TRACE

extern int mylog_init();
extern void log_message(char* file, int line, const char* func,const char* a_format, ...);
extern int mylog_fini();
#define LOG(fmt,args...) log_message(__FILE__, __LINE__, __FUNCTION__,fmt ,## args);
#endif
