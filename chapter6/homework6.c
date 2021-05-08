// 打印一个数字表格
#include <stdio.h>
int main(void)
{
    int start, end;
    printf("Please enter the start number:");
    scanf("%d", &start);
    printf("Please enter the end number:");
    scanf("%d", &end);
    printf("    Ori:    Square:    Cubic:\n");
    for (int i = start; i <= end; i++){
        printf("%6d,%10d,%10d", i, i * i, i * i * i);
        printf("\n");
    }
    return 0;
}