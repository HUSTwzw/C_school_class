//������Ŀ��
/*
Ҫ������100Ԫ�Ĵ�Ʊ�����ɵ�ֵ��50Ԫ��20Ԫ��10Ԫ��5Ԫһ�ŵ�С��Ʊ��
ÿ����ֵ����1�ţ����������п��ܵĻ���������Ӧ�ʵ����Ǽ����ظ�������
*/




#include<stdio.h>
int a_50[2000];
int a_20[2000];
int a_10[2000];
int a_5[2000];
int main(void)
{
	int amo_50 = 1;
	int amo_20 = 1;
	int amo_10 = 1;
	int amo_5 = 1;
	int price = 415;
	/*int a_50[2000];
	int a_20[2000];
	int a_10[2000];
	int a_5[2000];*/ //ʹ�ô����飬���ܵ���ջ��������⣬��ʱ����Խ������鶨��Ϊȫ�ֱ�����������ʹ�������ڴ澲̬��
	int i_50 = 0;
	int i_20 = 0;
	int i_10 = 0;
	int i_5 = 0;
	int w = 0;


	for (amo_50;; amo_50++)
	{

		if (price >= 50 * (amo_50 - 1))
		{
			price -= 50 * (amo_50 - 1);
			
		}
		else
		{
			amo_50 -= 1;
			break;
		}

		for (amo_20 = 1;; amo_20++)
		{
			if (price >= 20 * (amo_20 - 1))
			{
				price -= 20 * (amo_20 - 1);
				

			}
			else
			{
				amo_20 -= 1;
				price += (amo_50 - 1) * 50;
				
				break;
			}

			for (amo_10 = 1;; amo_10++)
			{
				if (price >= 10 * (amo_10 - 1))
				{
					price -= 10 * (amo_10 - 1);

				}
				else
				{
					amo_10 -= 1;
					price += 20 * (amo_20 - 1);
					break;
				}

				if (price >= 0)
				{
					amo_5 = price / 5 + 1;

					{
						a_5[i_5] = amo_5; i_5++;
						a_10[i_10] = amo_10; i_10++;
						a_20[i_20] = amo_20; i_20++;
						a_50[i_50] = amo_50; i_50++;
					}
					price = 0;
				}
				
				price += (amo_5 - 1) * 5;
				price += 10 * (amo_10 - 1);
			}
		}
	}


	for (w = 0; w < i_5; w++)
	{
		printf("50Ԫ��20Ԫ��10Ԫ��5Ԫ�����ֱ�Ϊ%d %d %d %d\n", a_50[w],a_20[w],a_10[w],a_5[w]);
	}
	
	return 0;
}