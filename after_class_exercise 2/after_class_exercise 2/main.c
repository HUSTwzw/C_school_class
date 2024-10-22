//程序题目：循环移位




#include<stdio.h>
void output_0(unsigned int num,int n);
void output_1(unsigned int num,int n);
int main(void)
{
unsigned int num;
int n=0;
int choice=0;
printf("请输入八进制数\n");
scanf("%o",&num);
printf("请输入要移动的位数\n");
scanf("%d",&n);
printf("进行循环左移(0)还是循环右移(1)\n");
scanf("%d",&choice);
switch(choice)
{
case 0:output_0(num,n);break;
case 1:output_1(num,n);break;
default:printf("输入数字错误\n");
}
return 0;
}


//循环左移：将移出的高位放到该数的低位
/*
输入一个八进制数，输入要移位的位数，最后将移位的结果显示在屏幕上（八进制形式）
*/
void output_0(unsigned int num,int n)
{
int x=0;
x=num>>(32-n);
num<<=n;
num|=x;
printf("%o\n",num);
}


//循环右移：将移出的低位放到该数的高位
/*
输入一个八进制数，输入要移位的位数，最后将移位的结果显示在屏幕上（八进制形式）
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