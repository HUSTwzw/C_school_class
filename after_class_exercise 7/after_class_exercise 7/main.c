//程序题目：创建链表
/*
输入学生姓名以及学号
若想要退出输入模块就在学号处输入0
输出所有的学生信息(姓名以及学号)
以链表的方式完成程序要求
*/




#include<stdio.h>
#include<stdlib.h>
#define len 20
struct student
{
char name[len];
int ID;
struct student *pNext;
};


struct student* CREAT(void);
void OUTPUT(struct student*pHead);
int main(void)
{
struct studnet *p;
p=CREAT();//可能会有警告C4133   "="从"student *"到"studnet *"的类型不兼容,可以忽略
OUTPUT(p);//可能会有警告C4133   "函数":从"studnet *"到"student *"的类型不兼容,可以忽略	
return 0;
}


int count=0;//定义全局变量，表示链表长度
struct student* CREAT(void)
{
struct student *pNew;//指向新结点的地址
struct student *pEnd;//指向上一个结点的地址
struct student *pHead=NULL;//头指针
pEnd=pNew=(struct student*)malloc(sizeof(struct student));
printf("请输入姓名\n");
scanf("%s",&(pNew->name));
printf("请输入ID号\n");
scanf("%d",&(pNew->ID));
while(pNew->ID!=0)
{
count++;
if(count==1)
{
pNew->pNext=NULL;//让每一个新创建的结点的pNext都先指向NULL
pEnd=pNew;//pNew指向新创建的结点的地址，pEnd指向上一个结点的地址，由于这是第一个创建的结点，因此pEnd=pNew
pHead=pNew;//头指针指向第一个结点
}
else
{
pEnd->pNext=pNew;//上一个结点的pNext指向新结点
pNew->pNext=NULL;//新结点的pNext指向NuLL
pEnd=pNew;//pEnd指向新节点，意味着下一次创建结点时这个结点就变成"上一个结点"(当前的新结点随着下一个结点的创建而变成旧结点)
}
pNew=(struct student*)malloc(sizeof(struct student));
printf("请输入姓名\n");
scanf("%s",&(pNew->name));
printf("请输入ID号\n");
scanf("%d",&(pNew->ID));
}
free(pNew);//跳出循环时还多创建了一个结点，利用free()函数释放该内存
return pHead;
}


void OUTPUT(struct student*pHead)
{
struct student *p;
int number=0;
printf("---总共有%d个人---\n",count);
for(p=pHead,number=1;p!=NULL;number++)
{
printf("第%d个同学的信息:",number);
printf("%s  ",p->name);
printf("%d\n",p->ID);
p=p->pNext;
}
}