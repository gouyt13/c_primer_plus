// 读取字符流输入，打印每个字符输入和其对应的ACSII十进制
#include <stdio.h>

int main(void){
    int counter = 0;
    char ch;
    while ((ch = getchar()) != EOF){
        if (counter++ == 10){
            printf("\n");
            counter = 1;
        }   // 输入计数器，判断是否打印换行符

        if (ch >= '\040'){
            printf(" \'%c\'--%3d", ch, ch);
            // 大于空格字符的可以显示作为字符的处理和判断
        }else if (ch == '\n'){
            printf(" \\n--\\n\n ");
            counter = 0;
        }else if (ch == '\t'){
            printf(" \\t--\\t");
            // 制表符的处理
        }else{
            printf(" \'%c\'--^%c ", ch, (ch + 64));
            // 其他非显示字符的处理
        }
    }

    return 0;
}