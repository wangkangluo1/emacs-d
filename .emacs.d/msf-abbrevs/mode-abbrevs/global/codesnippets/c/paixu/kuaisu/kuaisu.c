#include <stdio.h>
#include <sys/time.h>    
#include <unistd.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
     int temp;
     temp=*a;
     *a=*b;
    *b=temp;
}

int qSort_pos(int a[],int low,int high)
{
   int temp=a[low],i=low,j=high;
   while(i<j)
   {
      while((a[j]>=temp)&&(i<j)) j--;
      if(i<j)  {swap(&a[i],&a[j]);i++;}
      while((a[i]<=temp)&&(i<j)) i++;
      if(i<j)  {swap(&a[i],&a[j]);j--;}
   } 
   return i;
}


void qSort(int a[],int low,int high)
{
     int pos;
     if(low<high)
     {
        pos=qSort_pos(a,low,high);
        qSort(a,low,pos-1);
        qSort(a,pos+1,high);         
     }
}

void quicksort(int l[],int n)
{
   qSort(l,0,n - 1); //第一个作为枢轴 ，从第一个排到第n个
}

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
    for(i = 0; i < 10; i++)
    {
        printf("%d\n",a[i]);
    }
    quicksort(a,lens);

    printf("\n\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d\n",a[i]);
    }

    gettimeofday(&tv2, 0);
    sec = (double)(tv2.tv_sec - tv1.tv_sec) +  (double)(tv2.tv_usec - tv1.tv_usec) / 1000000;
    printf("time1: %f\n", sec);

    return 0;
}

