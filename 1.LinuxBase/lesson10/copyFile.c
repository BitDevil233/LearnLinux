#include<unistd.h>
#include<stdio.h>
//下面三个都是open函数需要包含的头文件
#include<sys/types.h>
#include<sys/stat.h> //状态宏
#include<fcntl.h>

int main() {
    //open 
    int srcfd = open("./english.txt", O_RDONLY);
    if(srcfd == -1) {
        perror("srcopen");
    }
    //creat new file
    int destfd = open("cpy.txt", O_WRONLY | O_CREAT, 0664);
    if(destfd == -1) {
        perror("destopen");
    }
    //read and write
    char buf[1024] = {0};
    int len = 0;
    do {
        len = read(srcfd, buf, sizeof(buf));
        if(len > 0) {
            write(destfd, buf, len);
        }else {
            break;
        }
    }while(len > 0);
    //close
    close(srcfd);
    close(destfd);
    return 0;
}