#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//初始化棋盘
void Initboard(char board[ROW][COL],int row,int col);
//打印棋盘
void Printboard(char board[ROW][COL],int row,int col);
//玩家下棋
void Playermove(char board[ROW][COL],int row,int col);
//电脑下棋
void Computermove(char board[ROW][COL],int row,int col);
//棋盘满没满,没满要继续下
int Isfull(char board[ROW][COL],int row,int col);
//判断谁赢
char Whowin(char board[ROW][COL],int row,int col);