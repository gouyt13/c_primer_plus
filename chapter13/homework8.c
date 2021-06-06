// 编写一个程序，以一个字符和任意文件名为命令行参数，如果字符后面没有参数，读取标准输入
// 否则，该程序依次打开每个文件并报告每个文件中该字符出现的次数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int count = 0;
    int para_count = 1;
    char ch;
    if (argc < 2)
    {
        printf("Usage : %s character filename1 filename2 ... \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) != 1)
    {
        printf("The second parameter should be a character\n");
        exit(EXIT_FAILURE);
    }
    // 检查命令行参数
    if (argc == 2)
    {
        printf("Now you can input the string:");
        while ((ch = getchar()) != EOF)
        {
            if (ch == argv[1][0])
                count++;
        }
        printf("There are %d characters '%c' in your input\n", count, argv[1][0]);
    }else{
        while (++para_count < argc)
        {
            count = 0;
            if ((fp = fopen(argv[para_count], "r")) == NULL)
            {
                printf("Can't open the file %s.\n", argv[para_count]);
                continue;
            }
            while ((ch = getc(fp)) != EOF)
            {
                if (ch == argv[1][0])
                    count++;
            }
            printf("There are %d character '%c' in file %s.\n", count, argv[1][0], argv[para_count]);
            fclose(fp);
            // 统计文件内的字符数据，统计完后关闭文件指针
        }
    }
    return 0;
}