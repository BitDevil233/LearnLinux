/*
#include <unistd.h>
int chdir(const char *path);    
作用：修改进程的工作目录
    比如在Linux/lesson14下启动一个可执行程序 a.out,则该可执行程序的工作目录就是Linux/lesson14
参数：path:
    修改后的工作目录
返回值：

 #include <unistd.h>

char *getcwd(char *buf, size_t size);
作用：获取当前的工作目录
参数：buf：
        获取目录后存储的缓存
    size ：数组的大小
返回值：
    返回一个指针，指针指向buf缓存。

*/
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    //获取当前工作目录
    char buf[128] = {0};
    getcwd(buf, sizeof(buf));

    printf("当前工作目录：%s\n",buf);
    //修改工作目录
    int ret = chdir("./testChdir");
    if(ret == -1) {
        perror("chdir");
        return -1;
    }

    //创建一个文件
    int fd = open("testChdir.txt",O_RDWR | O_CREAT, 0664);
    if(fd == -1) {
        perror("open");
    }
    close(fd);

    //获取当前工作目录
    char buf1[128] = {0};
    getcwd(buf1, sizeof(buf));

    printf("当前工作目录：%s\n",buf1);

     return 0;

}