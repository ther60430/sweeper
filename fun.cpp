#include"header.h"

IMAGE UnCell;         //δ�ҿ�����ͼƬ
IMAGE Cell;             //�ѽҿ�����ͼƬ              O
IMAGE HoverCell;   //�����ͣ����ͼƬ
IMAGE Landmine;   //��ͼƬ
IMAGE Flag;            //����ͼƬ
IMAGE Gamewithdraw; //��Ϸ����ͼƬ
IMAGE Win;            //��Ϸʤ��ͼƬ
IMAGE GameStart;  //��Ϸ��ʼͼƬ
IMAGE GamePause;  //��Ϸ��ͣͼƬ
IMAGE GameContinue; //������ϷͼƬ
IMAGE GameRestart;  //���¿�ʼͼƬ
IMAGE GameExit;    //�˳���ϷͼƬ
IMAGE num[8];     //����ͼƬ1-8
IMAGE score;          //����ͼƬ


void SweeperGame::run_game(void)
{
	initgraph(setting.width, setting.height);
	setbkcolor(setting.Backcolor);
	cleardevice();

	_getch();
}

void SweeperGame::InitGame()
{
	initgraph(setting.width, setting.height);
	setbkcolor(setting.Backcolor);
	loadimage(&UnCell, _T("images/uncell.png"));          //δ�ҿ�����ͼƬ
	loadimage(&Cell, _T("images/cell.png"));            //�ѽҿ�����ͼƬ
	loadimage(&HoverCell, _T("images/hover.png"));                     //�����ͣ����ͼƬ
	loadimage(&Landmine, _T("images/thounder.png"));              //��ͼƬ
	loadimage(&score, _T("images/history_scores.png"));         //����ͼƬ
	loadimage(&GameStart, _T("images/start.png"));              //��Ϸ��ʼͼƬ
	loadimage(&Gamewithdraw, _T("images/.png"));                    //��Ϸ����ͼƬ
	loadimage(&GamePause, _T("images/pause.png"));           //��Ϸ��ͣͼƬ
	loadimage(&GameContinue, _T("images/.png"));            //������ϷͼƬ
	loadimage(&GameRestart, _T("images/.png"));                   //���¿�ʼͼƬ
	loadimage(&GameExit, _T("images/end.png"));               //�˳���Ϸ��ťͼƬ
	loadimage(&Flag, _T("images/flag.png"));             //����ͼƬ
	loadimage(&num[0], _T("images/1.png"));
	loadimage(&num[1], _T("images/2.png"));
	loadimage(&num[2], _T("images/3.png"));
	loadimage(&num[3], _T("images/4.png"));
	loadimage(&num[4], _T("images/5.png"));
	loadimage(&num[5], _T("images/6.png"));
	loadimage(&num[6], _T("images/7.png"));
	loadimage(&num[7], _T("images/8.png"));
	mciSendString("open bgm.mp3", 0, 0, 0);
}