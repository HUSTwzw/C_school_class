#include<stdio.h>
void input(struct book *p);
void output(struct book *p);
struct book
{
char name[20];
char category[20];
int price;
};
int main(void)
{
struct book bok[3];
input(bok);
output(bok);
return 0;
}


void input(struct book *p)
{
int i=0;
for(i=0;i<3;i++)
{
printf("����������\n");
gets((p+i)->name);//��ЧΪgets((*(p+i)).name)��Ҳ��ЧΪgets(bok[i].name)
printf("����������\n");
gets((p+i)->category);
printf("������۸�\n");
scanf("%d",&((p+i)->price));//�������&
getchar();
}
}


void output(struct book *p)
{
int i=0;
for(i=0;i<3;i++)
{
printf("%s ",(p+i)->name);
printf("%s ",(p+i)->category);
printf("%d ",(p+i)->price);
printf("\n");
}
}