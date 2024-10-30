#include<stdio.h>
#include<string.h>
int main(void)
{
FILE * fp;
char str[300];
fp=fopen("C:\\Users\\48163\\Desktop\\test.txt","w+");
fputs("欲买桂花同载酒。\n",fp);
fputs("终不似，少年游。\n",fp);
fclose(fp);
fopen("C:\\Users\\48163\\Desktop\\test.txt","r+");
fgets(str,20,fp);//读取到回车就停止，储存字符串直到回车（回车字符也会储存），在字符串最后会补上'\0';
puts(str);
fgets(str,20,fp);
puts(str);
fclose(fp);
return 0;
}