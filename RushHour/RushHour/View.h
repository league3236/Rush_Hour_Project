#ifndef VIEW_H
#define VIEW_H

class View{

private:
public:
	void Collect_Color();				//�� ��� �ѹ� �����ֱ�
	void View_Logo();						//���α׷� ���۷ΰ�
	void XYPutStr(int x,int y, char str[]);	//���ϴ°��� str�ֱ�
	void View_Sub(int _stage,int *_step);
	void View_Help();					//���� ����
	int Show_Success(int _stage);			//�ϼ� ȭ�� ���
	int Sum_Score(int *_step,int _stage);		//���ھ� ���ϱ�
	void View_Score();						//���ھ� �����ֱ�
	void View_Image(int _Image);			//�̹��� �����ֱ�
	void delete_Image();					//�̹��� ����
};

#endif