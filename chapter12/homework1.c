// 不使用全局变量，重写12.4
#include <stdio.h>

void critic(int* n);

int main(void)
{
    int units;
    // 将units定义为main()函数中内块作用域的变量
    printf("How many pounds to firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must looked it up!\n");

    return 0;
}

void critic(int *n)
{
    printf("No lucy, my friend. Try again.\n");
    scanf("%d", n);
}