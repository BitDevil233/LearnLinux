#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {

    //创建子进程
    pid_t ret = fork();
    
    //判断
    if(ret == -1) {
        perror("fork");
    }else if(ret == 0) {
        printf("子进程: pid : %d , ppid : %d\n", getpid(), getppid());
    }else {
        printf("父进程: pid : %d , ppid : %d\n", getpid(), getppid());
    }

    //测试父子进程的执行顺序
    for(int i = 0; i < 10; i++) {
        printf("i = %d, pid = %d\n",i, getpid());
        sleep(1); //休眠一秒
    }

    return 0;
}