#ifndef STAGE_H
#define STAGE_H
#include "Model.h"


class Stage{
private:

protected:
	static int My_Stage[M_STAGE][M_X][M_Y];
public:
	bool End_Block(int stage,int _Character);
	void Map_Print(int Stage);			//�� ���
	void Stage_Start(int Stage);			// �������� ����
	int Find_X(int Stage,int Block_N);			//��� x��ǥ ã��
	int Find_Y(int Stage,int Block_N);			//��� y��ǥ ã��
	void Set_Stage(int Stage,int x,int y);		//x,y������ �� ����
	void Trans_Matrix(int Key,int stage,int Block_N,int x,int y,int *_step);	//����� �ű���ִ��� �˻� �� ��ȯ. 
};

#endif