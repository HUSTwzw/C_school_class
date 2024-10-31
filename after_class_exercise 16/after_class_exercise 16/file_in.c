

#include"student.h"
void f_input(void)
{
struct student * sp;
char address[40]="0";
printf("请输入文件的绝对路径\n");
gets(address);
fp=fopen(address,"w+");
sp=s_input();
fprintf(fp,"%s\t",sp->name);
fprintf(fp,"%s\t",sp->ID);
fprintf(fp,"%d\n",sp->score);
while(sp->pNext!=NULL)
{
sp=sp->pNext;
fprintf(fp,"%s\t",sp->name);
fprintf(fp,"%s\t",sp->ID);
fprintf(fp,"%d\n",sp->score);
}
fclose(fp);
}
