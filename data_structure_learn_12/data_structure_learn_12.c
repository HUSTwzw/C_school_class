//在data_structure_learn_11中展示了如何利用递归进行前序、中序、后续遍历
//以下代码将以模拟栈的方式实现前序遍历,以此替代递归算法(借助栈通过普通循环替代递归)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 100


typedef struct TreeNode 
{
    char data;
    struct TreeNode * lchild;
    struct TreeNode * rchild;
}TreeNode;


typedef struct Stack
{
    TreeNode * p[MAXSIZE];
    int top;
}Stack;


void CreateTree(TreeNode ** root,char * str);
void FrontRun(TreeNode * node);
void StackRun(TreeNode * node,Stack * s);
void pop(Stack * s,TreeNode ** newnode);
void push(Stack * s,TreeNode * rnode);


int index=0;
int main(void)
{
    TreeNode ** root;
    char str[]="ABDH##I##EJ###CF##G##";
    CreateTree(root,str);
    FrontRun(*root);
    printf("\n");
    
    Stack * s=(Stack *)malloc(sizeof(Stack));
    s->top=0;
    StackRun(*root,s);
    
    return 0;
}


void CreateTree(TreeNode ** root,char * str)
{
    char ch=str[index++];
    if (ch=='#'||index>strlen(str))
    {
        * root=NULL;
        return ;
    }
    else
    {
        * root=(TreeNode *)malloc(sizeof(TreeNode));
        (* root)->data=ch;
        CreateTree(&((* root)->lchild),str);
        CreateTree(&((* root)->rchild),str);
    }
}


void FrontRun(TreeNode * node)
{
    if (node==NULL)
    {
        return ;
    }
    printf("%4c",node->data);
    FrontRun(node->lchild);
    FrontRun(node->rchild);
}  


void StackRun(TreeNode * node,Stack * s)
{   
    while (node !=NULL||s->top>0)
    {
        if (node==NULL)
        {
            while (s->top>0&&node==NULL)
            {
                pop(s,&node);
            }
            if (node==NULL)
            {
                break;
            }
        }
        printf("%4c",node->data);
        push(s,node->rchild);
        node=node->lchild;
    }   
}


void pop(Stack * s,TreeNode ** newnode)
{
    if (s>0)
    {   
        *newnode=s->p[--s->top];
    }
    else
    {
        *newnode=NULL;
    }
}   


void push(Stack * s,TreeNode * rnode)
{
    s->p[s->top++]=rnode;
}