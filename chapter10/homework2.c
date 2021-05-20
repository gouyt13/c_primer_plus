// 三种方法拷贝数组
#include <stdio.h>
void copy_arr(double t[], double s[], int n);
void copy_ptr(double *t, double *s, int n);
void copy_ptrs(double *t, double *s_first, double *s_last);
// 根据要求调用函数格式还原的函数声明
int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    return 0;
}

void copy_arr(double t[], double s[], int n)
{
    for (int i = 0; i < n; i++)
        t[i] = s[i];
    // 使用数组作为函数的参数，同时需要数组的下标值，只需要使用下标访问数组
}

void copy_ptr(double *t, double *s, int n)
{
    for (int i = 0; i < n; i++)
        *(t + i) = *(s + 1);
    // 使用指针作为函数的参数，需要表明指针的访问范围，不能越界
    // 并使用 * 形式进行数据的赋值
}

void copy_ptrs(double *t, double *s_first, double *s_last)
{
    for (int i = 0; (s_last - s_first) > i; i++)
        *(t + i) = *(s_first + i);
    // 使用指针作为函数的参数，也可以通过首尾两个指针来表示
    // 指针允许访问的数据地址范围
}