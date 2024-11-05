//程序题目：复制一个文件（图片）
/*
在exe文件所在处使用cmd命令，输入after_class_exercise17.exe moon,jpg hello.jpg
即可在此目录新建一个名为hello.jpg的图片，同时图片内容是moon.jpg图片的复制版
此次复制采用单个字符重复读取操作
*/




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(int argc, char* argv[])
{
	FILE* forigin;
	FILE* fcopy;
	char ch = '0';
	if (argc != 3)
	{
		printf("参数输入错误\n");
		return 0;
	}
	else
	{
		forigin = fopen(argv[1], "rb");
		fcopy = fopen(argv[2], "wb");
		if (forigin == NULL)
		{
			printf("原文件打开失败\n");
			return 0;
		}
		if (fcopy == NULL)
		{
			printf("复制文件打开失败\n");
			return 0;
		}
		ch = fgetc(forigin);
		while (!feof(forigin))
		{
			fputc(ch, fcopy);
			ch = fgetc(forigin);
		}
		fclose(forigin);
		fclose(fcopy);
		return 0;
	}
}