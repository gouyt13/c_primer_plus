// 倒序打印字母
#include <stdio.h>
int main(void)
{
    int i, j;
    char c;

    for (i = 0; i < 6; i++){
        for (j = 0,c='F'; j <= i; j++,c--)
            printf("%c", c);
        printf("\n");
    }

    return 0;
}