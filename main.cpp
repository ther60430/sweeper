#include"header.h"
IMAGE UnCell;         //未揭开格子图片
IMAGE Cell;             //已揭开格子图片
IMAGE HoverCell;   //鼠标悬停格子图片
IMAGE Landmine;   //雷图片
IMAGE Flag;            //旗帜图片
IMAGE Background; //背景图片
IMAGE GameOver; //游戏结束图片
IMAGE Win;            //游戏胜利图片
IMAGE GameStart;  //游戏开始图片
IMAGE GamePause;  //游戏暂停图片
IMAGE GameContinue; //继续游戏图片
IMAGE GameRestart;  //重新开始图片
IMAGE GameExit;    //退出游戏图片
IMAGE num[9];     //数字图片0~9
class SweeperGame
{
    private:
		int width, height;                  //屏幕宽高
		int count_thounder;               //雷数
		bool is_game_over;               //游戏是否结束
		bool first_click;                     //是否第一次点击
	public:
		void CreateWindows();              //创建窗口
		void InitGame();                        //初始化游戏
		void HandleInput();                  //处理输入
		void reveal(int x, int y);             //揭开格子
		void mark(int x, int y);              //标记雷
		void backgroundmusic();         //背景音乐
};