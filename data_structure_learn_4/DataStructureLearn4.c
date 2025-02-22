//循环链表:首位相接
/*
                --->4-->5--->
head-->1-->2-->3             6
                <---8<--7<---
问题一:如何证明链表有环
问题二:判断环的入口是几号节点
*/
/*
算法思路:结合循环链表的性质以及快慢指针的巧用
对于问题一:
    让快指针每次走2步,让慢指针每次走1步,如果有环形结构则快慢指针一定会重合
对于问题二:
    当快慢指针重合后,保持快指针不动,让慢指针再绕环走一圈,使其再次与快指针重合,同时记录走一圈的步数m
    之后将快慢指针归位到头节点head,让快指针提前走m步,之后快慢指针每次走1步,记录快慢指针重合时的步数n
    n号节点即环的入口
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node * link;
}Node;


Node * InitHead();
void CreateNode(Node * head,int amount,int num);
Node * FindEntrance(Node * head);


int main(void)
{
    int amount=0;
    int num=0;
    printf("请输入链表的节点个数(不计入头节点)\n");
    scanf("%d",&amount);
    printf("请输入环的入口节点号\n");
    scanf("%d",&num);
    Node * head=InitHead();
    CreateNode(head,amount,num);
    Node * entrance=FindEntrance(head);
    return 0;
}


Node * InitHead()       //初始化头节点
{
    Node * head=(Node *)calloc(1,sizeof(Node));
    head->link=NULL;
    return head;
}


void CreateNode(Node * head,int amount,int num)     //构建一个带环的链表
{   
    Node * pnum;
    for (int i=0;i<amount;i++)
    {
        int value=0;
        printf("请输入data的值\n");
        scanf("%d",&value);
        Node * p=head;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        Node * last=(Node *)calloc(1,sizeof(Node));
        if (i==num-1)
        {
            pnum=last;
        }
        last->data=value;
        p->link=last;
        if (i==amount-1)
        {
            last->link=pnum;
        }
        else
        {
            last->link=NULL;
        }
        
    }
}


Node * FindEntrance(Node * head)      //寻找环的入口节点
{
    Node * slow=head;
    Node * fast=head->link;
    while(fast!=NULL&&fast->link!=NULL)
    {
        slow=slow->link;
        fast=fast->link->link;
        if (slow==fast)
        {
            printf("具有环结构\n");
            break;
        }
    }


    slow=slow->link;
    int circle_step=1;
    while(slow!=fast)
    {
        slow=slow->link;
        circle_step+=1;
    }
    

    Node * newslow=head;
    Node * newfast=head;
    for (int i=0;i<circle_step;i++)
    {
        newfast=newfast->link;
    }
    int step=0;
    while(newslow!=newfast)
    {
        newslow=newslow->link;
        newfast=newfast->link;
        step+=1;
    }
    printf("环的入口节点是%d号\n",step);
    printf("其存放的data是%d\n",newslow->data);
    return newslow;
}