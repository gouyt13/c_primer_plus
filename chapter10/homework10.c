// 把连个数组中对应元素相加，结果储存到第三个数组中
#include <stdio.h>
#define INDEX 4

void add_array(int n, int t[n], const int s1[n], const int s2[n]);
// 数组加法函数的3个形参分别表示数组长度，求和结果和两个相加的数组
// 程序使用变长数组形式分别表示3个数组的形参，s1,s2数组设置为const，可以保证在函数内不会修改两个源数组的值
int main(void)
{
    int sum[INDEX], s1[INDEX] = {2, 4, 5, 8}, s2[INDEX] = {1, 0, 4, 6};
    add_array(INDEX, sum, s1, s2);
    for (int i = 0; i < INDEX; i++)
        printf("%d ", sum[i]);
    return 0;
}

void add_array(int n, int t[n], const int s1[n], const int s2[n])
{
    for (int i = 0; i < n; i++)
        t[i] = s1[i] + s2[i];
}