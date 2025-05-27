#include"header.h"

IMAGE Title;            //标题
IMAGE UnCell;         //未翻开格子图片
IMAGE Cell;             //已翻开格子图片              
IMAGE HoverCell;   //鼠标悬浮格子图片
IMAGE Landmine;   //地雷图片
IMAGE Flag;            //旗帜图片
IMAGE Gamewithdraw; //游戏撤回图片
IMAGE Win;            //游戏胜利图片
IMAGE GameStart1, GameStart;  //游戏开始图片
IMAGE GamePause;  //游戏暂停图片
IMAGE GameContinue; //继续游戏图片
IMAGE GameRestart;  //重新开始图片
IMAGE GameExit1, GameExit;    //退出游戏图片
IMAGE num[8];     //数字图片1 - 8
IMAGE history_scores1, history_scores;          //分数图片
IMAGE BackGraound;//背景图片
IMAGE Simple1, Simple;//简单模式
IMAGE Medium1, Medium;//中等模式
IMAGE Difficult1, Difficult;//困难模式
IMAGE Withdraw,Withdraw1;//返回上一页
<<<<<<< HEAD
=======

>>>>>>> 1741e5a9e5929fd57a854be52eae04713d4b0b8c

int main()
{
	SweeperGame sg;
	sg.InitGame();
	mciSendString(L"open \"bgm.mp3\"", NULL, 0, NULL);
	mciSendString(L"play bgm.mp3 repeat", NULL, 0, NULL);
	sg.run_game();
}