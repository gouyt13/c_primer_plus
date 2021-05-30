// 读取输入，直到EOF，报告输入单词数，大写字母数，小写字母数，标点符号数和数字字符数
#include <stdio.h>
#include <ctype.h>
#define SIZE 256

int check_words(char *input);
int check_upper(char *input);
int check_lower(char *input);
int check_punct(char *input);
int check_digit(char *input);

int main(int argc, char * argv[])
{
    char input[SIZE];
    int i = 0;
    while ((input[i++] = getchar()) != EOF){
        if (i >= SIZE){
            printf("Over flowed.\n");
            break;
        }
    }
    // 读取用户输入的字符，直到遇到EOF结束

    printf("Hello you input complete.\nNow let's counting.\n");
    printf("Input words %d.\n", check_words(input));
    printf("Input upper char %d.\n", check_upper(input));
    printf("Input lower char %d.\n", check_lower(input));
    printf("Input punct char %d.\n", check_punct(input));
    printf("Input digital %d.\n", check_digit(input));

    return 0;
}

int check_words(char *input)
{
    // 统计单词数，当遇见第一个非空时设置标记位置，遇到非字符且标记位标记时，
    // 单词数量+1，且标记清空
    int count = 0;
    int start = 0;
    while (*input != EOF){
        if (isalpha(*input) == 0 && start == 0)
            input++;
        else if (isalpha(*input) == 0 && start == 1){
            input++;
            count++;
            start = 0;
        }
        else if (isalpha(*input) != 0){
            input++;
            start = 1;
        }
    }
    if (start == 1)
        count++;
    return count;
}

int check_upper(char * input)
{
    int count = 0;
    while (*input != EOF){
        if (isupper(*input++) != 0)
            count++;
    }
    return count;
}

int check_lower(char * input)
{
    int count = 0;
    while (*input != EOF){
        if (islower(*input++) != 0)
            count++;
    }
    return count;
}

int check_punct(char * input)
{
    int count = 0;
    while (*input != EOF){
        if (ispunct(*input++) != 0)
            count++;
    }
    return count;
}

int check_digit(char * input)
{
    int count = 0;
    while (*input != EOF){
        if (isdigit(*input++) != 0)
            count++;
    }
    return count;
}
