// 将double类型数组中的数据倒序排列
#include <stdio.h>

void r_sort(double number[], int n);

int main(void)
{
    double source[12] = {2.5, 3.2, 1.2, 1.6, 2.4, 0.1, 5.2, 0.96, 0.3, 1.4, 7.3, 0.9};
    for (int i = 0; i < 12; i++)
        printf("%g ", source[i]);
    printf("\n");
    r_sort(source, 12);
    for (int i = 0; i < 12; i++)
        printf("%g ", source[i]);

    return 0;
}

void r_sort(double number[], int n)
{
    // 这里排序使用常规的比较排序法，即，判断相邻元素的大小关系
    // 并核对需要排序的两个元素交换位置
    double temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (number[j] < number[j+1]){
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }
}