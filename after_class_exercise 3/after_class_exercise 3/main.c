//������Ŀ������һ���ַ������飬Ϊ�丳ֵ�����ú����ݹ���ý����������




#include<stdio.h>
#include<string.h>
#define len 100
void output(char *p1,char *p2);
int main(void)
{
char str[len]={'0'};
printf("�������ַ���\n");
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