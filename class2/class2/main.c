//������Ŀ��������С��




#include<stdio.h>
#include<stdlib.h>
int main(void)
{
int top=1;
int bottom=20;
int left=1;
int right=15;
int x=0;
int y=0;
int x_plus=1;
int y_plus=1;
int i=0;
int j=0;
int k=0;
while(1)
{
system("cls");//�����Ļ��ʹ���ص���ͷ
x+=x_plus;
y+=y_plus;
for(i=1;i<x;i++)
{
printf("\n");
}
for(j=1;j<y;j++)
{
printf(" ");
}
printf("o");//�䵱С��
if(k==1)//��ֹ��һ�ξ��ڳ�ʼλ�÷���
{
if(x==right||x==left)//ʵ�����ҷ���
{
x_plus=-x_plus;
}
if(y==top||y==bottom)//ʵ�����·���
{
y_plus=-y_plus;
}
}
k=1;
_sleep(100);//�ӳ�100����
}

}