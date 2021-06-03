// 对一个文件实现改写，将所有文本改为大写
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // toupper()

int main(void)
{
    FILE *fp;
    FILE *fpt;
    char filename[50];
    char ch;
    printf("Input the filename:");
    scanf("%s", filename);
    fpt=fopen("tempfile", "w");

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(toupper(ch), fpt);
    }
    fclose(fp);
    fclose(fpt);
    remove(filename);
    rename("tempfile", filename);

    return 0;
}