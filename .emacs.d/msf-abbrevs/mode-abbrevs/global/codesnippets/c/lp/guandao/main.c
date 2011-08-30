#include <unistd.h> 
#include <stdio.h> 
#include <sys/types.h> 
#include <assert.h> 
int main() 
{ 
    int fildes[2]; 
    pid_t pid; 
    int i,j; 
    char buf[256]; 
    assert(pipe(fildes) == 0);                          //  创建管道 
    assert((pid = fork()) >= 0);                      //  创建子进程 
    if(pid == 0){                                        //  子进程 
        close(fildes[1]);                                //  子进程关闭管道输出 
        memset(buf, 0, sizeof(buf)); 
        j = read(fildes[0], buf, sizeof(buf)); 
        fprintf(stderr, "[child] buf=[%s] len[%d]\n", buf, j); 
        return; 
    } 
    close(fildes[0]);                                              //  父进程关闭管道输入 
    write(fildes[1], "hello!", strlen("hello!")); 
    write(fildes[1], "world!", strlen("world!")); 
    return 0; 
} 

