//线性表之顺序表


#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100
typedef int ElemType;


struct SeqList
{
    ElemType * p;
    int length;
};


struct SeqList* InitList();
void AppendElem(struct SeqList * L,ElemType e);
void ShowListElem(struct SeqList * L);
void InsertElem(struct SeqList * L,int pos,ElemType e);
void DeleteElem(struct SeqList * L,int pos);
int FindElem(struct SeqList * L,ElemType e);


int main(void)  
{                       
    struct SeqList*list=InitList();
    AppendElem(list,88);
    AppendElem(list,22);
    AppendElem(list,66);
    AppendElem(list,52);
    InsertElem(list,3,98);
    ShowListElem(list);
    DeleteElem(list,4);
    ShowListElem(list);
    int pos=FindElem(list,22);
    printf("%4d\n",pos);
    return 0;
}


struct SeqList* InitList()      //顺序表的初始化
{
    struct SeqList * L=(struct SeqList *)calloc(1,sizeof(struct SeqList));
    L->p=(ElemType *)calloc(1,sizeof(ElemType)*MAXSIZE);
    L->length=0;
    return L;
}


void AppendElem(struct SeqList * L,ElemType e)       //在末尾添加元素
{
    if (L->length>=MAXSIZE)
    {
        printf("没有剩余空间\n");
    }
    else
    {
        L->p[L->length]=e;
        L->length+=1;
    }
}


void ShowListElem(struct SeqList * L)       //遍历顺序表
{
    for (int i=0;i<L->length;i++)
    {
        printf("%4d",L->p[i]);
    }
    printf("\n");
}


void InsertElem(struct SeqList * L,int pos,ElemType e)      //在顺序表中特定位置插入数据
{   
    if (pos>L->length)
    {
        printf("位置不正确,无法插入");
    }
    else
    {
        for (int i=L->length-1;i>=pos-1;i--)
        {
            L->p[i+1]=L->p[i];
        }
        L->p[pos-1]=e;
        L->length+=1;
    }
}


void DeleteElem(struct SeqList * L,int pos)     //删除顺序表指定位置的元素
{
    if (L->length<pos)
    {
        printf("无法删除该位置\n");
    }
    else
    {
        for (int i=L->p[pos-1];i+1<L->length;i++)
        {
            L->p[i]=L->p[i+1];
        }
        L->length-=1;
    }
}


int FindElem(struct SeqList * L,ElemType e)     //在顺序表查找指定信息的位置 
{
    for (int i=0;i<L->length;i++)
    {
        if (L->p[i]==e)
        {
            return i+1;
        }
    }
    return -1;
}