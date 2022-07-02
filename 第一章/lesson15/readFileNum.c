/*
目标：实现一个可以统计某个目录下所有普通文件数量的程序
a.out lesson15,返回一个数字

#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *name);
作用：打开一个目录
参数：
    - name: 目录的名字
返回值：
    指向目录流的一个指针
    NULL

#include <dirent.h>

struct dirent *readdir(DIR *dirp);
作用：返回指针，指向drip代表的目录流的下一个条目
参数：
    - dirp ：目录流指针
返回值：
    成功：dirent结构体指针。
    NULL：读到目录流的结尾，errno不变
    NULL：出错，errno变化。

#include <sys/types.h>

#include <dirent.h>

int closedir(DIR *dirp);
作用：关闭目录流
参数：
    - dirp：目录流指针
返回值：
    0:成功
    -1：失败，同时，errno也会变化。

*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getFileNum(const char * path);

int main(int argc, char * argv[]) {
    int count = 0;

    //获取传入的参数，即目录的路径

    if(argc < 2) {
        printf("plase input the name of director");
    }
    
    //获取普通文件数量
    count = getFileNum(argv[1]);
    
    printf("普通文件的个数为：%d\n", count);

    return 0;

}

int getFileNum(const char * path) {
    //文件数目
    int count = 0;

    //打开目录
    DIR * dir = opendir(path);
    if(dir == NULL) {
        perror("opendir");
        exit(0);
    }
    //读取目录
    struct dirent * dirEnt;

    while((dirEnt = readdir(dir)) != NULL) {
        //忽略. 和 ..
        char * dname = dirEnt->d_name;
        if(strcmp(dname,".") == 0 || strcmp(dname, "..") == 0) {
            continue;
        }
        //普通文件
        if(dirEnt->d_type == DT_REG) {
            count++;
        }

        //目录
        if(dirEnt->d_type == DT_DIR) {
            char newPath[1024];
            sprintf(newPath,"%s/%s",path,dname);
            count += getFileNum(newPath);
        }
    }
    
     //关闭目录流
    closedir(dir);

    return count;
}
