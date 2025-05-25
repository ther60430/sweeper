#include"header.h"

void SweeperGame::InitGame()
{
	initgraph(setting.width, setting.height);                          //1200*600
	loadimage(&Title, _T("images/title.png"), 800, 120);       //标题图片
	loadimage(&UnCell, _T("images/uncell.png"));          //未揭开格子图片
	loadimage(&Cell, _T("images/cell.png"));            //已揭开格子图片
	loadimage(&HoverCell, _T("images/hover.png"));                     //鼠标悬停格子图片
	loadimage(&Landmine, _T("images/thounder.png"));              //雷图片
	loadimage(&history_scores1, _T("images/history_scores1.png"), 256, 64);         //分数图片
	loadimage(&history_scores, _T("images/history_scores.png"), 256, 64);         //分数悬停图片
	loadimage(&GameStart1, _T("images/start1.png"),256,64);              //游戏开始图片
	loadimage(&GameStart, _T("images/start.png"), 256, 64);              //游戏开始悬停图片
	loadimage(&Gamewithdraw, _T("images/withdraw.png"));                    //游戏返回图片
	loadimage(&GamePause, _T("images/pause.png"));           //游戏暂停图片
	loadimage(&GameContinue, _T("images/go.png"));            //继续游戏图片
	loadimage(&GameRestart, _T("images/replay.png"));                   //重新开始图片
	loadimage(&GameExit1, _T("images/end1.png"),256,64);               //退出游戏按钮图片
	loadimage(&GameExit, _T("images/end.png"), 256, 64);               //退出游戏按钮悬停图片
	loadimage(&Flag, _T("images/flag.png"));             //旗帜图片
	loadimage(&num[0], _T("images/1.png"));
	loadimage(&num[1], _T("images/2.png"));
	loadimage(&num[2], _T("images/3.png"));
	loadimage(&num[3], _T("images/4.png"));
	loadimage(&num[4], _T("images/5.png"));
	loadimage(&num[5], _T("images/6.png"));
	loadimage(&num[6], _T("images/7.png"));
	loadimage(&num[7], _T("images/8.png"));
    loadimage(&BackGraound, _T("images/BackGround.png"), 1200, 600);
	mciSendString(L"open \"bgm.mp3\"alias bgmusic", NULL, 0, NULL);
	mciSendString(L"play bgmusic repeat", NULL, 0, NULL);
}

void deleteimage(IMAGE* img) {
	if (img) {
		img->Resize(0, 0);
	}
}

void SweeperGame::run_game(void)  
{  
	putimage(200, 100, &Title, SRCCOPY);
    putimage(472, 300, &GameStart1, SRCCOPY);
	putimage(472, 380, &GameExit1, SRCCOPY);
	putimage(472, 460, &history_scores, SRCCOPY);
    putimage(0, 0, &BackGraound, SRCCOPY);
    FlushBatchDraw();
    
	while (1)
	{
        hoverstart();
	}
}

void SweeperGame::hoverstart()
{
    ExMessage msg;
    msg = getmessage(EX_MOUSE);
    // 检查鼠标是否在开始按钮上
    bool inStartButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 300 && msg.y <= 364);
    // 检查鼠标是否在退出按钮上
    bool inExitButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 380 && msg.y <= 444);
    // 检查鼠标是否在分数按钮上
    bool inScoreButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 460 && msg.y <= 524);
    switch (msg.message)
    {
        case WM_MOUSEMOVE:
            // 处理开始按钮悬停
            if (inStartButton)
            {
                putimage(472, 300, &GameStart, SRCCOPY);
            }
            else
            {
                putimage(472, 300, &GameStart1, SRCCOPY);
            }
            // 处理退出按钮悬停
            if (inExitButton)
            {
                putimage(472, 380, &GameExit, SRCCOPY);
            }
            else
            {
                putimage(472, 380, &GameExit1, SRCCOPY);
            }
            // 处理分数按钮悬停
            if (inScoreButton)
            {
                putimage(472, 460, &history_scores1, SRCCOPY);
            }
            else
            {
                putimage(472, 460, &history_scores, SRCCOPY);
            }
            break;
    }
}