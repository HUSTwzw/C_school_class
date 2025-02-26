//串之顺序串
/*
BF算法(暴力破解):寻找子串在主串的位置,若位置不存在返回-1
假设主串长度为m,字串长度为n,则时间复杂度为O(m*(n-m+1))


KMP算法:
假设主串长度为m,字符串长度为n,则时间复杂度为O(m+n)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100


typedef struct main_string
{
    char string[MAXSIZE];
    int length;
}MS;


typedef struct subset_string
{
    char string[MAXSIZE];
    int length;
}SS;


int BF_Search(MS * pms,SS * pss);
int KMP_from_minus_one(MS * pms,SS * pss);

int main(void)
{
    MS * pms=(MS *)calloc(1,sizeof(MS));
    SS * pss=(SS *)calloc(1,sizeof(SS));
    strcpy(pms->string,"Success is not final, failure is not fatal: it is the courage to continue that counts.");
    pms->length=strlen("Success is not final, failure is not fatal: it is the courage to continue that counts.");
    strcpy(pss->string,"continue");
    pss->length=strlen("continue");
    int outcome=BF_Search(pms,pss);
    printf("%d\n",outcome);


    MS * pms2=(MS *)calloc(1,sizeof(MS));
    SS * pss2=(SS *)calloc(1,sizeof(SS));
    strcpy(pms2->string,"ABABABCABABABABABABABABCABABCABABCAB");
    pms2->length=strlen("ABABABCABABABABABABABABCABABCABABCAB");
    strcpy(pss2->string,"ABABCABABCAB");
    pss2->length=strlen("ABABCABABCAB");
    int outcome2=KMP_from_minus_one(pms2,pss2);
    printf("%d\n",outcome2);


    return 0;
}


int BF_Search(MS * pms,SS * pss)
{
    char * p=pms->string;
    char * q=pss->string;
    int i=0;
    int j=0;
    while(i<pms->length&&j<pss->length)
    {
        if (*(p+i)==*(q+j))
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if (j==pss->length)
    {
        return i-j;
    }
    else
    {
        return -1;
    }
}


int KMP_from_minus_one(MS * pms,SS * pss)
{
    //根据字串创建next数组
    /*
    注意:此处我采用首元素为-1的next数组版本
    
    next[i]的大小表示从序号0至序号i-1的字符串具有的最长公共前后缀的长度,也对应着表示公共前缀的下一个字符的序号

    在进入if判断的时候i对应着后缀的下一个字符,而j对应着前缀的下一个字符,若此时两字符相等,则前缀与后缀的长度+1,
    则此时i对应的字符成为了后缀的一部分,对应着后缀的最后一个字符;j对应的字符成为了前缀的一部分,对应着前缀的最后一个字符
    
    next数组的用法:在kmp算法中,当子串与主串进行匹配时,主串的指针一直向前移动(不会回溯),而子串的指针则需要回溯
    可以发现,当指向的字串字符与指向的主串字符不相等时,匹配失败,这时候字串指针就需要回溯,而回溯的位置下标恰好是匹配失败字符对应的next数组值
    因此借助next数组可以实现高效字串指针回溯
    */


    int * next=(int *)calloc(1, sizeof(int)*pss->length);
    next[0]=-1;
    int i=0;
    int j=-1;
    while(i<pss->length-1)
    {
        if (j==-1||*(pss->string+i)==*(pss->string+j))
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }



    //根据next数组构建nextval数组
    //nextval是next数组的改良版,可以进一步排除一些不可能成立的回溯点,进一步减少时间损耗
    //方式一:额外开辟一段空间创建nextval数组
    int t=1;
    int * nextval=(int *)calloc(1,sizeof(int)*pss->length);
    nextval[0]=-1;
    while (t<pss->length)
    {
        if (*(pss->string+t)==*(pss->string+next[t]))
        {
            nextval[t]=next[next[t]];
        }
        else
        {
            nextval[t]=next[t];
        }
        t++;
    }



    //方式二:在next数组的原地修改为nextval(不需要额外开辟空间)
    /*
    int r=1;        //r从1开始就保证了next[t]一定>=0,因此next[next[r]]下标越界错误的问题
    while(r<pss->length)
    {
        if(*(pss->string+r)==*(pss->string+next[r]))
        {
            next[r]=next[next[r]];
        }
        r++;
    }
    */



    //实现kmp匹配
    int u=0;
    int v=0;
    while(u<pms->length && v<pss->length)
    {
        if (*(pms->string+u)==*(pss->string+v))
        {
            u++;
            v++;
        }
        else
        {
            v=nextval[v];
            if (v==-1)
            {
                v++;
                u++;
            }
        }
    }
    if (v==pss->length)
    {
        return u-v;
    }
    else
    {
        return -1;
    }
}                   