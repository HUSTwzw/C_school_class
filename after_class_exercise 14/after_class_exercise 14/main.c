//�ļ���д�����ȡ




#include<stdio.h>
int main(void)
{
FILE * fp;
char ch='0';
int i=0;
//fp=fopen("C:\\Users\\48163\\Desktop\\test.txt","w+");
fp=fopen("test.txt","w+");
if(fp==NULL)
{
printf("�ļ���ʧ��\n");
}
else
{
ch=getchar();
while(ch!='\n')
{
fputc(ch,fp);//ÿд��һ���ַ����ļ�ָ��ͻ�ָ���ļ�����һ���ַ�
ch=getchar();
}
}
fclose(fp);
//fp=fopen("C:\\Users\\48163\\Desktop\\test.txt","r");
fp=fopen("test.txt","r");
if(ch==NULL)
{
printf("�ļ���ʧ��\n");
}
else
{
ch=fgetc(fp);//ÿ��ȡһ���ַ����ļ�ָ��ͻ�ָ���ļ�����һ���ַ�
while(ch!=EOF)
{
putchar(ch);
ch=fgetc(fp);
}
printf("\n");
}
fclose(fp);
return 0;
}