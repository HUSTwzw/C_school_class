//程序题目：链表




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct book
{
char name[20];
int amount;
struct book *pNext;
}BOOK;


BOOK *input(void);
void output(BOOK * pHead);
int main(void)
{
BOOK bok;
BOOK * pHead;
pHead=input();
output(pHead);
return 0;
}


int count=0;
BOOK *input(void)
{
BOOK * pHead;
BOOK * pNew;
BOOK * pEnd;
pEnd=pNew=(BOOK *)malloc(sizeof(BOOK));
printf("请输入书籍名称（C语言\Python语言\Java语言）\n");
gets(pNew->name);
printf("请输入数量\n");
scanf("%d",&(pNew->amount));
while(strcmp(pNew->name,"exit")!=0&&pNew->amount!=0)
{
count++;
if(count==1)
{
pNew->pNext=NULL;
pHead=pNew;
}
else
{
pEnd->pNext=pNew;
pNew->pNext=NULL;
pEnd=pNew;
}
rewind(stdin);
pNew=(BOOK *)malloc(sizeof(BOOK));
printf("请输入书籍名称\n");
gets(pNew->name);
printf("请输入数量\n");
scanf("%d",&(pNew->amount));
}
free(pNew);
return pHead;
}


void output(BOOK * pHead)
{
BOOK *p1=pHead;
for(;p1!=NULL;)
{
printf("%s  ",p1->name);
printf("%d\n",p1->amount);
p1=p1->pNext;
}
}