//������Ŀ����file1.txt�����ݽӵ�file2.txt��������




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
	fprintf(stdout, "�������һ���ļ���·��\n");
	gets(filename1);
	fprintf(stdout, "������ڶ����ļ���·��\n");
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
		len = ftell(fp1);//ͨ��������ƶ��������ַ�EOFǰ�棬�����ж��ļ����ַ���������
		rewind(fp1);//��ָ���ƶ����ļ���ͷ�������޷���ȡ��
		fgets(content, len, fp1);//�������ԣ�����������ַ�����Ҫlen+1������len���У�Ŀǰ��̫���ԭ��
		fseek(fp2, 0, SEEK_END);
		fputs(content, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}