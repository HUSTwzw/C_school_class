/*
练习题目:已知一个带有表头结点的单链表,节点结构为data(数据)和link(连接功能指针)
假设该链表只给出了头指针list,在不改变链表的前提下,请设计一个尽可能高效的算法,
实现如下功能:查找链表中倒数第k个位置的节点(k为正整数),若查找成功输出data并返回1,否则返回0
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef int ElemType;
typedef struct node     
{
    ElemType data;
    struct node * link;
}Node;


Node * InitNode(int length);
int SearchNode(Node * head,int pos);
void ShowNode(Node * head);


int main(void)
{
    int length=0;
    scanf("%d",&length);
    Node * list=InitNode(length);


    ShowNode(list);


    int pos=0;
    scanf("%d",&pos);
    int num=SearchNode(list,pos);
    printf("%d\n",num);
    return 0;
}


Node * InitNode(int length)     //初始化
{
    Node * head=(Node *)calloc(1,sizeof(Node));
    head->data=0;
    head->link=NULL;


    srand(time(NULL));
    Node * front =head;
    for (int i=0;i<length;i++)
    {
        Node * new=(Node *)calloc(1,sizeof(Node));
        front->link=new;
        new->data=rand()%10;
        new->link=NULL;
        front=new;
    }


    return head;   
}


void ShowNode(Node * head)      //遍历
{
    Node * p=head->link;
    while(p!=NULL)
    {
        printf("%4d",p->data);
        p=p->link;
    };
    printf("\n");
}


int SearchNode(Node * head,int pos)
{
    
    Node * slow=head->link;     //设置慢指针
    Node * fast=head->link;     //设置快指针
    for (int i=0;i<pos;i++)     //让快指针提前走pos步
    {
        if (fast==NULL)
        {
            return 0;       //如果pos数值有问题,提前退出并报错
        }
        fast=fast->link;
    }
    while(fast!=NULL)
    {
        slow=slow->link;
        fast=fast->link;
    }
    printf("%d\n",slow->data);
    return 1;
}