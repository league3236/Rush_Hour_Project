#ifndef CONTROL_H
#define CONTROL_H


class Control{
private:

public:

	Control();
	int Direct_Getkey();			//방향기 선택
	int Block_Numkey();			//차량 선택
	void Game_Start();		//컨트롤클레스의 메인함수
	void Game_Control(int stage);		//블록 컨트롤
	void Select_Character();			//캐릭터 선택
};

#endif