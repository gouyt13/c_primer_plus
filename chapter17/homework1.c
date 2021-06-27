#include <stdio.h>
int main(void)
{
    int *a;
    int b = 1;
    a = &b;
    printf("%d", *a);
    return 0;
}