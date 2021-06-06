// 编写一个程序打开两个文件，可以使用命令行参数或者提示用户输入文件名
// 依次打印两个文件的第一行，第二行，第三行
// 修改程序，把编号相同的行打印成一行

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 256

int main(int argc, char * argv[])
{
    char *line_one = (char *)malloc(LINE_SIZE * sizeof(char));
    char *line_two = (char *)malloc(LINE_SIZE * sizeof(char));
    // 定义两个读入行的缓冲区
    if (argc != 3)
    {
        fprintf(stderr, "Usage:%s filename filename", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp1, *fp2;
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Open %s failed\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Open %s failed\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    // 输入文件的相关设定
    // 开始打印独立行
    printf("Print the line one by one.\n");
    int i = 1;
    while (fgets(line_one, LINE_SIZE, fp1) != NULL){
        if (fgets(line_two, LINE_SIZE, fp2) != NULL){
            printf("File 1 line NO.%d : %s", i, line_one);
            printf("File 2 line NO.%d : %s", i, line_two);
            i++;
        }else{
            printf("File 1 line NO.%d : %s", i, line_one);
            i++;
        }
    }
    while (fgets(line_two, LINE_SIZE, fp2) != NULL)
        printf("File 2 line NO.%d : %s", i++, line_two);
    // 如果第一个文件打印完了，第二个文件还没打印完

    printf("Print the combine line.\n");
    rewind(fp1);
    rewind(fp2);
    // 开始合并打印，将文件指针设置为从头开始

    i = 1;
    while (fgets(line_one, LINE_SIZE, fp1) != NULL){
        if (fgets(line_two, LINE_SIZE, fp2) != NULL){
            printf("Line NO.%d : ", i);
            while (*line_one != '\n')
                printf("%c", *(line_one++));
            printf("+");
            printf("%s", line_two);
            i++;
        }else{
            printf("Line NO.%d : %s", i, line_one);
            i++;
        }
    }
    while (fgets(line_two, LINE_SIZE, fp2) != NULL)
        printf("File 2 line NO.%d : %s", i++, line_two);

    fclose(fp1);
    fclose(fp2);

    return 0;
}