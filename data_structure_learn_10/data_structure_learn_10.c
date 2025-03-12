//矩阵的压缩存储
//以稀疏矩阵为例,当存在大量的重复数字(比如0)时,可以用三元组记录剩余的特殊值,以此表示整个矩阵
//三元组基本结构为(i,j,array[i][j]),其中第0行存储整个矩阵的行数、列数、特殊值(非0值)个数


//矩阵的转置
//在通过三元组表示稀疏矩阵时,我们不必对原矩阵直接转置,而是可以直接对三元组进行转置操作
/*
操作有三个关键点:
1.将三元组每一个元素的行列值交换
2.将三元组的第0行的行数与列数交换
3.确保转置后三元组数组以升序有序排列
*/


#include <stdio.h>
#include <stdlib.h>


#define ROW 6
#define COLUMN 8
int main(void)
{

    //----------初始化一个不太稀疏的稀疏矩阵(主要探究算法思路,不必在意这些细节)----------//
    
    int array[ROW][COLUMN]={0};     
    array[0][1]=12;
    array[0][2]=9;
    array[2][0]=-3;
    array[2][4]=14;
    array[2][6]=22;
    array[3][2]=24;
    array[4][1]=18;
    array[5][0]=15;
    array[5][3]=-7;

    //----------创建一个三元组(按行排列)----------//

    int TripleArray[ROW*COLUMN+1][3];      //这个三元组按照最大空间进行开辟
    int index=1;
    for (int i=0;i<ROW;i++)
    {
        for (int j=0;j<COLUMN;j++)
        {
            if (array[i][j]!=0)
            {
                TripleArray[index][0]=i;
                TripleArray[index][1]=j;
                TripleArray[index][2]=array[i][j];
                index++;
            }
        }
    }
    TripleArray[0][0]=ROW;
    TripleArray[0][1]=COLUMN;
    TripleArray[0][2]=index-1;

    //----------创建一个针对array的列辅助向量----------//

    int NUM[COLUMN]={0};
    int POS[COLUMN]={0};
    for (int i=1;i<index;i++)
    {
        NUM[TripleArray[i][1]]++;
    }
    POS[0]=1;
    for (int i=1;i<COLUMN;i++)
    {   
        POS[i]=POS[i-1]+NUM[i-1];
    }

    //----------结合行原矩阵的三元数组和原矩阵的列辅助向量,创建一个转置矩阵的三元数组----------//

    int TripleArray_T[index][3];        //在统计过特殊值的个数之后就不必像TripleArray一样浪费大量空间了
    TripleArray_T[0][0]=COLUMN;
    TripleArray_T[0][1]=ROW;    
    TripleArray_T[0][2]=index-1;        
    for (int i=1;i<index;i++)
    {
        int col=TripleArray[i][1];

        
        int pos=POS[col]++;

        TripleArray_T[pos][0]=TripleArray[i][1];
        TripleArray_T[pos][1]=TripleArray[i][0];
        TripleArray_T[pos][2]=TripleArray[i][2];
        
    }

    //----------输出结果,检验代码----------//

    for (int i=0;i<index;i++)
    {
        printf("%4d",TripleArray[i][0]);
        printf("%4d",TripleArray[i][1]);
        printf("%4d",TripleArray[i][2]);
        printf("\n");
    }
    printf("\n\n\n");
    for (int i=0;i<index;i++)
    {
        printf("%4d",TripleArray_T[i][0]);
        printf("%4d",TripleArray_T[i][1]);
        printf("%4d",TripleArray_T[i][2]);
        printf("\n");
    }

    return 0;
}