//������Ŀ������һ���ļ���ͼƬ��
/*
��exe�ļ����ڴ�ʹ��cmd�������after_class_exercise17.exe moon,jpg hello.jpg
�����ڴ�Ŀ¼�½�һ����Ϊhello.jpg��ͼƬ��ͬʱͼƬ������moon.jpgͼƬ�ĸ��ư�
�˴θ��Ʋ��õ����ַ��ظ���ȡ����
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
		printf("�����������\n");
		return 0;
	}
	else
	{
		forigin = fopen(argv[1], "rb");
		fcopy = fopen(argv[2], "wb");
		if (forigin == NULL)
		{
			printf("ԭ�ļ���ʧ��\n");
			return 0;
		}
		if (fcopy == NULL)
		{
			printf("�����ļ���ʧ��\n");
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