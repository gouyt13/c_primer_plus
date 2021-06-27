// 实现简单的时间延迟函数
#include <stdio.h>
#include <time.h>

void delay(double second);
int main(void){
    double input;
    printf("Enter a second to delay:");
    scanf("%lf", &input);
    delay(input);
    return 0;
}

void delay(double second)
{
    clock_t start = clock();
    // 取得初始的处理器时间
    printf("Now let's test %f second delay \n", second);
    clock_t now = clock();
    // 取得延迟后的处理器时间
    while ((double)(now - start)/CLOCKS_PER_SEC < second){
        now = clock();
        printf("You delay %f second.\n", (double)(now - start) / CLOCKS_PER_SEC);
    }
}