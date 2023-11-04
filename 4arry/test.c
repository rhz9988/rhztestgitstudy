#include"game.h"
#include"game.c"
void menu(){
    printf("---------------------------\n");
    printf("----------1.开始------------\n");
    printf("----------0.退出------------\n");
}
//创建一个打印棋盘函数
void game(){
    char ret='0';
    char board[ROW][COL]={0};
    //初始化棋盘
    Initboard(board,ROW,COL);
    //打印棋盘
    Printboard(board,ROW,COL);
    //下棋
    while (1)
    {
        //玩家下棋
        Playermove(board,ROW,COL);
        Printboard(board,ROW,COL);
        //判断玩家是是否赢
        ret=Whowin(board,ROW,COL);
        if (ret!='C')
        {
            break;//分出结果就跳出
        }
        //电脑下棋
        Computermove(board,ROW,COL);
        Printboard(board,ROW,COL);
        //判断电脑是否赢
        ret=Whowin(board,ROW,COL);
        if (ret!='C')
        {
            break;//分出结果就跳出
        }
    }
    //有结果了
    if (ret=='*')
    {
        printf("玩家赢了\n");
    }
    else if (ret=='#')
    {
        printf("电脑赢了\n");
    }
    else
    {
        printf("平局\n");
    } 
}
int main()
{
    srand((unsigned int)time(NULL));//随机数的起点
    int input=0;//初始化输入
    do
    {
        menu();//打印菜单
        printf("请选择>\n");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
        break;
        default:
            printf("输入错误\n");
            break;
        }
    } while (input);
    
    return 0;
}