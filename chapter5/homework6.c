// 计算工资2
#include <stdio.h>

int main(void)
{
    int count = 0, sum = 0;
    printf("enter the number of days you work:");
    scanf("%d", &count);
    while (count>0){
        sum = sum + count*count;
        count--;
    }
    printf("You earned $ %d total.\n", sum);
    printf("PROGRAM EXIT!");
    return 0;
}