// 使用Queue接口
// 和queue1.c 一起编译
#include <stdio.h>
#include <stdlib.h> // rand() srand()
#include <time.h>   // time()
#include "queue1.h" // 新的 Item
#define MIN_PER_HR 60.0

bool newcustomer(double x);     // 是否有新顾客到来，这里假定每分钟至多来一个顾客
Item customertime(long when);   // 设置顾客参数

int main(void)
{
    Queue line; 
    Item temp;              // 新顾客数据
    int hours;              // 模拟小时数
    int perhour;            // 每小时平均多少位顾客
    long cycle, cyclelimit; // 循环计数器，计数器的上限
    long turnaways = 0;     // 因队列已满被拒绝的顾客数量
    long customers = 0;     // 加入队列的顾客数量
    long served = 0;        // 在模拟期间咨询过的顾客数量
    long sum_line = 0;      // 累计的队列总长
    int wait_time = 0;      // 从当前到Sigmund空闲所需时间
    double min_per_cust;    // 顾客到来的平均时间
    long line_wait = 0;     // 队列累计的等待时间

    InitializeQueue(&line);
    srand((unsigned int)time(0));   // srand() 随机初始化
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;  
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DeQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += QueueItemCount(&line);
    }

    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("         turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n",
               (double)sum_line / cyclelimit);
        printf("average wait time: %.2f minutes\n",
               (double)line_wait / served);
    }
    else
        puts("No customers!");
    EmptyTheQueue(&line);
    puts("Bye!");

    return 0;
}

// x是顾客到来的平均时间（单位：分钟）
// 如果1分钟内有顾客到来，则返回true
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

// when是顾客到来的时间
// 该函数返回一个Item结构，该顾客到达的时间设置为when
// 咨询时间设置为1~3的随机值
Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}