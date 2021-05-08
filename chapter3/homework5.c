// 通过输入的年龄打印秒数
#include <stdio.h>

int main(void)
{
    float sec_per_year = 3.156e7;
    float second;
    float year;

    printf("Enter how many years old you are:");
    scanf("%f", &year);
    second = year * sec_per_year;

    printf("So you are %.1f years old,\n", year);
    printf("and %e seconds old too.\n", second);

    return 0;
}