// 读取浮点数，以两种形式打印
#include <stdio.h>
int main(void)
{
    float input;
    printf("Enter a float number:\n");
    scanf("%f", &input);

    printf("The input is %.1f or %.1e \n", input, input);
    printf("The input is %+.3f or %.3E \n", input, input);

    return 0;
}