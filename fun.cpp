#include"header.h"

void SweeperGame::InitGame()
{
	initgraph(setting.width, setting.height);                          //1200*600
	loadimage(&Title, _T("images/title.png"), 800, 120);       //����ͼƬ
	loadimage(&UnCell, _T("images/uncell.png"));          //δ�ҿ�����ͼƬ
	loadimage(&Cell, _T("images/cell.png"));            //�ѽҿ�����ͼƬ
	loadimage(&HoverCell, _T("images/hover.png"));                     //�����ͣ����ͼƬ
	loadimage(&Landmine, _T("images/thounder.png"));              //��ͼƬ
    loadimage(&history_scores1, _T("images/history_scores1.png"), 256, 64);         //������ͣͼƬ
	loadimage(&history_scores, _T("images/history_scores.png"), 256, 64);         //����ͼƬ
	loadimage(&GameStart1, _T("images/start1.png"),256,64);              //��Ϸ��ʼͼƬ
	loadimage(&GameStart, _T("images/start.png"), 256, 64);              //��Ϸ��ʼ��ͣͼƬ
	loadimage(&Gamewithdraw, _T("images/withdraw.png"));                    //��Ϸ����ͼƬ
	loadimage(&GamePause, _T("images/pause.png"));           //��Ϸ��ͣͼƬ
	loadimage(&GameContinue, _T("images/go.png"));            //������ϷͼƬ
	loadimage(&GameRestart, _T("images/replay.png"));                   //���¿�ʼͼƬ
	loadimage(&GameExit1, _T("images/end1.png"),256,64);               //�˳���Ϸ��ťͼƬ
	loadimage(&GameExit, _T("images/end.png"), 256, 64);               //�˳���Ϸ��ť��ͣͼƬ
	loadimage(&Flag, _T("images/flag.png"),30,30);             //����ͼƬ
	loadimage(&num[0], _T("images/1.png"), 30, 30);
	loadimage(&num[1], _T("images/2.png"), 30, 30);
	loadimage(&num[2], _T("images/3.png"), 30, 30);
	loadimage(&num[3], _T("images/4.png"), 30, 30);
	loadimage(&num[4], _T("images/5.png"), 30, 30);
	loadimage(&num[5], _T("images/6.png"), 30, 30);
	loadimage(&num[6], _T("images/7.png"), 30, 30);
	loadimage(&num[7], _T("images/8.png"), 30, 30);
    loadimage(&BackGraound, _T("images/BackGround.png"), 1200, 600);
    loadimage(&Simple, _T("images/Simple.png"), 256, 64);
    loadimage(&Medium, _T("images/Medium.png"), 256, 64);
    loadimage(&Difficult, _T("images/Difficult.png"), 256, 64);
    loadimage(&Withdraw, _T("images/Withdraw.png"), 64, 64);

	mciSendString(L"open \"bgm.mp3\"alias bgmusic", NULL, 0, NULL);
	mciSendString(L"play bgmusic repeat", NULL, 0, NULL);
}

void deleteimage(IMAGE* img)
{
	if (img)
    {
		img->Resize(0, 0);
	}
}

void SweeperGame::run_game(void)  
{  
    int flag0 = -1;
	while (1)
	{
        cleardevice();
        putimage(0, 0, &BackGraound, SRCCOPY);                  //��
        putimage(200, 100, &Title, SRCCOPY);                    //һ
        putimage(472, 300, &GameStart1, SRCCOPY);               //��
        putimage(472, 380, &history_scores1, SRCCOPY);          //��
        putimage(472, 460, &GameExit1, SRCCOPY);                //��
        FlushBatchDraw();                                       //
        flag0 = hoverstart0();                                  //
        
        switch (flag0)
        {
            case 1:
                {
                    int flag1;
                    cleardevice();
                    putimage(0, 0, &BackGraound, SRCCOPY);
                    putimage(0, 0, &Withdraw, SRCCOPY);
                    putimage(472, 300, &Simple, SRCCOPY);
                    putimage(472, 380, &Medium, SRCCOPY);
                    putimage(472, 460, &Difficult, SRCCOPY);
                    flag1 = hoverstart1a();
                    switch (flag1)
                    {
                        case 4:break;
                    }
                };break;
            case 3:exit(1);
        }
	}
    
        
    
}

