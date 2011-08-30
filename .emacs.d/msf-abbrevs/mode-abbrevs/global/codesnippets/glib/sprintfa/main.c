#include        <errno.h>
#include        <math.h>  
#include        <stdio.h> 
#include        <stdlib.h>
#include        <string.h>
#include        <glib.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
        int
main ( int argc, char *argv[] )
{
        GString * p_gstr = g_string_new(NULL);
        char* desStr = "12345";
        g_string_sprintfa(p_gstr, "\"post_summary\":\"%s\",", desStr);
        char* buf = (char*)malloc(p_gstr->len + 1);
        strncpy(buf, p_gstr->str, p_gstr->len);
        //g_string_free(p_gstr, TRUE);                                        
        buf[p_gstr->len] = '\0';
        printf ("\nProgram %s\n\n", buf );
        free(buf);
        return EXIT_SUCCESS;
} 

