// 设计一个函数，打印指定的字符j行i列
#include <stdio.h>
void chline(char ch, int cols, int rows);

int main(void)
{
    char c;
    int i, j;
    printf("Enter the char you want to print :");
    scanf("%c", &c);
    printf("Enter the rows and cols you want to print: ");
    scanf("%d %d", &j, &i);
    chline(c, i, j);
    return 0;
}

void chline(char ch, int cols, int rows)
{
    for (int m = 0; m < rows; m++){
        for (int n = 0; n < cols; n++){
            putchar(ch);
        }
        putchar('\n');
    }
}