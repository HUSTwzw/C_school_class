//程序题目：N个人围成一个圈（分别为1-N号），从第一个人开始依次报数（从1到3循环报数），凡是报3的人退出圈子，问最后留下的人是原来圈子的几号？（使用指针解决问题）
/*
问题模块：
①如何表示退出？
②怎么记录1-3循环报数？
③怎么实现围圈？
④怎么判断循环停止？
*/




#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int amount = 0;		//参加的人数
	printf("请问有多少人参与游戏?\n");
	scanf("%d", &amount);
	int* stu = (int*)calloc(amount, sizeof(int));	//使用calloc而非malloc原因在于calloc可以自动将分配的内存统一初始化为0
	int step = 0;	//当前人应该报的数字（1-3）
	int flag = 1;
	int* p = stu;
	int num = 0;	//已淘汰的人数
	int final_number = 0;	//最后一人的序号
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
	printf("最后留下的人是%d号\n", final_number);

	return 0;
}