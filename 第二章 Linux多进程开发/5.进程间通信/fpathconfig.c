#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int pipefd[2];
    int ret = pipe(pipefd);

    printf("size of pipe : %d\n", fpathconf(pipefd[0], _PC_PIPE_BUF));

    return 0;
}