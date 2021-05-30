// 反序显示名命令行参数中的单词
#include <stdio.h>

int main(int argc, char * argv[])
{
    if (argc < 2){
        // 判断命令行中参数个数，若大于等于2，表示带参数
        printf("Error! not enough parameter to display.\n");
    }else{
        for (int i = argc; i > 1; i--)
            printf("%s ", argv[i - 1]);
            // argv[0]存储了程序的文件名
        printf("\n");
    }
    return 0;
}