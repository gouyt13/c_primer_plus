// 两个级数求和
#include <stdio.h>
int main(void)
{
    int length;
    double sum = 0.0;
    printf("Enter the limit length: ");
    scanf("%d", &length);
    while (length > 0){
        sum = 0.0;
        for (int i = 1; i <= length; i++){
            sum += 1.0 / i;
        }
        printf("The sum for 1.0 + ... + 1.0/%d.0 is %lf\n", length, sum);
        sum = 0.0;
        for (int i = 1; i <= length; i++)
        {
            if(i%2 != 0)
                sum = sum + 2 * 1.0 / i;
        }
        printf("The sum for 1.0 + 1.0 + 2.0/3.0 +...+ 2.0/%d.0 is %lf\n", length, sum);

        printf("Enter the limit length: ");
        scanf("%d", &length);
    }
    printf("\nDone!\n");

    return 0;
}