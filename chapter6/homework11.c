// 从数组中读取8个整数然后倒叙打印
#include <stdio.h>
int main(void)
{
    int data[8];
    printf("Enter the 8 integer data (seprate by blank): ");
    for (int i = 0; i < 8; i++){
        scanf("%d", &data[i]);
    }

    printf("Ok, the reverse data is: ");
    for (int i = 7; i >= 0; i--){
        printf(" %d", data[i]);
    }

    printf("\nDone!\n");

    return 0;
}