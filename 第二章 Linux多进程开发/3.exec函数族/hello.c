#include <stdio.h>
#include <unistd.h>
int main() {
    printf("hello,world\n");
    printf("after execl, child pid is: %d\n", getpid());
    return 0;
}