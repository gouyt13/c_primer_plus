// 更改输入，原样不变
#include <stdio.h>
#define SPACE ' '
int main(void){
    char ch;

    ch = getchar();
    while (ch != '\n'){
        if (ch == SPACE)
            putchar(ch);
        else
            putchar(ch + 1); 
        ch = getchar();
    }
    putchar(ch);    // 打印换行符

    return 0;
}