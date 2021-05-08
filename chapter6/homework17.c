// 取钱
#include <stdio.h>
#include <string.h>
int main(void)
{
    float chuckie = 100;
    int year = 0;
    do{
        chuckie = chuckie + chuckie * 0.08;
        chuckie -= 10;
        year++;
        printf("%f\n", chuckie);
    } while (chuckie > 9);
    printf("%d years later. Chuckie's account %f \n", year, chuckie);
    printf("%d years later. Chuckie's account is null \n", ++year);
    printf("\nDone!\n");

    return 0;
}