/*
 * =====================================================================================
 *
 *       Filename:  stringsReplace.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/21/2011 11:32:19 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */
#include	<stdlib.h>
#include	<string.h>
#include     "stringsReplace.h"

    static long int
find_strings_count ( const char *pStrings, const char *pFindStrings )
{
    long int n_counts = 0;
    if(pStrings != NULL && pFindStrings && strcmp(pStrings, "") && strcmp(pFindStrings, ""))
    {
        long int n_lengs = strlen(pFindStrings);
        char *p_head = (char*)pStrings ;
        char *p_point = (char*)pStrings;
        while(1)
        {
            p_point = strstr(p_head, pFindStrings);
            if(p_point != NULL)
            {
                n_counts++;
            }
            else
            {
                break;
            }
            p_head = p_point + n_lengs;
        }
    }
    return n_counts;
} /* ----- end of function calu_strings_num ----- */

    static  void 
strings_replace(char *dest, const char *pInput, const char *pSrc, const char *pDst)
{
    char *point = NULL;
    char *input_head = (char*)pInput;
    char *output_head = dest;
    long long int lens = 0;
    int src_lens = strlen(pSrc);
    int dst_lens = strlen(pDst);
    while(1)
    {
        point = strstr(input_head, pSrc);
        if(point != NULL)
        {
            lens =(long long int)(point) - (long long int)(input_head);
        }
        else
        {
            int len = (int)(&pInput[strlen(pInput)] - input_head);
            memcpy(output_head, input_head , len);
            break;
        }
        memcpy(output_head, input_head, lens);
        input_head = input_head + lens + src_lens;
        output_head = output_head + lens;
        memcpy(output_head, pDst, dst_lens);
        output_head = output_head + dst_lens;
    }
    return ;
}

   void
strings_replace_without_free (char **dest, const char  *pStrings, const char *pNeedReplace, const char *pNew )
{
    long int counts = find_strings_count(pStrings, pNeedReplace);
    int len = strlen(pNew) - strlen(pNeedReplace);
    int strings_len = strlen(pStrings);
    long int malloc_len = strings_len + counts*len + 1;
    *dest = (char*)malloc(malloc_len);
    (*dest)[malloc_len -1] = '\0';
    strings_replace(*dest, pStrings, pNeedReplace, pNew);
    return ;
} /* ----- end of function strings_replace ----- */

