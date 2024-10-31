#include"student.h"
void f_output(void)
{
char address[40]="0";
char str[40];
getchar();
printf("请输入文件的绝对路径\n");
gets(address);
fp=fopen(address,"r+");
if(fp==NULL)
{
printf("文件打开失败\n");
}
else
{
fgets(str,sizeof(struct student),fp);
while(!feof(fp))
{
puts(str);
fgets(str,sizeof(struct student),fp);
}
}
}
