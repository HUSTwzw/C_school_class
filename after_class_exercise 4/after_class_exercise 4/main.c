#include<stdio.h>
#define len 5
void input(char *p[],char str[len][100]);
void output(char *p[]);
char str[len][100]={"0"};
int main(void)
{
char *curriculum[len];
input(curriculum,str);
output(curriculum);
return 0;
}

void input(char *p[],char str[len][100])
{
int i=0;

for(i=0;i<len;i++)
{
printf("ÇëÊäÈë×Ö·û´®\n");
gets(*(str+i));
p[i]=*(str+i);
}

}


void output(char *p[])
{
int i=0;
for(i=0;i<len;i++)
{
printf("%s ",p[i]);
}
}