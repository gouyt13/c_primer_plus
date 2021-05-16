// 将三个double排序并放到三个地址中
#include <stdio.h>
void ordering(double *x, double *y, double *z);

int main(void){
    double d1, d2, d3;
    printf("Enter three float number: ");
    scanf("%lf %lf %lf", &d1, &d2, &d3);
    printf("Data you input is %g, %g and %g.\n", d1, d2, d3);
    ordering(&d1, &d2, &d3);
    printf("After function. data is %g, %g and %g", d1, d2, d3);

    return 0;
}

void ordering(double *x, double *y, double *z){
    double temp;
    if (*x > *y){
        temp = *x;
        *x = *y;
        *y = temp;
    }
    if (*x > *z){
        temp = *x;
        *x = *z;
        *z = temp;
    }
    if (*y > *z){
        temp = *y;
        *y = *z;
        *z = temp;
    }
}