/*
堆排序思想:
利用堆这种特殊的完全二叉树结构(利用二叉树的思想,但是并没有真正的构建出二叉树),将无序数组变成有序数组
大根堆:根节点是最大值,适合进行升序排序
堆的特性:每个节点都≥它的左右子节点
1.建堆:
把原始数组构建成一个大根堆
自底向上,从最后一个非叶子节点开始对每个节点调用heapify
时间复杂度是 O(n)
2.排序:
每次把堆顶(最大值)与末尾元素交换
然后对堆顶调用heapify以维护堆结构
重复这个过程,最终实现从大到小排序
3.总体时间复杂度:
建堆:O(n)
每次堆化:O(logn),共n次
所以总复杂度为:O(nlogn)且是原地排序


疑问:
1.为什么建堆要for循环从n/2-1开始?
顿悟:
从n/2往后的节点都是叶子节点,不需要处理
只有非叶子节点才可能违反堆性质
所以从最后一个非叶子节点(n/2-1)向上进行heapify,一步步"让子堆变堆"
2.heapify为什么要递归?我不是从底往上已经处理过了嘛?
顿悟:
虽然你是从下往上建堆,heapify的过程中发生了"值交换",值下沉到子节点,可能破坏子堆结构(上层很小的值与下一层交换后,下一层的那个节点可能不再拥有比下下层大的值)
所以必须递归调用heapify,继续向下修复
3.为什么排序阶段不用像建堆那样从下往上遍历?只对堆顶heapify就够？
顿悟:
因为你建完堆之后,整个数组就是一个合法的大根堆了
每次交换只破坏了堆顶的位置,所以只需要从堆顶往下"单独修一下"就行了
局部更新+下沉修复就能保持堆的正确性
4.heapify是为了"找最大值"吗?
顿悟:
heapify的目标不是找最大值,而是维护堆的结构
如果父节点比子节点小,就要交换,并递归修复子堆
但是从结果而言确实将最大值放在顶上(这是维护堆结构的必然结果)


总结:
堆排序是一个"先整体搭个金字塔结构,再一点点拆顶堆砖头下去"的过程,
通过heapify自上而下的局部调整维持"最大在顶"的堆特性,实现有序输出
*/


#include <stdio.h>
#include <stdlib.h>


int main(void)
{


    return 0;
}


void heapify(int * array,int i,int n)
{
    int largest=i;
    int left=i*2+1;     //这是数组下标从0开始的版本,如果下标从1开始就是2*i
    int right=i*2+2;        //这是数组下标从0开始的版本,如果下标从1开始就是2*i+1
    if (left<n&&array[left]>array[largest])
    {
        largest=left;
        
    }
    if (right<n&&array[right]>array[largest])
    {
        largest=right;
    }
    if (i!=largest)
    {
        int temp=array[i];
        array[i]=array[largest];
        array[largest]=temp;
        heapify(array,largest,n);
    }
}


void heap_sort(int * array,int n)
{
    for (int i=n/2-1;i>=0;i--)      //构建大根堆
    {
        heapify(array,i,n);
    }
    for (int i=n-1;i>0;i++)
    {
        int temp=array[i];
        array[i]=array[0];
        array[0]=temp;
        heapify(array,0,i);
    }
}