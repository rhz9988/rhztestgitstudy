#include"stdio.h"
// enum color
// {
//     RED=100,
//     GREEN,
//     BLUE
// };
void test(){
    static int a=1;//加了static之后就成了2到11
    a++;
    printf("%d\n",a);
}
int main()
{
    // char arr1[]="bit";//双引号引起来的是字符串，单引号是字符 char是字符类型，c语言没有字符串类型
    // char arr2[]={'b','i','t'};
    // char arr3[]={'b','i','t','\0'};
    // printf("%s",arr1);
    // printf("%s\n",arr2);
    // printf("%s\n",arr3);

    // printf("%d\n",RED);
    // printf("%d\n",GREEN);
    int i=0;
    while (i<10)
    {
        test();
        i++;
    }
    int num=10;
    printf("%p\n",&num);
    int* p=&num;//p的类型是int*，int说明p指向的对象（指向的对象是num，num又是10）的int类型  *p是地址的值，*说明p是指针变量
    //*p=10;    p是指针，*p是指针变量，*是解引用操作符，*p就是p指向的对象
    printf("%p\n",p);//打印指针所在内存的地址
    printf("%d\n",&p);//打印的指针的地址
    printf("%d\n",*p);//打印地址存放的值
    return 0;
}