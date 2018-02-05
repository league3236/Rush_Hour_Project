#ifndef STAGE_H
#define STAGE_H
#include "Model.h"


class Stage{
private:

protected:
	static int My_Stage[M_STAGE][M_X][M_Y];
public:
	bool End_Block(int stage,int _Character);
	void Map_Print(int Stage);			//맵 출력
	void Stage_Start(int Stage);			// 스테이지 시작
	int Find_X(int Stage,int Block_N);			//블록 x좌표 찾기
	int Find_Y(int Stage,int Block_N);			//블록 y좌표 찾기
	void Set_Stage(int Stage,int x,int y);		//x,y데이터 값 변경
	void Trans_Matrix(int Key,int stage,int Block_N,int x,int y,int *_step);	//블록을 옮길수있는지 검사 후 변환. 
};

#endif