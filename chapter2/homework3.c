// 将年龄转化为天数，不考虑闰年
#include <stdio.h>
int main(void)
{
    int years;
    int days;

    years = 25;
    days = years * 365;

    printf("Years is %d while days is %d.", years, days);

    return 0;
}