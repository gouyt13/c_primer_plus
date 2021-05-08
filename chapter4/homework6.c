// 打印姓名和相应的字母个数
#include <stdio.h>
int main(void)
{
    char name[40];
    char surname[40];
    int wname;
    int wsurname;
    printf("Please input your name:\n");
    scanf("%s", name);
    printf("Please input your last name:\n");
    scanf("%s", surname);

    wname = printf("%s", name);
    printf(" ");
    wsurname = printf("%s", surname);
    printf("\n%*d %*d\n", wname, wname, wsurname, wsurname);

    printf("%s %s\n", name, surname);
    printf("%-*d %-*d\n", wname, wname, wsurname, wsurname);
    return 0;
}