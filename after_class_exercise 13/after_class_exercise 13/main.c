//程序题目：文件的打开与关闭




#include<stdio.h>
int main(void)
{
FILE *fp;
fp=fopen("C:\\Users\\48163\\Desktop\\test.txt","r");//以绝对路径只读方式打开文件（存放在桌面的txt文件）
if(fp==NULL)
{
printf("失败\n");
}
else
{
printf("成功\n");
printf("%d\n",fp);
}
fclose(fp);
fp=fopen("test.txt","r");//以相对路径只读方式打开文件（将txt文件放于main.c源文件所在的同一目录下）
if(fp==NULL)
{
printf("失败\n");
}
else
{
printf("成功\n");
printf("%d\n",fp);
}
fclose(fp);
return 0;
}