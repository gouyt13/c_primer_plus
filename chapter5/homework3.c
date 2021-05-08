// 天数转换
#include <stdio.h>
#define WEEK_PER_DAY 7 
int main(void)
{
    int days, weeks, input;

    printf("CONVERT DAYS TO WEEKS!");
    printf("PLEASE INPUT THE NUMBER OF DAYS(<= 0 TO QUIT)");
    scanf("%d", &input);

    while (input > 0){
        weeks = input / WEEK_PER_DAY;
        days = input % WEEK_PER_DAY;
        printf("%d days are %d weeks, %d days\n", input, weeks, days);
        printf("PLEASE INPUT THE NUMBER OF DAYS(<= 0 TO QUIT)");
        scanf("%d", &input);
    }
    printf("PROGRAM EXIT!");

    return 0;
}