// 修改练习1的停止规定
#include <stdio.h>
#define SIZE 20
char *read_char(char *st, int n);

int main(void)
{
    char test[SIZE];
    puts("Start to test function. Enter a string.");
    read_char(test, SIZE);
    puts("The string you input is:");
    puts(test);

    return 0;
}

char *read_char(char *st, int n)
{
    int i = 0;
    do{
        st[i] = getchar();
        if (st[i] == '\n' || st[i] == '\t' || st[i] == ' ')
            break;  
        // 遇到第一个空白符时退出循环
    } while (st[i] != EOF && ++i < n);

    return st;
}