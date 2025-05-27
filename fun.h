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
	IMAGE Before_img;
	IMAGE After_img;
	IMAGE HoverImg;
	Ccoordinate top_left;
	Ccoordinate bottom_right;
	bool IsMine;
	int NumMine;
	bool isRevealed;
	bool isFlag;
	
	Blanks(IMAGE B_i, IMAGE A_i, IMAGE H_I, Ccoordinate top = Ccoordinate(), Ccoordinate bottom = Ccoordinate(), bool Is = 0, int Num = 0, bool Revealed = 0,bool flag=0 )
		:Before_img(B_i), After_img(A_i), HoverImg(H_I), top_left(top), bottom_right(bottom), IsMine(Is), NumMine(Num), isRevealed(Revealed), isFlag(flag) {}
	Blanks(const Blanks &other)
	{
		Before_img = other.Before_img;
		After_img= other.After_img;
		HoverImg = other.HoverImg;
		top_left = Ccoordinate(other.top_left);
		bottom_right = Ccoordinate(other.bottom_right);
		IsMine = other.IsMine;
		NumMine = other.NumMine;
		isRevealed = other.isRevealed;
		isFlag = other.isFlag;
	}

	void show(void)
	{
		if (isRevealed == 0)
			putimage(top_left.x, top_left.y, &Before_img, SRCCOPY);
		else
			putimage(top_left.x, top_left.y, &After_img, SRCCOPY);
	}
	
	void showUnCell(void)
	{

		putimage(top_left.x, top_left.y, &HoverImg, SRCCOPY);

	}
};

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
	vector<vector<Blanks>> blank;
	settings setting;
public:
	void InitGame();                        //��ʼ����Ϸ
	void HandleInput();                  //��������
	void reveal(int x, int y);             //�ҿ�����
	void mark(int x, int y);              //�����
	void run_game(void);            //������Ϸ
	int hoverstart1(void);                           //һ��������ͣ����
	int hoverstart2a(void);                           //����������ͣ����
	int hoverstart_simple(void);
	int hoverstart_middle(void);
	int hoverstart_difficult(void);
	void displayscreen1(void);                  //һ��������ʾ����
	void displayscreen_middle(void);        
	void displayscreen_difficult(void);
	void displayscreen2a(void);                  //����������ʾ����    
	void displayscreen_simple(void);			//���Ѷ�չʾ��Blank������
};

#endif