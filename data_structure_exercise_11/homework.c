//使用非递归方式复制二叉树


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


typedef struct Ostack
{
    TreeNode * op[MAXSIZE];
    int top;
}Ostack;


typedef struct Nstack
{
    TreeNode ** np[MAXSIZE];
    int top;
}Nstack;


void build(TreeNode ** root,char * str,int * index);
void front_run(TreeNode * node);
void central_run(TreeNode * node);


void copy(TreeNode * node,TreeNode ** firstnode,Ostack * os,Nstack * ns);
void Opush(TreeNode * node,Ostack * os);
void Npush(TreeNode ** copynode,Nstack * ns);
TreeNode * Opop(Ostack * os);
TreeNode ** Npop(Nstack * ns);
int main (void)
{
    TreeNode * root;
    int index=0;
    char str[]="ABDH##I##EJ###CF##G##";
    build(&root,str,&index);
    front_run(root);
    printf("\n");
    central_run(root);
    printf("\n");


    TreeNode * firstnode;
    Ostack os;
    Nstack ns;
    copy(root,&firstnode,&os,&ns);
    front_run(firstnode);
    printf("\n");
    central_run(firstnode);
    printf("\n");
}


void build(TreeNode ** root,char * str,int * index)
{   
    char ch=str[(*index)++];
    if (ch=='#'||*index>strlen(str))
    {
        *root=NULL;
        return ;
    }
    else
    {
        *root=(TreeNode *)calloc(1,sizeof(TreeNode));
        (*root)->data=ch;
        build(&((*root)->lchild),str,index);
        build(&((*root)->rchild),str,index);
    }
}


void front_run(TreeNode * node)
{
    if (node==NULL)
    {
        return ;
    }
    else
    {
        printf("%c",node->data);
        front_run(node->lchild);
        front_run(node->rchild);
    }
}


void central_run(TreeNode * node)
{
    if (node==NULL)
    {
        return ;
    }
    else
    {
        front_run(node->lchild);
        printf("%c",node->data);
        front_run(node->rchild);
    }
}


void copy(TreeNode * node,TreeNode ** firstnode,Ostack * os,Nstack * ns)
{
    TreeNode * copynode=(TreeNode *)calloc(1,sizeof(TreeNode));
    *firstnode=copynode;
    os->top=0;
    ns->top=0;
    

    while (node!=NULL||os->top>0)
    {
        if (node!=NULL)
        {
            copynode->data=node->data;
            if (node->rchild!=NULL)
            {
                Opush(node->rchild,os);
                Npush(&(copynode->rchild),ns);
            }
            else
            {
                copynode->rchild=NULL;
            }


            if (node->lchild!=NULL)
            {
                copynode->lchild=(TreeNode *)calloc(1,sizeof(TreeNode));
                copynode=copynode->lchild;
                node=node->lchild;
            }
            else
            {
                copynode->lchild=NULL;
                node=node->lchild;
            }
        }
        else
        {
            node=Opop(os);
            TreeNode ** npp=Npop(ns);
            *npp=(TreeNode *)calloc(1,sizeof(TreeNode));
            copynode=*npp;
        }
    }

}


void Opush(TreeNode * node,Ostack * os)
{
    os->op[os->top++]=node;
}


void Npush(TreeNode ** copynode,Nstack * ns)
{
    ns->np[ns->top++]=copynode;
}


TreeNode * Opop(Ostack * os)
{
    return os->op[--os->top];
}


TreeNode ** Npop(Nstack * ns)
{
    return ns->np[--ns->top];
}