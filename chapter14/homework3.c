// 修改程序清单14.2中的图书目录程序，使其按照输入图书的顺序输出图书的信息
// 然后按照书名字母的顺序输出图书的信息，最后按照价格的升序输出图书的信息
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char *s_gets(char *st, int n);
void list_book(struct book library[], int count);
void list_book_title(struct book library[], int count);
void list_book_value(struct book library[], int count);
// 声明排序函数
int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    printf("Please enter the book title.\n");
    printf("Pree [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL &&
        library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        list_book(library, count);
        list_book_title(library, count);
        list_book_value(library, count);
    }
    else
        printf("Noo books? Too bad.\n");

    return 0;
}

void list_book(struct book library[], int count)
{
    printf("Here is the list of your books:\n");
    for (int index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", library[index].title, library[index].author,
               library[index].value);
}

void list_book_title(struct book library[], int count)
{
    char *ptitle[count];
    char *temp;
    int top, seek;

    for (int index = 0; index < count; index++)
        ptitle[index] = library[index].title;
    for (top = 0; top < count; top++)
    {
        for (seek = top; seek < count; seek++)
            if (strcmp(ptitle[top], ptitle[seek]) > 0)
            {
                temp = ptitle[top];
                ptitle[top] = ptitle[seek];
                ptitle[seek] = temp;
            }
    }
    printf("Here is the list of your books by title :\n");
    for (int index = 0; index < count; index++)
        for (int i = 0; i < count; i++)
            if (ptitle[index] == library[i].title)
                printf("%s by %s: $%.2f\n", library[index].title, library[index].author,
                       library[index].value);
}

void list_book_value(struct book library[], int count)
{
    float *pvalue[count];
    float *temp;
    int top, seek;

    for (int index = 0; index < count; index++)
        pvalue[index] = &library[index].value;
    for (top = 0; top < count; top++)
    {
        for (seek = top; seek < count; seek++)
            if (*pvalue[top] > *pvalue[seek])
            {
                temp = pvalue[top];
                pvalue[top] = pvalue[seek];
                pvalue[seek] = temp;
            }
    }
    printf("Here is the list of your books by value :\n");
    for (int index = 0; index < count; index++)
        for (int i = 0; i < count; i++)
            if (*pvalue[index] == library[i].value)
                printf("%s by %s: $%.2f\n", library[index].title, library[index].author,
                       library[index].value);
}

char * s_gets(char * st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // 查找换行符
        if (find)                   // 如果地址不是NULL，在此处防止一个空字符串
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;           // 处理输入行中剩余的字符
    }
    return ret_val;
}