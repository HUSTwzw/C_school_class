#include"student.h"
void f_output(void)
{
char address[40]="0";
char str[40];
getchar();
printf("�������ļ��ľ���·��\n");
gets(address);
fp=fopen(address,"r+");
if(fp==NULL)
{
printf("�ļ���ʧ��\n");
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
