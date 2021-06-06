// 修改程序清单13.5中的程序，用命令行代替交互式界面
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
int main(int argc, char * argv[])
{
    FILE *fa, *fs;  //fa 指向目标文件，fs指向源文件
    int files = 0;  // 附加的文件数量
    int ch;
    char *file_app;
    char *file_src;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s dest_file src_file.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    file_app = argv[1];
    file_src = argv[2];

    if ((fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create dest buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    // 输入命令行参数，如果参数小于3个，则缺少附加文件
    files = argc - 2;
    // 附加文件的数量德语参数值减去2
    while (files > 0)
    {
        file_src = argv[argc - files];
        if ((fs = fopen(file_src, "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", file_src);
            continue;
        }
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading files %s.\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", file_app);
            fclose(fs);
            printf("File %s appended.\n", file_src);
            files -= 1;
            if (files > 0)
                printf("Next file:");
            else
                printf("No more file to appended.\n");
        }
    }
    printf("Done appending, and %d files appended.\n", argc - 2);
    rewind(fa);
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);
    return 0;
}


void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];  // 只分配一块

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}