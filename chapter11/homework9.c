// 编写一个函数，把字符串倒叙输出
#include <stdio.h>
#include <string.h>
#define SIZE 80

char *invert_str(char *st);

int main(int argc, char * argv[])
{
    char test_string[SIZE];
    printf("Enter a string (enter to quit.): ");
    fgets(test_string, SIZE, stdin);
    while (*test_string != '\n'){
        // 循环读取待逆序的字符串，直到输入回车
        invert_str(test_string);
        printf("Done.\nNow the intert string is :");
        printf("%s\n", test_string);
        printf("Another? Enter a string (enter to quit.): ");
        fgets(test_string, SIZE, stdin);
    }

    return 0;
}

char *invert_str(char *st)
{
    // 为了使用临时字符串来存储逆序的字符串，需要有临时储存空间
    // 也可以使用字符串首尾字符互换的方式进行反转，这时候需要使用
    // 两个下标索引分别进行首尾字符串查找
    int length = strlen(st);
    char invert[length];
    // 创建逆序字符串的临时存储区域
    for (int i = 0; i < length; i++)
        *(invert + i) = *(st + length - 1 - i);
    for (int i = 0; i < length; i++)
        *(st + i) = *(invert + i);
    // 这里也可以直接使用strcpy()
    return st;
}