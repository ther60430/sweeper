#include"header.h"

void SweeperGame::InitGame()
{
	initgraph(setting.width, setting.height);                          //1200*600
	loadimage(&Title, _T("images/title.png"), 800, 120);       //����ͼƬ
	loadimage(&UnCell, _T("images/uncell.png"),30,30);          //δ�ҿ�����ͼƬ
	loadimage(&Cell, _T("images/cell.png"), 30, 30);            //�ѽҿ�����ͼƬ
	loadimage(&HoverCell, _T("images/hover.png"), 30, 30);                     //�����ͣ����ͼƬ
	loadimage(&Landmine, _T("images/thounder.png"), 30, 30);              //��ͼƬ
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
	loadimage(&BackGraound, _T("images/BackGround.png"), 1200, 600);                  //����ͼƬ
	loadimage(&Simple1, _T("images/Simple1.png"), 256, 64);                                        //��ģʽͼƬ
	loadimage(&Medium1, _T("images/Medium1.png"), 256, 64);                                //�е�ģʽͼƬ
	loadimage(&Difficult1, _T("images/Difficult1.png"), 256, 64);                                 //����ģʽͼƬ
    loadimage(&Simple, _T("images/Simple.png"), 256, 64);                                        //��ģʽ��ͣͼƬ
    loadimage(&Medium, _T("images/Medium.png"), 256, 64);                                //�е�ģʽ��ͣͼƬ
    loadimage(&Difficult, _T("images/Difficult.png"), 256, 64);                                 //����ģʽ��ͣͼƬ
	loadimage(&Withdraw1, _T("images/Withdraw1.png"), 64, 64);                            //���ذ�ťͼƬ
    loadimage(&Withdraw, _T("images/Withdraw.png"), 64, 64);                            //���ذ�ť��ͣͼƬ

}

void SweeperGame::run_game(void)
{
    int flag0 = -1;
    while (1)
    {
        displayscreen1();				//һ��������ʾ����
        flag0 = hoverstart1();     //һ��������ͣ������¼�������       1/2/3                    
        switch (flag0)
        {
        case 1:
        {
            while (1)
            {
                int flag1 = -1;
                displayscreen2a();                   //����������ʾ����
                flag1 = hoverstart2a();                   // ����������ͣ������¼�������             1/2/3/4
                switch (flag1)
                {
                case 1:
                {
                    while (1)
                    {
                        cleardevice();
                        putimage(0, 0, &BackGraound, SRCCOPY);
                        for (int i = 0; i < 9; i++)
                        {
                            vector<Blanks> blank2;
                            for (int j = 0; j < 9; j++)
                            {
                                Ccoordinate t_l(465 + j * 30, 165 + i * 30);
                                Ccoordinate b_r(495 + j * 30, 195 + i * 30);
                                Blanks temp(UnCell, Cell, t_l, b_r);
                                temp.show();
                                blank2.push_back(temp);
                            }
                            blank.push_back(blank2);
                        }
                        while (1);
                    }
                }break;
                }
                if (flag1 == 4)
                    break;
            }break;
        case 3:exit(1);
        }
        }
    }
}

void SweeperGame::displayscreen1(void)                //һ��������ʾ����
{
    cleardevice();                                          //����
    putimage(0, 0, &BackGraound, SRCCOPY);                  //����ͼƬ
    putimage(200, 100, &Title, SRCCOPY);                    //����ͼƬ
    putimage(472, 300, &GameStart1, SRCCOPY);               //��Ϸ��ʼ��ť
    putimage(472, 380, &history_scores1, SRCCOPY);          //������ť
    putimage(472, 460, &GameExit1, SRCCOPY);                //�˳���ť
    FlushBatchDraw();                                       //ˢ����Ļ
}


void SweeperGame::displayscreen2a(void)                   //����������ʾ����
{
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    putimage(0, 0, &Withdraw1, SRCCOPY);
    putimage(472, 300, &Simple1, SRCCOPY);
    putimage(472, 380, &Medium1, SRCCOPY);
    putimage(472, 460, &Difficult1, SRCCOPY);
}

int SweeperGame::hoverstart1(void)                      //һ��������ͣ������¼�������
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
                putimage(472, 460, &GameExit, SRCCOPY);
            }
            else
            {
                putimage(472, 460, &GameExit1, SRCCOPY);
            }
            break;
        case WM_LBUTTONDOWN:
        {
            // �������¼�
            if (inStartButton)
                return 1;
            else if (inScoreButton)
                return 2;
            else if (inExitButton)
                return 3;
            break;
        }
        }
    }
}

int SweeperGame::hoverstart2a()                               // ����������ͣ������¼�������
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
        // �������Ƿ��ڷ��ذ�ť��
        bool inWithdrawButton = (msg.x >= 0 && msg.x <= 64) && (msg.y >= 0 && msg.y <= 64);
        switch (msg.message)
        {
            case WM_MOUSEMOVE:
                {
                    // ����򵥰�ť��ͣ
                    if (inSimpleButton)
                    {
                        putimage(472, 300, &Simple, SRCCOPY);
                    }
                    else
                    {
                        putimage(472, 300, &Simple1, SRCCOPY);
                    }
                    // �����еȰ�ť��ͣ
                    if (inMediumButton)
                    {
                        putimage(472, 380, &Medium, SRCCOPY);
                    }
                    else
                    {
                        putimage(472, 380, &Medium1, SRCCOPY);
                    }
                    // �������Ѱ�ť��ͣ
                    if (inDifficultButton)
                    {
                        putimage(472, 460, &Difficult, SRCCOPY);
                    }
                    else
                    {
                        putimage(472, 460, &Difficult1, SRCCOPY);
                    }
                    // �����ذ�ť��ͣ
                    if (inWithdrawButton)
                    {
                        putimage(0, 0, &Withdraw, SRCCOPY);
                    }
                    else
                    {
                        putimage(0, 0, &Withdraw1, SRCCOPY);
                    }
                }break;
            case WM_LBUTTONDOWN:                        // �������¼�
                {
                    if (inSimpleButton)
                        return 1;
                    else if (inMediumButton)
                        return 2;
                    else if (inDifficultButton)
                        return 3;
                    else if (inWithdrawButton)
                        return 4;
                }break;
        }
    }
}