#include<stdio.h>
#include<easyx.h>
int main(void)
{
	initgraph(1000, 500, EX_SHOWCONSOLE);
	setbkcolor(DARKGRAY);
	cleardevice();
	IMAGE girl[2];
	loadimage(girl, "girl1.jpg",500,250);//�Ƚ��ַ�������Ϊ���ַ���
	loadimage(girl + 1, "girl2.jpg",500,250);
	putimage(0,0, girl + 1, NOTSRCERASE);
	putimage(0,0, girl, SRCINVERT);
	settextstyle(50,0,"΢���ź�");//�����ı���ʽ,����0ΪĬ��ֵ
	settextcolor(WHITE);//�����ı���ɫ
	setbkmode(TRANSPARENT);//����������Ϊ͸��
	outtextxy(600, 125,"That girl");//����ı�����
	outtextxy(600, 260, "beautiful!!!");
	getchar();//��ֹ�˳�
	return 0;
}

//һ���ʽ��
//initgraph(number,number,EX_SHOWCONSOLE|EX_NOCLOSE)
//setbkcolor(COLOR);
//cleardevice();
//IMAGE picture[2];
//loadimage(picture,"",number,number);//����ͼ
//loadimage(picture+1,"",number,number);//ԭͼ
//putimage(number,number,picture,NOTSRCERASE);
//putimage(number,number,picture+1,SRCINVERT);
//settextstyle(number,number,"STYLE")
//settextcolor(COLOR);
//setbkmode(TRANSPARENT);
//outtextxy(number,number,"content");
//getchar();
//return 0;