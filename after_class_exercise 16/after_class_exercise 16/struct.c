#include"student.h"
int number=0;
struct student * s_input(void)
{
struct student * pHead;
struct student * pNew;
struct student * pEnd;
pHead=pNew=(struct student *)malloc(sizeof (struct student));
printf("������������\n");
gets(pNew->name);
printf("������ID��\n");
gets(pNew->ID);
printf("������ɼ�\n");
scanf("%d",&(pNew->score));
while(strcmp(pNew->name,"exit")!=0&&strcmp(pNew->ID,"exit")!=0&&pNew->score!=0)
{
number++;
if(number==1)
{
pEnd=pNew;
pNew->pNext=NULL;
}
else
{
pEnd->pNext=pNew;
pNew->pNext=NULL;
pEnd=pNew;
}
pNew=(struct student *)malloc(sizeof(struct student));
getchar();
printf("������������\n");
gets(pNew->name);
printf("������ID��\n");
gets(pNew->ID);
printf("������ɼ�\n");
scanf("%d",&(pNew->score));
}
free(pNew);
return pHead;
}