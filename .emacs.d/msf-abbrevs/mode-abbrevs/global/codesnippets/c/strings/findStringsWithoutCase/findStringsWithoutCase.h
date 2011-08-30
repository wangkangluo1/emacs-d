/*
 * =====================================================================================
 *
 *       Filename:  findStringsWithoutCase.h
 *
 *    Description:    
 *
 *        Version:  1.0
 *        Created:  07/26/2011 01:19:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */


#ifndef FIND_STRINGS_WITHOUT_CASE_H_
#define FIND_STRINGS_WITHOUT_CASE_H_

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


   char*
find_without_case (const char *content, const char *pkeywords);
#endif
