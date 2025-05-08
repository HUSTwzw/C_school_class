/*一个二叉树中任意两个节点间距离的定义是这两个节点间边的个数,
比如某个孩子节点和父节点间的距离是1,兄弟节点间的距离是2 
要求找出二叉树中距离最大的两个节点之间的距离值,并给出平均时间、空间复杂度
*/
/*
最大路径只可能有三种情况:
1.路径是经过当前root节点的左右子树深度之和
2.路径在root节点的下属的左子树区域之内(经过更底层的某一个root节点)
3.路径在root节点的下属的右子树区域之内(经过更底层的某一个root节点)

但不论如何,最大路径一定会经过整个树的某一层的root节点,因此可以通过遍历每一个root节点最终确认最大路径
*/




#include <stdio.h>


typedef struct TreeNode
{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
}TreeNode;


int main(void)
{

    return 0;
}


//方式一:
int max=0;
void find_max(TreeNode * root)
{
    if (root==NULL)
    {
        return ;
    }   
    int Left_Depth=dfs(root->left);
    int Right_Depth=dfs(root->right);
    if (Left_Depth+Right_Depth>max)
    {
        max=Left_Depth+Right_Depth;
    }
    find_max(root->left);
    find_max(root->right);
}


int dfs(TreeNode * root)        //计算路径上节点个数
{
    if (root==NULL)
    {
        return 0;
    }
    int left=dfs(root->left);
    int right=dfs(root->right);
    return (left>right)?left+1:right+1;
}




//方式二(将两部分结合起来,时间复杂度更低):
int Search(TreeNode * root,int * max_len)       
{
    if (root==NULL)
    {
        return 0;
    }
    int left=Search(root->left,max_len);        //计算从root->left开始到最底层的节点个数
    int right=Search(root->right,max_len);      //计算从root->right开始到最底层的节点个数
    if ((left+right)>*max_len)      //从root->left开始到最底层的节点个数+从root->right开始到最底层的节点个数=由root连接左右子树的最底层的路径之和
    {
        *max_len=left+right;
    }
    return (left>right)?left+1:right+1;     //如果要将节点个数返回上一层节点,则需要加上本层的这一个节点root
}