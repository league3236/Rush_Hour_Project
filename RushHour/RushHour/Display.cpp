#include <iostream>
#include "Consola.h"
#include "Display.h"
#include "Stage.h"
#include "Model.h"

using namespace std;

void Display::Background()
{
	textbackground(BLACK); //글자 배경색 지정
	textcolor(WHITE);
	gotoxy(1,1);
	for(int i=0;i<=13;i++)
	{
	cout << "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚"<<endl;
	cout << "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     "<<endl;
	}
}

void Display::Game_Bagic()			//게임 기본 바탕
{
	_setcursortype(_NOCURSOR);
	textbackground(BLACK); //글자 배경색 지정
	clrscr();					//전체화면 지우기
	textcolor(WHITE);			//글자색 지정
	textbackground(BLACK);		//글자 배경색 지정
	gotoxy(12,4);
}


void Display::Game_Loading()		//게임 로딩 화면
{
	Stage BAGIC;
	BAGIC.Map_Print(1);
	textcolor(WHITE);
	gotoxy(20,9);
	cout << "Rush Hour";
	gotoxy(20,11);
	cout << "Game Start";
	gotoxy(28,13);
	cout << "By.승혁";
	gotoxy(31,14);
	cout << "춘소";
	textcolor(BLACK);
}

void Display::Game_Level(int level,char *star)				//다음 시작 난이도 출력
{
	Background();			//배경출력
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

	cout << "난이도 : ";
	textcolor(YELLOW);
	cout << star;
}