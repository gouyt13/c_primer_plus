// 编写一个结构模板，用于描述将所有结构的数值成员的平均值
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CSIZE 4
typedef struct{
    char fname[30];
    char lname[30];
} FULLNAME;
// 定义姓名结构
typedef struct{
    FULLNAME name;
    float grade[3];
    float average;
} student;

void set_grade(student list[]);
// 输入学生信息
void set_average(student list[]);
// 计算平均分
void get_info_all(student list[]);
// 打印学生信息
void get_agerage_all(student list[]);
// 计算全体平均分
int main(void)
{
    student student_list[CSIZE];
    set_grade(student_list);
    set_average(student_list);
    get_info_all(student_list);
    get_agerage_all(student_list);
    return 0;
}

void set_grade(student list[])
{
    char fname[15], lname[15];
    int i = 0;
    while (i<CSIZE){
        printf("Enter the student name (FIRSTNAME  LASTNAME): ");
        scanf("%s %s", fname, lname);
        if (strlen(fname) < 1 && strlen(lname) < 1){
            printf("Error in student name! retry!");
            printf("Enter the student name (FIRSTNAME  LASTNAME): ");
            scanf("%s %s", fname, lname);
            break;
        }
        strcpy(list[i].name.fname, fname);
        strcpy(list[i].name.lname, lname);
        printf("Enter the 3 score of %s:", fname);
        scanf("%f %f %f", &list[i].grade[0], &list[i].grade[1], &list[i].grade[2]);
        i++;
    }
}

void set_average(student list[])
{
    for (int i = 0; i < CSIZE; i++)
        list[i].average = (list[i].grade[0] + list[i].grade[1] + list[i].grade[2]) / 3;
}

void get_info_all(student list[])
{
    for (int i = 0; i < CSIZE; i++)
        printf("No.%d: %s.%s : %5.2f %5.2f %5.2f, average = %5.2f\n", i,
               list[i].name.fname, list[i].name.lname, list[i].grade[0], list[i].grade[1],
               list[i].grade[2], list[i].average);
}

void get_agerage_all(student list[])
{
    float sum = 0.0;
    for (int i = 0; i < CSIZE; i++)
    {
        sum += list[i].average;
    }
    printf("Class average is %.2f\n", sum / 4);
}