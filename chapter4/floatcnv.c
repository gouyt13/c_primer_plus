// 不匹配的浮点型转换
// 这个代码无法实现书中预期的效果，好像是因为大小设备的问题
#include <stdio.h> 
int main(void) {
    float n1 = 3.0; 
    double n2 = 3.0; 
    long n3 = 2000000000; 
    long n4 = 1234567890;
    printf("int(%zd) long(%zd) float(%zd) double(%zd)\n", sizeof(int), sizeof(long), sizeof(float), sizeof(double));
 
    printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4); 
    printf("%ld %ld\n", n3, n4);
    printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
 
    return 0;
}
