//线性表之链表


#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;
typedef struct node 
{
    ElemType data;
    struct node *next;
}Node;


Node * InitList();
void InsertHead(Node * L,ElemType e);
void ListNode(Node * L);
Node * InsertTail(Node * L,ElemType e);
Node * GetTail(Node * L);
void InsertNode(Node * L,int pos,ElemType e);
void DeleteNode(Node * L,int pos);
int NodeLength(Node * L);
void FreeList(Node * L) ;


int main(void)
{
    Node * list_head=InitList();
    InsertHead(list_head,5);
    InsertHead(list_head,2);
    InsertHead(list_head,0);
    ListNode(list_head);


    Node * head=InitList();
    Node * tail;
    tail=InsertTail(head,5);
    tail=InsertTail(tail,2);
    tail=InsertTail(tail,0);
    ListNode(head);


    InsertNode(head,3,1);
    ListNode(head);
    DeleteNode(head,3);
    ListNode(head);


    int len=NodeLength(head);
    printf("%d\n",len);

    
    FreeList(head);
    len=NodeLength(head);
    printf("%d\n",len);


    return 0;
}



Node * InitList()       //创建一个头节点
{
    Node * head=(Node *)calloc(1,sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}


void InsertHead(Node * L,ElemType e)        //头插法:最新的数据始终插入在头节点后面
{
    Node * p=(Node *)calloc(1,sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
}


void ListNode(Node * L)     //遍历链表:不输出头节点的信息
{
    Node * p=L->next;
    while(p!=NULL)
    {
        printf("%4d",p->data);
        p=p->next;
    }
    printf("\n");
}


Node * InsertTail(Node * L,ElemType e)      //尾插法:最新的数据始终插入在尾节点后面
{
    Node * p=(Node *)calloc(1,sizeof(Node));
    p->data=e;
    L->next=p;
    p->next=NULL;
    return p;       //将尾节点返回
}


Node * GetTail(Node * L)        //获取尾节点地址
{
    Node *p=L;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}


void InsertNode(Node * L,int pos,ElemType e)        //将数据插入链表指定位置
{
    Node * p=L;     //p是新增节点的前驱
    for (int i=0;i<pos-1;i++)
    {
        p=p->next;
        if (p==NULL)
        {
            printf("插入位置错误\n");
        }
    }
    Node * q=(Node *)calloc(1,sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
}


void DeleteNode(Node * L,int pos)       //删除链表指定位置的数据
{
    Node * p=L;
    for (int i=0;i<pos-1;i++)
    {
        p=p->next;
        if (p==NULL)
        {
            printf("插入位置错误\n");
        }
    }
    Node * q=p->next;
    p->next=q->next;        //删除节点的前驱指向后继
    free(q);        //释放删除节点的空间
}


int NodeLength(Node * L)        //计算链表长度(包括头节点)
{
    Node * p=L;
    int i=0;
    for (i=0;p!=NULL;i++)
    {
        p=p->next;
    }
    return i;
}


void FreeList(Node * L)     //释放链表(只保留头节点)
{
    Node * p=L->next;
    Node * q;
    if (p==NULL)
    {
        printf("已经完全释放了,无需重复操作\n");
    }
    else
    {
        while(p->next!=NULL)
        {
            q=p->next;
            free(p);
            p=q;
        }
        free(p);
        L->next=NULL;
    }
}