#ifndef FUN_H
#define FUN_H
#include"header.h"

class settings
{
public:
	int width = 1200, height = 600;//��Ļ���
	COLORREF  Backcolor = RGB(71, 59, 120);
};

class SweeperGame
{
private:

	int count_thounder;               //����
	bool is_game_over;               //��Ϸ�Ƿ����
	bool first_click;                     //�Ƿ��һ�ε��
	settings setting;
public:
	void InitGame();                        //��ʼ����Ϸ
	void HandleInput();                  //��������
	void reveal(int x, int y);             //�ҿ�����
	void mark(int x, int y);              //�����
	void backgroundmusic();         //��������
	void run_game(void);            //������Ϸ
	void hoverstart();                           //��ͣ����
};

#endif