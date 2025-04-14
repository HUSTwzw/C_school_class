//交换排序
/*
冒泡排序:最为基础,此处将不展示代码
快速排序
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Quick_Sort(int * array,int left,int right);
int main(void)
{
    srand((int)time(NULL));
    int * array=(int *)calloc(10,sizeof(int));
    for (int i=1;i<10;i++)
    {
        array[i]=rand()%100;
    }
    for (int i=1;i<10;i++)
    {
        printf("%4d",array[i]);
    }
    printf("\n");
    Quick_Sort(array,1,9);
    for (int i=1;i<10;i++)
    {   
        printf("%4d",array[i]);
    }
    printf("\n");
    return 0;
}


void Quick_Sort(int * array,int left,int right)     //每次将第一个元素作为中间点,中间点左侧元素均小于中间点,中间点右侧元素均大于中间点
                                                    //通过递归每次能确定1、2、4、8……个中间点位置,时间复杂度为O(nlogn)
{
    if (left>=right)
    {
        return ;
    }

    array[0]=array[left];
    
    int i=left;
    int j=right;
    while(i<j)      //交替震荡式确定元素相对位置
    {
        while(i<j&&array[j]>=array[0])
        {
            j--;
        }
        array[i]=array[j];
        while(i<j&&array[i]<=array[0])
        {
            i++;
        }
        array[j]=i;
    }

    array[i]=array[0];

    Quick_Sort(array,left,i-1);
    Quick_Sort(array,i+1,right);
}               