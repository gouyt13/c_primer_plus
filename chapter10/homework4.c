// 编写一个程序，返回储存在double类型数组中最大值下标
#include <stdio.h>

int get_max(double number[], int n);
// 使用传统方式传递参数，n表示整数数组的长度

int main(void)
{
    double source[100] = {1.1, 2.1, 3.1, 4.1, 5.1};
    printf("The largest number's index in array is %d\n", get_max(source, 100));
    return 0;
}

int get_max(double number[], int n)
{
    double max = number[0];
    int index = 0;
    for (int i = 0; i < n; i++)
        if (number[i] > max)
        {
            max = number[i];
            index = i;
        };
    return index;
}