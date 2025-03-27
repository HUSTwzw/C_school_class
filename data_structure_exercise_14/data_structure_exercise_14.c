/*
程序题目:
给定一个包含大写字母和小写字母的字符串s,通过这些字母构建最长的回文串,并显示该回文串
要求用顺序存储和链式存储分别实现
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    char data;
    struct Node * link; 
}Node;


char * build_array(char * origin_str,int * sum);
Node * CreateNode(char * origin_str,int * sum);
int main(void)
{
    char * origin_str=(char *)calloc(100,sizeof(char));
    gets(origin_str);
    int sum=0;
    char * new_str=build_array(origin_str,&sum);
    for (int i=0;i<sum;i++)
    {
        printf("%c",new_str[i]);
    }
    sum=0;
    Node * firstnode=CreateNode(origin_str,&sum);
    for (int i=0;i<sum;i++)
    {
        printf("%c",firstnode->data);
        firstnode=firstnode->link;
    }
    return 0;
}


char * build_array(char * origin_str,int * sum)     //origin_str为原始输入字符串,sum用于统计回文字符串的字符个数
{
    int * ch_num=(int *)calloc(26,sizeof(int));     //构建统计26个英文字母出现次数的数组


    for (int i=0;i<strlen(origin_str);i++)      //统计26个英文字母的出现次数
    {
        if (origin_str[i]>='a')
        {
            ch_num[origin_str[i]-'a']++;
        }
        else
        {
            ch_num[origin_str[i]-'A']++;
        }
    }


    int has_odd=0;      //判断之前是否存在出现次数为奇数的英文字母


    for (int i=0;i<26;i++)
    {
        if (ch_num[i]%2==0)
        {
            *sum+=ch_num[i];
        }
        else
        {
            if (has_odd==0)     //没出现过奇数次字母就将该类型的英文字母全部计入
            {
                has_odd=1;
                *sum+=ch_num[i];
            }
            else if (has_odd==1)        //出现过奇数次字母就将最大偶数(出现次数-1)字母计入
            {
                ch_num[i]=ch_num[i]-1;
                *sum+=ch_num[i];
            }
        }
    }


    char * new_str=(char *)calloc(*sum,sizeof(char));       //构建回文字符串数组
    int pos=0;      //记录填充英文字母的位置
    for (int i=0;i<26;i++)
    {
        if (ch_num[i]!=0)
        {
            if (ch_num[i]%2==0)
            {
                for (int j=0;j<ch_num[i]/2;j++)     //对称填充回文字符串数组
                {
                    new_str[pos]='A'+i;
                    new_str[*sum-pos-1]='A'+i;
                    pos++;
                }
            }
            else
            {
                for (int j=*sum/2-(ch_num[i]/2);j<=*sum/2+(ch_num[i]/2);j++)        //将奇数次的字母放置在回文字符串数组的正中间
                {
                    new_str[j]='A'+i;
                }
            }
        }
    }
    return new_str;     //返回新回文字符串数组
}


Node * CreateNode(char * origin_str,int * sum)
{
    int * ch_num=(int *)calloc(26,sizeof(int));     //构建统计26个英文字母出现次数的数组


    for (int i=0;i<strlen(origin_str);i++)      //统计26个英文字母的出现次数
    {
        if (origin_str[i]>='a')
        {
            ch_num[origin_str[i]-'a']++;
        }
        else
        {
            ch_num[origin_str[i]-'A']++;
        }
    }


    int has_odd=0;      //判断之前是否存在出现次数为奇数的英文字母
    int odd_pos=0;


    for (int i=0;i<26;i++)
    {
        if (ch_num[i]%2==0)
        {
            *sum+=ch_num[i];
        }
        else
        {
            if (has_odd==0)     //没出现过奇数次字母就将该类型的英文字母全部计入
            {
                odd_pos=i;
                has_odd=1;
                *sum+=ch_num[i];
            }
            else if (has_odd==1)        //出现过奇数次字母就将最大偶数(出现次数-1)字母计入
            {
                ch_num[i]=ch_num[i]-1;
                *sum+=ch_num[i];
            }
        }
    }


    Node * head=(Node *)malloc(sizeof(Node));
    Node * left=head;
    Node * right=head;
    head->data=odd_pos+'A';
    ch_num[odd_pos]-=1;
    for (int j=0;j<ch_num[odd_pos]/2;j++)       //先创建正中间节点:存储奇数个英文字母
    {
        Node * newleft=(Node *)malloc(sizeof(Node));
        newleft->link=left;
        right->link=(Node *)malloc(sizeof(Node));
        newleft->data=odd_pos+'A';
        right->link->data=odd_pos+'A';
        left=newleft;       //left记录当前最左的节点
        right=right->link;      //right记录当前最右节点
    }
    for (int i=0;i<26;i++)
    {
        if (i!=odd_pos)
        {
            for (int j=0;j<ch_num[i]/2;j++)     //依次创建其他偶数次数的英文字母
            {
                Node * newleft=(Node *)malloc(sizeof(Node));
                newleft->link=left;
                right->link=(Node *)malloc(sizeof(Node));
                newleft->data=i+'A';
                right->link->data=i+'A';
                left=newleft;
                right=right->link;
            }
        }
    }


    return left;
}