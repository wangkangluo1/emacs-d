/*
 * =====================================================================================
 *
 *       Filename:  jiecheng.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/2011 01:05:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */


#include	<errno.h>
#include	<math.h>  
#include	<stdio.h> 
#include	<stdlib.h>
#include	<string.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */


    long long int
func ( int num )
{
    if(num != 1)
    {
        return num*func(num - 1);
    }
    else
    {
    return 1 ;
    }
}		/* -----  end of function func  ----- */

	int
main ( int argc, char *argv[] )
{
       int num = 3;
       long long int value = func(num);
	printf ("\nProgram %lld\n\n", value );

	return EXIT_SUCCESS;
}		/* ----------  end of function main  ---------- */

