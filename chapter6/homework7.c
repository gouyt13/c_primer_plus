// 读取用户输入的单词并且储存
#include <stdio.h>
#include <string.h>
int main(void)
{
    char word[30];
    printf("Please enter the words:");
    scanf("%s", word);
    printf("The word you enter is : %s\n", word);
    printf("The reverse word you enter is: ");
    printf("%d\n", strlen(word));
    for (int i = strlen(word) - 1; i >= 0; i--){
        printf("%c", word[i]);
    }
    // 逆序打印
    // 不包含'\0'，但是数组下标介于0~(数组长度-1)
    printf("\n");
    return 0;
}