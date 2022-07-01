/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//不是函数重载，是可变参数？？？
//打开一个存在的文件
int open(const char *pathname, int flags);
//创建一个新文件 
int open(const char *pathname, int flags, mode_t mode);
参数：    
    - path：路径
    - flags：权限等设置
        只能其中是一个:O_RDONLY, O_WRONLY, or O_RDWR
返回值：
    一个新的文件描述符，或者-1（如果失败的话）
errno属于Linux系统函数库，是库里面的一个全局变量，记录的是最近的错误号
    perror(“user error data”)函数可以打印user error data ：xxx 错误信息


*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>

int main() {
    int fp = open("a.txt", O_RDONLY);
    
    if(fp == -1) {
        perror("open");
    }

    close(fp);

    return 0;
}