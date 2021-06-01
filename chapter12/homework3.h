#include <stdio.h>


void set_mode(int *mode, int n);
// set_mode 需要修改mode变量，因此使用指针方式进行传输
void get_info(int mode, double * range, double * fuel);
// 同理，是使用指针
void show_info(int mode, double range, double fuel);
// 将函数修改为参数传递，因为该程序的功能是直接打印计算结果