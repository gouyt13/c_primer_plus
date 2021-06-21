// 设计一个位字段结构以存储指定的信息
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct font {
    unsigned int id : 8;
    unsigned int size : 7;
    unsigned int align : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
} font_mode = {1, 12, 0, 0, 0, 0};
// 初始化字体结构的数据
const char align[][8] = {"left", "center", "right"};
const char on_off[][4] = {"off", "on"};
// 设定字段与字符串的对应关系，用于菜单显示输出

void show_menu(void);
void change_font(void);
void change_size(void);
void change_align(void);
void change_others(char ch);

int main(void){
    char selected;
    show_menu();
    scanf("%c", &selected);
    while (selected != 'q'){
        while (getchar() != '\n')
            continue;
        switch (selected){
            case 'f':
                change_font();
                break;
            case 's':
                change_size();
                break;
            case 'a':
                change_align();
                break;
            default:
                change_others(selected);
                break;
        }
        show_menu();
        scanf("%c", &selected);
    }
    return 0;
}

void show_menu(void){
    printf("ID      SIZE    ALIGN   B       I       U\n");
    printf("%-8d%-8d%-8s%-8s%-8s%-8s\n", font_mode.id, font_mode.size, align[font_mode.align],
           on_off[font_mode.bold], on_off[font_mode.italic], on_off[font_mode.underline]);
    printf("f)change font   s)change size    a)change alignment\n");
    printf("b)toggle bold   i)toggle italic  u)toggle underline\n");
    printf("q)quit\n");
}


void change_font(void)
{
    unsigned int n;
    printf("Enter font of id (0-255): ");
    scanf("%u", &n);
    while (getchar()!='\n')
        continue;
    font_mode.id = n;
    // 通过结构变量直接赋值
}

void change_size(void)
{
    unsigned int n;
    printf("Enter font of size (0-127): ");
    scanf("%u", &n);
    while (getchar()!='\n')
        continue;
    font_mode.size = n;   
}

void change_align(void)
{
    char ch;
    printf("Select alignment:\nl)left   c)center    r)right\n");
    scanf("%c", &ch);
    while (getchar() !='\n')
        continue;
    if (ch == 'l')
        font_mode.align = 0;
    else if (ch == 'c')
        font_mode.align = 1;
    else if (ch == 'r')
        font_mode.align = 2;
}

void change_others(char ch)
{
    if (ch == 'b')
        font_mode.bold = !font_mode.bold;
    else if (ch == 'i')
        font_mode.italic = !font_mode.italic;
    else if (ch == 'u')
        font_mode.underline = !font_mode.underline;
    // 1位数据可以直接取反进行设置
}