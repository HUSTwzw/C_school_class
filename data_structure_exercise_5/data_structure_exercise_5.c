//队列应用:表达式求值
/*
中缀表达式          后缀表达式
5+6*3               563*+
b*c/d               bc*c/
(5+6)*7             56+7*
x/y-z+i*j-x*y       xy/z-ij*+xy*-
x*y-6               xy*6-
*/


//枚举(学习表达式求值前的补充知识)
/*
将变量的值一一列出来,枚举的值仅限于列出来的值
枚举中列出的每一个值称为枚举元素,
枚举元素用系统定义了一个序号表示数值,从0开始,分别为0,1,2,……
*/


//关于枚举的例子和讲解
typedef enum weekday        //WeekDay类型的变量只能赋mon-sun的值,对应的值为0-6
{
    mon,tue,wed,thu,fri,sat,sun     
}WeekDay;    


typedef enum weekday2       //WeekDay2类型的变量只能赋mon-sun的值,对应的值为1-7
{
    mon2=1,tue2,wed2,thu2,fri2,sat2,sun2        
}WeekDay2;
//注意:mon,tue,wed……这些只是元素的名字,实际存储的是0,1,2,……的值


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 100
typedef char Elemtype;
typedef struct stack        //动态规划版栈结构
{
    Elemtype * data;
    int top;
}Stack;


typedef enum        //创建一个关于运算的枚举类型
{
    Left_Pare,Right_Pare,Add,Sub,Mul,Div,Mod,Eos,Num        //左括号,右括号,加,减,乘,除,取余,'\0',数字
}ContentType;


void Push(Stack * p,Elemtype e);
Elemtype Pop(Stack * p);
Elemtype Result(Stack * p,char * q);
ContentType Gettoken(char value);
ContentType * Process(char * q);
char * Produce(Stack * p,char * q,ContentType * cal_str);


int main(void)
{
    WeekDay date;       //创建一个枚举类型的变量date
    date=wed;       //给date赋值(值来源于WeekDay列出的元素)
    printf("%d\n",date);


    WeekDay2 date2;
    date2=wed2;
    printf("%d\n",date2);


    Stack * p=(Stack *)calloc(1,sizeof(Stack));
    p->data=(Elemtype *)calloc(MAXSIZE,sizeof(Elemtype));
    p->top=0;


    char calculation[]="82/2+56*-";
    Elemtype result=Result(p,calculation);
    printf("%d\n",result);


    Stack * p2=(Stack *)calloc(1,sizeof(Stack));
    p2->data=(Elemtype *)calloc(MAXSIZE,sizeof(Elemtype));
    p2->top=0;


    char infix[]="6/2-1+2*3-2*5";
    ContentType * cal_str=Process(infix);
    char * suffix=Produce(p2,infix,cal_str);
    printf("%s\n",suffix);
    Elemtype result2=Result(p2,suffix);
    printf("%d\n",result2);



    Stack * p3=(Stack *)calloc(1,sizeof(Stack));
    p3->data=(Elemtype *)calloc(MAXSIZE,sizeof(Elemtype));
    p3->top=0;


    char infix2[]="5*(6-2)+3*2-6*(7-3)/3+5";
    ContentType * cal_str2=Process(infix2);
    char * suffix2=Produce(p3,infix2,cal_str2);
    printf("%s\n",suffix2);
    Elemtype result3=Result(p3,suffix2);
    printf("%d",result3);

    return 0;
}


//任务一:求后缀表达式的值(后缀表达式是计算机的计算逻辑,是给计算机看的,不是给人看的)
//简单模型:op1(操作数1)   symbol(操作符号)    op2(操作数2)    =   值
//注意:以下代码是简化版(操作数在1-9之内,同时运算只包含最简单的加减乘除,主要通过代码体验计算机运算过程)      以"82/2+56*-"为例
//注意:我在代码中没有使用枚举,枚举只作为补充知识,当数据种类较少且相对确定时,可以考虑使用枚举的数据类型


void Push(Stack * p,Elemtype e)     //压栈
{
    *(p->data+p->top)=e;
    p->top+=1;
}


