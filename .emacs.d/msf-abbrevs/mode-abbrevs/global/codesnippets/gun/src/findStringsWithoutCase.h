/*
 * =====================================================================================
 *
 *       Filename:  findStringsWithoutCase.h
 *
 *    Description:      
 *
 *        Version:  1.0
 *        Created:  07/20/2011 07:19:55 PM
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


#include	<string.h>

   char*
find_strings_without_case (const char *content, const char *pkeywords);    //如果是中文，原样输出 英文 则查找其在原文中到底具体字符的大小写

#endif
