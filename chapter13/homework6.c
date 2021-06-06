// 重写13.2，提示用户输入所需信息
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main(int argc, char * argv[])
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;
    char input[LEN];

    printf("Input the file name:");
    scanf("%s", input);
    // 删除命令行参数的条件语句，读取用户输入的文件名
    if ((in = fopen(input, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file.\"%s\"\n", input);
        exit(EXIT_FAILURE);
    }

    strncpy(name, input, LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");
    
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
    {
        if (count++ %3 == 0)
            putc(ch, out);
    }
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}