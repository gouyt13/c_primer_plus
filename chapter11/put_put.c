// 演示自定义的put1 put2 函数
#include <stdio.h>
void put1(const char *);
int put2(const char *);

int main(void)
{
    put1("If I'd as much money");
    put1(" as I could spend,\n");
    printf("I count %d characters.\n",
           put2("I never woudl cry old chairs to mend."));

    return 0;
}

void put1(const char * string)  // 不会改变字符串
{
    while (*string != '\0')
        putchar(*string++);
}

int put2(const char * string)
{
    int count = 0;
    while (*string)
    {
        putchar(*string++);
        count++;
    }
    putchar('\n'); // 不统计换行符

    return count;
}