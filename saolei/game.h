#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNTMINE 10
void menu();//打印菜单
void game();//游戏函数
void Initboard(char board[ROWS][COLS],int rows,int cols,char set);//初始化数组
void Displayboard(char board[ROWS][COLS],int row,int col);//打印数组，传的还是同一个数组还是11*11   
void Setmine(char board[ROWS][COLS],int row,int col,int num);//设置雷
//排查x,y周围8个坐标有多少个雷的的函数
int Getmine(char board1[ROWS][COLS],int x,int y);
//递归展开雷
void Recurmine(char board1[ROWS][COLS],char board2[ROWS][COLS],int row,int col,int x,int y);
void Findmine(char board1[ROWS][COLS],char board2[ROWS][COLS],int row,int col);//排查雷

//功能齐全了 但是递归排雷是学别人的！
//