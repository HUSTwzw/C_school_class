//������Ŀ��ɾ��ָ���ļ�




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE* fp;
	char filename[50];
	char ch[20] = "HELLO WARLD";
	char str[20];
	printf("���������·��\n");
	gets(filename);
	fp = fopen(filename, "wb+");//�����ö����ƶ�д(wb+)�������wb����ʹ��fread()����
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fwrite(ch, sizeof(char), sizeof(ch), fp);
	rewind(fp);//ʹ�ļ��ڲ�λ��ָ��ָ���ļ���
	fread(str, sizeof(char), sizeof(ch), fp);//ͨ�����ļ���֤�ļ�д��ɹ�
	puts(str);
	fclose(fp);
	remove(filename);//�����ļ�·��ɾ���ļ�
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("�Ѿ��ɹ�ɾ���ļ�\n");
	}
	else
	{
		printf("�ļ�ɾ��ʧ��\n");
	}
	return 0;

}