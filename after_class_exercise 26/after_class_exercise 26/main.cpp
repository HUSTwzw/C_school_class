#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>//ֻ�������µ�API��������,easyx����ר�Ÿ�C++ʹ�õĿ⣬���Դ�ļ���Ҫʱ.cpp�ĺ�׺
//#include<graphics.h>//��������easyx.h���������ɰ汾��һϵ�к���
void drawshape();
int main(void)
{
	initgraph(640, 480,EX_SHOWCONSOLE|EX_NOCLOSE|EX_NOMINIMIZE);//initial graph	��������(����,���,flag)������������flag����������
	/*
	#define EX_SHOWCONSOLE		1		// Maintain the console window when creating a graphics window	�����ֿ���̨(console)���ڴ���
	#define EX_NOCLOSE			2		// Disable the close button	��ֹɾ������
	#define EX_NOMINIMIZE		4		// Disable the minimize button	��ֹ��С������
	#define EX_DBLCLKS			8		// Support double-click events	֧�����˫���¼�
	*/
	setbkcolor(RGB(239,136,190));//set background color	���ô��ڵı�����ɫ,��ʱ������ɫ��δ�ı�,����Ҫ�ô���ɫ��գ���䣩��������
	//��ɫ������ϵͳ���е���ɫ,Ҳ����ͨ��������ԭɫ����ȷ����ɫ,��RGB����ɫ��ֵ����ɫ��ֵ����ɫ��ֵ��,����ͨ��windows+R��mspaint���Ѱ����ɫ
	cleardevice();//clear device	ʹ�õ�ǰ����ɫ��ջ�ͼ�豸
	drawshape();//�����Լ������ĺ���
	getchar();//ֻҪ����console�������ַ�,�Ͳ����˳�����,�Դ�ȷ�������Ĵ��ڳ�ʱ��ͣ��
	return 0;
}


void drawshape()
{
	putpixel(50, 50, WHITE);//put pixel(pixelӢ����˼�����ص�)	���ض��������һ���ض���ɫ�ĵ�
	
	setlinecolor(BLUE);//�����ߵ���ɫ����ɫ������RGBֵ��
	setlinestyle(PS_SOLID,6);//�����ߵ���ʽ����������ʽ����ϸ�ȣ�
	line(0, 0, 10, 50);//������(��ʼ����,ĩβ����)
	
	rectangle(100, 200, 50, 250);//���ƾ��Σ��Զ��ǵ����꣩
	setfillcolor(GREEN);//���������ɫ����ɫ������RGB��
	fillrectangle(100, 0, 200, 50);//����һ������ض���ɫ�ľ��Σ����ζԶ������꣩
	solidrectangle(400, 50, 450, 150);//�ޱ߿�������
	
	roundrect(200, 400, 400, 450,50,30);//����Բ�Ǿ��Σ����ζԽ�������,����Բ�Ǿ��ε�Բ�ǵ���Բ��ȣ�����Բ�Ǿ��ε�Բ�ǵ���Բ�߶ȣ�
	setfillcolor(YELLOW);
	fillroundrect(300,300,350,350,20,20);//��������ض���ɫ�Ĵ��ض�Բ�ǵľ���
	solidroundrect(400, 200, 450, 300, 10, 20);//����һ���ޱ߿����Բ�Ǿ���
	
	circle(30, 300, 20);//����Բ��Բ�����꣬�뾶��
	setfillcolor(LIGHTBLUE);
	fillcircle(60, 400, 20);//��������ض���ɫ��Բ
	solidcircle(60, 450, 20);//�����ޱ߿����Բ

	ellipse(300, 100, 350, 200);//������Բ�����ζԽ������꣩,������Բ��ԭ���Ǹ��ݲ���ȷ�����Σ����Ƴ����ε��ڽ���Բ
	setfillcolor(LIGHTGREEN);
	fillellipse(200, 100, 250, 200);//��������ض���ɫ����Բ
	solidellipse(300, 0, 350, 80);//�����ޱ߿������Բ

	POINT points[] = { {500,10}, { 500,100 } ,{ 400,30 }, { 600,400 },{540,200}, { 560,300 } };
	setlinecolor(BLACK);
	polyline(points, 6);//ͨ���������������������Ӧ�ĵ��������

	//ʹ�ù�setlinecolor������ߵ���ɫ����Ĭ��Ϊ����ɫ��������ʹ��setlinecolor����
	//ʹ�ù�setfillcolor����������ɫ����Ĭ��Ϊ����ɫ��������ʹ��setfillcolor����
}