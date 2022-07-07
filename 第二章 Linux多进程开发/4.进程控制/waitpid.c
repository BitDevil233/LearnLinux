#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
    //创建5个子进程（兄弟）
    pid_t ret = 0;
    for (int i = 0; i < 5; i++)
    {
        ret = fork();
        if(ret == 0) {  //for 和 ret搭配，实现创建5个子进程，而不创建孙子进程
            break;
        }
    }

    if (ret > 0){
        //父进程
        int st = 0;
        int pid = 0;
        while(1) {
            printf("父进程id:%d\n", getpid());
            pid = waitpid(-1, &st, WNOHANG);
            if(pid == -1) {     //所有子进程都已经退出
                printf("所有子进程都已经退出\n");
                break;
            }

            if(pid == 0) {
                break;
            }else {
                if(WIFEXITED(st)) {
                printf("child die pid = %d",pid);
                //子进程正常退出
                printf("子进程%d正常退出,退出的状态码:%d\n", pid, WEXITSTATUS(st));
                }
                if(WIFSIGNALED(st)) {
                    //子进程异常退出
                    printf("子进程%d异常退出, 被%d信号kill\n", pid, WTERMSIG(st));
                }
            
            }
            sleep(1);
        }
    } else if(ret == 0) {
        // 子进程
        while(1) {
            printf("子进程pid = %d\n",getpid());    
            sleep(1);           
        }

        exit(0);
    }

    return 0;
}