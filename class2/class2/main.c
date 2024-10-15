//程序题目：反弹的小球




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
system("cls");//清空屏幕，使光标回到开头
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
printf("o");//充当小球
if(k==1)//防止第一次就在初始位置反弹
{
if(x==right||x==left)//实现左右反弹
{
x_plus=-x_plus;
}
if(y==top||y==bottom)//实现上下反弹
{
y_plus=-y_plus;
}
}
k=1;
_sleep(100);//延迟100毫秒
}

}