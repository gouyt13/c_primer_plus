// 计算double类型数据的立方值
#include <stdio.h>
double cubic(double n);
int main(void)
{
    double input;
    printf("Enter the double datum to calc cubic:");
    scanf("%lf", &input);
    cubic(input);
    printf("PROGRAM EXIT!\n");

    return 0;
}

double cubic(double n)
{
    double t = n * n * n;
    printf("The %lg's cubic is %lg !\n", n, t);
    return t;
}