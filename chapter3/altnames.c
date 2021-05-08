// 可移植整数类型名
#include <stdio.h>
#include <inttypes.h>
int main(void)
{
    int32_t me32;

    me32 = 45933945;
    printf("First, assume int32_t is int: ");
    printf("me 32 = %d\n", me32);
    printf("Next, let't not make anny assumptions:\n");
    printf("Instead, use as \"macor\" from inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32);

    return 0;
}