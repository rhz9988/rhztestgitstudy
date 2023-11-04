#include<stdio.h>
#include <stdbool.h>
#include<math.h>
//
//判断数是不是素数函数
_Bool judgenumber(int a){
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a%i ==0)
        {
            return true;
        }
        return false;   
    }
}
//判断是不是闰年
//这里有错误 有两种情况，能被4整除且不能被100整除是闰年，能被400整除是闰年
_Bool judgeyear(int a){
    if (a%4==0)
    {
        return true;
    }
    return false; 
}
//二分查找有序数组
int findnumber(int arr[],int left,int right,int target){//这里的arr是一个指针变量，存放的数组首元素的地址
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
//每调用一次程序 num++
void numadd(int* a){
    (*a)++;//先解引用 再++
}
int main()
{
    // int a=0;
    // int b=0;
    // printf("����һ�����\n");
    // scanf("%d",&a);
    // printf("����һ����\n");
    // scanf("%d",&b);   
    // _Bool flag1=judgeyear(a);
    // _Bool flag2=judgenumber(b);
    // if (flag1)
    // {
    //     printf("%d������",a);
    // }
    // else
    // {
    //     printf("%d��������",a);
    // }
    // if (!flag2)
    // {
    //     printf("%d������",b);
    // }
    // else
    // {
    //     printf("%d��������",b);
    // }
    static int num=0;
    numadd(&num);
    numadd(&num);
    numadd(&num);
    printf("%d",num);
    return 0;
}