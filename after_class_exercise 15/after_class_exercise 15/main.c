#include<stdio.h>
#include<string.h>
int main(void)
{
FILE * fp;
char str[300];
fp=fopen("C:\\Users\\48163\\Desktop\\test.txt","w+");
fputs("�����ͬ�ؾơ�\n",fp);
fputs("�ղ��ƣ������Ρ�\n",fp);
fclose(fp);
fopen("C:\\Users\\48163\\Desktop\\test.txt","r+");
fgets(str,20,fp);//��ȡ���س���ֹͣ�������ַ���ֱ���س����س��ַ�Ҳ�ᴢ�棩�����ַ������Ჹ��'\0';
puts(str);
fgets(str,20,fp);
puts(str);
fclose(fp);
return 0;
}