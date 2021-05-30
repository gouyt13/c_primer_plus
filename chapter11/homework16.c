// 读取输入，直至读到文件结尾，然后打印字符串
// 该程序识别和实现下面的命令行参数
// -p 原样答应
// -u 输入全部转换成大写
// -l 输入全部转换成小写

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 256
void print_orig(char *st);
void print_upper(char *st);
void print_lower(char *st);

int main(int argc, char * argv[])
{
    char c;
    if (argc < 2)
        c = 'p';
    else
        c = argv[1][1];
    // 在无参数时按照参数p操作，其他参数取argv[][1]，忽略命令行中的 - 
    // 根据需要，也可以判断argv[][0] 来判断 - 是否正确输入
    char test[SIZE];
    printf("Enter a string to convert:");
    fgets(test, SIZE, stdin);
    switch(c){
        case 'p':
        case 'P':
            print_orig(test);
            break;
        case 'u':
        case 'U':
            print_upper(test);
            break;
        case 'l':
        case 'L':
            print_lower(test);
            break;
    }
    return 0;
}

void print_orig(char *st){
    printf("The original text is:\n%s", st);
}

void print_upper(char *st){
    printf("The upper text is:\n");
    while (*st != EOF && *st != '\0')
        putchar(toupper(*st++));
    // 处理转换的函数并未判断字母是否是小写，而是统一转换，这样省略了if判断
    // 当待转换字符多于不用转换的字符的时候这样效率更高
}

void print_lower(char *st){
    printf("The lower text is:\n");
    while (*st != EOF && *st != '\0')
        putchar(tolower(*st++));
}