// 编写一程序，返回存储在double类型数组中最大值和最小值的差值
#include <stdio.h>
double get_range(double number[], int n);

int main(void)
{
    double source[12] = {2.5, 3.2, 1.2, 1.6, 2.4, 0.1, 5.2, 0.96, 0.3, 1.4, 7.3, 0.9};
    printf("The max diff in array is %g ", get_range(source, 12));
    return 0;
}

double get_range(double number[], int n)
{
    double max = number[0];
    double min = number[0];
    for (int i = 0; i < n; i++)
    {
        if (max < number[i])
            max = number[i];
        if (min > number[i])
            min = number[i];
    }
    return max - min;
}