// 查找一个字符串中指定字符第一次出现的位置 
#include <stdio.h>
#define SIZE 80
char *string_char(char *st, char c);

int main(int argc, char * argv[])
{
    char source[SIZE];
    char dest = ' ';
    char *position;
    printf("Enter a String: ");
    fgets(source, SIZE, stdin);
    // 读取一个待检索的字符串
    while (dest != EOF) // 退出字符使用EOF
    {
        printf("Enter a char to find (EOF for Quit):");
        while ((dest = getchar()) == '\n')
            continue;
            // 读取目标字符，且移除多余的换行符
        if ((position = string_char(source, dest)) != NULL)
            printf("Found the char %c in the %p\n", *position, position);
        else
            printf("Char %c not found. Try another?\n", dest);
            // 调用函数，打印搜索结果
    }
    return 0;
}

char *string_char(char *st, char c)
{
    while(*st != '\0')
    {
        if (*st == c)
            return st;
        else
            st++;
    }
    return NULL;
}