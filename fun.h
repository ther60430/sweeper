#ifndef FUN_H
#define FUN_H

#include"header.h"

class Ccoordinate
{
public:
	int x;
	int y;
	Ccoordinate(int xx = 0, int yy = 0) :x(xx), y(yy) {}
	Ccoordinate(const Ccoordinate &other)
	{
		x = other.x;
		y = other.y;
	}
};

class Blanks
{
public:
	IMAGE img;
	bool IsMine;
	int NumMine;
	bool first_click;
	Ccoordinate top_left;
	Ccoordinate bottom_right;
	Blanks(IMAGE i, bool Is = 0, int Num = 0, bool first = 0, Ccoordinate top = Ccoordinate(), Ccoordinate bottom = Ccoordinate())
		:img(i), IsMine(Is), NumMine(Num), first_click(first), top_left(top), bottom_right(bottom){}
	Blanks(const Blanks &other)
	{
		img = other.img;
		IsMine = other.IsMine;
		NumMine = other.NumMine;
		first_click = other.first_click;
		top_left= Ccoordinate(other.top_left);
		bottom_right = Ccoordinate(other.bottom_right);
	}

};

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
	std::vector<Blanks> blank;
	settings setting;
public:
	void InitGame();                        //初始化游戏
	void HandleInput();                  //处理输入
	void reveal(int x, int y);             //揭开格子
	void mark(int x, int y);              //标记雷
	void backgroundmusic();         //背景音乐
	void run_game(void);            //运行游戏
	int hoverstart1(void);                           //一级界面悬停函数
	int hoverstart2a(void);                           //二a级界面悬停函数
};

#endif