#ifndef HEADER_H
#define HEADER_H

// Windows 
#include <windows.h>
#include <mmsystem.h>             //�ⲿý���
#pragma comment(lib, "winmm.lib")  
// C ++�����ļ�
#include <iostream>
#include <vector>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

#include"fun.h"


extern IMAGE Title;            //����
extern IMAGE UnCell;         //δ�ҿ�����ͼƬ
extern IMAGE Cell;             //�ѽҿ�����ͼƬ              O
extern IMAGE HoverCell;   //�����ͣ����ͼƬ
extern IMAGE Landmine;   //��ͼƬ
extern IMAGE Flag;            //����ͼƬ
extern IMAGE Gamewithdraw; //��Ϸ����ͼƬ
extern IMAGE Win;            //��Ϸʤ��ͼƬ
extern IMAGE GameStart1, GameStart;  //��Ϸ��ʼͼƬ
extern IMAGE GamePause;  //��Ϸ��ͣͼƬ
extern IMAGE GameContinue; //������ϷͼƬ
extern IMAGE GameRestart;  //���¿�ʼͼƬ
extern IMAGE GameExit1, GameExit;    //�˳���ϷͼƬ
extern IMAGE num[8];     //����ͼƬ1-8
extern IMAGE history_scores1, history_scores;          //����ͼƬ
extern IMAGE BackGraound;//����ͼƬ
extern IMAGE Simple;//��ģʽ
extern IMAGE Medium;//�е�ģʽ
extern IMAGE Difficult;//����ģʽ
extern IMAGE Withdraw;//������һҳ
#endif