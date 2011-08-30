/*
 * =====================================================================================
 *
 *       Filename:  xincan.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/21/2011 05:29:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <stdarg.h>
#include	<string.h>

int compare(const void * var1,const void * var2) 
{ 
    if(*(int *)var1 > *(int *)var2) 
    { 
        return(0); 
    } 
    else{ 
        return(1); 
    } 
} 

void myPrintf(const char * output ,...) 
{ 
    va_list arguments; 
    int stringlength,stringIndx; 
    char *s; 
    int d; 
    char c; 
    stringlength = strlen(output); 
    va_start(arguments,output); 
    for(stringIndx = 0;stringIndx < stringlength;stringIndx++) 
    { 
        if(output[stringIndx] == '%') 
        { 
            stringIndx++; 
            switch(output[stringIndx]) 
            { 
                case 's': /* string */ 
                    s = va_arg(arguments, char *); 
                    printf("%s\n", s); 
                    break; 
                case 'd': /* int */ 
                    d = va_arg(arguments, int); 
                    printf("%d\n", d); 
                    break; 
                case 'c': /* char */ 
                default: 
                    /* need a cast here since va_arg only 
                       takes fully promoted types */ 
                    c = (char)va_arg(arguments, char); 
                    printf("%c\n", c); 
                    break; 
            } 
        } 
        else{ 
            printf("%c",output[stringIndx]); 
        } 
    } 
} 

int main() 
{ 
    unsigned int au32Nos[10] = {32,44.,55,66,11,8,9,7,9,10}; 
    qsort(au32Nos,10,4,compare); 

    myPrintf(" %d %d %d %d %d %d %d %d %d %d",au32Nos[0],au32Nos[1],au32Nos[2],au32Nos[3],au32Nos[4],au32Nos[5],au32Nos[6],au32Nos[7],au32Nos[8],au32Nos[9]); 
    return 0;
}

