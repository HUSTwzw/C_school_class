#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char buf[1024*1024];
int main(int argc,char *argv[])
{
	FILE* forigin;
	FILE* fcopy;
	if (argc != 3)
	{
		printf("�����������\n");
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
		else if (fcopy == NULL)
		{
			printf("�����ļ���ʧ\n");
			return 0;
		}
		else
		{
			int len;
			do
			{
				len = fread(buf, sizeof(char), sizeof(buf), forigin);
				if (len > 0)
				{
					fwrite(buf, sizeof(char),len, fcopy);
				}
			} while (!feof(forigin));
			fclose(forigin);
			fclose(fcopy);
		}

	}
	return 0;
}