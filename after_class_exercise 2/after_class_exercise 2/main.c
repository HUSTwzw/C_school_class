//������Ŀ��ѭ����λ




#include<stdio.h>
void output_0(unsigned int num,int n);
void output_1(unsigned int num,int n);
int main(void)
{
unsigned int num;
int n=0;
int choice=0;
printf("������˽�����\n");
scanf("%o",&num);
printf("������Ҫ�ƶ���λ��\n");
scanf("%d",&n);
printf("����ѭ������(0)����ѭ������(1)\n");
scanf("%d",&choice);
switch(choice)
{
case 0:output_0(num,n);break;
case 1:output_1(num,n);break;
default:printf("�������ִ���\n");
}
return 0;
}


//ѭ�����ƣ����Ƴ��ĸ�λ�ŵ������ĵ�λ
/*
����һ���˽�����������Ҫ��λ��λ���������λ�Ľ����ʾ����Ļ�ϣ��˽�����ʽ��
*/
void output_0(unsigned int num,int n)
{
int x=0;
x=num>>(32-n);
num<<=n;
num|=x;
printf("%o\n",num);
}


//ѭ�����ƣ����Ƴ��ĵ�λ�ŵ������ĸ�λ
/*
����һ���˽�����������Ҫ��λ��λ���������λ�Ľ����ʾ����Ļ�ϣ��˽�����ʽ��
*/
void output_1(unsigned int num,int n)
{
int x=0;
x=num<<(32-n);
printf("%o\n",num);
num>>=n;
printf("%o\n",num);
num|=x;
printf("%o\n",num);
}