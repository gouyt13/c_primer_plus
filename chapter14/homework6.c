// 从文件读取球员信息，并保存至结构数组中
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char fname[20];
    char lname[20];
    int start_num;
    int hit_num;
    int base_num;
    int RBI;
    float BABIP;
}PLAYER;

PLAYER player_list[19] = {};
// 定义结构模板和结构数组

void read_data(PLAYER list[], FILE *fp);
// 读取文件信息，并保存在结构数组中
void set_babip(PLAYER list[]);
// 计算结构数组信息
void get_info(PLAYER list[]);
// 打印结构数组信息
int main(void)
{
    FILE *fp;
    if ((fp = fopen("data.txt", "r")) == NULL)
    {
        printf("Can't open %s\n", "data.txt");
        exit(EXIT_FAILURE);
    }
    read_data(player_list, fp);
    set_babip(player_list);
    get_info(player_list);
    fclose(fp);
    return 0;
}

void read_data(PLAYER list[], FILE * fp)
{
    if (fp == NULL){
        printf("Can not open the file.\n");
        exit(EXIT_FAILURE);
    }
    int id, start_num, hit_num, base_num, RBI;
    char fname[20], lname[20];
    int read_count = 1;
    while (1){
        read_count = fscanf(fp, "%d %s %s %d %d %d %d", &id, fname, lname, &start_num,
                            &hit_num, &base_num, &RBI);
        if (read_count < 7)
            break;
        // 在标准数据格式的情况下，可以使用fscanf()函数读取
        // 其返回值为读取的数据的个数，这个值可以作为读取成功的判别标准
        strcpy(list[id].fname, fname);
        strcpy(list[id].lname, lname);
        list[id].id = id;
        list[id].start_num += start_num;
        list[id].hit_num += hit_num;
        list[id].base_num += base_num;
        list[id].RBI += RBI;
    }
}

void set_babip(PLAYER list[])
{
    for (int i = 0; i < 19; i++)
        list[i].BABIP = (float)list[i].hit_num / (float)list[i].start_num;
}

void get_info(PLAYER list[])
{
    printf("ID: FIRST_NAME.LAST_NAME START HIT_NUM BASE_NUM RBI BABIP\n");
    for (int i = 0; i < 19; i++)
    {
        printf("%2d %10s.%-10s %5d %5d %7d %6d %.2f\n", list[i].id, list[i].fname,
               list[i].lname, list[i].start_num, list[i].hit_num, list[i].base_num, list[i].RBI,
               list[i].BABIP);
    }
}