// 从标准输入中读取字符，报告每个字符是否是字母，如果是，报告字母在字母表中的位置。
#include <stdio.h>
void get_char_pos(void);
// 函数读取标准输入，对于字符输入，打印其在字母表中的位置
int position(char ch);
// 函数计算并返回输入在字母表中的位置

int main(void){
    get_char_pos();
    return 0;
}

void get_char_pos(void){
    char ch;
    printf("Enter the chars(ended by EOF, not enter): ");
    while ((ch = getchar()) != EOF){
        if (ch == '\n')
            continue;
        if (position(ch) != -1){
            printf("The char %c's position in alphabet is %d.\n", ch, position(ch));
        }else
            printf("%c is not a alphabet.\n", ch);
    }
}

int position(char ch){
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 1;
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 1;
    return -1;
}