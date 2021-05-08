// 单利复利比较
#include <stdio.h>
#include <string.h>
int main(void){
    float daphne, deirdre;
    daphne = deirdre = 100.0;
    int year = 0;
    do{
        daphne = daphne + 0.1 * 100;
        deirdre = deirdre + 0.05 * deirdre;
        year++;
    } while ((deirdre - daphne) < 0);

    printf("%d years later.\nDaphne = %f.\nDeirdre= %f.\n", year, daphne, deirdre);
    printf("\nDone.\n");

    return 0;
}