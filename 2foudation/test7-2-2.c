#include<stdio.h>
int Strlen(const char* str){
    if(*str=='\0'){
        return 0;
    }
    else
    {
        return 1+Strlen(str+1);//一开始 str指向a的地址，Strlen(str+1)之后，str指向b的地址
    }
}
int main()
{   
    char* p="abcdef";
    int len=Strlen(p);
    printf("%d\n",len);
    return 0;
}