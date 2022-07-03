#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    //打开一个文件，获取文件描述符
    int fd = open("./1.txt", O_RDWR);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    //读取文件描述符的权限
    int flag = fcntl(fd, F_GETFL);
    if(flag == -1) {
        perror("fcntl");
        return -1;
    }

    //修改文件描述符的权限
    flag = flag | O_APPEND;
    int flag2 = fcntl(fd, F_SETFL, flag);
    if(flag2 == -1) {
        perror("fcntl2");
        return -1;
    }
    

    //写入数据
    char * buf = ",world!\n";
    write(fd, buf, strlen(buf));

    printf("fd: %d, flag: %d, flag2: %d\n", fd, flag, flag2);

    return 0;
}