int SweeperGame::hoverstart0()
{
    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        // �������Ƿ��ڿ�ʼ��ť��
        bool inStartButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 300 && msg.y <= 364);
        // �������Ƿ��ڷ�����ť��
        bool inScoreButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 380 && msg.y <= 444);
        // �������Ƿ����˳���ť��
        bool inExitButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 460 && msg.y <= 524);
        
        switch (msg.message)
        {
            case WM_MOUSEMOVE:
                // ����ʼ��ť��ͣ
                if (inStartButton)
                {
                    putimage(472, 300, &GameStart, SRCCOPY);
                }
                else
                {
                    putimage(472, 300, &GameStart1, SRCCOPY);
                }
                // ���������ť��ͣ
                if (inScoreButton)
                {
                    putimage(472, 380, &history_scores1, SRCCOPY);
                }
                else
                {
                    putimage(472, 380, &history_scores, SRCCOPY);
                }
                // �����˳���ť��ͣ
                if (inExitButton)
                {
                    ExMessage msg1;
                    msg1 = getmessage(EX_MOUSE);
                    putimage(472, 460, &GameExit, SRCCOPY);
                    if(msg1.message == WM_LBUTTONDOWN)
                    {
                        return 3;
                    }
                }
                else
                {
                    putimage(472, 460, &GameExit1, SRCCOPY);
                }
                break;
        }
        
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x >= 472 && msg.x <= 728 && msg.y >= 300 && msg.y <= 364)
                return 1;
            else if (msg.x >= 472 && msg.x <= 728 && msg.y >= 380 && msg.y <= 444)
                return 2;
            else if (msg.x >= 472 && msg.x <= 728 && msg.y >= 460 && msg.y <= 524)
                return 3;
        }

    }
}

int SweeperGame::hoverstart1a()
{
    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        // �������Ƿ��ڼ򵥰�ť��
        bool inSimpleButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 300 && msg.y <= 364);
        // �������Ƿ����еȰ�ť��
        bool inMediumButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 380 && msg.y <= 444);
        // �������Ƿ������Ѱ�ť��
        bool inDifficultButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 460 && msg.y <= 524);
        bool inWithdrawButton = (msg.x >= 0 && msg.x <= 64) && (msg.y >= 0 && msg.y <= 64);
        switch (msg.message)
        {
            case WM_MOUSEMOVE:
                // ����򵥰�ť��ͣ
                if (inSimpleButton)
                {
                    putimage(472, 300, &Simple, SRCCOPY);
                }
                else
                {
                    putimage(472, 300, &GameStart1, SRCCOPY);
                }
                // �������Ѱ�ť��ͣ
                if (inMediumButton)
                {
                    putimage(472, 380, &Medium, SRCCOPY);
                }
                else
                {
                    putimage(472, 380, &history_scores, SRCCOPY);
                }
                // �����˳���ť��ͣ
                if (inDifficultButton)
                {
                    ExMessage msg1;
                    msg1 = getmessage(EX_MOUSE);
                    putimage(472, 460, &Difficult, SRCCOPY);
                    if (msg1.message == WM_LBUTTONDOWN)
                    {
                        return 3;
                    }
                }
                else
                {
                    putimage(472, 460, &GameExit1, SRCCOPY);
                }
                break;
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x >= 472 && msg.x <= 728 && msg.y >= 300 && msg.y <= 364)
                return 1;
            else if (msg.x >= 472 && msg.x <= 728 && msg.y >= 380 && msg.y <= 444)
                return 2;
            else if (msg.x >= 472 && msg.x <= 728 && msg.y >= 460 && msg.y <= 524)
                return 3;
            else if (msg.x >= 0 && msg.x <= 64 && msg.y >= 0 && msg.y <= 64)
                return 4;
        }
    }
}