Elemtype Pop(Stack * p)     //出栈
{
    p->top-=1;
    return *(p->data+p->top);
}


Elemtype Result(Stack * p,char * q)
{
    Elemtype op2;
    Elemtype op1;
    for (int i=0;;i++)
    {
        switch(*(q+i))
        {
            case '+':       //对应加运算
                op2=Pop(p);
                op1=Pop(p);
                Push(p,op1+op2);
                break;
            case '-':       //对应减运算
                op2=Pop(p);
                op1=Pop(p);
                Push(p,op1-op2);
                break;
            case '*':       //对应乘运算
                op2=Pop(p);
                op1=Pop(p);
                Push(p,op1*op2);
                break;
            case '/':       //对应除运算
                op2=Pop(p);
                op1=Pop(p);
                Push(p,op1/op2);
                break;
            case '\0':      //对应后缀表达式的结尾
                Elemtype result=Pop(p);
                return result;
            default:        //对应操作数
                Push(p,*(q+i)-'0');     //ascii码值转换为计算的数值
                break;
        }
    }
}


//任务二:将中缀表达式转化为后缀表达式
//中缀转化为前缀的难点在于符号以及符号之间的优先级(包括处理括号)
/*
处理逻辑:
最开始在栈底放一个优先级最低的无意义的字符
如果是操作数直接输出
如果是运算符,判断优先级,如果优先级大于栈顶元素,压入栈中,否则(优先级小于等于栈顶元素)将栈顶元素输出,直到当前运算符的优先级大于栈顶元素,然后将当前运算符压入栈中
当左括号在栈外时,属于最高优先级,当左括号在栈里时,属于最低优先级
如果是右括号,且栈顶元素不是左括号,持续出栈并输出,直到栈顶为左括号出栈结束,最后将左括号也出栈
遇到'\0'表示到达结尾,将栈中元素依次输出,使栈中只剩那个优先级最低的无意义的字符
如此就能实现中缀表达式转换为后缀表达式
*/
//注意:此处将巧妙使用枚举


ContentType Gettoken(char value)
{
    switch(value)
    {
        case '(':
            return Left_Pare;
        case ')':
            return Right_Pare;
        case '+':
            return Add;
        case '-':
            return Sub;
        case '*':   
            return Mul;
        case '/':
            return Div;
        case '%':
            return Mod;
        case '\0':
            return Eos;
        default:
            return Num;
    }
}


ContentType * Process(char * q)
{   
    ContentType * cal_str=(ContentType *)calloc(strlen(q)+1,sizeof(Left_Pare));     //注意开辟的空间的长度要包括'\0'   
    for (int i=0;i<strlen(q)+1;i++)     
    {
        cal_str[i]=Gettoken(*(q+i));
    }
    return cal_str;
}


char * Produce(Stack * p,char * q,ContentType * cal_str)
{
    int in_stack[]={0,19,12,12,13,13,13,0,-1};      //栈内优先级
    int out_stack[]={20,19,12,12,13,13,13,0,-1};        //栈外优先级
    int length=strlen(q)+1;     //注意开辟的空间的长度要包括'\0' 
    char * suffix=(char *)calloc(2*length,sizeof(char));        //创建一个大空间,防止越界
    Push(p,-1);      //先在栈底放入一个无意义的最低优先级数
    int pos=0;

    for (int i=0;i<length;i++)
    {
        char current_char=q[i];
        ContentType current_token=cal_str[i];
        if (current_token==Num)
        {
            suffix[pos++]=current_char;     
        }
        else
        {   
            if (Gettoken(current_char)==Right_Pare)     //处理右括号
            {
                while(p->top>1)
                {
                    char top_char=Pop(p);
                    if (Gettoken(top_char)==Left_Pare)
                    {
                        break;
                    }
                    else
                    {
                        suffix[pos++]=top_char;
                    }
                }
            }


            else
            {
                while(out_stack[current_token]<=in_stack[Gettoken(*(p->data+p->top-1))]&&p->top>1)
                {
                    char top_char=Pop(p);
                    suffix[pos++]=top_char;
                    
                }
                Push(p,q[i]);
            }
        }
    }
    

    return suffix;
}