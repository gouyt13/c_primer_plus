// 泛型选择
#include <stdio.h>

#define MYTYPE(X) _Generic((X),\
    int: "int",\
    float: "float",\
    double: "double",\
    default: "other"\
)

int main(void)
{
    int d = 5;

    printf("%s\n", MYTYPE(d));  // d 是int类型
    printf("%s\n", MYTYPE(2.0 * d));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&d)); // &d 的类型是int
    return 0;
}