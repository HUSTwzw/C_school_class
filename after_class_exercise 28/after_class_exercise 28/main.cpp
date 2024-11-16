#include<stdio.h>
#include<easyx.h>
int main(void)
{
	initgraph(1000, 500, EX_SHOWCONSOLE);
	setbkcolor(DARKGRAY);
	cleardevice();
	IMAGE girl[2];
	loadimage(girl, "girl1.jpg",500,250);//先将字符串设置为多字符集
	loadimage(girl + 1, "girl2.jpg",500,250);
	putimage(0,0, girl + 1, NOTSRCERASE);
	putimage(0,0, girl, SRCINVERT);
	settextstyle(50,0,"微软雅黑");//设置文本样式,数字0为默认值
	settextcolor(WHITE);//设置文本颜色
	setbkmode(TRANSPARENT);//将背景设置为透明
	outtextxy(600, 125,"That girl");//输出文本内容
	outtextxy(600, 260, "beautiful!!!");
	getchar();//防止退出
	return 0;
}

//一般格式：
//initgraph(number,number,EX_SHOWCONSOLE|EX_NOCLOSE)
//setbkcolor(COLOR);
//cleardevice();
//IMAGE picture[2];
//loadimage(picture,"",number,number);//掩码图
//loadimage(picture+1,"",number,number);//原图
//putimage(number,number,picture,NOTSRCERASE);
//putimage(number,number,picture+1,SRCINVERT);
//settextstyle(number,number,"STYLE")
//settextcolor(COLOR);
//setbkmode(TRANSPARENT);
//outtextxy(number,number,"content");
//getchar();
//return 0;