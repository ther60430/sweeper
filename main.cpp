#include"header.h"

IMAGE Title;            //标题
IMAGE UnCell;         //未翻开格子图片
IMAGE Cell;             //已翻开格子图片              O
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
IMAGE score1, score;          //分数图片

int main()
{
	SweeperGame sg;
	sg.InitGame();
	sg.run_game();
	sg.hoverstart();
	_getch();
}