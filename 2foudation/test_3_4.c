#include"stdio.h"
/*��ϰ�� 1.����n�Ľ׳�
        2.����1��+2��+3��+����10��
        3.��һ�����������У����Ҿ����ĳ������n��������ֲ��ң�
        4.��д���룬��ʾ����ַ��������ƶ������м���
        5����д����ʵ�֣�ģ���û���¼����������ֻ�ܵ�¼���Σ�ֻ���������������룬�������˳�����
*/
//3.���ֲ��Һ���
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
    //1.2.��n=10
    int a=1;
    int b=0;
    for (int i = 1; i < 11; i++)
    {
        a=i*a;
        //b=a+b;
        b+=a;
    }
    
    printf("10�Ľ׳�Ϊ%d\n",a);
    printf("1!+2!������+10��=%d\n",b);
    //3.
    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=5;
    int resualt=findarry(arr,0,n-1,target);
    printf("Ŀ��������Ϊ%d\n",resualt);
    //4.
    char arr1[]="welcome to bit !!!";
    char arr2[]="##################";
    int left=0;
    int right=strlen(arr2)-1;//[a b c \0]strlenͳ�Ƶ���\0֮ǰ��Ԫ�ظ���
    //int right=sizeof(arr1)/sizeof(arr1[0])-2;//-2����Ϊ ����\0���±��0��ʼ
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
    //5.    Ĭ�ϵ�¼������cxcc9988 
    int i=0;
    char password[8]={0};
    for ( i = 0; i < 3; i++)
    {
        printf("����������\n");
        scanf("%s",password);//���ﲻ��Ҫȡ��ַ���������������ǵ�ַ
        if (strcmp(password,"cxcc9988")==0)//�Ƚ������ַ����Ƿ���ȣ�����ʹ��==����Ҫʹ��һ���⺯��strcmp
        {
            printf("��¼�ɹ�\n");
            break;
        }
    }
    if (i==3)
    {
        printf("���δ����˳�ϵͳ\n");

    }

    return 0;
}