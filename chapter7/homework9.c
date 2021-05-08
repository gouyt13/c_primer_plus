// 显示小于输入整数的素数
#include <stdio.h>

int main(int argc, char * argv[]){
    int datnum;
    do{
        printf("Enter a number( 0 to exit):");
        scanf("%d", &datnum);
        if (datnum<2){
            if (datnum == 0)
                break;
            printf("%d is out of range, retry.\n", datnum);
            continue;
        }

        printf("You input %d, so the prime from %d to 2 is: ", datnum, datnum);
        for (int i = datnum; i > 1; i--){
            int is_prime = 1;
            for (int j = 2; j * j <= i; j++){
                if (i % j == 0){
                    is_prime = 0;
                    break;
                }
            }
            if (is_prime == 1)
                printf("%d ", i);
        }
        printf("\n");
    } while (datnum != 0);
    printf("Done! bye.");

    return 0;
}