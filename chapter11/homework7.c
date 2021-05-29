// 实现strncpy()的功能，并在主程序中测试，使用一个循环提供输入值

#include <stdio.h>
#include <string.h>
#define SIZE 80

char *mystrncpy(char *dest, char *src, int n);

int main(int argc, char * argv[])
{
    char destination[SIZE], source[SIZE];
    int i = 0;
    printf("Enter a String as a source (blank to quit): ");
    fgets(source, SIZE, stdin);
    printf("Enter number of char you need to copy: ");
    scanf("%d", &i);
    // 读取用输入的源字符串和要复制的字符串数量n
    while (*source != '\n')
    {
        mystrncpy(destination, source, i);
        printf("Done!\nNow the dest string is:");
        puts(destination);
        while (getchar() != '\n')
            break;
        // 清除输入缓存中的剩余换行符
        printf("Another? Enter a String as s source(blank to quit.): ");
        fgets(source, SIZE, stdin);
        printf("Enter number of you char you need to copy:");
        scanf("%d", &i);
    };

    return 0;
}

char *mystrncpy(char *dest, char *src, int n)
{
    int count = 0;
    while (*src != '\0' && *src != '\n' && count < n)
        *(dest + count++) = *src++;
    // 当字符串不为空且小于n时，复制
    if (count < n){
        while (count < n)
            *(dest + count++) = '\0';
    }
    // 如果源字符串的长度小于n，填补空白
    return 0;
}