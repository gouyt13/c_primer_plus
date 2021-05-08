// 把秒数转化为分和秒
#include <stdio.h>
#define SECOND_PER_MIN 60
int main(void)
{
    int sec, min, left;

    printf("Convert seconds to minutes and seconds!\n");
    printf("Enter the number of seconds (<=0 to quit):\n");
    scanf("%d", &sec);
    while (sec > 0)
    {
        min = sec / SECOND_PER_MIN;
        left = sec % SECOND_PER_MIN;
        printf("%d seconds is %d minutes, %d seconds\n", sec, min, left);
        printf("Enter next value (<=0 to quit):\n");
        scanf("%d", &sec);
    }
    printf("Done!\n");

    return 0;
}