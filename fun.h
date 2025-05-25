#ifndef FUN_H
#define FUN_H
#include"header.h"

class settings
{
public:
	int width = 1200, height = 600;//屏幕宽高
	COLORREF  Backcolor = RGB(71, 59, 120);
};

class SweeperGame
{
private:

	int count_thounder;               //雷数
	bool is_game_over;               //游戏是否结束
	bool first_click;                     //是否第一次点击
	settings setting;
public:
	void InitGame();                        //初始化游戏
	void HandleInput();                  //处理输入
	void reveal(int x, int y);             //揭开格子
	void mark(int x, int y);              //标记雷
	void backgroundmusic();         //背景音乐
	void run_game(void);            //运行游戏
	void hoverstart();                           //悬停函数
};

#endif