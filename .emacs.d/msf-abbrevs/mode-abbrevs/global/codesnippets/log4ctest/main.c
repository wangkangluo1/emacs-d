#include <stdio.h>
#include "mylog.h"
#include "other.h"

int main(int argv, char **argc) {
  int i;
	if ( mylog_init() == 1 )
	{
		printf("mylog_init() failed!\n");
	}
	
    for(i=0;i<140;i++)
    {
    	LOG("%s%d","Hello!-",i);	
    	otherFunc();
    }
    if(mylog_fini() == 1)
    {
    	printf("mylog_fini() failed!\n");
    }
    
    return 0;
}
