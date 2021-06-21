// 接收一个int类型的参数，并返回该参数中打开的位的数量
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int switch_count(int n);
int main(int argc, char * argv[])
{
    if (argc != 2){
        printf("Usage: %s numerical.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int i = atoi(argv[1]);
    // 将命令行参数转换整型数据
    printf("The switch bit of %d is %d.\n", i, switch_count(i));
    return 0;
}

int switch_count(int n){
    const static int size = CHAR_BIT * sizeof(int);
    // 确定整型数据的位数
    int sum = 0;
    for (int i = 0; i < size; i++){
        if (n&1)
            sum++;
        n >>= 1;
        // 对参数n与1进行位操作，判断最后一位是否为1，并向右移位
    }
    return sum;
}