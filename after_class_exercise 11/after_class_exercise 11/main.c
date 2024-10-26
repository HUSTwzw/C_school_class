//程序题目：枚举




#include<stdio.h>
enum Season
{
mango=1,orange,watermelon,apple,banana
};


int main(void)
{
enum Season num=(enum Season)(0);
printf("请输入要选择的水果 1.芒果 2.橙子 3.西瓜 4.苹果 5.香蕉\n");
scanf("%d",&num);
switch(num)
{
case mango:printf("芒果\n");break;
case orange:printf("橙子\n");break;
case watermelon:printf("西瓜\n");break;
case apple:printf("苹果\n");break;
case banana:printf("香蕉\n");break;
default:printf("输入错误\n");break;
}
return 0;
}