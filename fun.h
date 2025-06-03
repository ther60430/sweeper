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
	IMAGE* Before_img = NULL;
	IMAGE* After_img[9];
	IMAGE* Hover_Img = NULL;
	IMAGE* Mine_Img = NULL;
	IMAGE* Flag_Img = NULL;
	Ccoordinate top_left;
	Ccoordinate bottom_right;
	bool IsMine;
	int NumMine;
	bool isRevealed;
	bool isFlag;
	Blanks(IMAGE* B_i = NULL, IMAGE* img0 = nullptr, IMAGE* img1 = nullptr, IMAGE* img2 = nullptr,
		IMAGE* img3 = nullptr, IMAGE* img4 = nullptr, IMAGE* img5 = nullptr,
		IMAGE* img6 = nullptr, IMAGE* img7 = nullptr, IMAGE* img8 = nullptr, IMAGE* H_Ii = NULL, IMAGE* M_i = NULL, IMAGE* F_i = NULL, Ccoordinate top = Ccoordinate(), Ccoordinate bottom = Ccoordinate(), bool Is = false, int Num = false, bool Revealed = false, bool flag = false)
		:Before_img(B_i), After_img{ img0, img1, img2, img3, img4, img5, img6, img7,img8 }, Hover_Img(H_Ii), Mine_Img(M_i),Flag_Img(F_i), top_left(top), bottom_right(bottom), IsMine(Is), NumMine(Num), isRevealed(Revealed), isFlag(flag) {}
	Blanks(const Blanks& other)
	{
		Before_img = other.Before_img;
		for(int i = 0; i < 9; i++)           //����After_img����
			After_img[i] = other.After_img[i];
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
	void select_show(void)                  //�����ͣʱ��ʾ
	{
		if (isRevealed == 0)
		{
			if (isFlag==1)
				putimage(top_left.x, top_left.y, Flag_Img, SRCCOPY);
			else
				putimage(top_left.x, top_left.y, Hover_Img, SRCCOPY);
		}
		else if (isFlag==0)
		{
			if(IsMine)
				putimage(top_left.x, top_left.y, Mine_Img, SRCCOPY);
			else if(NumMine==0&&IsMine==0)
			{
				putimage(top_left.x, top_left.y, After_img[8], SRCCOPY);
			}
			else if (NumMine!=0)
			{
				putimage(top_left.x, top_left.y, After_img[NumMine-1], SRCCOPY);
			}
		}
	}
	void Unselect_show(void)                       //���δ��ͣʱ��ʾ
	{
		if (isRevealed == 0)                                //δ�ҿ�����
		{
			if (isFlag == 1)
				putimage(top_left.x, top_left.y, Flag_Img, SRCCOPY);
			else
				putimage(top_left.x, top_left.y, Before_img, SRCCOPY);
		}
		else if (isFlag == 0)                                                       //�ѽҿ�����
		{
			if (IsMine)
				putimage(top_left.x, top_left.y, Mine_Img, SRCCOPY);
			else if (NumMine == 0 && IsMine == 0)
			{
				putimage(top_left.x, top_left.y, After_img[8], SRCCOPY);
			}
			else if (NumMine != 0)
			{
				putimage(top_left.x, top_left.y, After_img[NumMine - 1], SRCCOPY);
			}
		 }
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
	vector<vector<Blanks>> blank_simple;
	vector<vector<Blanks>> blank_middle;
	vector<vector<Blanks>> blank_difficult;
	settings setting;
	IMAGE Title;            //����
	IMAGE UnCell;         //δ�ҿ�����ͼƬ
	IMAGE Cell;             //�ѽҿ�����ͼƬ              
	IMAGE HoverCell;   //�����ͣ����ͼƬ
	IMAGE Landmine;   //��ͼƬ
	IMAGE Flag;            //����ͼƬ
	IMAGE Win;            //��Ϸʤ��ͼƬ
	IMAGE GameStart, GameStart1;  //��Ϸ��ʼͼƬ
	IMAGE GamePause;  //��Ϸ��ͣͼƬ
	IMAGE GameContinue; //������ϷͼƬ
	IMAGE GameRestart;  //���¿�ʼͼƬ
	IMAGE GameExit, GameExit1;    //�˳���ϷͼƬ
	IMAGE num[8];     //����ͼƬ1-8
	IMAGE history_scores, history_scores1;          //����ͼƬ
	IMAGE BackGraound;//����ͼƬ
	IMAGE Simple1, Simple;//��ģʽ
	IMAGE Medium1, Medium;//�е�ģʽ
	IMAGE Difficult1, Difficult;//����ģʽ
	IMAGE Withdraw1, Withdraw;//������һҳ
	IMAGE GameDefeat; //��Ϸʧ��ͼƬ
	IMAGE GameWin; //��Ϸʤ��ͼƬ
	bool firstclick_simple = false; //�Ƿ��һ�ε��
	bool firstclick_middle = false;//�Ƿ��һ�ε��
	bool firstclick_difficult = false;//�Ƿ��һ�ε��
	bool defeat = false;           //��Ϸ�Ƿ�ʧ��
public:
	void InitGame();                        //��ʼ����Ϸ
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
	void Raise_Mines(void);
	void Raise_Mines(int num);
	void getNumMinesimple(void);
	void getNumMinemiddle(void);
	void getNumMinedifficult(void);
	// �ݹ�չ���հ�����
	void ExpandEmptyCells_simple(int y, int x);
	void ExpandEmptyCells_middle(int y, int x);
	void ExpandEmptyCells_difficult(int y, int x);
	void setdefeat(){defeat = false;};
};

#endif