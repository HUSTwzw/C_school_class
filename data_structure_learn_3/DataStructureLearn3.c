/*
单链表应用之反转链表
例子:head->1->2->3->4->5->6经过反转变为NULL<-1<-2<-3<-4<-5<-6<-head
过程:
创建三个指针first,second,third
初始时first指向NULL,second指向节点1,third指向节点2
second指向first所指向的NULL
之后first、second、third统一向后移动(second的移动借助third,first的移动借助second),且每一次移动后再用second指向first
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node * link;
}Node;


Node * InitHead();
void CreateNode(Node * head,int num);
void ShowInfo(Node * head);
Node * ReverseNode(Node * head);
void Delete(Node * head);


int main(void)
{
    int num=0;
    printf("请输入数字链表的长度(不包括头节点)\n");
    scanf("%d",&num);
    Node * head=InitHead();
    CreateNode(head,num);
    ShowInfo(head);
    Node * newhead=ReverseNode(head);
    ShowInfo(newhead);
    if (num%2==1)
    {
        Delete(newhead);
        ShowInfo(newhead);
    }
    return 0;
}


Node * InitHead()       //初始化头节点
{
    Node * head=(Node *)calloc(1,sizeof(Node));
    head->link=NULL;
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
        while(p->link!=NULL)
        {
            p=p->link;
        }
        Node * last=(Node *)calloc(1,sizeof(Node));
        last->data=e;
        p->link=last;
        last->link=NULL;
    }
}


void ShowInfo(Node * head)      //遍历
{
    Node * p=head->link;
    while(p!=NULL)
    {
        printf("%4d",p->data);
        p=p->link;
    }
    printf("\n");
}


Node * ReverseNode(Node * head)     //反转链表
{
    Node * first=NULL;
    Node * second=head->link;
    Node * third=second->link;

    second->link=first;

    while(third!=NULL)
    {
        first=second;
        second=third;
        third=third->link;
        second->link=first;
    }

    Node * newhead=(Node *)calloc(1,sizeof(Node));
    newhead->link=second;
    return newhead;
}




/*
单链表应用之删除链表中间节点(链表数值节点个数为奇数)
*/
                   

void Delete(Node * head)        //删除链表中间节点的函数
{
    Node * fast=head->link;     //快慢指针新用法
    Node * slow=head;
    while(fast->link!=NULL)
    {
        fast=fast->link->link;
        slow=slow->link;
    }
    Node *  q=slow->link;
    slow->link=q->link;
    free(q);
}