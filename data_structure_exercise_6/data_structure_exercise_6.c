//递归之汉诺塔      重新理解分治思想(将一个大问题不断划分为多个子问题,直到每个子问题简单到可以直接解决)
/*
汉诺塔问题的核心在于将移动n个盘子的任务分解为:
先移动前n-1个盘子
移动第n个盘子
再移动前n-1个盘子


递归基是分治思想的终点,也是最简单的情况,当递归分解到只有一个盘子时,直接给出解决方案(即一步移动)


分治中的"治"和"合并"
治:在汉诺塔问题中,"治"体现在两次递归调用上:
第一次递归调用处理了前n-1个盘子的移动
第二次递归调用处理了temp柱上的前n-1个盘子的移动
合并:通过将前两次递归的结果与直接移动第n个盘子的步骤相结合,完成整个问题的解,这种合并体现在递归的过程是自动的,每次递归调用返回后,函数继续执行后续步骤
*/


#include <stdio.h>
#include <stdlib.h>


void Hanoi(int n,char start,char temp,char final);
int main(void)
{   
    int n=0;
    printf("请输入n的大小\n");
    scanf("%d",&n);
    Hanoi(n,'A','B','C');
    printf("请输入n的大小\n");
    scanf("%d",&n);
    Hanoi(n,'A','B','C');
    return 0;
}


void Hanoi(int n,char start,char temp,char final)       //将n个盘子从起点经过辅助点到达目标点
{
    if (n==1)
    {
        printf("move disk 1 from %c to %c\n",start,final);       
    }
    else
    {
        Hanoi(n-1,start,final,temp);        //先将n-1个盘子移动到辅助点
        printf("move disk %d from %c to %c\n",n,start,final);       //将第n个盘子从起点移动到目标点
        Hanoi(n-1,temp,start,final);        //将后n-1个盘子移动到目标点 
    }
}


//以n=3为例,展示整个递归过程
/*
Hanoi(3,A,B,C)      Hanoi(2,A,C,B)                  Hanoi(1,A,B,C)------------print(disk 1  A->C)      
                                                    print(disk 2    A->B)
                                                    Hanoi(1,C,A,B)------------print(disk 1  C->B)
        
    
                    print(disk 3    A->C)


                    Hanoi(2,B,A,C)                  Hanoi(1,B,C,A)------------print(disk 1  B->A)
                                                    print(disk 2    B->C)
                                                    Hanoi(1,A,B,C)------------print(disk 1  A->C)
*/