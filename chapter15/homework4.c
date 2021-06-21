// 接受两个int类型的参数，一个是值，一个是位的位置，返回指定位是1还是0
#include <stdio.h>
#include <limits.h>

int get_bit(int n, int pos);
int main(void){
    int i, pos;
    printf("Enter a number and a position.\n");
    scanf("%d %d", &i, &pos);
    printf("the %d postion of %d is %d\n", pos, i, get_bit(i, pos));
    return 0;
}

int get_bit(int n, int pos){
    const static int size = CHAR_BIT * sizeof(int);
    if (pos > size || pos < 0){
        printf("Error position.\n");
        return -1;
    }// 判断输入参数
    if (1 & (n>>pos))
        return 1;
    // 移位并且通过与判断pos位置上的值
    else
        return 0;
}