// 修改练习1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct month{
    char month_name[10];
    char month_abbrev[4];
    int days;
    int number;
} months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}};
// 结构数组的初始化
int calc_days(char *month, int day);

int main(void)
{
    int year, day;
    char month[10];
    int result;
    printf("Enter the YEAR MONTH DAY(seprate by blank) : ");
    scanf("%d %s %d", &year, month, &day);
    while (year > 1000)
    {
        result = calc_days(month, day);
        if (result < 0)
            printf("Error input, retry.\n");
        else
            printf("The %d/%s/%d is %d days.\n", year, month, day, result);
        printf("Enter the YEAR MONTH DAY(seprate by blank) : ");
        scanf("%d %s %d", &year, month, &day);
    }
    printf("Done");
    return 0;
}

int calc_days(char * month, int day)
{
    if (day < 1 || day > 31)
        return -1;
    int total = 0;
    int temp = atoi(month);
    for (int i = 0; i < 12; i++)
    {
        if (temp == months[i].number || strcmp(month, months[i].month_abbrev) == 0 
            || strcmp(month, months[i].month_name) == 0){
                if (day > months[i].days)
                    return -1;
                return total + day;
            }
        else
            total += months[i].days;
    }

    return -1;
}