/*
��windows+R������cmd���ٽ�exe�ļ��Ž�ȥ������ճ�������͵õ�C:\Users\48163>F:\VC2010.program\THQ\test\Debug\test.exe
����test�ǿ�ִ���ļ������ƣ���exe��׺�����������ո񣬲��������������ַ���ÿ������ո���൱��һ���ַ���������������һ��������
����C:\Users\48163>F:\VC2010.program\THQ\test\Debug\test.exe nihao wohao�൱�ڹ������ַ����ֱ�Ϊtest��nihao��wohao
*/




#include <stdio.h>
//Project_>set program's arguments...

int main(int argc,char *argv[])
//argc ��Ų���������ϵͳ�Զ�ͳ�Ʋ��������������˱�����
//�ڶ����������ַ�ָ�����飬����ַ�ָ�룬ÿ���ַ�ָ�붼ָ��һ���ַ��������������׵�ַ
//*argvָ���һ���ַ��������ַ�,*(argv+1)ָ��ڶ����ַ��������ַ�,*��argv+2��ָ��������ַ��������ַ�����
//*argv��ЧΪargv[0],*(argv+1)��ЧΪargv[1],*(argv+2)��ЧΪargv[2]����
//csdn���ѧϰ���ӡ�C������������https://mbd.baidu.com/ma/s/wJQs5MTG   https://mbd.baidu.com/ma/s/Tb5yefHE

{
    int i;
    printf("%d\n",argc);
    for(i=0;i<argc;i++)
    	printf("%d:  %s\n",i, argv[i]);
    return 0;
}