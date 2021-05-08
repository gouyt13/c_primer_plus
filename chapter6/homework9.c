// 修改作业8，使用一个函数达成目的
#include <stdio.h>
float calc(float x, float y);
int main(void)
{
    float x, y;
    printf("Please enter the two float data(seprate by blank): ");
    while (scanf("%f %f", &x,&y) == 2){
        printf("The answer is %f\n", calc(x, y));
        printf("Please enter the two float data(seprate by blank): ");
    }
    printf("Program end!\n");

    return 0;
}

float calc(float x, float y)
{
    float result;
    result = (x - y) / (x * y);
    return result;
}