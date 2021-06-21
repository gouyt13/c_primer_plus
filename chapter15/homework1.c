// 将一个二进制字符串转变为数值
#include <stdio.h> 
#include <stdlib.h>
#define SIZE 32
int bstoi(char * st);
int main(void)
{
    char input[SIZE];
    printf("Enter a binary string:");
    scanf("%s", input);
    printf("%d", bstoi(input));
    return 0;
}

int bstoi(char * st)
{
    int sum = 0;
    while (*st != '\0'){
        sum *= 2;
        sum += *st++ - '0';
    }
    return sum;
}