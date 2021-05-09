// 改进 get_first()
#include <stdio.h>
char get_first(void);

int main(void){
    char ch;

    ch = get_first();
    printf("%c\n", ch);

    return 0;
}

char get_first(void){
    char ch;

    do{
        ch = getchar();
    } while (ch == ' ' || ch == '\t' || ch == '\n');

    return ch;
}