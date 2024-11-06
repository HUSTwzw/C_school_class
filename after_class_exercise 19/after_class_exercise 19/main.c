//程序题目：一个关于二进制读写以及fseek函数的使用练习，主要为了提升熟练度


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void)
{
	FILE* fp;
	char str[50];
	char content[30];
	char ch = 0;
	printf("请输入文件的绝对路径\n");
	gets(str);
	fp = fopen(str, "wb");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
	}
	printf("请输入内容\n");
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