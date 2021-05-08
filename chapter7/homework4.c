// 符号替换
#include <stdio.h>
int main(void){
    int counter = 0;
    char ch;
    printf("Please input chars (# for exit):");
    while ((ch = getchar()) != '#'){
        if (ch == '!'){
            printf("!!");
            counter++;
        }
        else if (ch == '.'){
            printf("!");
            counter++;
        }
        else
            printf("%c", ch);
    }

    printf("\nTotal replace %d times.\n", counter);
    printf("Done.\n");

    return 0;
}