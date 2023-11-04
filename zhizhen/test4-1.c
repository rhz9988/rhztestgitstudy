#include<stdio.h>
// #define N_VALUES 5
// int my_strlen(char *s)
// {
// char *p = s;
// while(*p != '\0' )
// p++;
// return p-s;
// }
int main()
{
int arr[10] = {1,2,3,4,5,6,7,8,9,0};
printf("%p\n", arr);
printf("%p\n", &arr[0]);
return 0;
}
// int main(){
//     float values[N_VALUES];
//     float *vp;
//     //指针+-整数；指针的关系运算
//     for (vp = &values[0]; vp < &values[N_VALUES];)
//     {
    
//         *vp++ = 0; 
//     }
//         return 0;
// }