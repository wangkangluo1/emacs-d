#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/time.h>
#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

void Thread1(void);
void Thread2(void);
void Thread3(void);

int Alex=0;

sem_t sem12;

sem_t sem13;

int main(void)
{

    pthread_t pid1,pid2,pid3;
    printf("this is Main Thread!\n");

    int ret= sem_init(&sem12,0,0);
    if(ret !=0)
    {
        printf("sem12 init Fail!\n");
        return ret;
    }
    ret = sem_init(&sem13,0,0);
    if(ret !=0)
    {
        printf("Sem13 init fail\n");
        return ret;
    }

    pthread_create(&pid1,NULL,(void *)Thread1,NULL);

    pthread_create(&pid2,NULL,(void *)Thread2,NULL);

    pthread_create(&pid3,NULL,(void *)Thread3,NULL);

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
    pthread_join(pid3,NULL);

    sem_destroy(&sem12);
    sem_destroy(&sem13);
}

void Thread1(void)
{
    printf("This is Thread1!\n");
    int input;
    printf ("put an number:\n");
    getchar();
    sem_post(&sem12);
    sem_post(&sem13);

    printf("Thread1 Completed!\n");
}

void Thread2(void)
{
    printf("This is Thread2!\n");
    sem_wait(&sem12);
    printf("Thread2 Completed!\n");
}

void Thread3(void)
{
    struct timespec ts;
    printf("This is Thread3!\n");

    ts.tv_sec = time(NULL)+10;  //等待10秒超时
    int s=sem_timedwait(&sem13,&ts);
    if(s == -1)
    {
        printf ("Thread3 wait timeout\n");
        return;
    }
    printf("Thread3 Completed!\n");
}


