//在DataStructureLearn3中学习了反转链表以及如何寻找中间节点,一下练习将结合这两个知识
/*
练习题目:设线性表L=(a1,a2,a3……an-2,an-1,an)采用带头结点的单链表保存,链表定义如下:
typedef struct node 
{
int data;
struct node * next;
}Node;
请设计一个空间复杂度为O(1)且时间上尽可能高效的算法,重新排列L中的各节点,得到线性表L'=(a1,an,a2,an-1,a3,an-2,……)
*/
//算法思路:大体上将链表从中间位置一分为二,将链表后一段反转,最终"见缝插针"(后一段链表节点依次有序插入到前一段链表中)
//注意:此代码具有难度,需要深度思考


#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node * next;
}Node;


Node * InitHead();
void CreateNode(Node * head,int num);
void ShowInfo(Node * head);
void RebuildNode(Node * head);

int main(void)
{
    int num=0;
    printf("请输入数字链表的长度(不包括头节点)\n");
    scanf("%d",&num);
    Node * head=InitHead();
    CreateNode(head,num);
    ShowInfo(head);
    RebuildNode(head);
    ShowInfo(head);
    return 0;
}


Node * InitHead()       //初始化头节点
{
    Node * head=(Node *)calloc(1,sizeof(Node));
    head->next=NULL;
    return head;
}


void CreateNode(Node * head,int num)        //创建节点
{
    for (int i=0;i<num;i++)
    {
        int e=0;
        printf("请输入data\n");
        scanf("%d",&e);
        Node * p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        Node * last=(Node *)calloc(1,sizeof(Node));
        last->data=e;
        p->next=last;
        last->next=NULL;
    }
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


void RebuildNode(Node * head)
{
    int length=0;       //用于判断数字节点个数的奇偶性
    Node * slow=head;
    Node * fast=head->next;
    while(fast!=NULL&&fast->next!=NULL)     //经过循环后slow已经确定了中间位置
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    if (fast==NULL)
    {
       length=2;        //偶数:此时前后两端链表的节点数相同(不计入头节点)
    }
    else if (fast->next==NULL)
    {
        length=1;       //奇数
        slow=slow->next;        //确保前一段链表的节点数刚好比后一段多一个
    }


    Node * first=NULL;
    Node * second=slow->next;
    Node * third=NULL;
    slow->next=NULL;        //将链接中间节点的链子断开
    while(second!=NULL)     //经过循环后成功反转后一段链表
    {
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }


    Node * p1=head->next;
    Node * p2;
    Node * q1=first;
    Node * q2;
    while(p1!=NULL&&q1!=NULL)
    {
        p2=p1->next;
        q2=q1->next;
        p1->next=q1;
        q1->next=p2;
        p1=p2;
        q1=q2;
    }
}