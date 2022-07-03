```c
#include <unistd.h>
int execl(const char *pathname, const char *arg, ...)
参数：  - pathname:要执行的可执行文件的路径（推荐使用绝对路径）
        - arg：执行可执行程序所需要的参数，可以是多个。
        第一个参数一般是可执行程序的名字。
        从第二个参数开始才是参数列表，
        最后一个参数需要为NULL，表示输入参数结束
返回值：-1：出错时返回，errno被设置。
```

```c
#include <unistd.h>
int execl(const char *file, const char *arg, ...)
作用：到环境变量中根据可执行文件的名字**file**寻找可执行文件，找到了就执行，找不到就执行失败。
参数：  - file:要执行的可执行文件的文件名
        - arg：执行可执行程序所需要的参数，可以是多个。
        第一个参数一般是可执行程序的名字。
        从第二个参数开始才是参数列表，
        最后一个参数需要为NULL，表示输入参数结束
返回值：-1：出错时返回，errno被设置。
```