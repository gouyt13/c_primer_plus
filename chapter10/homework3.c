// 编写一个函数，返回存储在int类型数组中的最大值
#include <stdio.h>

int get_max(int number[], int n);
// 使用传统方式传递参数，n表示整数数组的长度

int main(void)
{
    int source[100] = {1, 2, 3, 4, 5};
    printf("The largest number in array is %d.\n", get_max(source, 100));
    return 0;
}

int get_max(int number[], int n)
{
    int max = number[0];
    for (int i = 0; i < n; i++)
        max = max < number[i] ? number[i] : max;
    return max;
}