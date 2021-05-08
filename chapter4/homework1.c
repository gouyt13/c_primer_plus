// 输入姓名，打印名姓
#include <stdio.h>
int main(void)
{
    char name[40];
    char surname[40];
    printf("Please input your first name:\n");
    scanf("%s", name);
    // 读取名字输入，储存到name数组中，由于scanf的特性，字符串的输入中不能有空格
    printf("Please input your last name:\n");
    scanf("%s", surname);
    printf("Hello, %s, %s.", name, surname);

    return 0;
}