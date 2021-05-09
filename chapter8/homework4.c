// 读取字符流，报告每个单词平均字母数量
#include <stdio.h>
#include <ctype.h>

int main(void){
    int words = 0;
    int letters = 0;
    char ch;

    while ((ch = getchar()) != EOF){
        if (isalpha(ch) != 0)
            letters++;
        if (ch == ' ' || ispunct(ch)){
            words++;
        }
    }
    printf("There are %d words, %d character, %.2f C/W.\n",
           words, letters, 1.0 * letters / words);
        
    return 0;
}