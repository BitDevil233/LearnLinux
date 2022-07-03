#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
    int num = 10;
    //创建子进程
    pid_t ret = fork();
    
    //判断
    if(ret == -1) {
        perror("fork");
    }else if(ret == 0) {
        printf("子进程: pid : %d , ppid : %d\n", getpid(), getppid());
        num += 10;
        printf("in child process , num = %d\n" , num);

    }else {
        printf("父进程: pid : %d , ppid : %d\n", getpid(), getppid());
        num += 100;
        printf("in parent process , num = %d\n" , num);
    }

    sleep(1);

    return 0;
}