//二叉树的链式结构以及遍历
//前序遍历:DLR
//中序遍历:LDR
//后序遍历:LRD
//已知前序遍历和中序遍历,可以唯一确定一棵二叉树;已知中序遍历和后序遍历,可以唯一确定一棵二叉树;已知前序遍历和后序遍历,不能确定一棵二叉树


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char Elemtype;
typedef struct TreeNode
{
    Elemtype data;
    struct TreeNode * lchild;
    struct TreeNode * rchild;
}TreeNode;


void CreateTree(TreeNode ** root,char * str);
void front_run(TreeNode * root);
void central_run(TreeNode * root);
void rear_run(TreeNode * root);
int index=0;
int main(void)
{
    TreeNode ** root1;
    char str[]="ABDH##I##EJ###CF##G##";
    CreateTree(root1,str);      //创建后整棵树的根为A
    front_run(*root1);
    printf("\n");
    central_run(*root1);
    printf("\n");
    rear_run(*root1);
    return 0;
}


void CreateTree(TreeNode ** root,char * str)        //创建二叉树(前序型创建)
{   

    char ch=str[index++];
    if (index>strlen(str)||ch=='#')
    {
        *root=NULL;
    }
    else
    {
        * root=(TreeNode *)malloc(sizeof(TreeNode));
        (* root)->data=ch;
        CreateTree(&((* root)->lchild),str);
        CreateTree(&((* root)->rchild),str);
    }
}


void front_run(TreeNode * root)     //前序遍历:DLR
{
    if (root==NULL)
    {
        return ;
    }
    printf("%c",root->data);
    front_run(root->lchild);
    front_run(root->rchild);
}


void central_run(TreeNode * root)       //中序遍历:LDR
{
    if (root==NULL)
    {
        return ;
    }
    central_run(root->lchild);
    printf("%c",root->data);
    central_run(root->rchild);
}


void rear_run(TreeNode * root)      //后序遍历:LRD
{
    if (root==NULL)
    {
        return ;
    }
    central_run(root->lchild);
    central_run(root->rchild);
    printf("%c",root->data);
}