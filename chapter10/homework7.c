// 初始化一个double类型的二维数组，使用练习2中的3个赋值函数将数组复制到另一个二维数组中
#include <stdio.h>
#define ROWS 5
#define COLS 12
void copy_arr(double t[], double s[], int n);
void copy_ptr(double *t, double *s, int n);
void copy_ptrs(double *t, double *s_first, double *s_last);
// 编程练习2中的赋值函数声明
void copy_2d_array(double t[][COLS], double s[][COLS], int n);
void copy_2d_ptr(double (*t)[COLS], double (*s)[COLS], int n);
// 二维数组的复制声明，只是用了指针和数组作为形参，
// 首尾指针作为参数的形式类似，略

int main(void)
{
    double target[ROWS][COLS];
    double source[ROWS][COLS] =
        {{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
         {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
         {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
         {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
         {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}};

    copy_2d_array(target, source, ROWS);
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++)
            printf("%5.2f", target[i][j]);
        printf("\n");
    }

    return 0;
}


void copy_arr(double t[], double s[], int n)
{
    for (int i = 0; i < n; i++)
        t[i] = s[i];
}

void copy_ptr(double *t, double *s, int n)
{
    for (int i = 0; i < n; i++)
        *(t + i) = *(s + 1);
}

void copy_ptrs(double *t, double *s_first, double *s_last)
{
    for (int i = 0; (s_last - s_first) > i; i++)
        *(t + i) = *(s_first + i);
}

void copy_2d_array(double t[][COLS], double s[][COLS], int n)
{
    // 参数n表示行数
    for (int i = 0; i < n; i ++)
        copy_arr(t[i], s[i], COLS);
}
// 以二维数组作为形参，参数列表内可以省略主数组中的元素数，但是其他数组的元素数不能省略
// 原一维数组的复制函数能复制二维数组的一行，所以通过循环，逐行复制，在参数的调用中需要注意
// 行数，列数在函数内使用的变量名，n表示列数

void copy_2d_ptr(double (*t)[COLS], double (*s)[COLS], int n)
{
    for (int i = 0; i < n; i++)
        copy_ptr(*(t + i), *(s + i), COLS);
}