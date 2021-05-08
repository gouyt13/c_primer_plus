// 输入英寸，打印英尺身高
#include <stdio.h>
int main(void)
{
    float height;
    char name[40];
    printf("Please enter your name: \n");
    scanf("%s", name);
    printf("Hi %s, how tall you are (inch):", name);
    scanf("%f", &height);

    printf("%s, you are %.3f feet tall.\n", name, height / 12.0);

    return 0;
}