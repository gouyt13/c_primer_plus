// 对数据进行累加求和
#include <stdio.h>
int main(void)
{
    double first[8], second[8];
    printf("Enter 8 data to the FIRST array: ");
    for (int i = 0; i < 8; i++){
        scanf("%lf", &first[i]);
    }

    for (int i = 0; i < 8; i++){
        double sum = 0;
        for (int j = 0; j <= i; j++){
            sum += first[j];
        }
        second[i] = sum;
    }

    printf("All data of two array.\n");
    printf("First  array: ");
    for (int i = 0; i < 8; i++){
        printf("%12lf.", first[i]);
    }
    printf("\nSecond array: ");
    for (int i = 0; i < 8; i++){
        printf("%12lf.", second[i]);
    }

    printf("\nDone!\n");
    return 0;
}