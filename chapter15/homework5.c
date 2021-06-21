// 把unsigned int类型值中的所有位向左旋转指定的位
#include <stdio.h>
#include <limits.h>

unsigned int rotate_l(unsigned int n, int length);
int main(int argc, char * argv[]){
    unsigned int i;
    int length;
    printf("Enter a number and a move bit:");
    scanf("%u %d", &i, &length);
    printf("the %u move %d bit, result is %u\n", i, length, rotate_l(i, length));
    return 0;
}

unsigned int rotate_l(unsigned int n, int length){
    const static int size = CHAR_BIT * sizeof(int);
    if(length > size || length < 0){
        printf("Error length.\n");
        return 0;
    }

    for (int i = 0; i < length; i++){
        if (n & (1 <<(size-1))){
            // 先读取要被溢出的数据，即把最高位设置位1，并于n进行与操作
            // 如果结果为0，直接移位，如果为1，则移位并在左侧至1
            n <<= 1;
            n |= 1;
        }else
            n <<= 1;
    }
    return n;
}