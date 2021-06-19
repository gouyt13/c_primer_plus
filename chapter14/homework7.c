// 修改14.14添加删除记录的功能
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 20
char *s_gets(char *st, int n);
struct book {   // 建立book模板
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int delete_flag;
};
// 添加删除标记成员
int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    FILE *pbooks;
    int size = sizeof(struct book);
    char delete;
    if ((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    // 添加标志位，并不影响数据的读取功能，fread函数按照结构体book的存储空间大小
    // 一次读取相同字节
    {
        if (count == 0)
            puts("Current contents of book.dat");
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author,
               library[count].value);
        count++;
    }
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    printf("Do you want modify library?(y/n): ");
    scanf("%c", &delete);
    if (delete == 'y')
    {
        for (int i = 0; i < count; i++)
        {
            printf("%s by %s: $%.2f\n", library[i].title, library[i].author,
                   library[i].value);
            while (getchar() != '\n')
                continue;
            puts("Do you want to delete this book ?(y/n).");
            scanf("%c", &delete);
            if (delete == 'y')
                library[i].delete_flag = 1;
        }
    }
    // 为了修改原数组，可以设置其标记位，表明它被删除。在要添加记录信息时，可通过改标记覆盖旧数据
    
    while (getchar() != '\n')
        continue;
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL &&
        library[count].title[0] != '\0' && library[count].delete_flag != 1)
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count].value);
        library[count++].delete_flag = 0;
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    // 记录新信息可以覆盖被删除信息
    rewind(pbooks);
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
        {
            if (library[index].delete_flag != 1)
            {
                printf("%s by %s: $%.2f\n", library[index].title, library[index].author,
                       library[index].value);
                fwrite(&library[index], size, 1, pbooks);
            }
        }
    }
    else
        puts("No books? Too bad.");
    puts("Bye.");
    return 0;
}

char * s_gets(char * st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    
        if (find)                 
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;         
    }
    return ret_val;
}