// 编写一个程序，打开读取一个文本文件，用二叉树存储单词以及出现的次数
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "homework7_tree.h"

char show_menu(void);
// 打印项信息
void show_item(Item item);
// 查找单词信息
extern void find_word(const Tree *pt);

int main(int argc, char * argv[])
{
    char choice;
    Tree word_tree;
    FILE *fp;
    Item temp;

    if (argc != 2)
    {
        fprintf(stderr, "Usage:commond filename\n");
        exit(1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(2);
    }

    InitializeTree(&word_tree);

    while (fscanf(fp, "%s", temp.word) == 1)
    // 使用fscanf函数读取文件中的残次，对于无空格的标点符号需要特殊处理
    {
        if (!isalpha(temp.word[0]))
            continue;
        if (!isalpha(temp.word[strlen(temp.word) - 1]))
            temp.word[strlen(temp.word) - 1] = '\0';
            // 处理标点符号
        temp.times = 1;
        AddItem(&temp, &word_tree);
    }

    fclose(fp);
    printf("file is opened, what do you want to do:\n");
    while ((choice = show_menu()) != 'q')
    {
        switch(choice)
        {
            case 's':
                Traverse(&word_tree, show_item);
                break;
            case 'r':
                find_word(&word_tree);
                break;
            case 'q':
                break;
            default:
                puts("Switching error");
        }
    }

    puts("Bye!");
    DeleteAll(&word_tree);
    return 0;
}

char show_menu(void)
{
    int ch;
    printf("s) show all words and its times\n");
    printf("r) find a word and report its times\n");
    printf("q) quit\n");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue;
        ch = towlower(ch);
        if (strchr("srq", ch) == NULL)
            puts("Please enter s, r or q");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';

    return ch;
}

void show_item(Item item)
{
    printf("%s appear %d times\n", item.word, item.times);
}