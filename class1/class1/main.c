/*
按windows+R，输入cmd，再将exe文件放进去（复制粘贴），就得到C:\Users\48163>F:\VC2010.program\THQ\test\Debug\test.exe
其中test是可执行文件的名称，在exe后缀后面可以输入空格，并继续输入其他字符，每次输入空格就相当于一串字符结束（即输入完一个参数）
例如C:\Users\48163>F:\VC2010.program\THQ\test\Debug\test.exe nihao wohao相当于共三个字符，分别为test、nihao、wohao
*/




#include <stdio.h>
//Project_>set program's arguments...

int main(int argc,char *argv[])
//argc 存放参数个数（系统自动统计参数个数并传给此变量）
//第二个参数是字符指针数组，存放字符指针，每个字符指针都指向一个字符串（参数）的首地址
//*argv指向第一个字符串的首字符,*(argv+1)指向第二个字符串的首字符,*（argv+2）指向第三个字符串的首字符……
//*argv等效为argv[0],*(argv+1)等效为argv[1],*(argv+2)等效为argv[2]……
//csdn相关学习链接【C主函数参数】https://mbd.baidu.com/ma/s/wJQs5MTG   https://mbd.baidu.com/ma/s/Tb5yefHE

{
    int i;
    printf("%d\n",argc);
    for(i=0;i<argc;i++)
    	printf("%d:  %s\n",i, argv[i]);
    return 0;
}