//向fifo中写数据
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main () {
    //1.判断fifo是否存在
    int ifExist = access("test", F_OK);
    if(ifExist == -1) {
        printf("管道不存在创建管道：\n");
        //2.创建FIFO
        int ret = mkfifo("test", 0664);
        if(ret == -1) {
            perror("mkfifo");
            exit(0);
        }
    }
    
    //3.打开FIFO文件
    int fd = open("test", O_WRONLY);
    if(fd == -1) {
        perror("open");
        exit(0);
    }

    //4.写FIFO
    for(int i = 0; i < 100; i++) {
        char buf[1024] = {0};
        sprintf(buf, "hello, %d\n", i);
        printf("write data : %s", buf);
        write(fd, buf, strlen(buf));
        sleep(1);
    }

    close(fd);

    return 0;
}