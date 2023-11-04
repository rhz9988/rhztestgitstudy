#include"game.h"
//利用数组实现扫雷游戏
void menu(){
    printf("---------------------------\n");
    printf("----------1.开始------------\n");
    printf("----------0.退出------------\n");
}
void Initboard(char board[ROWS][COLS],int rows,int cols,char set)//初始化数组
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j]=set;
        }
        
    }
    
}
void Setmine(char board[ROWS][COLS],int row,int col,int num){
    while (num)
    {
        int x=rand()%row+1;
        int y=rand()%col+1;
        if (board[x][y]=='0')
        {
            board[x][y]='1';
            num--;
        }
    }
}
int Getmine(char board1[ROWS][COLS],int x,int y){
    return (board1[x-1][y-1]+board1[x][y-1]+board1[x+1][y-1]
            +board1[x-1][y]+board1[x+1][y]+
            board1[x-1][y+1]+board1[x][y+1]+board1[x+1][y+1]
            -8*'0');
}
//递归展开雷
void Recurmine(char board1[ROWS][COLS],char board2[ROWS][COLS],int row,int col,int x,int y)
{
    int count=Getmine(board1,x,y);
    board2[x][y]=count+'0';
    //先写递归的终止条件
    if (count!=0)
    {
        return;
    }
    int xx[]={-1,0,1,1,1,0,-1};//一个点一个点的遍历
    int yy[]={-1,-1,-1,0,1,1,1};
    int i=0;
    for ( i = 0; i < 8; i++)
    {
        int dx=x+xx[i];
        int dy=y+yy[i];
        if (dx>=1&&dx<=row&&dy>=1&&dy<=col&&board1[dx][dy]!='1'&&board2[dx][dy]=='*')
        {
            Recurmine(board1,board2,ROW,COL,dx,dy);
        }
    } 
}
void Findmine(char board1[ROWS][COLS],char board2[ROWS][COLS],int row,int col)
{
    int x=0;
    int y=0;
    int win=0;
    while (win<row*col-COUNTMINE)
    {
        Displayboard(board2, ROW, COL);
        printf("请输入要排查的坐标\n");
        scanf("%d%d",&x,&y);
        if (x>=1&&x<=9&&y>=1&&y<=9)
        {
            if (board1[x][y]=='1')
            {
                printf("你被炸死了\n");
                break;
            }
            else
            {
                int count=Getmine(board1,x,y);
                board2[x][y]=count+'0';
                if (count==0)
                {
                    Recurmine(board1,board2,row,col,x,y);
                }
                board2[x][y]=count+'0';//数字3转换成数字字符
                Displayboard(board2,row,col);
                win++;
                //下面实现的是给雷插旗子操作
                printf("是否标记雷位\n");
                printf("1:是,0:否\n");
                int input=0;
                scanf("%d",&input);
                if (input==1)
                {
                    int a=0;
                    int b=0;
                    printf("请输入标记位置\n");
                    scanf("%d%d",&a,&b);
                    board2[a][b]='#';
                    Displayboard(board2,row,col);
                }
            }
        }
        else
        {
            printf("请重新输入\n");
        }
    }   
}

void Displayboard(char board[ROWS][COLS],int row,int col){
    int i=0;
    int j=0;
    printf("----------------------扫雷游戏--------------------\n");
    for ( j = 0; j <col; j++)
    {
        printf("%d ",j);
    }
    printf("\n");
    for ( i = 1; i < row; i++)
    {
        printf("%d ",i);//行号
        for ( j = 1; j < col; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("----------------------扫雷游戏--------------------\n");
}
void game(){
    char mine[ROWS][COLS]={0};//存放布置好的雷的信息
    char show[ROWS][COLS]={0};//存放探查出来的雷的信息
    //初始化数组的内容为指定的内容
    //mine数组没有布置雷的时候都是'0'
    Initboard(mine,ROWS,COLS,'0');
    Initboard(show,ROWS,COLS,'*');
    //设置雷
    Setmine(mine,ROW,COL,COUNTMINE);
    //排查雷
    //Findmine(mine,show,ROW,COL);
    Displayboard(mine,ROW,COL);
    //Displayboard(show,ROW,COL);
    Findmine(mine,show,ROW,COL);
    //show数组在没有排查雷的时候都是'*'
}
int main()
{
    //设置随机树的生成起点
    srand((unsigned)time(NULL));
    int input=0;
    do
    {
        menu();//打印菜单
        printf("请选择>\n");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            printf("开始扫雷游戏\n");
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
        printf("选择错误\n");
            break;
        }
    } while (input);
    return 0;
}