//程序题目：删除指定文件




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE* fp;
	char filename[50];
	char ch[20] = "HELLO WARLD";
	char str[20];
	printf("请输入绝对路径\n");
	gets(filename);
	fp = fopen(filename, "wb+");//必须用二进制读写(wb+)，如果用wb则不能使用fread()函数
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fwrite(ch, sizeof(char), sizeof(ch), fp);
	rewind(fp);//使文件内部位置指针指向文件首
	fread(str, sizeof(char), sizeof(ch), fp);//通过读文件验证文件写入成功
	puts(str);
	fclose(fp);
	remove(filename);//根据文件路径删除文件
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("已经成功删除文件\n");
	}
	else
	{
		printf("文件删除失败\n");
	}
	return 0;

}