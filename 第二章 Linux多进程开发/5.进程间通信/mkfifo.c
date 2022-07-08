#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    //判断fifo是否存在
    int ifExist = access("fifo1", F_OK);
    if(ifExist == -1) {
        printf("管道不存在创建管道：\n");
        int ret = mkfifo("./fifo1", 0664);
        if(ret == -1) {
            perror("mkfifo");
            exit(0);
        }
    }
    return 0;
}