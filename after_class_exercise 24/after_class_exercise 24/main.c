//������Ŀ������һ�ļ��Զ�������Ϣ




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void)
{
	FILE* fp1;
	FILE* fp2;
	char filename1[40];
	char filename2[40];
	char content[50];
	printf("��������ҽ�̸�ļ���\n");
	gets(filename1);
	printf("�������Զ��ظ��ļ�������\n");
	gets(filename2);
	fp1 = fopen(filename1, "w");
	fp2 = fopen(filename2, "r");
	if (fp1 == NULL || fp2 == NULL)
	{
		perror("error in opening");
		exit(1);
	}
	else
	{
		fgets(content, sizeof(content), fp2);
		fputs(content, fp1);
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
}