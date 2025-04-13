//插入排序
/*
直接插入排序
折半插入排序
2-路插入排序
希尔排序
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insert_sort1(int * array,int len);
void insert_sort2(int * array,int len);
void insert_sort3(int * array,int len);
void insert_sort4(int * array,int len);
int main(void)
{
    int * array=(int *)calloc(10,sizeof(int));
    srand((int)time(NULL));
    for (int i=1;i<10;i++)
    {
        array[i]=rand()%100;
    }

    for (int i=1;i<10;i++)
    {
        printf("%4d",array[i]);
    }
    printf("\n");
    return 0;
}


void insert_sort1(int * array,int len)        //直接插入法,时间复杂度为O(n)
{
    array[0]=array[1];      //array[0]放入哨兵
    
    for (int i=2;i<len;i++)
    {
        if (array[i]<array[i-1])
        {
            array[0]=array[i];
        
            int j;
            for (j=i-1;array[j]>array[0];j--)
            {
                array[j+1]=array[j];
            }

            array[j+1]=array[0];
        }
    }
}


void insert_sort2(int * array,int len)     //折半插入法,时间复杂度为O(nlog2n)  
{   
    array[0]=array[1];      //array[0]放入哨兵
   
    for (int i=2;i<len;i++)
    {
        if (array[i]<array[i-1])
        {   
            array[0]=array[i];
            
            int front=1;
            int rear=i-1;
            while(front<=rear)      //折半法寻找插入位置(注意：循环条件是<=因为当front==rear时还没有确定插入位置)
                                    //当front==rear时,front-1位置的元素<=哨兵,front+1位置的元素>哨兵,但是front位置的元素还没有与哨兵比较,也就是说插入位置可能是front,也可能是front+1
            {
                if (array[(rear+front)/2]>array[0])
                {
                    rear=(rear+front)/2-1;
                }
                else
                {
                    front=(rear+front)/2+1;
                }
            }
            
            for (int j=i-1;j>=front;j--)        //移动元素位置
            {
                array[j+1]=array[j];
            }
            array[front]=array[0];      //front就是确定插入的位置
        }
    }
}


void insert_sort3(int * array,int len)      //2-路插入排序(经过统计,时间复杂度约为1/8*n²)
{
    int * temp=(int *)calloc(2*len,sizeof(int));        //次数特意开辟一个2*len长度的数组空间,因为2-路插入排序需要从头尾两边插入,因此2倍空间可以防止从头尾两边插入时越界
    
    int head=len-1;
    int tail=len-1;
    
    temp[len-1]=array[1];

    for (int i=2;i<len;i++)
    {
        if (array[i]>temp[tail])        //比尾部大就放在尾部
        {
            temp[++tail]=array[i];
        }
        else if (array[i]<temp[head])       //比头部小就放在头部
        {
            temp[--head]=array[i];
        }
        else        //处于头尾之间就折半查找
        {
            temp[0]=array[i];
            
            int front=head;
            int rear=tail;
            while(front<=rear)
            {
                if(temp[(front+rear)/2]>temp[0])
                {
                    rear=(front+rear)/2-1;
                }
                else
                {
                    front=(front+rear)/2+1;
                }
            }
            
            for (int j=tail;j>=front;j--)
            {
                temp[j+1]=temp[j];
            }
            temp[front]=temp[0];
            
            tail++;
        }
    }
    
    for (int j=head;j<=tail;j++)        //将临时数组的信息放在原数组上
    {
        array[j-head+1]=temp[j];
    }

    free(temp);     
}


void insert_sort4(int * array,int len)      //希尔排序,最原始的时间复杂度为O(n²),但是可以通过使用不同增量序列降低时间复杂度
{
    for (int gap=len/2;gap>=1;gap/=2)       //确定间隔
    {
        for (int i=gap+1;i<len;i++)
        {
            array[0]=array[i];
            int j=i-gap;
            while(j>=1&&(array[j]>array[0]))
            {
                array[j+gap]=array[j];
                j-=gap;
            }
            array[j+gap]=array[0];
        }
    }
}