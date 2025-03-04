//在循环队列中rear=(rear+1)%MAXSIZE,front=(front+1)%MAXSIZE,但是当rear==front时不确定是队列满还是队列空
//基于上述问题,有如下循环队列判断队列空满的三种实现方式:
/*
1.方式一:
    在结构体中额外添加一个长度变量,用于储存当前栈的使用空间
2.方式二:
    在结构体中额外添加一个tag标签,tag==0表示空,tag==1表示满,每次进栈将tag置1,每次出栈将tag置0
3.方式三:
    牺牲栈的一个空间,front指向栈头,rear指向栈尾的下一个元素
    当(rear+1)%MAXSIZE==front表示rear的下一个位置就是front,此时证明栈已经满了
    当rear==front表示front已经退到栈外,即栈的最后一个元素已经被弹出,因此栈是空的
*/
//注意:关于代码将只展示三种方式的结构体以及相关入队出队的函数


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20


typedef struct stack1
{
    int * data;
    int front;
    int rear;
    int length;
}Stack1;


typedef struct stack2
{
    int * data;
    int front;
    int rear;
    int flag;
}Stack2;


typedef struct stack3
{
    int * data;
    int front;
    int rear;
}Stack3;


int main(void)
{
    
    return 0;
}


void Enqueue1(Stack1 * p,int e)
{
    if (p->length==MAXSIZE)
    {
        printf("满了\n");
    }
    else
    {
        p->data[p->rear]=e;
        p->rear=(p->rear+1)%MAXSIZE;
        p->length+=1;
    }
}


void Dequeue1(Stack1 * p,int * r)
{
    if (p->length==0)
    {
        printf("空了\n");
    }
    else
    {
        *r=p->data[p->front];
        p->front=(p->front+1)%MAXSIZE;
    }
}


void Enqueue2(Stack2 * p,int e)
{
    if (p->rear==p->front&&p->flag==1)
    {
        printf("满了\n");
    }
    else
    {
        p->data[p->rear]=e;
        p->rear=(p->rear+1)%MAXSIZE;
        p->flag=1;   
    }
}


void Dequeue2(Stack2 * p,int * r)
{   
    if (p->rear==p->front&&p->flag==0)
    {
        printf("空了\n");
    }
    else
    {
        *r=p->data[p->front];
        p->front=(p->front+1)%MAXSIZE;
    }
}


void Enqueue3(Stack3 * p,int e)
{
    if ((p->rear+1)%MAXSIZE==p->front)
    {
        printf("满了\n");
    }
    else
    {
        p->data[p->rear]=e;
        p->rear=(p->rear+1)%MAXSIZE;
    }
}


void Dequeue3(Stack3 * p,int * r)
{   
    if (p->rear==p->front)
    {
        printf("空了\n");
    }
    else
    {
        *r=p->data[p->front];
        p->front=(p->front+1)%MAXSIZE;
    }
}