// 打开一个文件并显示该文件
#include <stdio.h>
#include <stdlib.h> // exit()
int main(void){
    int ch;
    FILE *fp;
    char fname[50];

    printf("Enter the name of the file: ");
    scanf("%s", fname);
    fp = fopen(fname, "r"); // 打开待读取文件
    if (fp == NULL)
    {
        printf("Failed to open file. Bye\n");
        exit(1);
    }
    while ((ch = getc(fp)) != EOF){
        putchar(ch);
    }
    fclose(fp);

    return 0;
}