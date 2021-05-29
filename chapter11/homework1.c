// 从输入种获取n个字符，包括空白，制表符，换行符；把结果储存在一个数组里面
// 作为一个参数传递数组的地址
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
    } while (st[i] != EOF && ++i < n);
    // 读取用户输入，直到遇到EOF或者达到上限
    return st;
}