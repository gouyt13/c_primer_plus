// 修改程序13.3，在文件的末尾添加单词的同时,从1开始，根据加入列表的顺序为每个单词编号
// 同时确保程序下一次运行时，新的单词编号接着上一次开始
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int get_number(FILE *);
int main(void)
{
    FILE *fp;
    char words[MAX];
    int count = 1;

    if ((fp = fopen("homework9", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open homework9 file.\n");
        exit(EXIT_FAILURE);
    }
    count = get_number(fp);
    puts("Enter words to add to the file: press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d.%s\n", ++count, words);
    // 修改fprintf函数，添加行号，程序并未修改程序之前的行号

    puts("File contents:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file.\n");
    return 0;
}

int get_number(FILE *fp)
{
    int i = 0;
    char temp[MAX];
    rewind(fp);
    while (fgets(temp, MAX, fp) != NULL)
        i++;
    return i;
}