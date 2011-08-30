

#include	<errno.h>
#include	<math.h>  
#include	<stdio.h> 
#include	<stdlib.h>
#include	<string.h>
#include        "config.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */

	int
main ( int argc, char *argv[] )
{
        start_CONFIG();
        fuck_A(); 
	printf ("\nProgram %s\n\n", argv[0] );
        free_CONFIG();
	return EXIT_SUCCESS;
}		/* ----------  end of function main  ---------- */

