#include <stdio.h>
int main(void)
{
    char name[40];
    printf("Please enter your name:\n");
    scanf("%s", name);
    int width;
    width = printf("\"%s\"\n", name);
    // 打印名字
    width -= 3;
    // printf 的返回值为打印的字符数，因此需要排除两个引号和一个换行符
    printf("\"%20s\"\n", name);
    // 在宽度20的字段右端打印名字，包括双引号
    printf("\"%-20s\"\n", name);
    // 左端
    printf("\"%*s\"\n", (width+3), name);
    // 使用修饰符星号制定宽度打印名字字符串

    return 0;
}