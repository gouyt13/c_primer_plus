// 创建个人信息结构模板
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
    char fname[15];
    char mname[15];
    char lname[15];
};
struct user_id{
    char sid[30];
    struct user name;
} user_list[5] = {
    {"302039823", {"Flossie", "Mike", "Dribble"}}};

void print_user_id(struct user_id list[], int num);
int main(void)
{
    printf("Test to printf struct contents:\n");
    print_user_id(user_list, 5);
    return 0;
}

void print_user_id(struct user_id list[], int num)
{
    for (int i = 0; i < num; i++)
    {
        if (strlen(list[i].sid) < 9)
            break;
        printf("No %d : %s,", i + 1, list[i].name.lname);
        printf(" %s ", list[i].name.fname);
        if (strlen(list[i].name.mname) > 0)
            printf("%c. ", list[i].name.mname[0]);
        printf("-- %s", list[i].sid);
        printf("\n");
    }
}