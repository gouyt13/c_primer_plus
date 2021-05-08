// 发出一声警报，然后打印
#include <stdio.h>
int main(void)
{
    char ch = '\a';
    printf("%c", ch);

    printf("Starled by the sudden sound, Sally shouted, \n");
    printf("\"By the Great Pumpkin, what was that!\"\n");

    return 0;
}