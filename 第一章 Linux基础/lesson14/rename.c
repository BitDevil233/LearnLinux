/*
#include <stdio.h>

int rename(const char *oldpath, const char *newpath);
作用：修改目录的名字
参数：
    oldpath 旧目录的名字
    newpath 新目录的名字
返回值：
    0
    -1
*/
#include <stdio.h>

int main() {
    int ret = rename("aaa", "bbb");
    if(ret == -1) {
        perror("rename");
        return -1;//exit();
    }

    return 0;
}