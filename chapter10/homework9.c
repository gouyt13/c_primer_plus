// 使用处理变长二维数组的函数复制数组
#include <stdio.h>
void copy_array(int n, int m, double target[n][m], const double source[n][m]);
void show_array(int n, int m, const double array[n][m]);

int main(void)
{
    int n = 3;
    int m = 5;
    double target[n][m];
    double source[3][5] = {{0.2, 0.4, 2.4, 3.5, 6.6},
                           {8.5, 8.2, 1.2, 1.6, 2.4},
                           {9.1, 8.5, 2.3, 6.1, 8.4}};
    // 注意这里source如果使用n m进行初始化的话会报错，因为声明可变数组时不能同时初始化
    copy_array(n, m, target, source);
    show_array(n, m, target);
    return 0;
}

void copy_array(int n, int m, double target[n][m], const double source[n][m])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            target[i][j] = source[i][j];
}

void show_array(int n, int m, const double array[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%g ", array[i][j]);
        printf("\n");
    };
}