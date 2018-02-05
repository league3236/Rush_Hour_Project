#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <gdiplus.h>
#include <time.h>
#include <stdio.h>
#include "Consola.h"
#include "View.h"

using namespace std;
#pragma comment(lib,"Gdiplus.lib")

int score=0;


void View::XYPutStr(int a, int b, char *str)			//x,y좌표로가서 문자열 출력
{
	gotoxy(a, b);
	cout << str;
}

void View::View_Logo()
{

	textbackground(BLUE);
		//첫째줄
	gotoxy(8, 3);
	cout<<"      ";
	gotoxy(38, 3);
	cout<<"  ";
	Sleep(50);

	//둘째줄
	gotoxy(6, 4);
	cout<<"  ";
	gotoxy(14, 4);
	cout<<"  ";
	gotoxy(28, 4);
	cout<<"        ";
	gotoxy(38, 4);
	cout<<"  ";
	Sleep(50);

	//셋째줄
	gotoxy(6, 5);
	cout<<"  ";
	gotoxy(14, 5);
	cout<<"  ";
	gotoxy(28, 5);
	cout<<"  ";
	gotoxy(38, 5);
	cout<<"  ";
	
	Sleep(50);

	//넷째줄
	gotoxy(6, 6);
	cout<<"        ";
	gotoxy(18, 6);
	cout<<"  ";
	gotoxy(24, 6);
	cout<<"  ";
	gotoxy(28, 6);
	cout<<"        ";
	gotoxy(38, 6);
	cout<<"        ";
	Sleep(50);

	//다섯째줄
	gotoxy(6, 7);
	cout<<"  ";
	gotoxy(14, 7);
	cout<<"  ";
	gotoxy(18, 7);
	cout<<"  ";
	gotoxy(24, 7);
	cout<<"  ";
	gotoxy(34, 7);
	cout<<"  ";
	gotoxy(38, 7);
	cout<<"  ";
	gotoxy(44, 7);
	cout<<"  ";
	Sleep(50);

	//여섯째줄
	gotoxy(6, 8);
	cout<<"  ";
	gotoxy(14, 8);
	cout<<"  ";
	gotoxy(18, 8);
	cout<<"  ";
	gotoxy(24, 8);
	cout<<"  ";
	gotoxy(34, 8);
	cout<<"  ";
	gotoxy(38, 8);
	cout<<"  ";
	gotoxy(44, 8);
	cout<<"  ";
	Sleep(50);

	//일곱째줄
	gotoxy(6, 9);
	cout<<"  ";
	gotoxy(14, 9);
	cout<<"  ";
	gotoxy(18, 9);
	cout<<"        ";
	gotoxy(28, 9);
	cout<<"        ";
	gotoxy(38, 9);
	cout<<"  ";
	gotoxy(44, 9);
	cout<<"  ";
	Sleep(50);

	//아홉번째줄
	gotoxy(28,11);
	cout<<"  ";
	Sleep(50);
	
	//열번째줄
	gotoxy(28,12);
	cout<<"  ";
	Sleep(50);

	//열한번째줄
	gotoxy(28,13);
	cout<<"  ";
	gotoxy(58,13);
	cout<<"  ";
	Sleep(50);

	//열두번째줄
	gotoxy(28,14);
	cout<<"        ";
	gotoxy(38,14);
	cout<<"        ";
	gotoxy(48,14);
	cout<<"  ";
	gotoxy(54,14);
	cout<<"  ";
	gotoxy(58,14);
	cout<<"  ";
	Sleep(50);

	//열세번째줄
	gotoxy(28,15);
	cout<<"  ";
	gotoxy(34,15);
	cout<<"  ";
	gotoxy(38,15);
	cout<<"  ";
	gotoxy(44,15);
	cout<<"  ";
	gotoxy(48,15);
	cout<<"  ";
	gotoxy(54,15);
	cout<<"  ";
	gotoxy(58,15);
	cout<<"  ";
	gotoxy(60,15);
	cout<<"    ";
	Sleep(50);

	//열네번째줄
	gotoxy(28,16);
	cout<<"  ";
	gotoxy(34,16);
	cout<<"  ";
	gotoxy(38,16);
	cout<<"  ";
	gotoxy(44,16);
	cout<<"  ";
	gotoxy(48,16);
	cout<<"  ";
	gotoxy(54,16);
	cout<<"  ";
	gotoxy(58,16);
	cout<<"  ";
	Sleep(50);

	//열다섯번째줄
	gotoxy(28,17);
	cout<<"  ";
	gotoxy(34,17);
	cout<<"  ";
	gotoxy(38,17);
	cout<<"        ";
	gotoxy(48,17);
	cout<<"        ";
	gotoxy(58,17);
	cout<<"  ";
	Sleep(50);



	textbackground(BLACK);
	textcolor(WHITE);
	gotoxy(28, 19);
	printf("Made By 박춘소, 곽승혁");
	textcolor(RED);
	gotoxy(26, 22);
	printf("Please press Any Key  ");

	fflush(stdin);
	Sleep(1000);
	_getch();
	system("cls");
	_setcursortype(_NOCURSOR); //커서 없애기
}

