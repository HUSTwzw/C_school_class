//������Ŀ����ѯѧ����Ϣ�������ʹ�ú������ؽṹ��ָ�룩
/*
��ѯǰ����ѧ����Ϣϵͳ
��ѯʱ����ѧ������
���������ڣ����һЩ��ѧ����Ϣ���������ڣ����"���޴���"
Ҫ��������ֵ�ǽṹ��ָ��
*/




#include<stdio.h>
#include<string.h>
#define len 5
void input(struct student *p);
struct student * search(struct student *p,int *flag);
void output(struct student *p,int flag);
struct student
{
char name[20];
char ID[20];
char major[20];
int score;
};


int main(void)
{
struct student stu[len];
int flag=0;
struct student *p;
input(stu);
p=search(stu,&flag);
output(p,flag);
}


void input(struct student *p)
{
int i=0;
for(i=0;i<len;i++)
{
printf("�������%d��ѧ��������\n",i+1);
gets((p+i)->name);
printf("�������%d��ѧ����ѧ��\n",i+1);
gets((p+i)->ID);
printf("�������%d��ѧ����רҵ\n",i+1);
gets((p+i)->major);
printf("�������%d��ѧ���ķ���\n",i+1);
scanf("%d",&((p+i)->score));
getchar();
}
}


struct student * search(struct student *p,int *flag)
{
int i=0;
char Name[20];
printf("������Ҫ���ҵ�ѧ��������\n");
gets(Name);
for(i=0;i<len;i++)
{
if(strcmp(Name,(p+i)->name)==0)
{
*flag=1;
break;
}
}
return p+i;
}


void output(struct student *p,int flag)
{
if(flag==0)
{
printf("���޴���\n");
}
else
{
printf("%s %s %s %d\n",p->name,p->ID,p->major,p->score);
}
}