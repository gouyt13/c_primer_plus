// 观察上溢和下溢
#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(void)
{
    int big_int = 2147483647;
    // 有符号整数最大是2的31次方-1
    float big_float = 3.4e38;
    // 浮点型数据最大值一般是3.4E38
    float small_float = 10.0 / 3;
    // 浮点型数据有效位数为6位
    printf("The big int data is %d\n", big_int+1);
    // 整型数据最大值加1会造成越界，结果为-2147483648
    printf("The big float data is %f\n", big_float * 10);
    // 浮点型最大数据乘10造成越界，输出inf。如过浮点数据只加一个小数据，由于精度限制不会造成越界
    printf("The big float data is %f\n", small_float);
    // 打印3.33333精度损失
    printf("The MAX float data is %f\n", FLT_MAX);
    // 打印最大的浮点数
    printf("The MAX int data is %d\n", INT_MAX);
    // 打印最大有符号整数
    return 0;
}