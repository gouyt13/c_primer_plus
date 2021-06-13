// 更改复习题5
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

int calc_days(char *month);
int main(int argc, char * argv[])
{
    char name[10];
    printf("Enter a capitalize month name: ");
    scanf("%s", name);
    while (strlen(name) > 3){
        printf("The total to %s is %d \n", name, calc_days(name));
        printf("Enter a capitalize month name: ");
        scanf("%s", name);
    }
    printf("Done.");

    return 0;
}

int calc_days(char * month)
{
    int total = 0;
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(month, months[i].month_name) == 0)
            return (total + months[i].days);
        else
            total += months[i].days;
    }
    // 通过循环对比用户的输入和结构数组内的字符串，并计算天数
    return -1;
}