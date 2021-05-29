// 编写一个is_within() 该函数以一个字符和一个指向字符串的指针为两个形参
// 如果字符在字符串中，该函数返回一个非零值，否则，返回0
#include <stdio.h>
#define SIZE 80
int is_within(char c, char *st);

int main(int argc, char * argv[])
{
    char source[SIZE];
    char dest = ' ';
    printf("Enter a String: ");
    fgets(source, SIZE, stdin);
    // 读取一个待检索的字符串
    while (dest != EOF) // 退出字符使用EOF
    {
        printf("Enter a char to find (EOF for Quit):");
        while ((dest = getchar()) == '\n')
            continue;
            // 读取目标字符，且移除多余的换行符
        if (is_within(dest, source) != 0)
            printf("Found the char %c in the string\n", dest);
        else
            printf("Char %c not found. Try another?\n", dest);
            // 调用函数，打印搜索结果
    }
    return 0;
}

int is_within(char c, char *st)
{
    while (*st != '\0')
    {
        if (*st == c)
            return 1;
        else
            st++;
    }
    return 0;
}