//������Ŀ��һ�����ڶ����ƶ�д�Լ�fseek������ʹ����ϰ����ҪΪ������������


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void)
{
	FILE* fp;
	char str[50];
	char content[30];
	char ch = 0;
	printf("�������ļ��ľ���·��\n");
	gets(str);
	fp = fopen(str, "wb");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
	}
	printf("����������\n");
	gets(content);
	fwrite(content, sizeof(char), sizeof(content), fp);
	fclose(fp);
	fopen(str, "rb");
	fseek(fp, 2, SEEK_SET);
	fread(&ch, sizeof(char), sizeof(ch), fp);
	putchar(ch);
	fseek(fp, 3, SEEK_CUR);
	fread(&ch, sizeof(char), sizeof(ch), fp);
	putchar(ch);
	fseek(fp, 1, SEEK_CUR);
	fread(&ch, sizeof(char), sizeof(ch), fp);
	putchar(ch);
	fseek(fp, 0, SEEK_SET);
	fread(&ch, sizeof(char), sizeof(ch), fp);
	putchar(ch);
	fclose(fp);
	return 0;
}