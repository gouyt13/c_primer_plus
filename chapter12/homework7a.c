// 编写一个程序，按照程序清单12.13输出示例后面讨论的内容
// 修改程序，使其可以一次选择多投个sets的骰子，每个set 由相同sides的多个dice组成
#include "homework7.h"
#include <stdio.h>
#include <stdlib.h> // rand()
int roll_count = 0; // 外部链接
static int rollem(int sides)    // 文件私有
{
    int roll;
    roll = rand() % sides + 1;
    ++roll_count;   // 计算机函数调用次数
    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2){
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1){
        printf("Need at least 1 dice.\n");
        return -1;
    }
    for (d = 0; d < dice; d++)
        total += rollem(sides);
    return total;
}