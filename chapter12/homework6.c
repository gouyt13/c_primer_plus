// 生成1000个介于1~10之间的随机数，保存或打印数字，只打印每个数字出现的次数
// 使用10个不同的随机种子值运行

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10 
#define LENGTH 1000

int main(int argc, char * argv[])
{
    int data_count[SIZE + 1];
    int datum;
    for (int seed = 1; seed <= 10; seed++)
    {
        printf("This is %d round to create data.\n", seed);
        srand((unsigned int) time(0));
        // 设置随机数种子，对于每次循环设置不同的种子数
        for (int i = 0; i <= SIZE; i++)
            data_count[i] = 0;
        for (int i = 0; i < LENGTH; i++){
            datum = rand() % 10 + 1;
            data_count[datum]++;
            // 生成随机数，并通过下标记录随机数的出现次数
        }
        printf("Random data created, let's stata it.\n");
        for (int i = 1; i <= SIZE; i++){
            printf("The datum %d created %d times.\n", i, data_count[i]);
            // 打印所有随机数出现的次数
        }
    }
    return 0;
}