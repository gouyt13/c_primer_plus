// 修改程序13.1，从命令行获取文件信息改为用户输入文件名
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
    int ch; // 在读取文件时，存储每个字符的地方
    FILE *fp;   // 文件指针
    unsigned long count = 0;
    char file_name[50];
    printf("Input the filename:");
    scanf("%s", file_name);
    // 通过scanf()函数读取用户输入，并将输入保存在filename中
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %lu characters.\n", file_name, count);

    return 0;
}