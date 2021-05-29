// 写一个函数，并且测试：以一个字符串作为参数，并删除字符串中的空格
#include <stdio.h>
#include <string.h>
#define SIZE 80

char *trim_str(char *st);

int main(int argc, char * argv[])
{
    char test_string[SIZE];
    printf("Enter a string (enter to quit): ");
    fgets(test_string, SIZE, stdin);
    while(*test_string != '\n'){
        printf("%p ", test_string);
        trim_str(test_string);
        printf("%p ", test_string);
        printf("Done!\nNow the trim string is :");
        printf("%s\n", test_string);
        printf("Another? Enter a string (enter to quit): ");
        fgets(test_string, SIZE, stdin);
    }
    return 0;
}

char *trim_str(char *st)
{
    char *head = st;
    int count = 1;
    while (*st != '\0'){
        if (*st != ' ')
            *head++ = *st++;
        else{
            st++;
            count++;
        }
    }
    while(count--)
        *head++ = '\0';
    return st;
}