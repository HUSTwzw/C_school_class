/*
练习题目:用单链表保存n个整数,节点的结构包括data(int类型)和link,且data的绝对值小于等于n(n为正整数)
现要求设计一个时间复杂度尽可能高效的算法,对于链表中的data的绝对值相等的节点,仅保留第一次出现的节点而删除其余绝对值相等的节点
例如给定单链表:head->21->-15->-15->-7->15,最终保留head->21->-15->-7
*/


/*
以空间换时间的思想:
由于data的绝对值小于等于n,因此最终最多保留n+1个数,即除去头节点以外最多剩余n+1个节点
由于数据为整数,data的绝对值恰好与数组的序号产生联系,因此可以构建一个长度为n+1的数组作为查重表
查重原理如下:先将所有数组赋值为0,当遇到节点的某一个data,求其绝对值并寻找对应的数组,若数组元素为0则赋值为1,若为1则代表data的绝对值重复,删除该节点
通过该算法,时间复杂度为O(n)
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node * link;
}Node;


Node * InitHead();
void DeleteNode(Node *head,int n);
void CreateNode(Node * head,int num);
void ShowInfo(Node * head);


int main(void)
{
    int n=0;
    printf("请输入n的值\n");
    scanf("%d",&n);
    int num=0;
    printf("请输入数据节点个数\n");
    scanf("%d",&num);
    

    Node * head=InitHead();
    CreateNode(head,num);
    ShowInfo(head);
    DeleteNode(head,n);
    ShowInfo(head);
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


void DeleteNode(Node *head,int n)       //删除重复的节点
{
    int * p=(int *)calloc(1,sizeof(int)*(n+1));
    Node * front=head->link;
    Node * current=front->link;
    *(p+abs(front->data))=1;
    while(current!=NULL)
    {
        if (*(p+abs(current->data))==0)
        {
            *(p+abs(current->data))=1;
            front=current;
            current=current->link;
        }
        else if(*(p+abs(current->data))==1)
        {
            front->link=current->link;
            current->link=NULL;
            free(current);
            current=front->link;
        }
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