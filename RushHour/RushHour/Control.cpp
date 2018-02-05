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

int Block_N;		//Block���� ����
int Key;			//���� ���ù���
int oldch;			//���� ��� �״�� ����
int _Character=1;   //ĳ���� ���ÿ� ���� ����¤�

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
		gotoxy(42,8);									//(40,4)�� �̵��ؼ� ������ ��� ���
		oldch=ch;
		std::cout<<"Collect:";
		switch(char(ch))								//� ����� �����ߴ��� ��Ÿ����.
		{
		case '1':
			textcolor(RED);
			std::cout << "��";
			q.delete_Image();
			q.View_Image(1);
			break;
		case '2':
			textcolor(BLUE);
			std::cout << "��";
			q.delete_Image();
			q.View_Image(2);
			break;
		case '3':
			textcolor(GREEN);
			std::cout << "��";
			q.delete_Image();
			q.View_Image(3);
			break;
		case '4':
			textcolor(CYAN);
			std::cout << "��";
			q.delete_Image();
			q.View_Image(4);
			break;
		case '5':
			textcolor(MAGENTA);
			std::cout << "��";
			q.delete_Image();
			q.View_Image(5);
			break;
		case '6':
			textcolor(BROWN);
			std::cout << "��";
			q.delete_Image();
			q.View_Image(6);
			break;
		case '7':
			textcolor(LIGHTBLUE);
			std::cout << "��";
			q.delete_Image();
			q.View_Image(7);
			break;
		case '8':
			textcolor(LIGHTGREEN);
			std::cout << "��";
			q.delete_Image();
			q.View_Image(8);
			break;
		}
		return ch;				//���ڸ� �� ch����
	}
	else{
		getch();						//����ǥ�� int ���� �ι��ޱ⿡ �ѹ��� getch()�� �޾Ƶ���
		Key=ch;
		return oldch;				//���� ���ڰ� �ƴ� ����Ű�� �ԷµǸ� ���� ����� �����̰� ������ֵ��� �ٲ�.
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
	cout << "��";
	while(_Select!=1)
	{
		_oldx=_x;
		_oldy=_y;
		key=Direct_Getkey();					//����Ű�� �޾ƿ�
			if(key==M_DOWNKEY&&_y<17)
			{
				gotoxy(_oldx,_oldy);
				cout << "  ";
				_y+=7;
				gotoxy(_x,_y);
				cout << "��";
			}
			else if(key==M_UPKEY&&_y>10)
			{
				gotoxy(_oldx,_oldy);
				cout << "   ";
				_y-=7;
				gotoxy(_x,_y);
				cout << "��";
			}
			else if(key==M_RIGHTKEY&&_x<68)
			{
				gotoxy(_oldx,_oldy);
				cout << "   ";
				_x+=66;
				gotoxy(_x,_y);
				cout << "��";
			}
			else if(key==M_LEFTKEY&&_x>4)
			{
				gotoxy(_oldx,_oldy);
				cout << "   ";
				_x-=66;
				gotoxy(_x,_y);
				cout << "��";
			}
			else if(key==32)
			{
				{
				_Select=1;
				if(_x==4&&_y==10)
					_Character=1;			//�ɸ��� ����
				else if(_x==70&&_y==10)
					_Character=2;			//�ɸ��� ���
				else if(_x==4&&_y==17)
					_Character=3;			//�ɸ��� ����
				else if(_x==70&&_y==17)
					_Character=4;			//�ɸ��� �׸�
				}
				
			}
	}
	system("cls");					//��üȭ�� �����
}

void Control::Game_Control(int stage)
{

	int x,y;
	int end;
	int step=0;						//������ 0���� ����
	int *_step; _step=&step;		//����Ʈ ���� ������� step�� �ּҸ� ����Ŵ.
	Stage s;
	View v;
	Display r;
	switch(_Character)					//���� ĳ���Ϳ� ���� �����
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
	s.Map_Print(stage);					//�����
	v.Collect_Color();					//�� ���ú�Ͽ� ���� Į�� ���

		do{
		Block_N=Block_Numkey();					//����� ���ڸ� �޾ƿ�
		Key=Direct_Getkey();					//����Ű�� �޾ƿ�
		x=s.Find_X(stage,Block_N);				//�迭�ȿ��� ��ϼ��ڿ� �ش��ϴ� x�� ������.
		y=s.Find_Y(stage,Block_N);				//�迭�ȿ��� ��ϼ��ڿ� �ش��ϴ� y�� ������.
		s.Trans_Matrix(Key,stage,Block_N,x,y,_step);		//�ش� ���,�ش� ����Ű�� �迭 �����Ͱ� ��ȯ.
		v.View_Sub(stage-1,_step);			//Sub ǥ����(���̵� �� ������ Ƚ�� ǥ��)
		end=s.End_Block(stage,_Character);
	}while(end);
		v.Sum_Score(_step,stage);
		system("cls");					//��üȭ�� �����
		r.Background();				//��� ���
		v.Show_Success(stage);				//����ȭ�� ���.
}

void Control::Game_Start()		//��Ʈ��Ŭ������ �����Լ�
{

	View MyView;
	Display MyGame;
	MyGame.Background();			//��� ���

	MyView.View_Logo();
	MyGame.Background();			//������

	MyView.View_Help();				//���� ����
	MyGame.Background();			//������

	MyGame.Game_Bagic();			//�⺻ ����Ʋ ����
	MyGame.Background();			//������

	Select_Character();	        	//���� ĳ���� ����
	MyGame.Background();			//������

	MyGame.Game_Loading();			//���� �ε�ȭ��
	delay(3000);					//3�� ������

	MyGame.Game_Level(1,"��");		//���� ���̵� ǥ��
	delay(3000);					//3�� ������

	Stage MyMap;							
	MyGame.Background();			//������
	Game_Control(2);						//ù��° �������� ���۰� ��Ʈ��

	MyGame.Game_Level(2,"�ڡ�");		//���� ���̵� ǥ��
	delay(3000);					//3�� ������
	
	MyGame.Background();			//������
	Game_Control(3);						//�ι�° �������� ���۰� ��Ʈ��
	
	MyGame.Game_Level(3,"�ڡڡ�");		//���� ���̵� ǥ��
	delay(3000);					//3�� ������
	
	MyGame.Background();			//������
	Game_Control(4);						//����° �������� ���۰� ��Ʈ��
	
	MyGame.Game_Level(4,"�ڡڡڡ�");		//���� ���̵� ǥ��
	delay(3000);					//3�� ������
	
	MyGame.Background();			//������
	Game_Control(5);						//�׹�° �������� ���۰� ��Ʈ��
}

