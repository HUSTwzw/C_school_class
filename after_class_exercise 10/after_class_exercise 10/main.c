//������Ŀ��������
/*
ʵ�ֶ�ѧ����Ϣ����Ĵ���(����)�����ӡ�ɾ�����������
�����Զ�����������λ��
�����Զ���ɾ������λ��
*/




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len 20
struct student
{
char name[len];
char ID[len];
int grade;
struct student *pNext;
};


struct student *input(void);
struct student *insert(struct student *pHead);
struct student * Delete(struct student *pHead);
void output(struct student *Head);
int main(void)
{
struct student *pHead;
pHead=input();
pHead=insert(pHead);
pHead=Delete(pHead);
output(pHead);
return 0;
}


int count;
struct student *input(void)
{
struct student *pHead=NULL;
struct student *pNew;
struct student *pEnd;
pNew=pEnd=(struct student *)malloc(sizeof(struct student));
printf("����������\n");
gets(pNew->name);
printf("������ID\n");
gets(pNew->ID);
printf("�������꼶\n");
scanf("%d",&(pNew->grade));
while(strcmp(pNew->ID,"0")!=0&&(pNew->grade)!=0)
{
count++;
if(count==1)
{
pHead=pNew;
pNew->pNext=NULL;
}
else
{
pNew->pNext=NULL;
pEnd->pNext=pNew;
pEnd=pNew;
}
pNew=(struct student *)malloc(sizeof(struct student));
rewind(stdin);
printf("����������\n");
gets(pNew->name);
printf("������ID\n");
gets(pNew->ID);
printf("�������꼶\n");
scanf("%d",&(pNew->grade));
}
free(pNew);
return pHead;
}


struct student *insert(struct student *pHead)
{
int place=0;
struct student *p1=pHead;
struct student *p2=p1->pNext;
struct student *pNew;
int i=0;
pNew=(struct student *)malloc(sizeof(struct student));
printf("����Ҫ�ںδ�������\n");
scanf("%d",&place);
rewind(stdin);
printf("����������\n");
gets(pNew->name);
printf("������ID\n");
gets(pNew->ID);
printf("�������꼶\n");
scanf("%d",&(pNew->grade));
if(place==1)
{
printf("����Ϣ���뵽��λ\n");
pNew->pNext=pHead;
pHead=pNew;
}
if(place>1&&place<=count)
{
for(i=2;i<place;i++)
{
p1=p1->pNext;
p2=p1->pNext;
}
p1->pNext=pNew;
pNew->pNext=p2;
}
if(place>count)
{
for(;p1->pNext!=NULL;)
{
p1=p1->pNext;
}
p1->pNext=pNew;
pNew->pNext=NULL;
}
count++;
return pHead;
}


struct student * Delete(struct student *pHead)
{
int number=0;
struct student *p1=pHead;
struct student *p2=pHead;
int i=0;

printf("����Ҫɾ����һ�����\n");
scanf("%d",&number);
if(number==1)
{
pHead=p1->pNext;
free(p1);
count--;
return pHead;
}
if(number>1&&number<count)
{
for(i=1;i<number;i++)
{
p1=p2;
p2=p2->pNext;
}
p1->pNext=p2->pNext;
free(p2);
count--;
return pHead;
}
if(number==count)
{
for(i=1;i<count;i++)
{
p1=p2;
p2=p2->pNext;
}
free(p2);
p1->pNext=NULL;
count--;
return pHead;
}
}


void output(struct student *Head)
{
struct student *p;
int i=0;
printf("�ܹ�%d����Ϣ\n",count);
for(p=Head,i=1;p!=NULL;i++)
{
printf("%d:%s  ",i,p->name);
printf("%s  ",p->ID);
printf("%d\n",p->grade);
p=p->pNext;
}
}