void View::Collect_Color()							//게임 아래에 각 컨트롤가능 블록숫자 표시
{
	textcolor(WHITE);					//텍스트 색상 WHITE
	XYPutStr(40, 9,  "┏━━━━━━━━┓");
	XYPutStr(40, 10, "┃ Please Number  ┃");
	XYPutStr(40, 11, "┃   Choose       ┃");
	XYPutStr(40, 12, "┃Move : ↑↓←→ ┃");
	XYPutStr(40, 13, "┃Your Score :    ┃");
	gotoxy(54,13);
	cout << score;				//score 출력
	XYPutStr(40, 14, "┃                ┃");
	XYPutStr(40, 15, "┃                ┃");
	XYPutStr(40, 16, "┃                ┃");
	XYPutStr(40, 17, "┃                ┃");
	XYPutStr(40, 18, "┗━━━━━━━━┛");

	gotoxy(42,15);
	textcolor(RED); cout << "■=1 ";		//각 블록 색상과 넘버 표시
	textcolor(BLUE); cout << "■=2 ";
	textcolor(GREEN); cout << "■=3";
	gotoxy(42,16);
	textcolor(CYAN); cout << "■=4 ";
	textcolor(MAGENTA); cout << "■=5 ";
	textcolor(BROWN); cout << "■=6";
	gotoxy(42,17);
	textcolor(LIGHTBLUE); cout << "■=7 ";
	textcolor(LIGHTGREEN); cout << "■=8 ";
	
}

void View::View_Sub(int _stage,int *_step)				//화면 오른쪽에 진행중이 Stage 및 
{														//옮긴 횟수 출력
	textcolor(WHITE);
	XYPutStr(40, 3, "┏━━━━━━━━┓");
	XYPutStr(40, 4, "┃ Stage :	 ┃");
	gotoxy(52, 4);
	cout << _stage;
	XYPutStr(40, 5, "┃		 ┃");
	XYPutStr(40, 6, "┃ Step  :        ┃");
	gotoxy(52, 6);
	cout << *_step;
	XYPutStr(40, 7, "┗━━━━━━━━┛");
}

