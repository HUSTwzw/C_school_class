//程序题目:利用基数排序实现数字的排序


/*
基数排序:

算法思想:
基数排序将元素的多个关键字按优先级分多次排序,例如,将数字的每一位看作一个关键字,先按最低位排序,再按次低位排序,直到最高位
每次排序必须稳定,即相同关键字的元素在排序后保持原有相对顺序

操作步骤:
以[1,52,478,12,83,7,45,333]为例
首先先根据个位数字进行排序(根据数字0-9分成第0-9组)       第一组:1   第二组:52,12   第三组:83,333   第五组:45   第七组:7   第八组:478  
根据该顺序回收进数组,数组内部顺序变成[1,52,12,83,333,45,7,478]
之后根据十位数字进行排序        第零组:1,7   第一组:12   第三组:333   第四组:45   第五组:52   第七组:478   第八组:83
根据该顺序回收进数组,数组内部顺序变成[1,7,12,333,45,52,478,83]
之后根据百位数字进行排序        第零组:1,7,12,45,52,83   第三组:333   第四组:478
根据该顺序回收进数组,数组内部顺序变成[1,7,12,45,52,83,333,478]
由于数组中最大数字的位数为3,因此不需要根据千位进行排序,已经得到最终结果

时间复杂度:
时间复杂度大概为(m+1)*n,其中n表示数组的长度,n表示最小值到最大值之间的位数差
由于位数差有限,可以看成O(n)的时间复杂度

空间复杂度:
需要开辟一个二维数组,大小为10*n:10表示每一位数字是0-9这10个数字,n表示数组的长度     用于记录数组中不同元素根据当前位次的数字所对应的组号
还需要开辟一个一维数组,大小为10:10表示每一位数字是0-9这10个数字     用于记录当前位数0-9这10个数字分别出现的次数
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void radixSort(int * arr,int length);
int main(void)
{
    int arr[]={1,52,12,83,333,45,7,478};
    radixSort(arr,8);
    for (int i=0;i<8;i++)
    {
        printf("%4d",arr[i]);
    }
    return 0;
}   


void radixSort(int * arr,int length)
{
    int min=arr[0];
    int max=arr[0];
    for (int i=0;i<length;i++)      //找出最大值和最小值
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        else if (arr[i]<min)
        {
            min=arr[i];
        }
    }
    int min_length;
    int max_length;
    for (min_length=1;min>=10;min_length+=1)        //判断最小值的位数
    {
        min/=10;
    }
    for (max_length=1;max>=10;max_length+=1)        //判断最大值的位数
    {
        max/=10;
    }
    

    const int radix=10;
    int ** buckets=(int **)calloc(radix,sizeof(int *));
    for (int i=0;i<radix;i++)
    {
        buckets[i]=(int *)calloc(length,sizeof(int));       //创建大小为10*n的二维数组:用于记录数组中不同元素根据当前位次的数字所对应的组号
    }
    int * buckets_element_counts=(int *)calloc(radix,sizeof(int));      //创建大小为10的数组:用于记录当前位数0-9这10个数字分别出现的次数
    
    
    int divide=1;
    for (int digit=1;digit<min_length;digit++,divide*=10)
    {

    }
    for (int digit=min_length;digit<=max_length;digit++,divide*=10)
    {
        memset(buckets_element_counts,0,radix*sizeof(int));
        for (int i=0,num=0;i<length;i++)
        {
            num=(arr[i]/divide)%radix;      //计算当前位数的数字
            buckets[num][buckets_element_counts[num]]=arr[i];       //填充二维数组
            buckets_element_counts[num]+=1;     //记录对应数字的出现次数
        }
        
        for (int i=0,index=0;i<radix;i++)       //回收进数组
        {   
            for (int j=0;j<buckets_element_counts[i];j++)
            {
                arr[index++]=buckets[i][j];
            }
        }
    }


    for (int i=0;i<radix;i++)       //释放二维数组
    {
        free(buckets[i]);
    }
    free(buckets);      
    free(buckets_element_counts);       //释放一维数组
}