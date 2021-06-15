// 将函数参数修改为传递结构而不是结构的地址
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user_id{
    char sid[30];
    char fname[15];
    char mname[15];
    char lname[15];
}user_list[5] = {
    {"302039823", "Flossie", "Mike", "Dribble"}};

void print_user_id(struct user_id user);
int main(void)
{
    printf("Test to printf struct contents:\n");
    print_user_id(user_list[0]);
    return 0;
}

void print_user_id(struct user_id user)
{
    if (strlen(user.sid) < 9)
        return;
    printf("USERID: %s, ", user.lname);
    printf(" %s ", user.fname);
    if (strlen(user.mname) > 0)
        printf("%c. ", user.mname[0]);
    printf("-- %s", user.sid);
    printf("\n");
    return;
}