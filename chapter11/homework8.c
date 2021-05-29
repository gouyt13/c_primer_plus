// 实现string_in()，判断第二个字符串是否包含在第一个字符串中
// 如果在，返回第一个字符串中相应的地址，否则返回空指针
#include <stdio.h>
#include <string.h>
#define SIZE 80

char *string_in(char *st, char *sub);

int main(int argc, char * argv[])
{
    char *res;
    res = string_in("gouyutong", "yutong");
    printf("%p", res);
    return 0;
}

char *string_in(char *st, char *sub)
{
    int count = 0;
    int src_len = strlen(sub);
    while (*st != '\0' && count < src_len){
        // count表示子串中匹配的字符数，循环入口为主串不为空或者子串匹配完成
        if(*(st + count) == *(sub + count)){
            count++;
        }else{
            count = 0;
            st++;
            // 如果没有匹配到子串的字符，主串的指针后移，并清空字串计数
        }
    }
    if (count == src_len)
        return st;
    else
        return NULL;
}