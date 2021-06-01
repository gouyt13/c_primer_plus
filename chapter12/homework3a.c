#include "homework3.h"

void set_mode(int *mode, int n)
{
    if (n > 1){
        printf("invalid mode specified.");
        if (*mode == 0){
            printf(" Mode 0(Mrtric) used.\n");
        }else{
            printf(" Mode 1(US) used.\n");
        }
        return;
    }
    else
        *mode = n;
}

void get_info(int mode, double * range, double * fuel)
{
    if (mode == 0)
        printf("Enter distance traveled in kilometers:");
    else
        printf("Enter distance traveled in miles:");
    scanf("%lf", range);

    if (mode == 0)
        printf("Enter fuel consumed in liters:");
    else
        printf("Enter fuel consumed in gallons:");
    scanf("%lf", fuel);
}

void show_info(int mode, double range, double fuel)
{
    if (mode == 0)
        printf("Fuel consumption is %.2lf liters per 100 km.\n", (fuel / range) * 100);
    else
        printf("Fuel consumption is %.1lf miles per gallon.\n", range / fuel);
}