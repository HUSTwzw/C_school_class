//������Ŀ��ʹ��perror




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void)
{
	FILE* fp;
	fp = fopen("C:\\Users\\48163\\Desktop\\fi.txt", "r");//��һ�������ڵ��ļ�
	if (fp == NULL)
	{
		perror("this is an error");//���������Ϣ this is an error: No such file or directory.
	}
	else
	{
		fclose(fp);
		return 0;
	}
}