#include <Windows.h>
#include "Control.h"
#pragma comment(lib,"winmm.lib")

void main()
{
	system("mode con: cols=80 lines=30");
	PlaySound(TEXT("BGM.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP |SND_NOSTOP);
	Control A;
	A.Game_Start();							//���� ����
	system("pause>null");				//����Ϸ��� �ƹ�Ű�� �����ʽÿ� ����.
}