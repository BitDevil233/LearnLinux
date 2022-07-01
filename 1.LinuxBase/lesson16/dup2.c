#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {

    //创建一个文件，获取文件描述符fd
    int fd = open("1.txt", O_RDWR | O_CREAT,0644);
    if(fd == -1) {
        perror("open");
        return -1;//exit(0);
    }
    
    //再创建一个文件，获取文件描述符fd1
    int fd1 = open("2.txt", O_RDWR | O_CREAT,0644);
    if(fd1 == -1) {
        perror("open");
        return -1;//exit(0);
    }
    
    //打印fd, fd1
    printf("fd: %d, fd1: %d\n", fd, fd1);
    
    //文件描述符重定向fd1->fd，返回fd2
    int fd2 = dup2(fd, fd1);
    if(fd2 == -1) {
        perror("dup");
        return -1;
    }
    
    //修改fd1指向的文件
    char * buf = "hello,dup2";
    int len = write(fd1, buf, strlen(buf));
    
    //打印fd, fd1, fd2
    printf("fd: %d, fd1: %d, fd2: %d\n", fd, fd1,fd2);
    
    //关闭fd,fd1,fd2
    close(fd);
    close(fd1);
    
    return 0;
}