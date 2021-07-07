// 双向链表逆序显示电影列表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
    struct film *next;
    struct film *pre;
};
// 双向链表

char *s_gets(char *st, int n);
int main(void)
{
    struct film *head = NULL;
    struct film *prev = NULL;
    struct film *current;
    char input[TSIZE];

    // 收集并存储信息
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
            head = current;
        else{
            prev->next = current;
            current->pre = prev;
        }
        current->next = NULL;
        // 最后一个节点的指针设置为空
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }
    // 显示电影列表
    if (head == NULL)
        puts("No data entered.");
    else
        puts("Here is the movie list (by sequence):");
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }
    // 逆序显示电影列表
    puts("Here is the movie list (by inverted sequence):");
    current = prev;
    // 当前指针指向末尾节点
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->pre;
    }
    // 完成任务，释放已分配内存
    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
    }

    printf("Bye!\n");
    return 0;
}

char *s_gets(char *st, int n)
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