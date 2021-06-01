// 与homework3a.c一起编译
#include <stdio.h>
#include "homework3.h"

int main(void)
{
    int mode;
    double range, fuel;
    int n;

    printf("Enter 0 for metric mode, 1 for US mode:");
    scanf("%d", &n);
    while (n >= 0){
        set_mode(&mode, n);
        get_info(mode, &range, &fuel);
        show_info(mode, range, fuel);
        printf("Enter 0 for metric mode, 1 for US mode:");
        printf(" (-1 to quit): ");
        scanf("%d", &n);
    }
    printf("Done.\n");

    return 0;
}