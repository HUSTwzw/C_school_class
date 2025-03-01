/*练习题目:
有三种符号:圆括号,方括号,花括号,彼此可以嵌套
设计算法检验所给字符串能否实现括号配对------栈
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 50
typedef struct stack
{
    char data[MAXSIZE];
    int top;
}Stack;

void Push(Stack * p,char string);
char Pop(Stack * p);
int Check(Stack * p,char * str);


int main(void)
{
    Stack * p=(Stack *)calloc(1,sizeof(Stack));
    char str[]="[{325}]3[5]6(3)2{22(56)7[4]}";
    char str2[]="5[{534}]534[6)34]({(11)1[3]}";
    int outcome=Check(p,str);
    int outcome2=Check(p,str2);
    printf("%d\n",outcome);
    printf("%d\n",outcome2);
    return 0;
}


void Push(Stack * p,char string)
{
    *(p->data+p->top)=string;
    p->top+=1;
}


char Pop(Stack * p)
{
    char string=*(p->data+p->top-1);
    p->top-=1;
    return string;
}


int Check(Stack * p,char * str)
{
    int length=strlen(str);
    int flag=0;
    for (int i=0;i<length;i++)
    {
        if (*(str+i)==')')
        {
            while(p->top>0)
            {
                char str=Pop(p);
                if (str=='(')
                {
                    flag=1;
                    break;
                }
            }
            if (flag==1)
            {
                flag=0;
            }
            else
            {
                return -1;
            }
            
        }
        else if (*(str+i)==']')
        {
            while(p->top>0)
            {
                char str=Pop(p);
                if (str=='[')
                {
                    flag=1;
                    break;
                }
            }
            if (flag==1)
            {
                flag=0;
            }
            else
            {
                return -1;
            }
        }
        else if (*(str+i)=='}')
        {
            while(p->top>0)
            {
                char str=Pop(p);
                if (str=='{')
                {
                    flag=1;
                    break;
                }
            }
            if (flag==1)
            {
                flag=0;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            Push(p,*(str+i));
        }
    }
    return 0;
}