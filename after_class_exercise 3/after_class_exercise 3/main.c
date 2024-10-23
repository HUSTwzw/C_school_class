//程序题目：定义一个字符串数组，为其赋值，利用函数递归调用将其逆序输出




#include<stdio.h>
#include<string.h>
#define len 100
void output(char *p1,char *p2);
int main(void)
{
char str[len]={'0'};
printf("请输入字符串\n");
gets(str);
output(str,str+strlen(str)-1);
}


void output(char *p1,char *p2)
{
if(p1<p2)
{
output(p1+1,p2);
}
printf("%c ",*p1);
}