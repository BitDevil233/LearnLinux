/*
 #include <sys/stat.h>
int chmod(const char *pathname, mode_t mode);
作用：修改文件权限
参数
    - path：文件路径
    - mode 需要修改的权限值、八进制数
返回值:
    0:成功
    -1：失败

*/

 #include <sys/stat.h>
 #include<stdio.h>

 int main () {

    int ret = chmod("a.txt", 0775);
    if(ret == -1) {
        perror("chmod");
        return -1;
    } 
    return 0;
 }

