#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main() {
    //新建文件,获取文件描述符
    int fd = open("a.txt", O_RDWR | O_CREAT, 0664);
    if(fd == -1) {
        perror("open");
        return -1;
    }
    //复制文件描述符
    int fd1 = dup(fd);

    //验证复制出来的文件描述符是否生效：用fd1写文件。
    char * buf = "hello,world";
    int ret = write(fd1, buf, strlen(buf));
    if(ret == -1) {
        perror("write");
        return -1;
    }

    printf("fd: %d, fd1: %d\n", fd, fd1);

    return 0;
}