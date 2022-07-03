#include <stdio.h>
#include <unistd.h>

int main() {
    //创建子进程
    int pid = fork();
    if(pid > 0) {
        //父进程
        printf("parent process, pid : %d\n", getpid());
    } else if(pid == 0) {
        //子进程
        printf("child process, pid : %d\n", getpid());
        execlp("ps", "ps", "aux",NULL);
    }
}