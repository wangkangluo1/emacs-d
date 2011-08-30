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

int qSort_pos(int* a[],int low,int high)
{
   int temp=*a[low],i=low,j=high;
   while(i<j)
   {
      while((*a[j]>=temp)&&(i<j)) j--;
      if(i<j)  {swap(a[i],a[j]);i++;}
      while((*a[i]<=temp)&&(i<j)) i++;
      if(i<j)  {swap(a[i],a[j]);j--;}
   } 
   return i;
}

void qSort(int* a[],int low,int high)
{
     int pos;
     if(low<high)
     {
        pos=qSort_pos(a,low,high);
        qSort(a,low,pos-1);
        qSort(a,pos+1,high);         
     }
}

void quicksort(int* l[],int n)
{
   qSort(l,0,n - 1); //第一个作为枢轴 ，从第一个排到第n个
}

    int 
main()
{
    int lens = 100;
    int* a[100];
    int i = 0;
    for(i = 0; i < lens; i++ )
    {
        a[i] = (int*)malloc(sizeof(int));
        *a[i] = rand();
    } 

    quicksort(a,lens);


    return 0;
}

