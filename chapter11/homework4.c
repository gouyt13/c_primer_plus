// 修改编程3的代码，可以通过第二个参数指明可以读取的最大字符数字
#include <stdio.h>
#include <ctype.h>
// 使用 isalpha()
#define SIZE 80
char *get_word(char *out, int n);

int main(void)
{
    char output[SIZE];
    get_word(output, SIZE);
    printf("First word you input is : %s", output);

    return 0;
}

char *get_word(char *out, int n)
{
    char input[SIZE];
    char *in = input;
    puts("Enter a String:");
    fgets(input, SIZE, stdin);

    while ((*in == '\n' || *in == '\t' || *in == ' ') && *in != '\0')
        in++;
    // 删除前面的空白
    while (*in != '\n' && *in != '\t' && *in != ' ' && *in != '\0')
        *out++ = *in++;
    *out++ = '\0';
    return out;
}