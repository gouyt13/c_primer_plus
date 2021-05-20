// 声明一个int类型的3x5二维数组，并用初始化，顺序打印该数组中的值，然后把各值翻倍，并显示。
// 分别编写两个函数负责显示数组和翻倍数组
#include <stdio.h>
#define ROWS 3 
#define COLS 5

void show_element(int rows, int cols, const int t[rows][cols]);
void double_element(int rows, int cols, int t[rows][cols]);
// 这里使用变长数组作为形参
// 如果使用传统方法如下
// void show_element(int rows, int t[][COLS]);
// void double_element(int rows, int t[][COLS]);

int main(void)
{
    int arr[ROWS][COLS] =
        {{1, 0, 4, 6, 9},
         {2, 5, 6, 8, 3},
         {5, 3, 21, 1, 6}};
    show_element(ROWS, COLS, arr);
    double_element(ROWS, COLS, arr);
    printf("\n");
    show_element(ROWS, COLS, arr);

    return 0;
}

void show_element(int rows, int cols, const int t[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
}

void double_element(int rows, int cols, int t[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            t[i][j] = 2 * t[i][j];
}