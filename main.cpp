#include"header.h"
IMAGE Cell;          //格子图片
IMAGE Landmine; //雷图片
IMAGE Flag;          //旗帜图片
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