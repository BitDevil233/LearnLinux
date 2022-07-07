#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    //在fork之前创建管道
    int pipefd[2];
    int ret = pipe(pipefd);
    if(ret == -1) {
        perror("pipe");
    }

    //fork
    pid_t pid = fork();
    if(pid == -1) {
        perror("fork");
        exit(0);
    }else if(pid == 0) {
        //子进程
        while(1) {
                //写数据
            
            char * str = "Hello, i am child\n";
            int send = write(pipefd[1], str, strlen(str));
            //sleep(1);
            //读数据
            close(pipefd[0]);
            //char buf[1024] = {0};
            //int receive = read(pipefd[0],buf, sizeof(buf));
            //printf("child receive : %s\n" ,buf);
        }
    } else {
        //父进程
        while(1) {
            
                //读取数据
            char buf[1024] = {0};
            int receive = read(pipefd[0],buf, sizeof(buf));
            printf("parent receive : %s\n" ,buf);
            close(pipefd[1]);
            //写数据
            //char * str = "Hello, i am parent";
            //int send = write(pipefd[1], str, strlen(str));
            //sleep(1);
        }
    }


    return 0;
}