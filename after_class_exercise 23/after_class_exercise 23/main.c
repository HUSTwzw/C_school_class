//程序题目：将file1.txt的内容接到file2.txt内容下面




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void)
{
	char filename1[40];
	char filename2[40];
	FILE* fp1;
	FILE* fp2;
	char content[40];
	long len;
	char ch;
	fprintf(stdout, "请输入第一个文件的路径\n");
	gets(filename1);
	fprintf(stdout, "请输入第二个文件的路径\n");
	gets(filename2);
	fp1 = fopen(filename1, "r");
	fp2 = fopen(filename2, "r+");
	if (fp1 == NULL || fp2 == NULL)
	{
		perror("error in file's opening");
		return 1;
	}
	else
	{
		fseek(fp1, 0, SEEK_END);
		len = ftell(fp1);//通过将光标移动到隐藏字符EOF前面，可以判断文件中字符的数量。
		rewind(fp1);//将指针移动会文件开头，否则无法读取。
		fgets(content, len, fp1);//经过测试，如果是中文字符就需要len+1，否则len就行，目前不太清楚原因。
		fseek(fp2, 0, SEEK_END);
		fputs(content, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}