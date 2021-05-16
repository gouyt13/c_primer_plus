// 返回两个double中较小的值

#include <stdio.h>
double min(double x, double y);

int main(void)
{
    double d1, d2;
    printf("Enter two float number: ");
    scanf("%lf %lf", &d1, &d2);
    printf("you input %g and %g. The MIN is %g.", d1, d2, min(d1, d2));

    return 0;
}

double min(double x, double y)
{
    if (x < y)
        return x;
    else
        return y;
    // return x < y ? x : y;
}