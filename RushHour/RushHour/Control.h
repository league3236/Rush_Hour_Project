#ifndef CONTROL_H
#define CONTROL_H


class Control{
private:

public:

	Control();
	int Direct_Getkey();			//����� ����
	int Block_Numkey();			//���� ����
	void Game_Start();		//��Ʈ��Ŭ������ �����Լ�
	void Game_Control(int stage);		//��� ��Ʈ��
	void Select_Character();			//ĳ���� ����
};

#endif