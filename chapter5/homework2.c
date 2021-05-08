// 打印指定范围内的数据
#include <stdio.h>

int main(void)
{
    int counter, i = 0;
    printf("Print continue 10 numbers!\n");
    printf("Please input the start number : ");
    scanf("%d", &counter);
    while (i++ < 11)
        printf("%d \n", counter++);
    printf("Program exit!");

    return 0;
}