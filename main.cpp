#include"header.h"



int main()
{
	SweeperGame sg;
	sg.InitGame();
	mciSendString(L"open \"bgm.mp3\"", NULL, 0, NULL);
	mciSendString(L"play bgm.mp3 repeat", NULL, 0, NULL);
	sg.run_game();
}