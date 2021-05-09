// 文件中字符数量统计
#include <stdio.h>
int main(void){
    int counter = 0;
    char ch;
    while ((ch = getchar()) != EOF){
        counter++;
    }

    printf("The file has %d characters.\n", counter);

    return 0;
}