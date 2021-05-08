// 身高厘米和英寸的转换
#include <stdio.h>
#define FEET_TO_CM 60.48
#define INCH_TO_CM 2.54

int main(void)
{
    int feet;
    float inches, cm;
    printf("convert cm to inches\n");
    printf("enter the height in centimeters:");
    scanf("%f", &cm);
    while (cm > 0){
        feet = cm / FEET_TO_CM;
        inches = (cm - feet * FEET_TO_CM) / INCH_TO_CM;
        printf("%.1f cm = %d feet, %.1f inches\n", cm, feet, inches);
        printf("enter the height in centimeters:");
        scanf("%f", &cm);
    }
    printf("program exit!");

    return 0;
}