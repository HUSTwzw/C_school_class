//������Ŀ������rename�����ĳ�������




#include<stdio.h>
int main(void)
{;
	char filename[40];
	char newfilename[40];
	printf("������Ҫ���������ļ�\n");
	gets(filename);
	printf("������������\n");
	gets(newfilename);
	rename(filename, newfilename);
	return 0;
}