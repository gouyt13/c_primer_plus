// 生成100个介于1~10的随机数，并以降序排列
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void sort(int array[], int n);

int main(void)
{
    int data[SIZE];

    srand((unsigned int)time(0));
    for (int i = 0; i < SIZE; i++)
        data[i] = rand() % 10 + 1;
    // 设定随机数种子，并生成包含随机数的数组
    printf("The original data is: ");
    for (int i = 0; i < SIZE; i++)
        printf("%4d ", data[i]);
    printf("\n");

    sort(data, SIZE);
    printf("The sorted data is: ");
    for (int i = 0; i < SIZE; i++)
        printf("%4d", data[i]);

    return 0;
}

void sort(int array[], int n)
{
    // 通过整数的比较运算，循环查找数组中的最大值，并交换到数组末尾
    int temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++)
            if (array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
    }
}