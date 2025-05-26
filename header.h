#ifndef HEADER_H
#define HEADER_H

// Windows 
#include <windows.h>
#include <mmsystem.h>             //外部媒体库
#pragma comment(lib, "winmm.lib")  
// C ++运行文件
#include <iostream>
#include <vector>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

#include"fun.h"


extern IMAGE Title;            //标题
extern IMAGE UnCell;         //未揭开格子图片
extern IMAGE Cell;             //已揭开格子图片              O
extern IMAGE HoverCell;   //鼠标悬停格子图片
extern IMAGE Landmine;   //雷图片
extern IMAGE Flag;            //旗帜图片
extern IMAGE Gamewithdraw; //游戏返回图片
extern IMAGE Win;            //游戏胜利图片
extern IMAGE GameStart1, GameStart;  //游戏开始图片
extern IMAGE GamePause;  //游戏暂停图片
extern IMAGE GameContinue; //继续游戏图片
extern IMAGE GameRestart;  //重新开始图片
extern IMAGE GameExit1, GameExit;    //退出游戏图片
extern IMAGE num[8];     //数字图片1-8
extern IMAGE history_scores1, history_scores;          //分数图片
extern IMAGE BackGraound;//背景图片
extern IMAGE Simple;//简单模式
extern IMAGE Medium;//中等模式
extern IMAGE Difficult;//困难模式
extern IMAGE Withdraw;//返回上一页
#endif