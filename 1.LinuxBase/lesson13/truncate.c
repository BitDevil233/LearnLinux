/*
#include <unistd.h>
#include <sys/types.h>

int truncate(const char *path, off_t length);
作用：修改文件尺寸
参数：
    - path 文件路径
    - length 修改后的文件大小
返回值：
    0：成功
    -1：失败
*/

#include <unistd.h>
#include <sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
int main() {
    int ret = truncate("a.txt", 5);
    if(ret == -1) {
        perror("truncate");
        return -1;
    } else {
        struct stat st;
        long int retStat = stat("a.txt", &st);
        if(retStat == -1) {
            perror("stat");
        }
        printf("修改成功，修改之后的文件大小为%d\n", st.st_size);
    }
    return 0;
}
