// 极坐标转指教坐标
#include <stdio.h>
#include <math.h>
#define PI 3.14
typedef struct{
    double length;
    double angle;
} polar;
// 极坐标结构
typedef struct{
    double x;
    double y;
} rect;
// 直角坐标
rect p_to_t(polar pc);
int main(void){
    polar pc;
    printf("set the length and angle of polar: ");
    scanf("%lf %lf", &pc.length, &pc.angle);
    pc.angle = pc.angle * (PI / 180.0);
    // 把角度转换为弧度
    rect r = p_to_t(pc);
    // 坐标变换
    printf("%lf %lf\n", r.x, r.y);

    return 0;
}

rect p_to_t(polar pc)
{
    rect r;
    r.x = pc.length * cos(pc.angle);
    r.y = pc.length * sin(pc.angle);
    return r;
}