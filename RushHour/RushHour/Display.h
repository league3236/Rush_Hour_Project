#ifndef DISPLAY_H
#define DISPLAY_H


class Display{
private:
	
public:
	void Game_Bagic();		// 게임 기본화면 출력
	void Game_Loading();	//게임 로딩 화면
	void Game_Level(int level,char *star);		//다음 난이도 출력
	void Background(); //배경 출력
};

#endif