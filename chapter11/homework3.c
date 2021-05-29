// 从一行输入中读取第一个单词，并舍弃其他字符，同时跳过第一个非空白符前面的所有空白符号
// 将一个单词定义为没有空白、制表符或换行符的序列
#include <stdio.h>
#include <ctype.h>
// 使用 isalpha()
#define SIZE 80
char *get_word(char *out);

int main(void)
{
    char output[SIZE];
    get_word(output);
    printf("First word you input is : %s", output);

    return 0;
}

char *get_word(char *out)
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