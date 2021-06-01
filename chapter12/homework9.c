#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int amount;
    printf("How many words do you wish to enter?");
    scanf("%d", &amount);
    printf("Enter %d words now: ", amount);
    char **pst = (char **)malloc(amount * sizeof(char *));
    // 因为数组的每个元素都是指向char的指针，所以用与存储malloc()
    // 返回值的指针应该是一个指向指针的指针，且它所指向的指针指向char
    for (int i = 0; i < amount; i++)
    {
        char temp[100];
        scanf("%s", temp);
        int length = strlen(temp);
        // 获取用户输入的字符串长度
        char *str = (char *)malloc(length * sizeof(char));
        // 根据用户输入的字符串长度，创建一个长度匹配的字符串
        strcpy(str, temp);
        *(pst + i) = str;
        // 将字符串数组指向新创建的字符串
    }
    for (int i = 0; i < amount; i++)
        printf("%s\n", *(pst + i));
    free(pst);
    printf("All done!\n");

    return 0;
}