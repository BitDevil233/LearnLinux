/*

#include <unistd.h>

       int access(const char *pathname, int mode);
       作用：判断某个文件是否由某种权限，或者文件是否存在
       参数：
            path：文件路径
            mode：权限（宏）
                R_OK 当前进程是否由读权限
                W_OK
                X_OK
                F_OK(存在)
        返回值：
            0：成功
            -1：失败
*/

#include <unistd.h>
#include<stdio.h>
int main() {
    int ret = access("a.txt", F_OK);
    if(ret == -1) {
        perror("access");
    } else {
        printf("文件存在\n");
    }
    return 0;
}