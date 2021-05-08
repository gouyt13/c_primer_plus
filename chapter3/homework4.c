// 读取一个浮点数，打印其各种形式
#include <stdio.h>

int main(void)
{
    float input;
    printf("Enter a floating-point value:");
    scanf("%f", &input);
    // 读取用户输入，储存在input变量中
    printf("fixed-point notation: %f \n", input);
    // 打印普通形式，转换说明符使用%f
    printf("exponential notation: %e \n", input);
    // 打印指数形式，转换说明符使用%e
    printf("p notation: %a \n", input);
    // 打印p记数法形式，转换说明符使用%a

    return 0;
}