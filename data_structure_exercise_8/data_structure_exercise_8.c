//练习题目:设计一个算法,将数组An中的元素A[0]至A[n-1]循环右移k位,并要求只用一个元素大小的附加存储,元素移动或交换次数为O(n)
/*
算法思想:
先将整个数组反转,这样原本在数组最后面的元素就放置在数组最前面了,这符合循环移动的现象(原本末尾的元素移动到首位)
但是,虽然通过反转数组将末尾元素移动到首位,但移动到首位的原末尾元素的相对位置因为反转操作而相反
因此要将新数组的前k个元素(新数组的前k个元素恰好是原数组的后k个元素,即将要移动到数组首位的k个元素)再次反转,这样就保证了新数组前k个元素的相对位置的正确性
同理,新数组的剩余len-k个元素的相对位置也有问题,对于剩余的元素,也需要进行反转,由此可得循环移动后的数组
*/


#include <stdio.h>
#define len 10


void move(int * arr,int k);
int main(void)
{   
    int arr[len]={0,1,2,3,4,5,6,7,8,9};
    int k=0;

    printf("请输入k的值\n");
    scanf("%d",&k);
    move(arr,k);
    for (int i=0;i<len;i++)
    {
        printf("%4d",arr[i]);
    }
    return 0;
}


void move(int * arr,int k)
{
    int temp=0;
    for (int i=0;i<len/2;i++)       //反转原数组
    {
        temp=arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=temp;
    }
    for (int i=0;i<k/2;i++)     //反转前k个数组
    {
        temp=arr[i];
        arr[i]=arr[k-i-1];
        arr[k-i-1]=temp;
    }
    for (int i=k;i<=(k+len-1)/2;i++)        //反转后len-k个数组    
    {
        temp=arr[i];
        arr[i]=arr[k+len-1-i];
        arr[k+len-1-i]=temp;
    }
}