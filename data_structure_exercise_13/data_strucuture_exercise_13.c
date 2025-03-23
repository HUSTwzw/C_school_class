/*
程序题目:
给定一棵二叉树T,采用二叉链表存储,节点结构如下:left|weight|right
其中叶节点的weight域保存该节点的非负权值,设root为指向T的根节点的指针,设计算法求T的带权路径长度
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TreeNode 
{
    struct TreeNode * left;
    int weight;
    struct TreeNode * right;
}TreeNode;


int main(void)
{
    
    
    return 0;
}


int WPL(TreeNode * root)
{
    TreeNode ** queue=(TreeNode **)calloc(100,sizeof(TreeNode *));
    int front=0;
    int rear=0;
    int depth=0;
    int wpl=0;
    queue[rear++]=root;
    while (front<rear)
    {
        int num=rear-front;
        for (int i=0;i<num;i++)
        {
            TreeNode * node=queue[front++];
            if (node->left==NULL&&node->right==NULL)
            {
                wpl+=(node->weight)*depth;
            }
            if (node->left!=NULL)
            {
                queue[rear++]=node->left;
            }
            if (node->right!=NULL)
            {
                queue[rear++]=node->right;
            }
        }
        depth++;
    }
    free(queue);
    return wpl;
}