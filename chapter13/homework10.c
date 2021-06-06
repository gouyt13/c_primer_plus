// 通过交互打开一个文本文件，通过循环，提示用户输入一个文件位置
// 然后该程序打印从该位置开始到下一个换行符之前的内容

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

int main(void)
{
    FILE *fp;
    char filename[40];
    long position;
    char buffer[SIZE];

    printf("Input a filename:");
    scanf("%s", filename);
    if((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can not open %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("Input the position the read (q or -1 to quit):");
    while (scanf("%ld", &position) == 1 && position >= 0)
    {
        fseek(fp, position, SEEK_SET);
        if (fgets(buffer, SIZE, fp) != NULL)
            printf("Content is : %s", buffer);
        printf("Input the position the read (q or -1 to quit):");
    }
    fclose(fp);
    return 0;
}