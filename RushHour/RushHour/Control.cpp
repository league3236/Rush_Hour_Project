#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Consola.h"
#include "Control.h"
#include "Display.h"
#include "Stage.h"
#include "Model.h"
#include "View.h"


using namespace std;

int Block_N;		//Block선택 받음
int Key;			//방향 선택받음
int oldch;			//전에 블록 그대로 선택
int _Character=1;   //캐릭터 선택에 따라 맵출력ㄴ

Control::Control()
{

}

int Control::Direct_Getkey() {
	int ch;
	ch = _getch();
	return (ch == 0xe0) ? (0xe000 | _getch()) : ch;
}

int Control::Block_Numkey() {
	int ch;
	ch = _getch();
	textcolor(WHITE);
	View q;
	if(ch>='1'&&ch<='9')
	{
		gotoxy(42,8);									//(40,4)로 이동해서 선택한 블록 출력
		oldch=ch;
		std::cout<<"Collect:";
		switch(char(ch))								//어떤 블록을 선택했는지 나타내줌.
		{
		case '1':
			textcolor(RED);
			std::cout << "■";
			q.delete_Image();
			q.View_Image(1);
			break;
		case '2':
			textcolor(BLUE);
			std::cout << "■";
			q.delete_Image();
			q.View_Image(2);
			break;
		case '3':
			textcolor(GREEN);
			std::cout << "■";
			q.delete_Image();
			q.View_Image(3);
			break;
		case '4':
			textcolor(CYAN);
			std::cout << "■";
			q.delete_Image();
			q.View_Image(4);
			break;
		case '5':
			textcolor(MAGENTA);
			std::cout << "■";
			q.delete_Image();
			q.View_Image(5);
			break;
		case '6':
			textcolor(BROWN);
			std::cout << "■";
			q.delete_Image();
			q.View_Image(6);
			break;
		case '7':
			textcolor(LIGHTBLUE);
			std::cout << "■";
			q.delete_Image();
			q.View_Image(7);
			break;
		case '8':
			textcolor(LIGHTGREEN);
			std::cout << "■";
			q.delete_Image();
			q.View_Image(8);
			break;
		}
		return ch;				//숫자면 전 ch받음
	}
	else{
		getch();						//방향표는 int 값을 두번받기에 한번을 getch()로 받아들임
		Key=ch;
		return oldch;				//만약 숫자가 아닌 방향키가 입력되면 전에 블록을 움직이게 만들수있도록 바꿈.
	}
}

void Control::Select_Character()
{
	View v;
	v.View_Image(0);
	int _x=4,_y=10;
	int _oldx,_oldy;
	int key;
	int _Select=0;

	textcolor(BLUE);
	gotoxy(_x,_y);
	cout << "●";
	while(_Select!=1)
	{
		_oldx=_x;
		_oldy=_y;
		key=Direct_Getkey();					//방향키를 받아옴
			if(key==M_DOWNKEY&&_y<17)
			{
				gotoxy(_oldx,_oldy);
				cout << "  ";
				_y+=7;
				gotoxy(_x,_y);
				cout << "●";
			}
			else if(key==M_UPKEY&&_y>10)
			{
				gotoxy(_oldx,_oldy);
				cout << "   ";
				_y-=7;
				gotoxy(_x,_y);
				cout << "●";
			}
			else if(key==M_RIGHTKEY&&_x<68)
			{
				gotoxy(_oldx,_oldy);
				cout << "   ";
				_x+=66;
				gotoxy(_x,_y);
				cout << "●";
			}
			else if(key==M_LEFTKEY&&_x>4)
			{
				gotoxy(_oldx,_oldy);
				cout << "   ";
				_x-=66;
				gotoxy(_x,_y);
				cout << "●";
			}
			else if(key==32)
			{
				{
				_Select=1;
				if(_x==4&&_y==10)
					_Character=1;			//케릭터 레드
				else if(_x==70&&_y==10)
					_Character=2;			//케릭터 블루
				else if(_x==4&&_y==17)
					_Character=3;			//케릭터 퍼플
				else if(_x==70&&_y==17)
					_Character=4;			//케릭터 그린
				}
				
			}
	}
	system("cls");					//전체화면 지우기
}

void Control::Game_Control(int stage)
{

	int x,y;
	int end;
	int step=0;						//스텝은 0으로 지정
	int *_step; _step=&step;		//포인트 변수 사용으로 step의 주소를 가르킴.
	Stage s;
	View v;
	Display r;
	switch(_Character)					//선택 캐릭터에 따라서 맵출력
	{
		case 2:
			stage+=4;
			break;
		case 3:
			stage+=8;
			break;
		case 4:
			stage+=12;
			break;
	}
	s.Map_Print(stage);					//멥출력
	v.Collect_Color();					//각 선택블록에 따른 칼라 출력

		do{
		Block_N=Block_Numkey();					//블록의 숫자를 받아옴
		Key=Direct_Getkey();					//방향키를 받아옴
		x=s.Find_X(stage,Block_N);				//배열안에서 블록숫자에 해당하는 x값 가져옴.
		y=s.Find_Y(stage,Block_N);				//배열안에서 블록숫자에 해당하는 y값 가져옴.
		s.Trans_Matrix(Key,stage,Block_N,x,y,_step);		//해당 블록,해당 방향키로 배열 데이터값 변환.
		v.View_Sub(stage-1,_step);			//Sub 표시줄(난이도 및 움직인 횟수 표시)
		end=s.End_Block(stage,_Character);
	}while(end);
		v.Sum_Score(_step,stage);
		system("cls");					//전체화면 지우기
		r.Background();				//배경 출력
		v.Show_Success(stage);				//성공화면 출력.
}

void Control::Game_Start()		//컨트롤클레스의 메인함수
{

	View MyView;
	Display MyGame;
	MyGame.Background();			//배경 출력

	MyView.View_Logo();
	MyGame.Background();			//배경출력

	MyView.View_Help();				//게임 도움말
	MyGame.Background();			//배경출력

	MyGame.Game_Bagic();			//기본 게임틀 제작
	MyGame.Background();			//배경출력

	Select_Character();	        	//게임 캐릭터 선택
	MyGame.Background();			//배경출력

	MyGame.Game_Loading();			//게임 로딩화면
	delay(3000);					//3초 딜레이

	MyGame.Game_Level(1,"★");		//다음 난이도 표시
	delay(3000);					//3초 딜레이

	Stage MyMap;							
	MyGame.Background();			//배경출력
	Game_Control(2);						//첫번째 스테이지 시작과 컨트롤

	MyGame.Game_Level(2,"★★");		//다음 난이도 표시
	delay(3000);					//3초 딜레이
	
	MyGame.Background();			//배경출력
	Game_Control(3);						//두번째 스테이지 시작과 컨트롤
	
	MyGame.Game_Level(3,"★★★");		//다음 난이도 표시
	delay(3000);					//3초 딜레이
	
	MyGame.Background();			//배경출력
	Game_Control(4);						//세번째 스테이지 시작과 컨트롤
	
	MyGame.Game_Level(4,"★★★★");		//다음 난이도 표시
	delay(3000);					//3초 딜레이
	
	MyGame.Background();			//배경출력
	Game_Control(5);						//네번째 스테이지 시작과 컨트롤
}

