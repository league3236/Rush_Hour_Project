#include <iostream>
#include "Consola.h"
#include "Display.h"
#include "Stage.h"
#include "Model.h"

using namespace std;

void Display::Background()
{
	textbackground(BLACK); //���� ���� ����
	textcolor(WHITE);
	gotoxy(1,1);
	for(int i=0;i<=13;i++)
	{
	cout << "     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��"<<endl;
	cout << "��     ��     ��     ��     ��     ��     ��     ��     ��     ��     ��     "<<endl;
	}
}

void Display::Game_Bagic()			//���� �⺻ ����
{
	_setcursortype(_NOCURSOR);
	textbackground(BLACK); //���� ���� ����
	clrscr();					//��üȭ�� �����
	textcolor(WHITE);			//���ڻ� ����
	textbackground(BLACK);		//���� ���� ����
	gotoxy(12,4);
}


void Display::Game_Loading()		//���� �ε� ȭ��
{
	Stage BAGIC;
	BAGIC.Map_Print(1);
	textcolor(WHITE);
	gotoxy(20,9);
	cout << "Rush Hour";
	gotoxy(20,11);
	cout << "Game Start";
	gotoxy(28,13);
	cout << "By.����";
	gotoxy(31,14);
	cout << "���";
	textcolor(BLACK);
}

void Display::Game_Level(int level,char *star)				//���� ���� ���̵� ���
{
	Background();			//������
	Stage BAGIC;
	BAGIC.Map_Print(1);
	textcolor(WHITE);
	gotoxy(20,9);
	cout << "NEXT";
	gotoxy(26,10);
	cout << "STAGE";
	gotoxy(27,12);
	cout << level;
	gotoxy(18,14);

	cout << "���̵� : ";
	textcolor(YELLOW);
	cout << star;
}