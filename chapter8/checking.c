// 输入验证
#include <stdio.h>
#include <stdbool.h>
// 验证输入是一个整数
long get_long(void);
// 验证上下限范围是否有效
bool bad_limits(long begin, long end,
                long low, long high);
// 计算a~b的平方和
double sum_squares(long a, long b);

int main(void){
    const long MIN = -10000000;
    const long MAX = +10000000;
    long start;
    long stop;
    double answer;

    printf("This program computes the sum of the squares of ");
    printf("integers in a range.\nThe lower bound should not ");
    printf("be less than -10000000 and \nthe upper bound ");
    printf("should not be more than +10000000.\nEnter the ");
    printf("limits (enter 0 for both limits to quit):\n"
           "lower limit: ");
    start = get_long();
    printf("upper limit: ");
    stop = get_long();
    while (start != 0 || stop != 0){
        if (bad_limits(start, stop, MIN, MAX)){
            printf("Please try again.\n");
        }else{
            answer = sum_squares(start, stop);
            printf("The sum of the squares of the integers ");
            printf("from %ld to %ld is %g\n",
                   start, stop, answer);
        }
        printf("Enter the limits (enter 0 for both limits to quit):\n");
        printf("lower limit: ");
        start = get_long();
        printf("upper limit: ");
        stop = get_long();
    }
    printf("Done.\n");

    return 0;
}

long get_long(void){
    long input;
    char ch;

    while (scanf("%ld", &input) != 1){
        while ((ch = getchar()) != '\n')
            putchar(ch); // 处理错误的输入,会把整行都抛弃
        printf(" is not an integer.\nPlease enter an");
        printf("integer value, such as 25, -178 or 3: ");
    }

    return input;
}

double sum_squares(long a, long b){
    double total = 0;
    long i;

    for (i = a; i <= b; i++){
        total += (double)i * (double)i;
    }

    return total;
}

bool bad_limits(long begin, long end,
                long low, long high)
{
    bool not_good = false;

    if (begin > end){
        printf("%ld is not smaller than %ld.\n", begin, end);
        not_good = true;
    }
    if (begin < low || end < low){
        printf("Values must be %ld or greater.\n", low);
        not_good = true;
    }
    if (begin > high || end > high){
        printf("Value must be %ld or less.\n", high);
        not_good = true;
    }

    return not_good;
}