// 提示输入英寸身高，显示厘米身高
#include <stdio.h>
#define INCH_TO_CM 2.56

int main(void)
{

    float inch;
    float cm;

    printf("Please enter the inch of your height:");
    scanf("%f", &inch);
    cm = INCH_TO_CM * inch;
    printf("So you are %.2f inch tall and %.2f cm tall.", inch, cm);

    return 0;
}