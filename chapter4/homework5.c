// 提示用户多少MB的文件用多块Mbits的网速的下载时间
#include <stdio.h>
int main(void)
{
    float speed, size, time;
    printf("Please input the net speed(megabits per second):\n");
    scanf("%f", &speed);
    printf("Please input the file size(magabytes):\n");
    scanf("%f", &size);

    time = size * 8 / speed;
    printf("At %.2f megabits per second, a file of %.2f megabytes download in %.2f \
seconds.\n",
           speed, size, time);
    return 0;
}