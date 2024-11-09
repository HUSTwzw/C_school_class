//程序题目：使用perror




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void)
{
	FILE* fp;
	fp = fopen("C:\\Users\\48163\\Desktop\\fi.txt", "r");//打开一个不存在的文件
	if (fp == NULL)
	{
		perror("this is an error");//输出错误消息 this is an error: No such file or directory.
	}
	else
	{
		fclose(fp);
		return 0;
	}
}