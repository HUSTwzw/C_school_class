//利用文章统计每个英文字母的出现次数,根据不同英文字母出现次数构建huffman树,统计WPL,最终为每一个英文字母进行huffman编码


/*
构建huffman树函数的巧妙思想:
可以发现,代码中定义了not_null变量,用于统计Tp数组中非NULL元素的数量,同时很巧妙的将有效节点集中到Tp数组前面,
因此每次for循环遍历TP数组获得的元素一定都是有效节点,防止每次对元素进行NULL判断,代码更加简洁.

同时仅使用一次遍历就同时找到了min_pos和next_min_pos,每次找到weight更小的节点都现将下标赋值给min_pos,之后将原本的min_pos赋值给next_min_pos,
保证了这两个变量存储weight最小的两个节点位于Tp数组的下标.

关于如何使有效节点集中到Tp数组前面,此处将Tp数组最后一个有效节点放置在next_min_pos所在位置,将新节点放置在min_pos所在位置,
这样不仅覆盖刚合并的节点,同时防止最后面的有效节点因为not_null减少而无法遍历到,十分巧妙.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TreeNode 
{
    char isalpha;        //标记是中间节点还是英文单词,如果是中间节点则赋值为-1,否则是0-25对应26个英文单词
    int weight;
    struct TreeNode * left;
    struct TreeNode * right;
}TreeNode;


int * count_alpha(char * str);
TreeNode * build_huffman(int * count_array);
void run(TreeNode * node);
int WPL(TreeNode * node);
void build_codes(TreeNode * node,char ** codes,int pos,char * path);
int main(void)
{
    char str[]="Students attend their first class after winter break at Beijing Huajiadi Experimental Primary School on Feb 13, 2023. [Photo by Wang Zhuangfei/China Daily]"
               "The double reduction policy, introduced to reduce the after-school tutoring and homework burden on students, will continue to be the top priority in education supervision this year, a notice said on Monday."
               "Issued by the education supervision office of the State Council, or China's cabinet, the notice stated that a joint supervision mechanism between the State, provincial, municipal and county levels will be used to strengthen the regulation of after-school tutoring institutions, prevent misbehavior that harms the public interests, and promote a sound education system and the all-round and healthy development of students."
               "Based on the progress made over the past two years, local authorities need to make supervision of the sector more effective and achieve better results in reducing the academic burden on students."
               "The supervision of double reduction will focus on hidden academic tutoring, substandard nonacademic tutoring, management of tutoring tuition fees for courses, art exams and tutoring with foreign teachers."
               "Municipal and county governments should assume responsibility of supervision, and education supervisors are to conduct inspection of all primary and middle schools."
               "State and provincial education supervisors will conduct snap inspections in cities and counties with slow progress and excessive complaints, the notice stated, adding that the names of those cities and counties will be made public to add pressure.";

    int * count_array=count_alpha(str);
    for (int i=0;i<26;i++)
    {
        printf("%4d",count_array[i]);
    }
    TreeNode * head=build_huffman(count_array);
    run(head);
    int wpl=WPL(head);
    printf("%d",wpl);
    printf("\n");
    char * codes[26]={NULL};
    char path[100];
    build_codes(head,codes,0,path);
    for (int i=0;i<26;i++)
    {
        printf("%s\n",codes[i]);
    }
    return 0;
}


int * count_alpha(char * str)       //统计
{
    int length=strlen(str);
    int * count_array=(int *)calloc(26,sizeof(int));
    for (int i=0;i<length;i++)
    {   
        if (str[i]>='A'&&str[i]<='Z')
        {
            count_array[str[i]-'A']+=1;
        }
        else if (str[i]>='a'&&str[i]<='z')
        {
            count_array[str[i]-'a']+=1;
        }
    }
    return count_array;
}


TreeNode * build_huffman(int * count_array)
{
    int * sort=(int *)calloc(26,sizeof(int));
    TreeNode ** Tp=(TreeNode **)calloc(26,sizeof(TreeNode *));      //创建一个指针数组,记录关键节点对应的指针
    for (int i=0;i<26;i++)
    {
        TreeNode * p=(TreeNode *)calloc(1,sizeof(TreeNode));
        p->isalpha=i+'A';
        p->weight=count_array[i];
        p->left=NULL;
        p->right=NULL;
        Tp[i]=p;
    }
    int not_null=26;
    while (not_null>=2)     
    {
        int min_pos=-1;
        int next_min_pos=-1;
        for (int i=0;i<not_null;i++)        //找出weight最小和倒数第二小的节点
        {
            if (min_pos==-1||Tp[i]->weight<Tp[min_pos]->weight)
            {
                next_min_pos=min_pos;
                min_pos=i;
            }
            else if (next_min_pos==-1||Tp[i]->weight<Tp[next_min_pos]->weight)
            {
                next_min_pos=i;
            }
        }
        TreeNode * newp=(TreeNode *)calloc(1,sizeof(TreeNode));
        newp->isalpha=-1;       //每次合并节点产生的节点都是中间节点,赋值为-1
        newp->weight=Tp[min_pos]->weight+Tp[next_min_pos]->weight;      //记录当前中间节点的权重值
        newp->left=Tp[min_pos];
        newp->right=Tp[next_min_pos];
        Tp[min_pos]=newp;
        Tp[next_min_pos]=Tp[not_null-1];        //Tp中后面的元素放入next_min_pos的位置,因为随着not_null的减少,将逐渐无法遍历到Tp数组的最后面的多个元素
        not_null-=1;        //每次合并都会消耗两个有效节点,同时产生一个新节点
    }
}


void run(TreeNode * node)
{
    if (node==NULL)
    {
        return;
    }
    else
    {
        if(node->isalpha==-1)
        {   
            printf("central");
            printf("%d",node->weight);
            printf("\n");
        }
        else
        {
            printf("%c",node->isalpha);
            printf("%d",node->weight);
            printf("\n");
        }
        run(node->left);
        run(node->right);
    }
}


int WPL(TreeNode * node)
{
    TreeNode * queue[1000];
    int front=0;
    int rear=0;
    queue[rear++]=node;
    int height=0;
    int wpl=0;
    while(rear>front)
    {
        int j=rear-front;
        for (int i=0;i<j;i++)
        {
            TreeNode * node=queue[front++];
            if (node!=NULL)
            {
                if (node->isalpha!=-1)
                {
                    wpl+=(node->weight)*height;
                }
                if (node->left!=NULL)
                {
                    queue[rear++]=node->left;
                }
                if (node->right!=NULL)
                {
                    queue[rear++]=node->right;
                }
            }
        }
        height++;
    }
    return wpl;
}   


void build_codes(TreeNode * node,char ** codes,int pos,char * path)
{

    if (node->isalpha!=-1)
    {
        path[pos]='\0';
        char index=node->isalpha-'A';
        codes[index]=(char *)calloc(pos+1,sizeof(char));
        strcpy(codes[index],path);
        return ;
    }
    else
    {
        path[pos]='0';
        build_codes(node->left,codes,pos+1,path);
        path[pos]='1';
        build_codes(node->right,codes,pos+1,path);
    }
}