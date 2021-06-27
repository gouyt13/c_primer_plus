// 计算调和平均数的宏
#include <stdio.h>
#define HMEAN(X,Y) 1/((1/(X) + 1/(Y))/2)

int main(void)
{
    double f1, f2;
    printf("Enter two float number:");
    scanf("%lf %lf", &f1, &f2);
    printf("The %lf and %lf's HMEAN is %lf", f1, f2, HMEAN(f1, f2));

    return 0;
}