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
#include <random>
#include <chrono>

using namespace std;

#include"fun.h"


extern IMAGE Title;            //����
extern IMAGE UnCell;         //δ�ҿ�����ͼƬ
extern IMAGE Cell;             //�ѽҿ�����ͼƬ              
extern IMAGE HoverCell;   //�����ͣ����ͼƬ
extern IMAGE Landmine;   //��ͼƬ
extern IMAGE Flag;            //����ͼƬ
extern IMAGE Gamewithdraw; //��Ϸ����ͼƬ
extern IMAGE Win;            //��Ϸʤ��ͼƬ
extern IMAGE GameStart, GameStart1;  //��Ϸ��ʼͼƬ
extern IMAGE GamePause;  //��Ϸ��ͣͼƬ
extern IMAGE GameContinue; //������ϷͼƬ
extern IMAGE GameRestart;  //���¿�ʼͼƬ
extern IMAGE GameExit, GameExit1;    //�˳���ϷͼƬ
extern IMAGE num[8];     //����ͼƬ1-8
extern IMAGE history_scores, history_scores1;          //����ͼƬ
extern IMAGE BackGraound;//����ͼƬ
extern IMAGE Simple1,Simple;//��ģʽ
extern IMAGE Medium1,Medium;//�е�ģʽ
extern IMAGE Difficult1,Difficult;//����ģʽ
extern IMAGE Withdraw1,Withdraw;//������һҳ
<<<<<<< HEAD
=======

>>>>>>> 1b5f7a54c03aee1ff19c6ed37616943ab61f41ff
#endif