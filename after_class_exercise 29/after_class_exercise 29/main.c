//������Ŀ��N����Χ��һ��Ȧ���ֱ�Ϊ1-N�ţ����ӵ�һ���˿�ʼ���α�������1��3ѭ�������������Ǳ�3�����˳�Ȧ�ӣ���������µ�����ԭ��Ȧ�ӵļ��ţ���ʹ��ָ�������⣩
/*
����ģ�飺
����α�ʾ�˳���
����ô��¼1-3ѭ��������
����ôʵ��ΧȦ��
����ô�ж�ѭ��ֹͣ��
*/




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int amount = 0;		//�μӵ�����
	printf("�����ж����˲�����Ϸ?\n");
	scanf("%d", &amount);
	int* stu = (int*)calloc(amount, sizeof(int));	//ʹ��calloc����mallocԭ������calloc�����Զ���������ڴ�ͳһ��ʼ��Ϊ0
	int step = 0;	//��ǰ��Ӧ�ñ������֣�1-3��
	int flag = 1;
	int* p = stu;
	int num = 0;	//����̭������
	int final_number = 0;	//���һ�˵����
	while (flag)
	{
		p = stu;
		for (p = stu; p <= stu + amount - 1; p++)
		{
			if (*p == 0)
			{
				step += 1;
				if (step == 3)
				{
					step = 0;
					*p = -1;
					if (num < amount - 1)
					{
						num++;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (num == amount - 1)
		{
			for (int i = 0; i <= amount - 1; i++)
			{
				if (*(stu + i) == 0)
				{
					final_number = i + 1;
					flag = 0;
				}
			}
		}
	}
	printf("������µ�����%d��\n", final_number);

	return 0;
}