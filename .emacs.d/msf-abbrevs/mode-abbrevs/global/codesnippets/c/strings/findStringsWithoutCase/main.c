/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/26/2011 02:51:40 PM
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

#include	"findStringsWithoutCase.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
    char *strings = "fjdkasjfkdjsipho中H";
    char *key = "中h";
    char *pos = find_without_case(strings, key);
    printf ("\nProgram %s\n\n", pos);
    free(pos);
	printf ("\nProgram %s\n\n", argv[0] );

	return EXIT_SUCCESS;
}		/* ----------  end of function main  ---------- */

