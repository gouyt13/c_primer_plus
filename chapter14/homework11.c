// transform(), 接收4个参数，分别为内涵double类型的源数组名，内涵double类型的目标数组名
// 一个表示数组元素个数的int， 函数名（或等价的函数指针）
// transform()将函数应用于源数组中每个元素并将返回值存储在目标数组中
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LENGTH 10
void transform(double src[], double tar[], int n, double (*func)(double));

int main(void){
    double source[LENGTH], target[LENGTH];
    for (int i = 0; i < LENGTH; i++){
        source[i] = (double)i;
    }
    printf("The source data is:\n");
    for (int i = 0; i < LENGTH; i++){
        printf("%5g", source[i]);
    }
    printf("\n");

    transform(source, target, LENGTH, sin);

    printf("The target data is:\n");
    for (int i = 0; i < LENGTH; i++){
        printf("%g  ", target[i]);
    }
    printf("\n");

    transform(source, target, LENGTH, cos);

    printf("The target data is:\n");
    for (int i = 0; i < LENGTH; i++){
        printf("%g  ", target[i]);
    }
    printf("\n");

    return 0;
}

void transform(double src[], double tar[], int n, double (*func)(double)){
    for (int i = 0; i < n; i++){
        tar[i] = func(src[i]);
    }
}