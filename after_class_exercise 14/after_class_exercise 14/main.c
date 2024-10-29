//文件的写入与读取




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
printf("文件打开失败\n");
}
else
{
ch=getchar();
while(ch!='\n')
{
fputc(ch,fp);//每写入一个字符，文件指针就会指向文件中下一个字符
ch=getchar();
}
}
fclose(fp);
//fp=fopen("C:\\Users\\48163\\Desktop\\test.txt","r");
fp=fopen("test.txt","r");
if(ch==NULL)
{
printf("文件打开失败\n");
}
else
{
ch=fgetc(fp);//每读取一个字符，文件指针就会指向文件中下一个字符
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