#include"stdio.h"
/*练习： 1.计算n的阶乘
        2.计算1！+2！+3！+。。10！
        3.在一个有序数组中，查找具体的某个数字n（讲解二分查找）
        4.编写代码，演示多个字符从两端移动，像中间汇聚
        5，编写代码实现，模拟用户登录场景，并且只能登录三次（只允许输入三次密码，错误则退出程序）
*/
//3.二分查找函数
int findarry(int arr[],int left,int right,int target){
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if (arr[mid]==target)
        {
            return mid;
        }
        if (arr[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}
int main()
{   
    //1.2.设n=10
    int a=1;
    int b=0;
    for (int i = 1; i < 11; i++)
    {
        a=i*a;
        //b=a+b;
        b+=a;
    }
    
    printf("10的阶乘为%d\n",a);
    printf("1!+2!。。。+10！=%d\n",b);
    //3.
    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=5;
    int resualt=findarry(arr,0,n-1,target);
    printf("目标点的索引为%d\n",resualt);
    //4.
    char arr1[]="welcome to bit !!!";
    char arr2[]="##################";
    int left=0;
    int right=strlen(arr2)-1;//[a b c \0]strlen统计的是\0之前的元素个数
    //int right=sizeof(arr1)/sizeof(arr1[0])-2;//-2是因为 考虑\0且下标从0开始
    while (left<=right)
    {
        arr2[left]=arr1[left];
        arr2[right]=arr1[right];
        printf("%s\n",arr2);
        Sleep(1000);
        system("cls");
        left++;
        right--;
    }
    printf("%s\n",arr2);
    //5.    默认登录密码是cxcc9988 
    int i=0;
    char password[8]={0};
    for ( i = 0; i < 3; i++)
    {
        printf("请输入密码\n");
        scanf("%s",password);//这里不需要取地址，数组名本来就是地址
        if (strcmp(password,"cxcc9988")==0)//比较两个字符串是否相等，不能使用==，而要使用一个库函数strcmp
        {
            printf("登录成功\n");
            break;
        }
    }
    if (i==3)
    {
        printf("三次错误，退出系统\n");

    }

    return 0;
}