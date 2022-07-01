/*
#include <sys/stat.h>
#include <sys/types.h>

int mkdir(const char *pathname, mode_t mode);
作用：创建目录
参数：
    - pathname 创建的目录的名称
    - mode 权限，八进制数或者宏
返回值：
    0：成功
    -1：失败
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    int ret = mkdir("aaa", 0777);
    if(ret == -1) {
        perror("mkdir");
        return -1;
    }

    return 0;
}