#include <stdio.h>
void print_char(char ch, int cols, int rows);
// 打印的字符，cols为列数，即一行内打印的字符数，rows为行数
// 一共打印多少行，即外层循环数
int main(void)
{
    char c;
    int i, j;
    printf("Enter the char you want to print :");
    scanf("%c", &c);
    printf("Enter the rows and cols you want to print: ");
    scanf("%d %d", &j, &i);
    print_char(c, i, j);
    return 0;
}

void print_char(char ch, int cols, int rows)
{
    for (int m = 0; m < rows; m++){
        for (int n = 0; n < cols; n++){
            putchar(ch);
        }
        putchar('\n');
    }
}