// 计算连个浮点数的差除以两个数的乘积
#include <stdio.h>
int main(void)
{
    float x, y;
    printf("Please enter the two float data(seprate by blank): ");
    while (scanf("%f %f", &x, &y) == 2){
        printf("The answer is %f\n", (x - y) / (x * y));
        printf("Please enter the two float data(seprate by blank): ");
    }
    printf("Program end!");
    return 0;
}