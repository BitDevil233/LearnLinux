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
        while(1) {
            sleep(1);
            printf("父进程: pid : %d , ppid : %d\n", getpid(), getppid());
        }
    }

    return 0;
}