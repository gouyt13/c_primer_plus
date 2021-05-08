// 读取输入中ei出现的次数
#include <stdio.h>
int main(void){
    int counter = 0;
    int halfpair = 0;   // 部分匹配标记
    char ch;

    printf("Please input chars( # for exit):");
    while ((ch = getchar()) != '#'){
        switch(ch){
            case 'e':
                halfpair = 1;
                break;
            case 'i':
                if (halfpair)
                    counter++;
                halfpair = 0;
                break;
            default :
                halfpair = 0;
        }
    }
    printf("\nTotal exist %d \'ei\' in all char!\n", counter);
    printf("Done.\n");

    return 0;
}