#include <stdio.h>
#include <stdlib.h> // srand()
#include <time.h>   // time()
#include "homework7.h"  // roll_n_dice(), roll_count

int main(void)
{
    int dice, roll;
    int sides;
    int set;
    srand((unsigned int)time(0));
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &set) == 1 && set > 0)
    {
        printf("How many sides and how many dice? ");
        if (scanf("%d %d", &sides, &dice) == 2 && sides > 0 && dice > 0){
            printf("Here are %d sets of %d %d-sided throws.\n", set, dice, sides);
            for (int i = 0; i < set; i++){
                roll = roll_n_dice(dice, sides);
                printf("%d ", roll);
            }
            set = 0;
            putchar('\n');
        }
        printf("Enter the number of sets; enter q to stop :");
    }
    printf("The rollem() function was called %d times.\n", roll_count);
    //使用外部变量
    printf("GOOD LUCK TO YOU!\n");

    return 0;
}