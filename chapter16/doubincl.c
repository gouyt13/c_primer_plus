// 包含头文件names.h两次用于测试

#include <stdio.h>
#include "names.h"
#include "names.h"

int main(void)
{
    names winter = {"Less", "Ismoor"};
    printf("The winter is %s %s.\n", winter.first,
           winter.last);
    return 0;
}