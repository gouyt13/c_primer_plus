// 实现atoi(),如果输入不是纯数字，返回0
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int myatoi(char *st);
int main(int argc, char * argv[])
{
    char test[8];
    printf("Enter a number of int:");
    scanf("%s", test);
    printf("Your input int is: %d\n", myatoi(test));

    return 0;
}

int myatoi(char *st)
{
    int result = 0;
    int bit_mark = 1;
    int length = strlen(st);
    // 从末尾开始转换，获取字符串的长度
    for (int i = length; i > 0;i--){
        if (isdigit(*(st+i-1)) == 0){
            // 从字符串的末尾开始读取数字，因此需要减少1
            printf("Error in character.\n");
            return 0;
        }
        result += (*(st + i - 1) - '0') * bit_mark;
        // 通过提取字符串中的数字字符，并根据bit_mark记录的位数计算数据值
        bit_mark *= 10;
        // 从个位开始，递增10
    }
    return result;
}