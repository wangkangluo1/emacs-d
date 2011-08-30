#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>


    void
change_node ( int data[], int head, int start, int end )
{
int j = 0;
    for(j = end; j > start; j--)
    {
        data[j] = data[j-1];
    }
    data[start] = head;
    return ;
}        /* -----  end of function change_node  ----- */

    void
insert_data (int data[], int num)
{
    int i = 0;
    for(i = num - 1; i >= 0 ; i--)
    {
        if((data[num] > data[i]))
        {
            if(i == num - 1)
            {
                break;
            }
            change_node(data, data[num], i+1, num);
            break;
        }
        else
        {
            if(i == 0)
            {
                change_node(data, data[num], 0, num);
            }
        }
    }
    return ;
}        /* -----  end of function insert_data  ----- */

    void
sort (int data[], int nums)
{
    int i = 1;
    for(i = 1; i < nums ; i++)
    {
        insert_data(data, i);    
    }
    return ;
}        /* -----  end of function sort  ----- */

    int 
main()
{
    int lens = 100000;
    int a[100000];
    int i = 0;
    for(i = 0; i < lens; i++ )
    {
        a[i] = rand();
    }
    struct timeval tv1, tv2;
    double sec = 0;
    gettimeofday(&tv1, 0);

    sort(a,lens);

    gettimeofday(&tv2, 0);
    sec = (double)(tv2.tv_sec - tv1.tv_sec) +  (double)(tv2.tv_usec - tv1.tv_usec) / 1000000;
    printf("time1: %f\n", sec);

    return 0;
}

