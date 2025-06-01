#ifndef FUN_H
#define FUN_H

#include"header.h"
#pragma once
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
	IMAGE *Before_img = NULL;
	IMAGE *After_img = NULL;
	IMAGE *Hover_Img = NULL;
	IMAGE *Mine_Img = NULL;
	IMAGE *Flag_Img = NULL;
	Ccoordinate top_left;
	Ccoordinate bottom_right;
	bool IsMine;
	int NumMine;
	bool isRevealed;
	bool isFlag;

	Blanks(IMAGE *B_i=NULL, IMAGE *A_i = NULL, IMAGE *H_Ii = NULL, IMAGE *M_i = NULL, IMAGE *F_i = NULL, Ccoordinate top = Ccoordinate(), Ccoordinate bottom = Ccoordinate(), bool Is = false, int Num = false, bool Revealed = false,bool flag=false )
		:Before_img(B_i), After_img(A_i), Hover_Img(H_Ii), Mine_Img(M_i),Flag_Img(F_i), top_left(top), bottom_right(bottom), IsMine(Is), NumMine(Num), isRevealed(Revealed), isFlag(flag) {}
	Blanks(const Blanks& other)
	{
		Before_img = other.Before_img;
		After_img = other.After_img;
		Hover_Img = other.Hover_Img;
		Mine_Img = other.Mine_Img;
		Flag_Img = other.Flag_Img;
		top_left = Ccoordinate(other.top_left);
		bottom_right = Ccoordinate(other.bottom_right);
		IsMine = other.IsMine;
		NumMine = other.NumMine;
		isRevealed = other.isRevealed;
		isFlag = other.isFlag;
	}
	void flag(void)
	{
		if (isFlag)
			isFlag = false;
		else
			isFlag = true;
	}
	void select_show(void)
	{
		if (isRevealed == 0)
		{
			if (isFlag==1)
				putimage(top_left.x, top_left.y, Flag_Img, SRCCOPY);
			else
				putimage(top_left.x, top_left.y, Hover_Img, SRCCOPY);
		}
		else
		{
			if(IsMine)
				putimage(top_left.x, top_left.y, Mine_Img, SRCCOPY);
			else
				putimage(top_left.x, top_left.y, After_img, SRCCOPY);
		}
			
	}
	void Unselect_show(void)
	{
		if (isRevealed == 0)
		{
			if (isFlag == 1)
				putimage(top_left.x, top_left.y, Flag_Img, SRCCOPY);
			else
				putimage(top_left.x, top_left.y, Before_img, SRCCOPY);
		}
		else
			if (IsMine)
				putimage(top_left.x, top_left.y, Mine_Img, SRCCOPY);
			else
				putimage(top_left.x, top_left.y, After_img, SRCCOPY);

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
	vector<vector<Blanks>> blank_simple;
	vector<vector<Blanks>> blank_middle;
	vector<vector<Blanks>> blank_difficult;
	settings setting;
	IMAGE Title;            //标题
	IMAGE UnCell;         //未揭开格子图片
	IMAGE Cell;             //已揭开格子图片              
	IMAGE HoverCell;   //鼠标悬停格子图片
	IMAGE Landmine;   //雷图片
	IMAGE Flag;            //旗帜图片
	IMAGE Gamewithdraw; //游戏返回图片
	IMAGE Win;            //游戏胜利图片
	IMAGE GameStart, GameStart1;  //游戏开始图片
	IMAGE GamePause;  //游戏暂停图片
	IMAGE GameContinue; //继续游戏图片
	IMAGE GameRestart;  //重新开始图片
	IMAGE GameExit, GameExit1;    //退出游戏图片
	IMAGE num[8];     //数字图片1-8
	IMAGE history_scores, history_scores1;          //分数图片
	IMAGE BackGraound;//背景图片
	IMAGE Simple1, Simple;//简单模式
	IMAGE Medium1, Medium;//中等模式
	IMAGE Difficult1, Difficult;//困难模式
	IMAGE Withdraw1, Withdraw;//返回上一页

public:
	void InitGame();                        //初始化游戏
	void HandleInput();                  //处理输入
	void reveal(int x, int y);             //揭开格子
	void mark(int x, int y);              //标记雷
	void run_game(void);            //运行游戏
	int hoverstart1(void);                           //一级界面悬停函数
	int hoverstart2a(void);                           //二级界面悬停函数

	int hoverstart_simple(void);
	int hoverstart_middle(void);
	int hoverstart_difficult(void);

	void displayscreen1(void);                  //一级界面显示函数

	void displayscreen_middle(void);        
	void displayscreen_difficult(void);
	void displayscreen2a(void);                  //二级界面显示函数    
	void displayscreen_simple(void);			//简单难度展示及Blank类生成
	void Raise_Mines(int num);

};

#endif