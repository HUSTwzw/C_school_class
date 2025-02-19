/*
阶斐波那契序列:
第0项到第k-2项均为0,第k-1项为1,从第k项开始,每一项为之前k项的和(例如第k项为第0项到第k-1项之和,第k+1项为第1项到第k项之和)
编写求k阶斐波那契第m项值的算法
*/


#include <stdio.h>
#include <stdlib.h>

int calculate(int k,int m);
int calculate2(int k,int m);
int main(void)
{
    int k=0;
    int m=0;
    printf("请输入k:");
    scanf("%d",&k);
    printf("请输入m:");
    scanf("%d",&m);
    int outcome=calculate(k,m);
    printf("%d\n",outcome);
    int outcome2=calculate2(k,m);
    printf("%d\n",outcome2);
    return 0;
}


//方法一:递归法
/*
可以实现基本功能,但递归存在大量重复项的计算(因为要计算k项)
每次递归分成k个子问题,递归树的深度为m,每个分支再次生成k个子节点,最终产生k的m次方个节点
这种时间复杂度是指数级的,效率太低
*/
int calculate(int k,int m)
{
    int num=0;
    if (m<k-1)
    {
        return 0;
    }
    else if (m==k-1)
    {
        return 1;
    }
    else if (m>k-1)
    {
        for (int i=1;i<=k;i++)
        {
            num+=calculate(k,m-i);
        }
        return num;
    }
}


//方法二:动态规划
/*
随着项数增加,不断用新项替换掉最数组的首项
此时时间复杂度为(k-1)(m-k),明显减小
*/
int calculate2(int k,int m)
{
    if (m<k-1)
    {
        return 0;
    }
    else if (m==k-1)
    {
        return 1;
    }
    else if (m>k-1)
    {
        int * head=(int *)calloc(1,sizeof(int)*k);
        *(head+k-1)=1;
        int sum=1;
        for (int i=k;i<m;i++)
        {
            int new_val=sum;
            int first_val=*(head+0);
            for (int j=0;j+1<=k-1;j++)
            {
                *(head+j)=*(head+j+1);
            }
            *(head+k-1)=new_val;
            sum-=first_val;
            sum+=new_val;
        }
        free(head);
        return sum;
    }
}