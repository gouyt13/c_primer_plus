// 读取字符返回 打印字符-ASCII码组合
#include <stdio.h>
int main(void){
    char ch;
    int counter = 0;
    printf("Please input chars( # for exit): ");
    while ((ch = getchar()) != '#'){
        if (counter++ % 8 == 0)
            printf("\n");
        if (ch == '\n')
            printf("'\\n'-%03d. ", ch);
            // 对于换行符，转换显示的方式，防止不足8个字符的时候就换行
        else if (ch == '\t')
            printf("'\\t'-%03d. ", ch);
            // 制表符同换行符
        else
            printf("'%c'-%03d. ", ch, ch);
            // 对于其他字符，打印元字符和十进制数
    }
    printf("Done.\n");

    return 0;
}