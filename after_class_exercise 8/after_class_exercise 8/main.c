//������Ŀ��
/*
�����������������Ϣ
*/




#include<stdio.h>
#include<stdlib.h>
#define len 20
struct app
{
char name[len];
int pay;
struct app *pNext;
};


struct app* input(void);
void output(struct app *pHead);
int main(void)
{
struct app *p;
p=input();
output(p);
return 0;
}


int count;
struct app* input(void)
{
struct app *pHead=NULL;
struct app *pNew;
struct app *pEnd;
count=0;
pEnd=pNew=(struct app*)malloc(sizeof(struct app));
printf("������APP����\n");
gets(pNew->name);
printf("��������\n");
scanf("%d",&(pNew->pay));
getchar();
while(pNew->pay!=0)
{
count++;
if(count==1)
{
pEnd->pNext=NULL;
pHead=pNew;
}
else
{
pEnd->pNext=pNew;;
pNew->pNext=NULL;
pEnd=pNew;
}
pNew=(struct app*)malloc(sizeof(struct app));
printf("������APP����\n");
gets(pNew->name);
printf("��������\n");
scanf("%d",&(pNew->pay));
getchar();
}
free(pNew);
return pHead;
}


void output(struct app *pHead)
{
struct app *p;
int i=0;
for(i=1,p=pHead;p!=NULL;i++)
{
printf("%d:",i);
printf("%s  ",&(p->name));
printf("%d\n",p->pay);
p=p->pNext;
}
if(i==1)
{
printf("û�������κ���Ϣ\n");
}
}