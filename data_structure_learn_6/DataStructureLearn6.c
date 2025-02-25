//栈:一种特殊的线性表(只能在栈顶进行压栈和出栈)
/*
栈的链式结构实现:本质就是单链表,但是要符合栈的性质(先进后出),首节点就是栈顶,尾节点就是栈底
压栈对应头插法,出栈对应删除首节点(头节点后面的第一个节点)
*/
//队列:一种先进先出的线性表(只允许在表的一端进行插入,在另一端删除元素)
/*
基本操作:入队,出队(每次入队rear就向后移动,每次出队front就向前移动)
*/


#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100
typedef int ElemType;
typedef struct stack 
{
    ElemType * data;
    int top;
}Stack;
typedef struct queue
{
    ElemType * data;
    int front;
    int rear;
}Queue;


Stack * InitStack();
void Push(Stack * s,ElemType e);
void Pop(Stack * s);
void GetTop(Stack * s,ElemType * e);
void ShowInfo(Stack * s);


Queue * InitQueue();
int IsEmpty(Queue * q);
void Dequeue(Queue * q,ElemType * e);
void Equeue(Queue * q,ElemType e);


int main(void)
{
    Stack * s=InitStack();
    Push(s,5);
    Push(s,2);
    Push(s,0);
    ShowInfo(s);
    Pop(s);
    ShowInfo(s);
    ElemType top;
    ElemType * e=&top;
    GetTop(s,e);
    printf("%d\n",*e);
    
    
    Queue * q=InitQueue();
    ElemType tail;
    ElemType * ee=&tail;
    Equeue(q,5);
    printf("Is Empty:%d\n",IsEmpty(q));
    Equeue(q,2);    
    Dequeue(q,ee);
    Dequeue(q,ee);
    printf("Is Empty:%d",IsEmpty(q));
    

    return 0;
}


Stack * InitStack()     //栈的初始化
{
    Stack * s=(Stack *)calloc(1,sizeof(Stack));
    s->data=(ElemType *)calloc(1,sizeof(ElemType)*MAXSIZE);
    s->top=-1;
    return s;
}


void Push(Stack * s,ElemType e)     //压栈
{
    if (s->top>=MAXSIZE-1)
    {   
        printf("栈已经满了\n");
    }
    else
    {
        s->top+=1;
        *(s->data+s->top)=e;
    }
}


void Pop(Stack * s)     //出栈
{
    if (s->top<0)
    {
        printf("栈是空的\n");
    }
    else
    {
        s->top-=1;      //和顺序表原理一样,不必真正删除对应空间的数据,只需要将栈顶减小即可
    }
}


void GetTop(Stack * s,ElemType * e)     //获取栈顶数据
{
    if (s->top<0)
    {
        printf("栈是空的\n");
    }
    else
    {   
        *e=*((s->data)+s->top);
    }
}   


void ShowInfo(Stack * s)        //遍历
{
    for (int i=0;i<=s->top;i++)
    {   
        printf("%4d",*(s->data+i));
    }
    printf("\n");
}


Queue * InitQueue()     //队列的初始化
{
    Queue * q=(Queue *)calloc(1,sizeof(Queue));
    q->front=0;
    q->rear=0;
    q->data=(ElemType *)calloc(1,sizeof(Queue)*MAXSIZE);
    return q;
}


int IsEmpty(Queue * q)      //判断队列是否是空的
{
    if (q->front==q->rear)
    {
        printf("队列是空的\n");
        return 1;
    }
    else 
    {
        return 0;
    }
}


void Dequeue(Queue * q,ElemType * e)        //出队
{
    if (IsEmpty(q))
    {
        printf("队列是空的\n");
    }
    else 
    {
        *e=*(q->data+q->front);
        q->front+=1;
    }
}


void Equeue(Queue * q,ElemType e)       //入队
{
    if (q->rear>=MAXSIZE)
    {
        if (q->front>0)
        {
            int step=q->front;
            for (int i=q->front;i<q->rear;i++)
            {
                *(q->data+i-step)=*(q->data+i);
            }
            q->front=0;
            q->rear-=step;
        }
        else
        {
            printf("存储已达上限\n");
        }
    }
    else
    {
        *(q->data+q->rear)=e;
        q->rear+=1;
    }
}