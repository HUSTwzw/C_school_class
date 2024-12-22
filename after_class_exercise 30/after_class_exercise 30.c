//程序题目：制作员工信息管理程序
/*
一个公司有若干名员工，每名员工有姓名，性别，工龄，工资，工资发放币种组合等
信息，现需要完成一个简单的员工信息与工资管理小程序，要求如下：
1.定义员工数据结构 Worker，用于记录以上员工档案信息，便于工资发放的各种钞
票数（工资为整数，发放的工资各种钞票限定为 100 元，50 元，20 元，10 元，5 元，
1 元，发放的钞票数张数要求为最少）；
2.能够根据工资从高到低对员工档案信息进行排序；
3.最后输出工龄大于 10 年，工资高于 5000 元的所有女员工信息。
程序要求如下：
1. 提供 void getWorkerInfo(Worker* worker)函数，记录一个员工的信息，并通过
worker 返回给主调函数。(3’)
2. 提供 void sortWorkersByWage(Worker* workers, int len)函数,对员工信息结
构体数组进行排序，排序条件为员工工资条件（由高到低）。(3’)
3. 提供 void displaySingleWorker(Worker worker)函数，能够对一个员工的信息
进行完整的显示，显示顺序为姓名、性别、工龄、工资、工资发放组合，一个具体示
例如下：Tom,M,10,8585,[100:85 50:1 20:1 10:1 5:1 1:0]。(2’)
4. 提 供 void displayWorkers(Worker* workers, int len) 函 数 ， 通 过
displaySingleWorker 对员工信息结构体数组进行统一输出显示。(2’)
5. 编写主程序，实现并使用定义的函数，要求能够读入 5 个员工信息，并对员工信
息根据工资进行排序，输出排序后员工的信息，最后输出满足条件的女员工信息。 (12’)
*/




#include<stdio.h>
#define size 5
#define name_len 20
#define gender_m 'M'
#define gender_f 'F'
#define wage_len 6
typedef struct work_inform
{
    char name[name_len];
    char gender;
    int work_age;
    int wage;
    int wage_combine[wage_len];
}Worker;


void getWorkerInfo(Worker*worker);
void Wage_Combine(int wage,int *combine);
void SortWorkersByWage(Worker*worker,int len);
void displaySingleWorker(Worker worker);
void displayWorkers(Worker*workers,int len);
int main(void)
{
    Worker workers[size];
    Worker *worker=workers;
    for(int i=0;i<size;i++)
    {
        getWorkerInfo(workers+i);
    }
    SortWorkersByWage(workers,size);
    displayWorkers(workers,size);
    
    return 0;
}


void getWorkerInfo(Worker*worker)
{
    printf("请输入姓名\n");
    scanf("%s",worker->name);
    getchar();
    printf("请输入性别(男性:'M',女性:'F')\n");
    worker->gender=getchar();
    rewind(stdin);
    printf("请输入工作年龄\n");
    scanf("%d",&(worker->work_age));
    getchar();
    printf("请输入工资\n");
    scanf("%d",&(worker->wage));
    getchar();
    Wage_Combine(worker->wage,worker->wage_combine);
}


void Wage_Combine(int wage,int *combine)
{
    *combine=wage/100;
    wage=wage%100;
    *(combine+1)=wage/50;
    wage=wage%50;
    *(combine+2)=wage/20;
    wage=wage%20;
    *(combine+3)=wage/10;
    wage=wage%10;
    *(combine+4)=wage/5;
    wage=wage%5;
    *(combine+5)=wage;   
}


void SortWorkersByWage(Worker*worker,int len)
{
    Worker temp;
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j+1<len-i;j++)
        {
            if((worker+j)->wage<(worker+j+1)->wage)
            {
                temp=*(worker+j);
                *(worker+j)=*(worker+j+1);
                *(worker+j+1)=temp;
            }
        }
    }
}


void displaySingleWorker(Worker worker)
{
    printf("%s,%c,%d,%d,[100:%d 50:%d 20:%d 10:%d 5:%d 1:%d]",
    worker.name,worker.gender,worker.work_age,worker.wage,
    worker.wage_combine[0],worker.wage_combine[1],worker.wage_combine[2],worker.wage_combine[3],worker.wage_combine[4],worker.wage_combine[5]);
    
}


void displayWorkers(Worker*workers,int len)
{
    for(int i=0;i<len;i++)
    {
        displaySingleWorker(*(workers+i));
    }
}