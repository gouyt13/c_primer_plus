// 求模运算
#include <stdio.h>

int main(int argc, char *argv[])
{
    int first, second;
    printf("This program compute moduli.\n");
    printf("Enter an integer to sever as the second operand: ");
    scanf("%d", &second);
    printf("Now enter the first operand: ");
    scanf("%d", &first);
    while(first > 0){
        printf("%d %% %d is %d\n", first, second, (first % second));
        printf("Enter an integer to sever as the first operand:(<=0 to quit) ");
        scanf("%d", &first);
    }
    printf("Done!\n");
    return 0;
}