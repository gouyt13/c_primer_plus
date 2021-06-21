// 通过命令行读取两个二进制字符串，对这两个二进制字符串使用~ & | ^ 并以二进制形式打印结果
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define SIZE 32

int bstoi(char *st);
char *itobs(int n, char *ps);

int main(int argc, char * argv[])
{
    if (argc != 3){
        printf("Usage:%s binary_string binary_string .\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char bs[SIZE] = {};
    int result = 0;
    result = (~bstoi(argv[1]));
    itobs(result, bs);
    printf("~%s result is : %s\n", argv[1], bs);
    result = (~bstoi(argv[2]));
    itobs(result, bs);
    printf("~%s result is : %s\n", argv[2], bs);
    // 按位取反

    result = (bstoi(argv[1]) & bstoi(argv[2]));
    itobs(result, bs);
    printf("%s & %s result is %s\n", argv[1], argv[2], bs);
    // 与

    result = (bstoi(argv[1]) | bstoi(argv[2]));
    itobs(result, bs);
    printf("%s | %s result is %s\n", argv[1], argv[2], bs);
    // 或

    result = (bstoi(argv[1]) ^ bstoi(argv[2]));
    itobs(result, bs);
    printf("%s ^ %s result is %s\n", argv[1], argv[2], bs);
    // 异或

    return 0;
}

int bstoi(char * st){
    // 为了将字符串转换成整数，需要进行二进制位数据的检测
    int sum = 0;
    while (* st != '\0'){
        sum *= 2;
        if (*st != '0' && *st != '1'){
            printf("The argument should be binary. \n");
            exit(EXIT_FAILURE);
        }
        sum += *st++ - '0';
    }
    return sum;
}

char * itobs(int n, char * ps){
    // 将整数转换成字符串输出
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    // CHAR_BIT 表示char中的位数，size表示int类型的位数
    for (i = size - 1; i >= 0; i--,n>>=1){
        ps[i] = (01 & n) + '0';
        ps[size] = '\0';
    }
    return ps;
}