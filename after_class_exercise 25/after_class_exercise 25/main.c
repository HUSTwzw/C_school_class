#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"head.h"
int main(void)
{
	char filename[40];
	FILE* fp;
	
	printf("�������ļ��ľ���·��\n");
	gets(filename);
	fp = fopen(filename, "w");
	if (fp == NULL)
	{
		perror("error in opening");
		exit(1);
	}
	else
	{
		REST rest[3];
		for (int i=0;i<3;i++)
		{
			printf("�������%d�����������\n",i + 1);
			scanf("%d", &(rest[i].number));
			getchar();
			printf("�������%d������������\n",i + 1);
			gets(&(rest[i].name));
			printf("�������%d�������ĵص�\n", i + 1);
			gets(&(rest[i].site));
			printf("�������%d��������ID\n", i + 1);
			gets(&(rest[i].ID));
		}
		for (int i = 0; i < 3; i++)
		{
			fprintf(fp, "%d", rest[i].number);
			fputc('\t',fp);
			fputs(&(rest[i].name), fp);
			fputc('\t', fp);
			fputs(&(rest[i].site), fp);
			fputc('\t', fp);
			fputs(&(rest[i].ID), fp);
			fputc('\n', fp);
		}
		fclose(fp);
		return 0;
	}
}