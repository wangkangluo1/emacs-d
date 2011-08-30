#include "stdio.h"
struct DEMO
{
    int x,y;
    int (*func)(int,int); //函数指针
};
int add2(int x,int y)
{
    return x+y;
}
int main()
{
    struct DEMO demo;
    demo.func=&add2; //结构体函数指针赋值
    printf("func(3,4)=%d\n",demo.func(3,4));
    return 0;
}
