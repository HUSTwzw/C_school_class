//练习题目:使用递归操作对串进行求逆操作
/*
对于求逆操作,每次将字符串拆分为第一个字符和剩余字符串,之后对剩余字符串进行求逆操作,之后再将第一个字符串放置在最后面
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * Reverse(char *str);
int main(void)
{
    char origin[]="hello world , never give up !";
    char * reverse=Reverse(origin);
    printf("%s\n",origin);
    printf("%s\n",reverse);
    return 0;
}


char * Reverse(char * str)
{
    if (strlen(str)<=1)
    {
        char * result=(char *)calloc(strlen(str)+1,sizeof(char));
        strcpy(result,str);
        return result;
    }
    else
    {
        char * reverse_sub=Reverse(str+1);
        char * reverse_full=(char *)calloc(strlen(str)+1,sizeof(char));
        strcpy(reverse_full,reverse_sub);
        int sub_len=strlen(reverse_sub);
        reverse_full[sub_len]=str[0];
        reverse_full[sub_len+1]='\0';
        free(reverse_sub);
        return reverse_full;
    }
}