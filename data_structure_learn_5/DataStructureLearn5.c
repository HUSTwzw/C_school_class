//双向链表


#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;
typedef struct node 
{
    ElemType data;
    struct node * pre;
    struct node * next;
}Node;


Node * InitHead();
void InsertHead(Node * head,ElemType e);
void ShowInfo(Node * head);
void InsertTail(Node * head,ElemType e);
void InsertNode(Node * head,int num,ElemType e);
void DeleteNode(Node * head,int num);
void FreeList(Node * head);


int main (void)
{
    Node * head=InitHead();
    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head,3);
    ShowInfo(head);


    Node * newhead=InitHead();
    InsertTail(newhead,1);
    InsertTail(newhead,2);
    InsertTail(newhead,3);
    ShowInfo(newhead);


    InsertNode(newhead,3,6);
    InsertNode(newhead,5,4);
    ShowInfo(newhead);
    DeleteNode(newhead,5);
    DeleteNode(newhead,1);
    ShowInfo(newhead);


    FreeList(newhead);
    ShowInfo(newhead);
    return 0;
}


Node * InitHead()       //初始化头节点
{
    Node * head=(Node *)calloc(1,sizeof(Node));
    head->pre=NULL;
    head->next=NULL;
    return head;
}


void InsertHead(Node * head,ElemType e)     //头插法
{
    Node * p=(Node *)calloc(1,sizeof(Node));
    p->data=e;
    p->pre=head;
    p->next=head->next;
    if (head->next!=NULL)
    {
        head->next->pre=p;
    }
    head->next=p;
}


void ShowInfo(Node * head)      //遍历
{
    Node * p=head->next;
    while(p!=NULL)
    {
        printf("%4d",p->data);
        p=p->next;
    }
    printf("\n");
}


void InsertTail(Node * head,ElemType e)     //尾插法
{
    Node * tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node * p=(Node *)calloc(1,sizeof(Node));
    p->data=e;
    p->pre=tail;
    p->next=NULL;
    tail->next=p;
}


void InsertNode(Node * head,int num,ElemType e)        //在指定位置插入节点
{
    Node * p=head;
    for (int i=1;i<num;i++)
    {
        p=p->next;
    }
    Node * new=(Node *)calloc(1,sizeof(Node));
    new->data=e;
    if (p->next==NULL)
    {
        new->pre=p;
        new->next=NULL;
        p->next=new;
    }
    else
    {
        new->pre=p;
        new->next=p->next;
        p->next->pre=new;
        p->next=new;
    }
}


void DeleteNode(Node * head,int num)        //删除链表指定位置的节点
{
    Node * p=head;
    for (int i=1;i<=num;i++)
    {
        p=p->next;
    }
    if (p->next==NULL)
    {
        p->pre->next=NULL;
        free(p);
    }
    else
    {
        Node * pre_node=p->pre;
        Node * next_node=p->next;
        pre_node->next=next_node;
        next_node->pre=pre_node;
        free(p);
    }
}


void FreeList(Node * head)      //释放链表
{
    Node * p=head->next;
    Node * q;
    while(p->next!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(p);
    head->next=NULL;
}