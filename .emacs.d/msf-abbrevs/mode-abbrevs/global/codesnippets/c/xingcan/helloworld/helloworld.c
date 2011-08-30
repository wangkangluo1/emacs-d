/*
 * =====================================================================================
 *
 *       Filename:  canshu.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2011 05:00:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */

#include <stdio.h> 
#include <stdarg.h> ////处理可变参数列表，需要包含这个头文件

int max(int num, int b, ...)  ///num表示参数的个数
{
    va_list ap; 
    int m,i,temp; 

    va_start(ap,b); ////处理可变参数列表，初始化
    m=b; 
    for(i=1;i<num;i++) 
    { 
        temp=va_arg(ap,int); ////处理可变参数列表，每次取一个参数
        if(m<temp)m=temp; 
    } 
    va_end(ap); ////处理可变参数列表，结束
    return m; 
} 

int main(void) 
{ 
    printf("max(1,1)=%d\n", max(1,1)); 
    printf("max(2,1,2)=%d\n", max(2,1,2)); 
    printf("max(3,1,2,3)=%d\n", max(3,1,2,3)); 
    return 0; 
}
