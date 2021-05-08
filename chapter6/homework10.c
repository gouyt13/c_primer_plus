// 计算指定范围内整数的平方和 
#include <stdio.h>
int main(void)
{
    int lower, upper;
    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &lower, &upper);
    while (upper > lower){
        int sum = 0;
        for (int i = lower; i <= upper; i++){
            sum += i * i;
        }
        printf("The sum of the squares from %d to %d is %d\n", lower, upper, sum);
        printf("Enter lower and upper integer limits: ");
        scanf("%d %d", &lower, &upper);
    }
    printf("Done!");
   
    return 0;
}