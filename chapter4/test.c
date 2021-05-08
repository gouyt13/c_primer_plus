#include <stdio.h>
int main(void)
{
    int a;
    char name[40];
    scanf("%s", name);
    a = printf("\"%s\"\n", name);
    printf("%d", a);

    return 0;
}