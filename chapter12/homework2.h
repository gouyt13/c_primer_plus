#include <stdio.h>

static int mode;
static double range, fuel;
// 三个变量在函数外定义，使用static修饰
void set_mode(int n);
// 由于需要判断用户输入的数据，因此使用带参数的函数
void get_info(void);
void show_info(void);
// 在函数内处理的是文件作用域变量，因此不需要通过函数的参数传递数据