//������Ŀ���ļ��Ĵ���ر�




#include<stdio.h>
int main(void)
{
FILE *fp;
fp=fopen("C:\\Users\\48163\\Desktop\\test.txt","r");//�Ծ���·��ֻ����ʽ���ļ�������������txt�ļ���
if(fp==NULL)
{
printf("ʧ��\n");
}
else
{
printf("�ɹ�\n");
printf("%d\n",fp);
}
fclose(fp);
fp=fopen("test.txt","r");//�����·��ֻ����ʽ���ļ�����txt�ļ�����main.cԴ�ļ����ڵ�ͬһĿ¼�£�
if(fp==NULL)
{
printf("ʧ��\n");
}
else
{
printf("�ɹ�\n");
printf("%d\n",fp);
}
fclose(fp);
return 0;
}