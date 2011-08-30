#include    <errno.h>
#include    <stdio.h> 
#include    <stdlib.h>
#include    <string.h>
#include        <math.h>


    static int
is_english ( const char *pkeywords )     //判断是否存在英文字符
{
    int back = 0;
    int lens = strlen(pkeywords);
    int i = 0;
    for(i = 0; i < lens ; i++)
    {
        if((unsigned char)pkeywords[i] > 0xe0 && (unsigned char)pkeywords[i] < 0xef) 
        {
            i = i + 2;
        }

        if((unsigned char)pkeywords[i] > 0x40 && (unsigned char)pkeywords[i] < 0x5b) 
        {
            back = 1;
        }   
        if((unsigned char)pkeywords[i] > 0x60 && (unsigned char)pkeywords[i] < 0x7b) 
        {
            back = 1;
        }
    }

    return back;
}               /* -----  end of function is_chinese  ----- */

    static char
is_anti ( const char key )
{
    char back = key;
    if((unsigned char)key > 0x40 && (unsigned char)key < 0x5b )
    {
        back = (unsigned char)key + 0x20;
    }
     if((unsigned char)key > 0x60 && (unsigned char)key < 0x7b )
    {
        back = (unsigned char)key - 0x20;
    }
   
    return back;
}               /* -----  end of function is_anti  ----- */

 static char*
get_strings_by_bit (const char *pkeywords, const long long int num )        //根据比特位对相应字符取反
{
    char *back = NULL;
    int lens = strlen(pkeywords);
    back = (char*)malloc(lens + 1);
    memset(back, '\0', lens + 1);
    int i = 0;
    for(i = 0; i < lens ; i++)
    {
       long long  int is_bit_true = pow(2, i);
       if((is_bit_true&num) != 0)
       {
          back[i] = is_anti(pkeywords[i]);
       }
       else
       {
          back[i] = pkeywords[i];
       }
       
    }
    back[lens] = '\0';
    return back;
}               /* -----  end of function get_strings_by_bit  ----- */

    static char*
get_exact_whatis ( const char *content, const char *pkeywords )    //根据原文中出现的英文单词 确定大小写
{
    char *back = NULL;
    int lens = strlen(pkeywords);
    int counts = pow(2, lens);
    long long int i = 0;
    for(i = 0; i < counts ; i++)
    {
        char *strings = get_strings_by_bit(pkeywords, i);
        char *point = NULL;

        point =  strstr(content, strings);
        if( point != NULL)
        {
           back = (char*)malloc(lens + 1);
           strncpy(back, strings, lens);
           back[lens] = '\0';
           free(strings);
           return back;
        }
        free(strings);
        strings = NULL;
    }
    return back ;
}               /* -----  end of function get_exact_whatis  ----- */

  char*
find_without_case (const char *content, const char *pkeywords)    //如果是中文，原样输出 英文 则查找其在原文中到底具体字符的大小写
{
    char *back = NULL;
    if((is_english(pkeywords)))    
    {
        back = get_exact_whatis(content, pkeywords);
    }
    return back;
}               /* -----  end of function get_change_by_case  ----- */

/*
    int
main ( int argc, char *argv[] )
{
    char *strings = "fjdkasjfkdjsipho中H";
    char *key = "中h";
    char *pos = find_without_case(strings, key);
    printf ("\nProgram %s\n\n", pos);
    free(pos);
    return EXIT_SUCCESS;
}
*/