void View::View_Help()
{
	textcolor(WHITE);
	XYPutStr(16, 9, "┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
	XYPutStr(16, 10, "┃                     <Help>                     ┃");
	XYPutStr(16, 11, "┃                ↑↓←→ : Move                 ┃");
	XYPutStr(16, 12, "┃     1. Press the number you want to choose.    ┃");
	XYPutStr(16, 13, "┃               2. Press the arrow key.	         ┃");
	XYPutStr(16, 14, "┃    3. The goal is to get the red block out     ┃");
	XYPutStr(16, 15, "┃	      of the board buy sliding		 ┃");
	XYPutStr(16, 16, "┃	   the other blocks out of the way.	 ┃");
	XYPutStr(16, 17, "┃			             		 ┃");
	XYPutStr(16, 18, "┃	          Space: Restart  		 ┃");
	XYPutStr(16, 19, "┗━━━━━━━━━━━━━━━━━━━━━━━━┛");
	_getch();
	system("cls");
}

int View::Show_Success(int _stage)
{
	textcolor(WHITE);
	XYPutStr(10, 5, " ┏━━━━━━━━━━━━┓");
	XYPutStr(10, 6, " ┃                        ┃");
	XYPutStr(10, 7, " ┃                        ┃");
	XYPutStr(10, 8, " ┃                        ┃");
	XYPutStr(10, 9, " ┃                        ┃");
	XYPutStr(10, 10, " ┃     Congratulation     ┃");
	XYPutStr(10, 11, " ┃                        ┃");
	XYPutStr(10, 12, " ┃                        ┃");
	XYPutStr(10, 13, " ┃                        ┃");
	XYPutStr(10, 14, " ┃                        ┃");
	XYPutStr(10, 15, " ┗━━━━━━━━━━━━┛");
	Sleep(2000);
	if (_stage == 5||_stage == 9||_stage == 13||_stage == 17)
	{
	XYPutStr(10, 5, " ┏━━━━━━━━━━━━┓");
	XYPutStr(10, 6, " ┃    All Stage Clear     ┃");
	XYPutStr(10, 7, " ┃       Your Score       ┃");
	XYPutStr(10, 8, " ┃                        ┃");
	XYPutStr(10, 9, " ┃                        ┃");
	XYPutStr(10, 10, " ┃                        ┃");
	XYPutStr(10, 11, " ┃                        ┃");
	XYPutStr(10, 12, " ┃                        ┃");
	XYPutStr(10, 13, " ┃                        ┃");
	XYPutStr(10, 14, " ┃                        ┃");
	XYPutStr(10, 15, " ┗━━━━━━━━━━━━┛");
	View_Score();
		return 0;
	}
	else
		return 1;
}

int View::Sum_Score(int *_step,int _stage)			//각 스테이지가 끝났을때 점수를 더해준다.
{
	switch(_stage)
	{
		case 2:
			if(*_step<=20)
				score+=25;
			else if(*_step>20&&*_step<=23)
				score+=20;
			else if(*_step>23&&*_step<=25)
				score+=15;
			else if(*_step>25)
				score+=10;
			break;
		case 3:
			if(*_step<=26)
				score+=25;
			else if(*_step>26&&*_step<=28)
				score+=20;
			else if(*_step>28&&*_step<=31)
				score+=15;
			else if(*_step>31)
				score+=10;
			break;
		case 4:
			if(*_step<=34)
				score+=25;
			else if(*_step>34&&*_step<=36)
				score+=20;
			else if(*_step>36&&*_step<=38)
				score+=15;
			else if(*_step>38)
				score+=10;
			break;
		case 5:
			if(*_step<=34)
				score+=25;
			else if(*_step>34&&*_step<=36)
				score+=20;
			else if(*_step>36&&*_step<=38)
				score+=15;
			else if(*_step>38)
				score+=10;
			break;
	}
	return score;
}

void View::View_Score()
{
	textcolor(YELLOW);
	if(score>=90)
	{
		XYPutStr(12, 8 , "         ■■        ");
		Sleep(50);
		XYPutStr(12, 9 , "        ■  ■       ");
		Sleep(50);
		XYPutStr(12, 10, "       ■    ■      ");
		Sleep(50);
		XYPutStr(12, 11, "      ■■■■■     ");
		Sleep(50);
		XYPutStr(12, 12, "     ■        ■    ");
		Sleep(50);
		XYPutStr(12, 13, "    ■          ■   ");
		Sleep(50);
		XYPutStr(12, 14, "   ■            ■  ");
	}
	else if(score<90&&score>=80)
	{
		XYPutStr(14, 8 , "      ■■■■       ");
		Sleep(50);
		XYPutStr(14, 9 , "      ■      ■     ");
		Sleep(50);
		XYPutStr(14, 10, "      ■      ■     ");
		Sleep(50);
		XYPutStr(14, 11, "      ■■■■       ");
		Sleep(50);
		XYPutStr(14, 12, "      ■      ■     ");
		Sleep(50);
		XYPutStr(14, 13, "      ■      ■     ");
		Sleep(50);
		XYPutStr(14, 14, "      ■■■■       ");
	}
	else if(score<80&&score>=70)
	{
		XYPutStr(14, 8 , "        ■■■       ");
		Sleep(50);
		XYPutStr(14, 9 , "      ■      ■     ");
		Sleep(50);
		XYPutStr(14, 10, "     ■              ");
		Sleep(50);
		XYPutStr(14, 11, "    ■               ");
		Sleep(50);
		XYPutStr(14, 12, "     ■              ");
		Sleep(50);
		XYPutStr(14, 13, "      ■      ■     ");
		Sleep(50);
		XYPutStr(14, 14, "        ■■■       ");
	}
	else if(score<70&&score>=60)
	{
		XYPutStr(14, 8 , "      ■■■■       ");
		Sleep(50);
		XYPutStr(14, 9 , "      ■      ■     ");
		Sleep(50);
		XYPutStr(14, 10, "      ■       ■    ");
		Sleep(50);
		XYPutStr(14, 11, "      ■       ■    ");
		Sleep(50);
		XYPutStr(14, 12, "      ■       ■    ");
		Sleep(50);
		XYPutStr(14, 13, "      ■      ■     ");
		Sleep(50);
		XYPutStr(14, 14, "      ■■■■       ");
	}
	else if(score<60)
	{
		XYPutStr(14, 8 , "     ■■■■■■    ");
		Sleep(50);
		XYPutStr(14, 9 , "     ■              ");
		Sleep(50);
		XYPutStr(14, 10, "     ■              ");
		Sleep(50);
		XYPutStr(14, 11, "     ■■■■■      ");
		Sleep(50);
		XYPutStr(14, 12, "     ■              ");
		Sleep(50);
		XYPutStr(14, 13, "     ■              ");
		Sleep(50);
		XYPutStr(14, 14, "     ■              ");
	}
}

void View::View_Image(int _Image)
{
	using namespace Gdiplus;
	char keyInput[10] = "";
	Image *pImage = NULL;
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken = NULL;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
 
	Graphics *pGraphics = new Graphics(GetDC(GetConsoleWindow()));

	switch(_Image)
	{
		case 0:
			pImage = pGraphics ? new Image(L"Character.bmp") : NULL;
			break;
		case 1:
			pImage = pGraphics ? new Image(L"RED.bmp") : NULL;
			XYPutStr(45, 20, "┏━━━━━━━━┓");
			XYPutStr(45, 21, "┃ 내이름은 맥퀸  ┃");
			XYPutStr(45, 22, "┃세계의 유명인사 ┃");
			XYPutStr(45, 23, "┃나를모르는다니  ┃");
			XYPutStr(45, 24, "┃간첩은 아니겠지?┃");
			XYPutStr(45, 25, "┗━━━━━━━━┛");
			break;
		case 2:
			pImage = pGraphics ? new Image(L"BLUE.bmp") : NULL;
			XYPutStr(45, 20, "┏━━━━━━━━┓");
			XYPutStr(45, 21, "┃ 나는 최고의    ┃");
			XYPutStr(45, 22, "┃      비밀요원  ┃");
			XYPutStr(45, 23, "┃   거기 너!!!   ┃");
			XYPutStr(45, 24, "┃내 비밀을 지켜라┃");
			XYPutStr(45, 25, "┗━━━━━━━━┛");
			break;
		case 3:
			pImage = pGraphics ? new Image(L"GREEN.bmp") : NULL;
			XYPutStr(45, 20, "┏━━━━━━━━┓");
			XYPutStr(45, 21, "┃ 다 비켜라!!    ┃");
			XYPutStr(45, 22, "┃   내가가는길을 ┃");
			XYPutStr(45, 23, "┃ 막을자는 없다  ┃");
			XYPutStr(45, 24, "┃  우하하하하하  ┃");
			XYPutStr(45, 25, "┗━━━━━━━━┛");
			break;
		case 4:
			pImage = pGraphics ? new Image(L"CYAN.bmp") : NULL;
			XYPutStr(47, 20, "┏━━━━━━━━┓");
			XYPutStr(47, 21, "┃ 내 미모를      ┃");
			XYPutStr(47, 22, "┃   닮고싶다고?? ┃");
			XYPutStr(47, 23, "┃ 고맙지만       ┃");
			XYPutStr(47, 24, "┃너도 충분히이뻐 ┃");
			XYPutStr(47, 25, "┗━━━━━━━━┛");
			break;
		case 5:
			pImage = pGraphics ? new Image(L"MAGENTA.bmp") : NULL;
			XYPutStr(45, 20, "┏━━━━━━━━┓");
			XYPutStr(45, 21, "┃ 하..정말로     ┃");
			XYPutStr(45, 22, "┃ 비밀요원도     ┃");
			XYPutStr(45, 23, "┃ 모해먹겠군     ┃");
			XYPutStr(45, 24, "┃ 일탈하고 싶다  ┃");
			XYPutStr(45, 25, "┗━━━━━━━━┛");
			break;
		case 6:
			pImage = pGraphics ? new Image(L"BROWN.bmp") : NULL;
			XYPutStr(45, 20, "┏━━━━━━━━┓");
			XYPutStr(45, 21, "┃ 나를 가진다고? ┃");
			XYPutStr(45, 22, "┃ 흠... 노력좀   ┃");
			XYPutStr(45, 23, "┃ 해야될거야     ┃");
			XYPutStr(45, 24, "┃ 엄청 비싸거든  ┃");
			XYPutStr(45, 25, "┗━━━━━━━━┛");
			break;
		case 7:
			pImage = pGraphics ? new Image(L"LIGHTBLUE.bmp") : NULL;
			XYPutStr(45, 20, "┏━━━━━━━━┓");
			XYPutStr(45, 21, "┃ 우리는 새로운  ┃");
			XYPutStr(45, 22, "┃ 미션이 필요해  ┃");
			XYPutStr(45, 23, "┃ 엄청 굶주린    ┃");
			XYPutStr(45, 24, "┃  야생마라고!!  ┃");
			XYPutStr(45, 25, "┗━━━━━━━━┛");
			break;
		case 8:
			pImage = pGraphics ? new Image(L"LIGHTGREEN.bmp") : NULL;
			XYPutStr(45, 20, "┏━━━━━━━━┓");
			XYPutStr(45, 21, "┃ 나만 큼 빠른애 ┃");
			XYPutStr(45, 22, "┃ 있으면 나와봐  ┃");
			XYPutStr(45, 23, "┃ 없다면 다들    ┃");
			XYPutStr(45, 24, "┃ 집에서 발씻구자┃");
			XYPutStr(45, 25, "┗━━━━━━━━┛");
			break;
		default:
			printf("Error\n");
			break;
	}

	if (pImage)
	{
		if(_Image==0)
			pGraphics->DrawImage(pImage,60, 100);
		else
			pGraphics->DrawImage(pImage,100, 320);
		
	}
 
	delete pImage;
	delete pGraphics;
	GdiplusShutdown(gdiplusToken);
}

void View::delete_Image()
{
	textcolor(WHITE);
	XYPutStr(12, 20, "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚");
	XYPutStr(40, 21, "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ");
	XYPutStr(40, 22, "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚");
	XYPutStr(40, 23, "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ");
	XYPutStr(40, 24, "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚");
	XYPutStr(40, 25, "˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ");
	XYPutStr(40, 26, "     ˚     ˚     ˚     ˚     ˚     ˚     ˚     ˚");
}
