// 读取字符流输入，返回大小写字符数量
#include <stdio.h>
#include <ctype.h>  // islower() isupper()

int main(void){
    int lowercase = 0;
    int uppercase = 0;
    char ch;
    
    while ((ch = getchar()) != EOF){
        if (ch >= 'A' && ch <= 'Z'){
            uppercase++;
        }
        if (ch >= 'a' && ch <= 'z'){
            lowercase++;
        };
        // if islower(ch) lowercase++;
        // if isupper(ch) uppercase++;
    }
    printf("There are %d uppercase and %d lowercase.", uppercase, lowercase);

    return 0;
}
