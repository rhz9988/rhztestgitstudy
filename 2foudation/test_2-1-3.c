#include"stdio.h"
#include<stdlib.h>
#include<time.h>
//#include <头文件>  : 编译器只会从系统配置的库环境中去寻找头文件，不会搜索当前文件夹。通常用于引用标准库头文件
//#include "头文件"  : 编译器会先从当前文件夹中寻找头文件,如果找不到则到系统默认库环境中去寻找。一般用于引用用户自己定义使用的头文件。
int main()
{
    //生成一个1到100的随机数
    //输出随机数是奇数还是偶数
    //随机数种子
    srand((unsigned)time(NULL));//随机数种子要放在随机数的前面
    //rand()函数用法，rand%a产生一个0到a的随机数，包括0但不包括a；
    int a=rand()%100+1;
    //要想每次出现的不一样需要包含随机树种子 srand((unsigned)time(NULL));
    //使用rand（）和srand需要包含头文件#include<ctime> #include<cstdlib>
    printf("产生的随机数为%d\n",a);
    if (1==a%2)
    {
        printf("a为奇数\n");
    }
    else
    {
        printf("a为偶数\n");
    }
    return 0;
}
