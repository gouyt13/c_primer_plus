// 使用递归完成练习8
#include <stdio.h>
double power(double n, int p);

int main(void){
    double x, xpow;
    int exp;

    printf("Enter a number and the integer power");
    printf(" to which \n the number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf %d", &x, &exp) == 2){
        xpow = power(x, exp);
        printf("%.3g to the power %d is %.5g.\n", x, exp, xpow);
        printf("Enter the next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoy this power trip -- bye!\b");
    return 0;
}

double power(double n, int p){
    if (n == 0 && p == 0){
        printf("The %g to the power %c is not define, return 1!\n", n, p);
        return 1;
    }
    if (n == 0)
        return 0;
    if (p == 0)
        return 1;
    if (p > 0){
        return n * power(n, p - 1);
    }else{
        return power(n, p + 1) / n;
    }
}