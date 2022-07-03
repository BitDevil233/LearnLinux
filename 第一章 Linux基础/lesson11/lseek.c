#include <sys/types.h>  //open lseek
#include<sys/stat.h>    //open
#include<fcntl.h>   //open
#include <unistd.h> //lseek
#include<stdio.h>   //perror

int main() {
    int fd = open("./hello.txt",O_RDWR);
    if(fd == -1) {
        perror("open");
        return -1;
    }
    //文件扩容
    int ret = lseek(fd, 100, SEEK_END);
    if(ret == -1) {
        perror("lssek");
    }
    //写入字符串 
    write(fd, " ", 1);
    //关闭文件
    close(fd);
    return 0;
}