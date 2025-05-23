#include"header.h"
IMAGE UnCell;         //未揭开格子图片
IMAGE Cell;             //已揭开格子图片              
IMAGE HoverCell;   //鼠标悬停格子图片
IMAGE Landmine;   //雷图片
IMAGE Flag;            //旗帜图片
IMAGE Gamewithdraw; //游戏返回图片
IMAGE Win;            //游戏胜利图片
IMAGE GameStart;  //游戏开始图片
IMAGE GamePause;  //游戏暂停图片
IMAGE GameContinue; //继续游戏图片
IMAGE GameRestart;  //重新开始图片
IMAGE GameExit;    //退出游戏图片
IMAGE num[8];     //数字图片1-8
IMAGE score;          //分数图片
class settings
{
public:
	int width = 1200, height = 600;     //屏幕宽高
	COLORREF  Backcolor =RGB(57,197,187);
};

class SweeperGame
{
    private:
		                  
		int count_thounder;               //雷数
		bool is_game_over;               //游戏是否结束
		bool first_click;                     //是否第一次点击
		settings setting;
	public:
		void InitGame();                        //初始化游戏
		void HandleInput();                  //处理输入
		void reveal(int x, int y);             //揭开格子
		void mark(int x, int y);              //标记雷
		void backgroundmusic();         //背景音乐
		void run_game(void)
		{
				initgraph(setting.width, setting.height);
				setbkcolor(setting.Backcolor);
				cleardevice();

				_getch();
		}
};

void SweeperGame::InitGame()
{
	initgraph(setting.width, setting.height);
	setbkcolor(setting.Backcolor);
	loadimage(&UnCell, _T("images/uncell.png"));          //未揭开格子图片
	loadimage(&Cell, _T("images/cell.png"));            //已揭开格子图片
	loadimage(&HoverCell, _T("images/hover.png"));                     //鼠标悬停格子图片
	loadimage(&Landmine, _T("images/thounder.png"));              //雷图片
	loadimage(&score, _T("images/history_scores.png"));         //分数图片
	loadimage(&GameStart, _T("images/start.png"));              //游戏开始图片
	loadimage(&Gamewithdraw, _T("images/withdraw.png"));                    //游戏返回图片
	loadimage(&GamePause, _T("images/pause.png"));           //游戏暂停图片
	loadimage(&GameContinue, _T("images/.png"));            //继续游戏图片
	loadimage(&GameRestart, _T("images/replay.png"));                   //重新开始图片
	loadimage(&GameExit, _T("images/end.png"));               //退出游戏按钮图片
	loadimage(&Flag, _T("images/flag.png"));             //旗帜图片
	loadimage(&num[0], _T("images/1.png"));
	loadimage(&num[1], _T("images/2.png"));
	loadimage(&num[2], _T("images/3.png"));
	loadimage(&num[3], _T("images/4.png"));
	loadimage(&num[4], _T("images/5.png"));
	loadimage(&num[5], _T("images/6.png"));
	loadimage(&num[6], _T("images/7.png"));
	loadimage(&num[7], _T("images/8.png"));
	mciSendString(L"open \"bgm.mp3\"alias bgmusic", NULL, 0, NULL);
	mciSendString(L"play bgmusic repeat", NULL, 0, NULL);
}

int main()
{
	SweeperGame sg;
	sg.run_game();
}