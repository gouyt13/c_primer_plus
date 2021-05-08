// 输数据判断奇偶性
#include <stdio.h>
int main(void){
    int odd_sum = 0;
    int even_sum = 0;
    int odd_count = 0;
    int even_count = 0;
    int input = 0;

    printf("Please input numbers (0 or exit): ");
    while (scanf("%d", &input)){
        if (input == 0)
            break;
        if (input % 2 == 0){
            even_count++;
            even_sum += input;
        }
        else{
            odd_count++;
            odd_sum += input;
        }
    }
    printf("Have %d even number, average is %g\n", even_count, 1.0 * even_sum / even_count);
    printf("Have %d odd number, average is %g\n", odd_count, 1.0 * odd_sum / odd_count);
    printf("Done\n");

    return 0;
}