// 顺序打印字母
#include <stdio.h>
int main(void)
{
    int i, j;
    char c = 'A';

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j <= i; j++,c++)
            printf("%c", c);
        printf("\n");
    }
    return 0;
}