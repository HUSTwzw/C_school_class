#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>//只包含最新的API（函数）,easyx库是专门给C++使用的库，因此源文件需要时.cpp的后缀
//#include<graphics.h>//不仅包含easyx.h，还包括旧版本的一系列函数
void drawshape();
int main(void)
{
	initgraph(640, 480,EX_SHOWCONSOLE|EX_NOCLOSE|EX_NOMINIMIZE);//initial graph	创建窗口(长度,宽度,flag)，第三个参数flag有如下四种
	/*
	#define EX_SHOWCONSOLE		1		// Maintain the console window when creating a graphics window	即保持控制台(console)窗口存在
	#define EX_NOCLOSE			2		// Disable the close button	禁止删除窗口
	#define EX_NOMINIMIZE		4		// Disable the minimize button	禁止最小化窗口
	#define EX_DBLCLKS			8		// Support double-click events	支持鼠标双击事件
	*/
	setbkcolor(RGB(239,136,190));//set background color	设置窗口的背景颜色,此时窗口颜色还未改变,还需要用此颜色清空（填充）整个窗口
	//颜色可以是系统已有的颜色,也可以通过输入三原色数据确定颜色,即RGB（红色数值，绿色数值，蓝色数值）,可以通过windows+R打开mspaint软件寻找颜色
	cleardevice();//clear device	使用当前背景色清空绘图设备
	drawshape();//调用自己创建的函数
	getchar();//只要不在console中输入字符,就不会退出程序,以此确保创建的窗口长时间停留
	return 0;
}


void drawshape()
{
	putpixel(50, 50, WHITE);//put pixel(pixel英文意思是像素点)	在特定坐标放置一个特定颜色的点
	
	setlinecolor(BLUE);//设置线的颜色（颜色名或者RGB值）
	setlinestyle(PS_SOLID,6);//设置线的样式（线条的样式，粗细度）
	line(0, 0, 10, 50);//绘制线(起始坐标,末尾坐标)
	
	rectangle(100, 200, 50, 250);//绘制矩形（对顶角的坐标）
	setfillcolor(GREEN);//设置填充颜色（颜色名或者RGB）
	fillrectangle(100, 0, 200, 50);//绘制一个填充特定颜色的矩形（矩形对顶角坐标）
	solidrectangle(400, 50, 450, 150);//无边框填充矩形
	
	roundrect(200, 400, 400, 450,50,30);//绘制圆角矩形（矩形对角线坐标,构成圆角矩形的圆角的椭圆宽度，构成圆角矩形的圆角的椭圆高度）
	setfillcolor(YELLOW);
	fillroundrect(300,300,350,350,20,20);//绘制填充特定颜色的带特定圆角的矩形
	solidroundrect(400, 200, 450, 300, 10, 20);//绘制一个无边框填充圆角矩形
	
	circle(30, 300, 20);//绘制圆（圆心坐标，半径）
	setfillcolor(LIGHTBLUE);
	fillcircle(60, 400, 20);//绘制填充特定颜色的圆
	solidcircle(60, 450, 20);//绘制无边框填充圆

	ellipse(300, 100, 350, 200);//绘制椭圆（矩形对角线坐标）,绘制椭圆的原理是根据参数确定矩形，绘制出矩形的内接椭圆
	setfillcolor(LIGHTGREEN);
	fillellipse(200, 100, 250, 200);//绘制填充特定颜色的椭圆
	solidellipse(300, 0, 350, 80);//绘制无边框填充椭圆

	POINT points[] = { {500,10}, { 500,100 } ,{ 400,30 }, { 600,400 },{540,200}, { 560,300 } };
	setlinecolor(BLACK);
	polyline(points, 6);//通过连接数组中六个坐标对应的点绘制折线

	//使用过setlinecolor则后续线的颜色都会默认为此颜色，除非再使用setlinecolor更改
	//使用过setfillcolor则后续填充颜色都会默认为此颜色，除非再使用setfillcolor更改
}