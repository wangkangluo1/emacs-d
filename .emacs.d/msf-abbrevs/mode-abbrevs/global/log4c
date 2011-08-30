/*
 * =====================================================================================
 *
 *       Filename:  log4c.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2011 04:01:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "log4c.h"

int main(int argc, char** argv){
    int rc = 0;
    char *test = "test strings";
    log4c_category_t* mycat = NULL;

    if (log4c_init()){
        printf("log4c_init() failed");
        rc = 1;  
    }else{
        mycat = log4c_category_get("log4c.examples.helloworld");
        log4c_category_log(mycat, LOG4C_PRIORITY_ERROR, "hellworld");
        log4c_category_log(mycat, LOG4C_PRIORITY_ERROR, "%d", rc);
        log4c_category_log(mycat, LOG4C_PRIORITY_ERROR, "%s", test);
        /* Explicitly call the log4c cleanup routine */
        if ( log4c_fini()){
            printf("log4c_fini() failed");
        }
    }
    return 0;
}
