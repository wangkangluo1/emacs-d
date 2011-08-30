

#include	<errno.h>
#include	<math.h>  
#include	<stdio.h> 
#include	<stdlib.h>
#include	<string.h>
#include        "a.h"


typedef struct PageStr PageStrCPN;


struct PageStr
{
    char* p_ch_data;
    int a;
    int b;
};

    int
main ( int argc, char *argv[] )
{
    int4 a = 10 , b = 100;
    char *c = g_new(PageStrCPN);
    ((PageStrCPN*)c)->a = 10;
    printf ("\nProgram %d\n\n", ((PageStrCPN*)c)->a  );
    printf ("\nProgram %d\n\n",(int)MAX(a, b) );
    free(c);
    return EXIT_SUCCESS;
}		/* ----------  end of function main  ---------- */

