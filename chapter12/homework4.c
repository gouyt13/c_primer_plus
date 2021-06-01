// 在一个循环中编写并测试一个函数，该函数返回自身被调用的次数

#include <stdio.h>

static int count = 0;
// 静态内部链接
int run_counter(void);

int main(void)
{
    for (int i = 0; i < 100; i++)
        printf("The function run_time run %d times.\n", run_counter());
    return 0;
}

int run_counter(void)
{
    return ++count;
    // 函数内部使用内部链接类别的变量，因为其存储期是静态的
    // 所以每一次调用结束，count保存的数据都不会丢失
}