#include<stdio.h>
#include<easyx.h>
int main(void)
{
	initgraph(1920, 1142,EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	IMAGE ima_eye;
	loadimage(&ima_eye, "C:\\Users\\48163\\Desktop\\eye.jpg",1920/10,1142/10);//�Ƚ���Ŀ���Ը�Ϊ���ֽ��ַ���
	putimage(0, 0,&ima_eye);

	//�ٳ�ͼƬ����
	IMAGE ima_eye1;
	IMAGE ima_eye2;
	loadimage(&ima_eye1, "eye1.jpg",1920/5,1142/5);
	loadimage(&ima_eye2, "eye2.jpg",1920/5,1142/5);
	putimage(1920 / 5, 1142 / 5, &ima_eye2,NOTSRCERASE);//����ͼ
	putimage(1920 / 5, 1142 / 5, &ima_eye1,SRCINVERT);//ԭͼ

	getchar();
	return 0;
}