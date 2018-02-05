#ifndef VIEW_H
#define VIEW_H

class View{

private:
public:
	void Collect_Color();				//각 블록 넘버 보여주기
	void View_Logo();						//프로그램 시작로고
	void XYPutStr(int x,int y, char str[]);	//원하는곳에 str넣기
	void View_Sub(int _stage,int *_step);
	void View_Help();					//게임 도움말
	int Show_Success(int _stage);			//완성 화면 출력
	int Sum_Score(int *_step,int _stage);		//스코어 더하기
	void View_Score();						//스코어 보여주기
	void View_Image(int _Image);			//이미지 보여주기
	void delete_Image();					//이미지 삭제
};

#endif