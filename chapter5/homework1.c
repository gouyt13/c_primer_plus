// 分钟转换成小时+分钟
#include <stdio.h>
#define MIN_PER_HOUR 60
int main(void)
{
    int input, hours, minutes;

    printf("Please input time in MINUTES( <= 0 TO QUIT):");
    scanf("%d", &input);
    while(input > 0){
        hours = input / MIN_PER_HOUR;
        minutes = input % MIN_PER_HOUR;
        printf("CONVERT TO %d HOUR AND %d MINUTES\n", hours, minutes);
        printf("Please continue input the number of minutes( <= 0 TO QUIT):");
        scanf("%d", &input);
    }
    printf("PROGRAM EXIT!\n");
    return 0;
}