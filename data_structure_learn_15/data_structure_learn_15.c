//选择排序
/*
简单选择排序
锦标赛排序
堆排序
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


typedef struct Node
{
    int value;
    int index;
    struct Node * left;
    struct Node * right;
    int isleaf;
}Node;


void select_sort1(int * array,int len);
void select_sort2(int * array,int len);
Node * create_leaf(int value,int index);
Node * link_node(Node * left,Node * right);
Node * build_tree(Node ** nodes,int l,int r);
void update(Node * root,int index,int new_value);
int main(void)
{
    srand((int)time(NULL));
    int * array=(int *)calloc(10,sizeof(int));
    for (int i=1;i<10;i++)
    {
        array[i]=rand()%100;
    }
    //select_sort1(array,10);
    select_sort2(array,10);
    for (int i=1;i<10;i++)
    {
        printf("%4d",array[i]);
    }
    printf("\n");
    return 0;
}


void select_sort1(int * array,int len)      //简单选择排序
{
    for (int i=1;i<len;i++)
    {
        int min=array[i];
        int index=i;
        for (int j=i+1;j<len;j++)
        {
            if (array[j]<min)
            {
                min=array[j];
                index=j;
            }
        }
        array[index]=array[i];
        array[i]=min;

    }
}


void select_sort2(int * array,int len)      //锦标赛排序
{
    Node ** nodes=(Node **)calloc(len-1,sizeof(Node *));
    for (int i=1;i<len;i++)
    {
        nodes[i]=create_leaf(array[i],i);
    }   
    Node * root=build_tree(nodes,1,len-1);
    array[1]=root->value;
    for (int i=2;i<len;i++)
    {
        update(root,root->index,INT_MAX);
        array[i]=root->value;
    }
}   


Node * create_leaf(int value,int index)     //为数组每一个元素创建一个叶子结点
{
    Node * p=(Node *)calloc(1,sizeof(Node));
    p->index=index;
    p->value=value;
    p->isleaf=1;
    p->left=NULL;
    p->right=NULL;
    return p;
}


Node * link_node(Node * left,Node * right)      //利用递归将叶子结点
{
    Node * p=(Node *)calloc(1,sizeof(Node));
    p->left=left;
    p->right=right;
    p->isleaf=0;
    if (left->value<=right->value)
    {
        p->value=left->value;
        p->index=left->index;
    }
    else
    {
        p->value=right->value;   
        p->index=right->index;
    }
    return p;
}


Node * build_tree(Node ** nodes,int l,int r)        //构建一整个锦标赛树
{
    if (l==r)
    {
        return nodes[l];
    }
    int mid=(l+r)/2;        //每次分成左右两个大子树
    Node * left=build_tree(nodes,l,mid);
    Node * right=build_tree(nodes,mid+1,r);
    return link_node(left,right);       //将左右子树合成一个新结点,同时作为新的左右子树返回
}


void update(Node * root,int index,int new_value)        //每次确定最小值后将其叶子结点赋值为最大值,同时调整部分树的结点
{
    if (root->isleaf&&root->index==index)       //如果是叶子结点就直接赋值
    {
        root->value=new_value;
        return ;
    }
    if (root->left!=NULL&&root->right!=NULL)
    {
        if (root->left->index==index)
        {
            update(root->left,index,new_value);     //继续搜寻直到叶子结点
        }
        else
        {   
            update(root->right,index,new_value);
        }
        
        if (root->left->value<=root->right->value)      //自下而上根据新value更改部分树
        {   
            root->value=root->left->value;
            root->index=root->left->index;
        }
        else
        {   
            root->value=root->right->value;
            root->index=root->right->index;
        }
    }
}