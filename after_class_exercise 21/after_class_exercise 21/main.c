//程序题目：关于rename函数的初步试验




#include<stdio.h>
int main(void)
{;
	char filename[40];
	char newfilename[40];
	printf("请输入要重命名的文件\n");
	gets(filename);
	printf("请输入新名字\n");
	gets(newfilename);
	rename(filename, newfilename);
	return 0;
}