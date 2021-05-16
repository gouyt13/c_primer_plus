// 将两个double中的较大值重新赋值给两个变量
#include <stdio.h>
void larger_of(double * x, double * y);

int main(void){
    double d1, d2;
    printf("Enter two float number: ");
    scanf("%lf %lf", &d1, &d2);
    printf("Data you input is %g and %g.\n", d1, d2);
    larger_of(&d1, &d2);
    printf("Now data is %g and %g.\n", d1, d2);
    
    return 0;
}

void larger_of(double * x, double * y){
    if (*x > *y)
        *y = *x;
    else
        *x = *y;
}