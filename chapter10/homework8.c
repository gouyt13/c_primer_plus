// 使用编程练习2中的复制函数，把一个含7个元素的数组中第3~5个元素复制到内涵3个元素的数组中

#include <stdio.h>
#include <stdlib.h>

void copy_ptr(double *t, double *s, int n);

int main(void)
{
    double src[7] = {1, 2, 3, 4, 5, 6, 7};
    double targ[3];
    copy_ptr(targ, src + 2, 3);
    printf("Now show the src array:\n");
    for (int i = 0; i < 7; i++)
        printf("%0.1f ", src[i]);

    printf("Now show the targ array:\n");
    for (int i = 0; i < 3; i++)
        printf("%0.1f ", targ[i]);

    return 0;
}

void copy_ptr(double *t, double *s, int n)
{
    for (int i = 0; i < n; i++)
        *(t + i) = *(s + i);
}