#include"game.h"
void Initboard(char board[ROW][COL],int row,int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j]=' ';
        }
        
    }
    
}
//第一版打印棋盘，问题:列是固定的
// void Printboard(char board[ROW][COL],int row,int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         //打印数据
//         printf(" %c | %c | %c\n");
//         //打印分割行
//         if (i<row-1)
//         {
//             printf("---|---|---\n");
//         }  
//     }
    
// }

void Printboard(char board[ROW][COL],int row,int col)
{
    for (int i = 0; i < row; i++)
    {
        //打印数据
        for (int j = 0; j < col; j++)
        {
            printf(" %c ",board[i][j]);
            if (j<col-1)
            {
                printf("|");
            }   
        }
        printf("\n");
        //打印分割行
        if (i<row-1)
        {
            for (int j = 0; j < col; j++)
            {
                printf("---");
                if (j<col-1)
                {
                    printf("|");
                }   
           }
           printf("\n");
        }  
    }
    
}
void Playermove(char board[ROW][COL],int row,int col)
{
    printf("玩家下棋：\n");
    int x=0;
    int y=0;
    while (1)
    {
        printf("请输入坐标\n");
        //scanf("%d%d",&x,&y);
        scanf("%d%d", &x, &y);
        //坐标范围合法的判断
        if (x>=1&&x<=row&&y>=1&y<=col)
        {
            if (board[x-1][y-1]==' ')
            {   
                board[x-1][y-1]='*';
                break;
            }
            else
            {
                printf("坐标被占用，请重新输入\n");
            }
        }
        else
        {
            printf("请重新输入\n");
        }
    }       
}
//找空白的位置随机下
void Computermove(char board[ROW][COL],int row,int col)
{

     printf("电脑下棋\n");
     int x=0;
     int y=0;
     while (1)
     {
        x=rand()%row;//0-2的随机数  任意数除以三余0-2
        y=rand()%col;
        if (board[x][y]==' ')
        {
            board[x][y]='#';
            break;
        }
     }     
}
int Isfull(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            if (board[i][j]==' ')
            {
                return 0;//没满
            }
            
        }
    }  
    return 1;//满了
}
char Whowin(char board[ROW][COL],int row,int col)
{
    //赢的三种方式，横三行，竖三行，斜三行
    //横三行
    int i=0;
    for ( i = 0; i < col; i++)
    {
        if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]!=' ')
        {
            return board[i][0];
        }
    }
    //竖三列
    for ( i = 0; i < col; i++)
    {
        if (board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[2][i]!=' ')
        {
            return board[0][i];
        }
    }
    //两个对角线
    if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]!=' ')
    {
        return board[0][0];
    }
    if (board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]!=' ')
    {
        return board[0][0];
    }
    if (1==Isfull(board,ROW,COL))
    {
        return 'Q';//平局
    }
    return 'C';//继续  
}