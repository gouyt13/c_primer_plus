// 使用循环计算Fibonacci()函数
#include <stdio.h>
void Fibonacci(int n);

int main(void){
    int n;
    printf("Enter the number of Fibonacci (q to quit):");
    while (scanf("%d", &n) == 1){
        if (n >= 2){
            Fibonacci(n);
            printf("Enter the number of Fibonacci (q to quit):");
        }
    }
    return 0;
}

void Fibonacci(int n){
    unsigned long f1, f2, temp;
    f1 = 1;
    f2 = 1;
    for (int i = 0; i < n; i++){
        printf("%lu ", f1);
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    printf("\n");
}