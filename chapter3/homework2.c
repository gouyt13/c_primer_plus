// 要求提示输入一个ASCII编码，打印输出的字符
#include <stdio.h>
int main(void)
{
    int input;
    printf("Enter a value of char in ASCII:");
    scanf("%d", &input);
    // 通过scanf读取用户输入，并储存在input变量中
    printf("Your input value is %d, and char is %c\n", input, input);
    // 通过转换说明符%d %c打印整型数值和字符
    return 0;
}