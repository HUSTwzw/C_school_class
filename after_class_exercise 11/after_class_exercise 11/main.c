//������Ŀ��ö��




#include<stdio.h>
enum Season
{
mango=1,orange,watermelon,apple,banana
};


int main(void)
{
enum Season num=(enum Season)(0);
printf("������Ҫѡ���ˮ�� 1.â�� 2.���� 3.���� 4.ƻ�� 5.�㽶\n");
scanf("%d",&num);
switch(num)
{
case mango:printf("â��\n");break;
case orange:printf("����\n");break;
case watermelon:printf("����\n");break;
case apple:printf("ƻ��\n");break;
case banana:printf("�㽶\n");break;
default:printf("�������\n");break;
}
return 0;
}