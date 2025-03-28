//此处为data_structure_exercise_14的升级版
/*
注意:判定回文字符串的机制是将同一英文字母的小写版本与大写版本视为同一种，但是不统一成小写或者大写的格式
例如AaaaBbbDdee将展示为AaDeBbbedaa，而不是像data_structure_exercise_14代码中统一为AADEBBBEDAA
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void build(char * str);
int main(void)
{
    char str[]="AaaABbCCCcDddDdEeeFF";
    build(str);
    return 0;
}



void build(char * str)
{   
    int * lower_str=(int *)calloc(26,sizeof(int));
    int * upper_str=(int *)calloc(26,sizeof(int));
    int * final_str=(int *)calloc(26,sizeof(int));
    for (int i=0;i<strlen(str);i++)
    {
        if (str[i]>='a'&&str[i]<='z')
        {   
            lower_str[str[i]-'a']++;
        }
        else if (str[i]>='A'&&str[i]<='Z')
        {
            upper_str[str[i]-'A']++;
        }
    }   
    for (int i=0;i<26;i++)
    {
        final_str[i]=upper_str[i]+lower_str[i];
    }



    int is_odd=0;
    int odd_pos=-1;
    int length=0;
    for (int i=0;i<26;i++)      //确保只有一个奇数
    {
        if (final_str[i]%2==1)
        {
            if (is_odd==0)
            {
                is_odd=1;
                odd_pos=i;
                length+=final_str[i];
            }
            else
            {
                final_str[i]-=1;
                length+=final_str[i];
            }
        }
        else
        {
            length+=final_str[i];
        }
    }


    
    char * result=(char *)calloc(length+1,sizeof(char));
    result[length]='\0';
    if (is_odd==1)
    {
        for(int i=length/2-(final_str[odd_pos]-1)/2;i<length/2;i++)     //优先处理出现次数为奇数次的单词
        {
            if (lower_str[odd_pos]>0)
            {
                result[i]=odd_pos+'a';
                lower_str[odd_pos]-=1;
            }
            else 
            {
                printf("%d",upper_str[odd_pos]);
                result[i]=odd_pos+'A';
                upper_str[odd_pos]-=1;
            }

            if (lower_str[odd_pos]>0)
            {
                result[length-1-i]=odd_pos+'a';
                lower_str[odd_pos]-=1;
            }
            else
            {
                result[length-1-i]=odd_pos+'A';
                upper_str[odd_pos]-=1;
            }
        }

        if (lower_str[odd_pos]>0)
        {
            result[length/2]=odd_pos+'a';
            lower_str[odd_pos]-=1;
        }
        else
        {
            result[length/2]=odd_pos+'A';
            upper_str[odd_pos]-=1;
        }
    }

    
    int i=0;
    int j=0;
    while(1)        //处理出现次数为偶数次的单词
    {
        if(lower_str[j]>0||upper_str[j]>0)
        {
            if (lower_str[j]>0)
            {
                result[i]=j+'a';
                lower_str[j]-=1;
            }
            else if (upper_str[j]>0)
            {
                result[i]=j+'A';
                upper_str[j]-=1;
            }
            if (lower_str[j]>0)
            {
                result[length-i-1]=j+'a';
                lower_str[j]-=1;
                i++;
            }
            else if (upper_str[j]>0)
            {
                result[length-i-1]=j+'A';
                upper_str[j]-=1;
                i++;
            }
                
        }
        else
        {
            if (j<25)
            {
                j++;
            }
            else
            {
                break;
            }
        }
    }

    printf("%s",result);

}