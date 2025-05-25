#include"header.h"

void SweeperGame::InitGame()
{
	initgraph(setting.width, setting.height);                          //1200*600
	setbkcolor(setting.Backcolor);
	loadimage(&Title, _T("images/title.png"), 800, 120);       //����ͼƬ
	loadimage(&UnCell, _T("images/uncell.png"));          //δ�ҿ�����ͼƬ
	loadimage(&Cell, _T("images/cell.png"));            //�ѽҿ�����ͼƬ
	loadimage(&HoverCell, _T("images/hover.png"));                     //�����ͣ����ͼƬ
	loadimage(&Landmine, _T("images/thounder.png"));              //��ͼƬ
	loadimage(&score1, _T("images/history_scores1.png"), 256, 64);         //����ͼƬ
	loadimage(&score, _T("images/history_scores.png"), 256, 64);         //������ͣͼƬ
	loadimage(&GameStart1, _T("images/start1.png"),256,64);              //��Ϸ��ʼͼƬ
	loadimage(&GameStart, _T("images/start.png"), 256, 64);              //��Ϸ��ʼ��ͣͼƬ
	loadimage(&Gamewithdraw, _T("images/withdraw.png"));                    //��Ϸ����ͼƬ
	loadimage(&GamePause, _T("images/pause.png"));           //��Ϸ��ͣͼƬ
	loadimage(&GameContinue, _T("images/go.png"));            //������ϷͼƬ
	loadimage(&GameRestart, _T("images/replay.png"));                   //���¿�ʼͼƬ
	loadimage(&GameExit1, _T("images/end1.png"),256,64);               //�˳���Ϸ��ťͼƬ
	loadimage(&GameExit, _T("images/end.png"), 256, 64);               //�˳���Ϸ��ť��ͣͼƬ
	loadimage(&Flag, _T("images/flag.png"));             //����ͼƬ
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
	putimage(472, 460, &score, SRCCOPY);
    FlushBatchDraw();
}

void SweeperGame::hoverstart()
{
    ExMessage msg;
    bool startButtonHover = false;
    bool exitButtonHover = false;
    bool scoreButtonHover = false;
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        // �������Ƿ��ڿ�ʼ��ť��
        bool inStartButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 300 && msg.y <= 364);
        // �������Ƿ����˳���ť��
        bool inExitButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 380 && msg.y <= 444);
        // �������Ƿ��ڷ�����ť��
        bool inScoreButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 460 && msg.y <= 524);
        switch (msg.message)
        {
        case WM_MOUSEMOVE:
            // ����ʼ��ť��ͣ
            if (inStartButton && !startButtonHover)
            {
                putimage(472, 300, &GameStart, SRCCOPY);
                startButtonHover = true;
            }
            else if (!inStartButton && startButtonHover)
            {
                putimage(472, 300, &GameStart1, SRCCOPY);
                startButtonHover = false;
            }
            // �����˳���ť��ͣ
            if (inExitButton && !exitButtonHover)
            {
                putimage(472, 380, &GameExit, SRCCOPY);
                exitButtonHover = true;
            }
            else if (!inExitButton && exitButtonHover)
            {
                putimage(472, 380, &GameExit1, SRCCOPY);
                exitButtonHover = false;
            }
            // ���������ť��ͣ
            if (inScoreButton && !scoreButtonHover)
            {
                putimage(472, 460, &score1, SRCCOPY);
                scoreButtonHover = true;
            }
            else if (!inScoreButton && scoreButtonHover)
            {
                putimage(472, 460, &score, SRCCOPY);
                scoreButtonHover = false;
            }
            break;
        }
    }
}