// 使用不同类型的字符串
#include <stdio.h>
#define PRAISE "You are an extraodinary being."

int main(void)
{
    char name[40];

    printf("What's your name? ");
    scanf("%s", name); // scanf()只会读取字符串中的一个单词，而不是一整句话
    printf("Hello, %s. %s\n", name, PRAISE);

    return 0;
}