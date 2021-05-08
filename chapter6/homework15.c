// 读取一行输入，将输入的内容倒叙打印
#include <stdio.h>
#include <string.h>
int main(void){
    char data[256];
    printf("Enter the char in a line: ");
    int i = 0;
    do{
        scanf("%c", &data[i]);
    } while (data[i] != '\n' && ++i);
    // 循环读取用户输入的字符，并保存在字符数组中，直到用户输入回车
    // 循环未检查输入的字符数量，可能产生溢出
    printf("The reverse char of the data: ");
    for (i--; i >= 0; i--){
        printf("%c", data[i]);
    }
    printf("\nDone!\n");
    return 0;
}