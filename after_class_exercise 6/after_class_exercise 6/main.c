//程序题目：查询学生信息并输出（使用函数返回结构体指针）
/*
查询前输入学生信息系统
查询时输入学生姓名
若姓名存在，输出一些列学生信息；若不存在，输出"查无此人"
要求函数返回值是结构体指针
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
printf("请输入第%d个学生的姓名\n",i+1);
gets((p+i)->name);
printf("请输入第%d个学生的学号\n",i+1);
gets((p+i)->ID);
printf("请输入第%d个学生的专业\n",i+1);
gets((p+i)->major);
printf("请输入第%d个学生的分数\n",i+1);
scanf("%d",&((p+i)->score));
getchar();
}
}


struct student * search(struct student *p,int *flag)
{
int i=0;
char Name[20];
printf("请输入要查找的学生的姓名\n");
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
printf("查无此人\n");
}
else
{
printf("%s %s %s %d\n",p->name,p->ID,p->major,p->score);
}
}