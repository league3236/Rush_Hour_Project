#include <Windows.h>
#include "Control.h"
#pragma comment(lib,"winmm.lib")


using namespace std;

void main()
{
	Control A;
	A.Game_Start();							//게임 시작
	system("pause>null");				//계속하려면 아무키나 누르십시오 제거.
}