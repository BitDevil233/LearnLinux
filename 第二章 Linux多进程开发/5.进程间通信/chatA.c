#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>


int main() {
    //FIFO1
    int ret1 = access("fifo1", F_OK);
    //fifo不存在
    if(ret1 == -1) {
        //创造有名管道
        printf("fifo1不存在,创建有名管道。\n");
        int fifoRet1 = mkfifo("fifo1",0664);
        if(fifoRet1 == -1) {
            perror("mkfifo1");
            exit(0);
        }
    }

    //FIFO2
    int ret2 = access("fifo2", F_OK);
    //fifo不存在
    if(ret2 == -1) {
        //创造有名管道
        printf("fifo2不存在,创建有名管道。\n");
        int fifoRet2 = mkfifo("fifo2",0664);
        if(fifoRet2 == -1) {
            perror("mkfifo2");
            exit(0);
        }
    }
    printf("test0");
    //打开fifo1， fifo2
    int fdw = open("fifo1", O_WRONLY);
    if(fdw == -1) {
        perror("open");
        exit(0);
    }
    printf("test 1");
    int fdr = open("fifo2", O_RDONLY);
    if(fdr == -1) {
        perror("open");
        exit(0);
    }
    printf("test 2");
    while(1) {
        //写fifo1
        char bufw[128];
        printf("chatA : ");
        fgets(bufw,sizeof(bufw),stdin);
        write(fdw,bufw,strlen(bufw));
        memset(bufw,0,strlen(bufw));

        //读fifo2
        char bufr[128];
        int len = read(fdr,bufr,strlen(bufr));
        if(len == 0) {
            printf("chatB offline ...\n");
            break;
        }
        printf("chatB : %s\n", bufr);
        memset(bufr,0,strlen(bufr));


    }

    close(fdr);
    close(fdw);

    return 0;
}