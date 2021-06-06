// 程序接收两个命令行参数，第一个参数是一个字符串，第二个是一个文件名
// 通过该程序查找文件，打印文件包括对应字符串的所有行
// 使用fgets()面向行，使用标准C库中的strstr()查找字符串

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

int string_in(char *st, char *sub);

int main(int argc, char * argv[])
{
    FILE *fp;
    char buffer[SIZE];
    char *seek_string;
    if (argc<3)
    {
        printf("Usage:%s string filename ... \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    seek_string = argv[1];

    if ((fp = fopen(argv[2], "r"))== NULL)
    {
        printf("Can not open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(buffer, SIZE, fp) != NULL)
    {
        if (strstr(buffer, seek_string))
            puts(buffer);
            // 也可以使用自定义的字符串查找函数
            // string_in(buffer, seek_string)
    }
    return 0;
}

int string_in(char *st, char *sub)
{
    int count = 0;
    int src_len = strlen(sub);
    while (*st != '\0' && count < src_len)
        // count表示子串中匹配的字符数，循环入口为主串不为空或者字串匹配完毕
        if (*(st + count) == *(sub + count))
            count++;
        else{
            count = 0;
            st++;
        }
    if (count == src_len)
        return 1;
    else
        return 0;
}