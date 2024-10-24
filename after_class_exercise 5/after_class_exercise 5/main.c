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
printf("请输入书名\n");
gets((p+i)->name);//等效为gets((*(p+i)).name)，也等效为gets(bok[i].name)
printf("请输入种类\n");
gets((p+i)->category);
printf("请输入价格\n");
scanf("%d",&((p+i)->price));//必须加上&
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