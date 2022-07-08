#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main () {
    //1.打开FIFO
    int fd = open("test", O_RDONLY);
    if(fd == -1) {
        perror("open");
        exit(0);
    }

    //2.读FIFO
    while(1) {
        char buf[1024] = {0};
        int len = read(fd,buf,sizeof(buf));
        if(len == 0) {
            //读完了 写端没断开 read会阻塞
            //      写端端开，read没有阻塞，说明写端下线了
            printf("write offline ...\n");
            break;
        }
        printf("read recv: %s\n", buf);
    }
   
    close(fd);
    return 0;
}