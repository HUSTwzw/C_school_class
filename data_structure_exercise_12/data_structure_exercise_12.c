//按行输出树


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TreeNode 
{
    char data;
    struct TreeNode * lchild;
    struct TreeNode * rchild;
}TreeNode;


void CreateNode(TreeNode ** root,char * str,int * index);
void front_run(TreeNode * node);
void row_run(TreeNode * root);
void queue_run(TreeNode * root);
int Check(TreeNode * root);
int main(void)
{
    char str[]="ABDH##I##EJ###CF##G##";
    int index=0;
    TreeNode * root;
    CreateNode(&root,str,&index);
    front_run(root);
    printf("\n");
    row_run(root);
    queue_run(root);
    int outcome=Check(root);
    printf("%d",outcome);
    return 0;    
}


void CreateNode(TreeNode ** root,char * str,int * index)        //创建树
{   
    char ch=str[(*index)++];
    if (ch=='#'||*index>strlen(str))
    {
        *root=NULL;
    }
    else
    {
        *root=(TreeNode *)calloc(1,sizeof(TreeNode));
        (*root)->data=ch;
        CreateNode(&((*root)->lchild),str,index);
        CreateNode(&((*root)->rchild),str,index);
    }
}


void front_run(TreeNode * node)     //前序输出
{
    if(node==NULL)
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


void row_run(TreeNode * root)       //使用双数组按行输出树的结点
{
    int max_index=0;
    int index_num=1;
    TreeNode ** cur_t=(TreeNode **)calloc(1,sizeof(TreeNode *));
    TreeNode ** new_t=(TreeNode **)calloc(2,sizeof(TreeNode *));
    cur_t[0]=root;
    while (index_num>0)
    {
        max_index=index_num*2;
        index_num=0;
        for (int i=0;i<(max_index/2);i++)
        {
            TreeNode * node=cur_t[i];
            if (node!=NULL)
            {
                printf("%4c",node->data);
            }
            if (node->lchild!=NULL)
            {
                new_t[index_num++]=node->lchild;
            }
            if (node->rchild!=NULL)
            {
                new_t[index_num++]=node->rchild;
            }
        }
        printf("\n");
        TreeNode ** temp=cur_t;
        cur_t=new_t;
        new_t=(TreeNode **)calloc(index_num*2,sizeof(TreeNode *));
        free(temp);
    }
}


void queue_run(TreeNode * root)     //使用队列方法按行输出树的结点
{
    TreeNode ** t=(TreeNode **)calloc(100,sizeof(TreeNode *));
    int front=0;
    int rear=0;
    t[rear++]=root;
    while(front<rear)
    {
        int node_num=rear-front;
        for (int i=0;i<node_num;i++)
        {
            TreeNode * node=t[front++];
            printf("%4c",node->data);
            if (node->lchild!=NULL)
            {   
                t[rear++]=node->lchild;
            }
            if (node->rchild!=NULL)
            {
                t[rear++]=node->rchild;
            }
        }
        printf("\n");
    }
}


int Check(TreeNode * root)      //判断树是否是完全二叉树(利用队列思想解决)
{
    TreeNode ** tn=(TreeNode **)calloc(100,sizeof(TreeNode *));
    int front=0;
    int rear=0;
    tn[rear++]=root;
    int has_null=0;
    while (front<rear)
    {
        TreeNode * node=tn[front++];
        if (node==NULL)
        {
            has_null=1;
        }
        else
        {
            if (has_null==1)        //如果非空结点前面有NULL则不为完全二叉树
            {
                free(tn);
                return -1;
            }
            else
            {
                tn[rear++]=node->lchild;
                tn[rear++]=node->rchild;
            }
        }
    }
    free(tn);
    return 0;
}