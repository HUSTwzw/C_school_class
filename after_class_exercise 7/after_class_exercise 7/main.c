//������Ŀ����������
/*
����ѧ�������Լ�ѧ��
����Ҫ�˳�����ģ�����ѧ�Ŵ�����0
������е�ѧ����Ϣ(�����Լ�ѧ��)
������ķ�ʽ��ɳ���Ҫ��
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
p=CREAT();//���ܻ��о���C4133   "="��"student *"��"studnet *"�����Ͳ�����,���Ժ���
OUTPUT(p);//���ܻ��о���C4133   "����":��"studnet *"��"student *"�����Ͳ�����,���Ժ���	
return 0;
}


int count=0;//����ȫ�ֱ�������ʾ������
struct student* CREAT(void)
{
struct student *pNew;//ָ���½��ĵ�ַ
struct student *pEnd;//ָ����һ�����ĵ�ַ
struct student *pHead=NULL;//ͷָ��
pEnd=pNew=(struct student*)malloc(sizeof(struct student));
printf("����������\n");
scanf("%s",&(pNew->name));
printf("������ID��\n");
scanf("%d",&(pNew->ID));
while(pNew->ID!=0)
{
count++;
if(count==1)
{
pNew->pNext=NULL;//��ÿһ���´����Ľ���pNext����ָ��NULL
pEnd=pNew;//pNewָ���´����Ľ��ĵ�ַ��pEndָ����һ�����ĵ�ַ���������ǵ�һ�������Ľ�㣬���pEnd=pNew
pHead=pNew;//ͷָ��ָ���һ�����
}
else
{
pEnd->pNext=pNew;//��һ������pNextָ���½��
pNew->pNext=NULL;//�½���pNextָ��NuLL
pEnd=pNew;//pEndָ���½ڵ㣬��ζ����һ�δ������ʱ������ͱ��"��һ�����"(��ǰ���½��������һ�����Ĵ�������ɾɽ��)
}
pNew=(struct student*)malloc(sizeof(struct student));
printf("����������\n");
scanf("%s",&(pNew->name));
printf("������ID��\n");
scanf("%d",&(pNew->ID));
}
free(pNew);//����ѭ��ʱ���ഴ����һ����㣬����free()�����ͷŸ��ڴ�
return pHead;
}


void OUTPUT(struct student*pHead)
{
struct student *p;
int number=0;
printf("---�ܹ���%d����---\n",count);
for(p=pHead,number=1;p!=NULL;number++)
{
printf("��%d��ͬѧ����Ϣ:",number);
printf("%s  ",p->name);
printf("%d\n",p->ID);
p=p->pNext;
}
}