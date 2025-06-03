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
	loadimage(&GamePause, _T("images/pause.png"));           //��Ϸ��ͣͼƬ
	loadimage(&GameContinue, _T("images/go.png"));            //������ϷͼƬ
	loadimage(&GameRestart, _T("images/replay.png"),64,64);                   //���¿�ʼͼƬ
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
	loadimage(&Medium1, _T("images/middle2.png"), 256, 64);                                //�е�ģʽͼƬ
	loadimage(&Difficult1, _T("images/difficult2.png"), 256, 64);                                 //����ģʽͼƬ
    loadimage(&Simple, _T("images/Simple.png"), 256, 64);                                        //��ģʽ��ͣͼƬ
    loadimage(&Medium, _T("images/middle1.png"), 256, 64);                                //�е�ģʽ��ͣͼƬ
    loadimage(&Difficult, _T("images/Difficult1.png"), 256, 64);                                 //����ģʽ��ͣͼƬ
	loadimage(&Withdraw1, _T("images/Withdraw1.png"), 64, 64);                            //���ذ�ťͼƬ
    loadimage(&Withdraw, _T("images/Withdraw.png"), 64, 64);                            //���ذ�ť��ͣͼƬ
	loadimage(&GameDefeat, _T("images/Defeat.png"), 512, 128);                       //��Ϸʧ��ͼƬ
	loadimage(&GameWin, _T("images/Victory.png"), 512, 128);                            //��Ϸʤ��ͼƬ
}

void SweeperGame::showtime(void)
{
    time_t StartTime = time(nullptr);
    while (1)
    {
        if (defeat == 1)
        {
            break;
        }
        if (win == 1)
        {
            break;
        }
        if (replay == 1)
        {
            break;
        }
        if (back == 1)
        {
            break;
        }

        time_t NowTime = time(nullptr);

        int second = NowTime - StartTime;

        string tim = to_string(second) + "s";
        outtextxy(1000, 0, tim.c_str());
    }
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
                defeat = false;
                win = false;
                replay = false;
                back = false;
                int flag1;
                displayscreen2a();                   //����������ʾ����
                flag1 = hoverstart2a();                   // ����������ͣ������¼�������             1/2/3/4
                switch (flag1)
                {
                    case 1:
                        {
                            while (1)
                            {
                                setdefeat();
                                int flag2;
                                displayscreen_simple();//���Ѷ�չʾ��Blank������
                                Raise_Mines(1);
                                getNumMinesimple();
                                thread t(&SweeperGame::showtime, this);
                                t.detach();
                                flag2 = hoverstart_simple();
                                if(flag2 == -1) // ���ذ�ť�����
                                {
                                    back = true;
                                    vector<vector<Blanks>> temp;
                                    swap(temp, blank_simple);
                                    break;
								}
                                if (flag2 == -2)
                                {
                                    replay = true;
                                    vector<vector<Blanks>> temp;
                                    swap(temp, blank_simple);
                                    defeat = false;
                                    win = false;
                                    replay = false;
                                    back = false;
                                }
                            }
                        }break;
                    case 2:
                        {
                            while (1)
                            {
                                setdefeat();
                                int flag2;
                                displayscreen_middle();
                                Raise_Mines(2);
                                getNumMinemiddle();
                                thread t(&SweeperGame::showtime, this);
                                t.detach();
                                flag2 = hoverstart_middle();
                                if (flag2 == -1) // ���ذ�ť�����
                                {
                                    win = true;
                                    back = true;
                                    vector<vector<Blanks>> temp;
                                    swap(temp, blank_middle);
                                    break;
                                }
                                if (flag2 == -2) // ���ذ�ť�����
                                {
                                    replay = true;
                                    vector<vector<Blanks>> temp;
                                    swap(temp, blank_middle);
                                }
                            }
                        }break;
                    case 3:
                        {
                            while (1)
                            {
                                setdefeat();
                                int flag2;
                                displayscreen_difficult();
                                Raise_Mines(3);
                                getNumMinedifficult();
                                thread t(&SweeperGame::showtime, this);
                                t.detach();
                                flag2 = hoverstart_difficult();
                                if (flag2== -1)
                                {
                                    win = true;
                                    back = true;
                                    vector<vector<Blanks>> temp;
                                    swap(temp, blank_difficult);
									break;
                                }
                                if (flag2 == -2)
                                {
                                    replay = true;
                                    vector<vector<Blanks>> temp;
                                    swap(temp, blank_difficult);
                                }
                            }
                        }break;
                }
             if(flag1==4)
                    break;
             }
         }break;
        case 3:exit(1);
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

int SweeperGame::hoverstart2a(void)                               // ����������ͣ������¼�������
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

void SweeperGame::displayscreen_simple(void)
{
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    if (blank_simple.size() != 11)
    {
        for (int i = 0; i < 11; i++)
        {
            vector<Blanks> blank1;
            for (int j = 0; j < 11; j++)
            {
                Ccoordinate t_l(435 + j * 30, 135 + i * 30);
                Ccoordinate b_r(465 + j * 30, 165 + i * 30);
                if (i == 0 || i == 10 || j == 0 || j == 10)           //�߽���Ӳ���ʾ
                {
                    t_l.x = -100;
                    t_l.y = -100;
                    b_r.x = -100;
                    b_r.y = -100;
                }
                Blanks temp(&UnCell,&num[0], &num[1] , &num[2] , &num[3] , &num[4] , &num[5] , &num[6] , &num[7],&Cell, &HoverCell, &Landmine, &Flag, t_l, b_r);
                temp.select_show();
                blank1.push_back(temp);
            }
            blank_simple.push_back(blank1);
        }
    }
}

void SweeperGame::displayscreen_middle(void)
{
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    if (blank_middle.size() != 18)
    {
        for (int i = 0; i < 18; i++)
        {
            vector<Blanks> blank1;
            for (int j = 0; j < 18; j++)
            {
                Ccoordinate t_l(360 + j * 30, 60 + i * 30);
                Ccoordinate b_r(390 + j * 30, 90 + i * 30);
                if(i == 0 || i == 17 || j == 0 || j == 17)           //�߽���Ӳ���ʾ
                {
                    t_l.x = -100;
                    t_l.y = -100;
                    b_r.x = -100;
                    b_r.y = -100;
				}
                Blanks temp(&UnCell,&num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &Cell, &HoverCell, &Landmine, &Flag, t_l, b_r);
                    temp.select_show();                                //������ʾ����
                blank1.push_back(temp);
            }
            blank_middle.push_back(blank1);
        }
    }
}

void SweeperGame::displayscreen_difficult(void)
{
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    if (blank_difficult.size() != 18)
    {
        for (int i = 0; i < 18; i++)
        {
            vector<Blanks> blank1;
            for (int j = 0; j < 32; j++)
            {
                Ccoordinate t_l(150 + j * 30, 60 + i * 30);
                Ccoordinate b_r(180 + j * 30, 90 + i * 30);
                if (i == 0 || i == 17 || j == 0 || j == 31)           //�߽���Ӳ���ʾ
                {
                    t_l.x = -100;
                    t_l.y = -100;
                    b_r.x = -100;
                    b_r.y = -100;
                }
                Blanks temp(&UnCell, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &Cell, &HoverCell, &Landmine, &Flag, t_l, b_r);
                temp.select_show();
                blank1.push_back(temp);
            }
            blank_difficult.push_back(blank1);
        }
	}
}

int SweeperGame::hoverstart_simple(void)
{
    ExMessage msg;
    firstclick_simple = 0;

    
    while (1)
    {
        msg = getmessage(EX_MOUSE); 
        putimage(70, 0, &GameRestart, SRCCOPY);
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
            {
                return -1;
            }
            if (msg.x <= 134 && msg.x >= 70 && msg.y <= 64 && msg.y >= 0)
            {
                return -2;
            }
        }

        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                blank_simple[i][j].Unselect_show();
            }
        }

		int score = 0; // ��ʼ��������
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (blank_simple[i][j].isRevealed == 1&&blank_simple[i][j].IsMine==0)
                {
                    score++;
                }
            }
        }

        if (defeat == 1)                           //չʾʧ�ܽ���
        {
            putimage(344, 0, &GameDefeat, SRCCOPY);
            settextstyle(60, 60, _T("����"));
            settextcolor(RED);
            string score_str = "SCORE:"+to_string(score);
			outtextxy(400,540 , (score_str.c_str())); // ��ʾ����
            break;
        }

		int countblank = 0; // ����δ�ҿ��ĸ���
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (blank_simple[i][j].isRevealed == 0)
                {
					countblank++;
                }
            }
        }

        if(countblank==12) // ������з��׸��Ӷ����ҿ�
        {
            win = 1;
            putimage(344, 0, &GameWin, SRCCOPY); // ��ʾʤ������
            defeat = 0;
            break;
		}

        if (msg.x > 435 && msg.y > 135 && msg.x < 735 && msg.y < 435)
        {
            int posX = (msg.x - 435) / 30;
            int posY = (msg.y - 135) / 30;
            switch (msg.message)
            {
                case WM_MOUSEMOVE:
                    {
                        blank_simple[posY][posX].select_show();
                    }break;

                case WM_LBUTTONDOWN:
                    { 
                        if (firstclick_simple == 1)                //�ǵ�һ�ε��
                        {
                            if (blank_simple[posY][posX].isFlag == 0)
                            {
                                if (blank_simple[posY][posX].NumMine == 0)
                                {
                                    ExpandEmptyCells_simple(posY, posX);
                                }
                                blank_simple[posY][posX].isRevealed = 1;
                                if(blank_simple[posY][posX].IsMine == 1) //����㵽��
                                {
                                    for (int i = 1; i <= 9; i++)
                                    {
                                        for (int j = 1; j <= 9; j++)
                                        {
                                            if(blank_simple[i][j].IsMine == 1) //��ʾ������
                                            {
                                                blank_simple[i][j].isRevealed = 1;
											}
                                        }
                                    }
                                    defeat = 1;                  //������Ϸ״̬Ϊʧ��
								}
                            }
                        }
                        else if (firstclick_simple == 0&& blank_simple[posY][posX].isFlag==0)                 //��һ��������
                        {
                            firstclick_simple = 1;
                            if (blank_simple[posY][posX].NumMine != 0)
                            {
                                while (blank_simple[posY][posX].NumMine != 0 || blank_simple[posY][posX].IsMine == 1)
                                {
                                    Raise_Mines(1);
                                    getNumMinesimple();
                                 }
                                if (blank_simple[posY][posX].NumMine == 0)
                                {
                                    ExpandEmptyCells_simple(posY, posX);
                                }
                            }
                            else
                            {
                                ExpandEmptyCells_simple(posY, posX);
                            }
                        }
                    }break;

                case WM_RBUTTONDOWN:
                    {
                        blank_simple[posY][posX].flag();
                    }break;
            }
        }

    }
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        putimage(70, 0, &GameRestart, SRCCOPY);
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
            {
                return -1;
            }
            if (msg.x <= 134 && msg.x >= 70 && msg.y <= 64 && msg.y >= 0)
            {
                return -2;
            }
        }
    }
}

int SweeperGame::hoverstart_middle(void)
{
    ExMessage msg;
    firstclick_middle = 0;
    while (1)
    {
        msg = getmessage(EX_MOUSE);
        putimage(70, 0, &GameRestart, SRCCOPY);
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
            {
                return -1;
            }
            if (msg.x <= 134 && msg.x >= 70 && msg.y <= 64 && msg.y >= 0)
            {
                return -2;
            }
        }

        for (int i = 0; i < 18; i++)
        {
            for (int j = 0; j < 18; j++)
            {
                blank_middle[i][j].Unselect_show();
            }
        }

        if (defeat == 1)                           //չʾʧ�ܽ���
        {
            putimage(344, 0, &GameDefeat, SRCCOPY);
            defeat = 0;
            break;
        }
        int countblank = 0; // ����δ�ҿ��ĸ���
        for (int i = 1; i <= 16; i++)
        {
            for (int j = 1; j <= 16; j++)
            {
                if (blank_middle[i][j].isRevealed == 0)
                {
                    countblank++;
                }
            }
        }

        if (countblank == 64) // ������з��׸��Ӷ����ҿ�
        {
            putimage(344, 0, &GameWin, SRCCOPY); // ��ʾʤ������
            defeat = 0;
            break;
        }

        if (msg.x >= 360 && msg.y >= 60 && msg.x <= 870 && msg.y <= 570)
        {
            int posX = (msg.x - 360) / 30;
            int posY = (msg.y - 60) / 30;
            switch (msg.message)
            {
                case WM_MOUSEMOVE:
                    {
                        blank_middle[posY][posX].select_show();
                    }break;
                case WM_LBUTTONDOWN:
                    {
                        if (firstclick_middle == 1)                //�ǵ�һ�ε��
                        {
                            if (blank_middle[posY][posX].isFlag == 0)
                            {
                                blank_middle[posY][posX].isRevealed = 1;
                                if (blank_middle[posY][posX].NumMine == 0)
                                {
                                    ExpandEmptyCells_middle(posY, posX);
                                }
                                if (blank_middle[posY][posX].IsMine == 1) //����㵽��
                                {
                                    for (int i = 1; i <= 16; i++)
                                    {
                                        for (int j = 1; j <= 16; j++)
                                        {
                                            if (blank_middle[i][j].IsMine == 1) //��ʾ������
                                            {
                                                blank_middle[i][j].isRevealed = 1;
                                            }
                                        }
                                    }
                                    defeat = 1;                  //������Ϸ״̬Ϊʧ��
                                }
                            }
                        }
                            else if (firstclick_middle == 0 && blank_middle[posY][posX].isFlag == 0)                 //��һ��������
                            {
                                firstclick_middle = 1;
                                if (blank_middle[posY][posX].NumMine != 0)
                                {
                                    while (blank_middle[posY][posX].NumMine != 0 || blank_middle[posY][posX].IsMine == 1)
                                    {
                                        Raise_Mines(2);
                                        getNumMinemiddle();
                                    }
                                    if (blank_middle[posY][posX].NumMine == 0)
                                    {
                                        ExpandEmptyCells_middle(posY, posX);
                                    }
                                }
                                else
                                {
                                    ExpandEmptyCells_middle(posY, posX);
                                }
                            }
                        }break;
                case WM_RBUTTONDOWN:
                    {
                        blank_middle[posY][posX].flag();
                    }break;
            }
        }
    }
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        putimage(70, 0, &GameRestart, SRCCOPY);
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
            {
                return -1;
            }
            if (msg.x <= 134 && msg.x >= 70 && msg.y <= 64 && msg.y >= 0)
            {
                return -2;
            }
        }
    }
}

int SweeperGame::hoverstart_difficult(void)
{
    ExMessage msg;
    firstclick_difficult = 0;
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        putimage(70, 0, &GameRestart, SRCCOPY);
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
            {
                return -1;
            }
            if (msg.x <= 134 && msg.x >= 70 && msg.y <= 64 && msg.y >= 0)
            {
                return -2;
            }
        }

        for (int i = 0; i < 18; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                blank_difficult[i][j].Unselect_show();
            }
        }

        if (defeat == 1)                           //չʾʧ�ܽ���
        {
            putimage(344, 0, &GameDefeat, SRCCOPY);
            defeat = 0;
            break;
        }

        int countblank = 0; // ����δ�ҿ��ĸ���
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (blank_difficult[i][j].isRevealed == 0)
                {
                    countblank++;
                }
            }
        }

        if (countblank == 120) // ������з��׸��Ӷ����ҿ�
        {
            putimage(344, 0, &GameWin, SRCCOPY); // ��ʾʤ������
            defeat = 0;
            break;
        }

        if (msg.x > 150 && msg.y > 60 && msg.x < 1080 && msg.y < 570)
        {
            int posX = (msg.x - 150) / 30;
            int posY = (msg.y - 60) / 30;
            switch (msg.message)
            {
                case WM_MOUSEMOVE:
                    {
                        blank_difficult[posY][posX].select_show();
                    }break;

                case WM_LBUTTONDOWN:
                    {
						if (firstclick_difficult == 1)                         //�ǵ�һ�ε��
                        {
                            if (blank_difficult[posY][posX].isFlag == 0)
                            {
                                blank_difficult[posY][posX].isRevealed = 1;
                                if (blank_difficult[posY][posX].NumMine == 0)
                                {
                                    ExpandEmptyCells_difficult(posY, posX);
                                }
                                if (blank_difficult[posY][posX].IsMine == 1)
                                {
                                    for (int i = 1; i <= 16; i++)
                                    {
                                        for (int j = 1; j <= 30; j++)
                                        {
                                            if (blank_difficult[i][j].IsMine == 1)
                                            {
                                                blank_difficult[i][j].isRevealed = 1;
                                            }
                                        }
                                    }
                                    defeat = 1;                  //������Ϸ״̬Ϊʧ��
                                }
                            }
                        }
                        else if (firstclick_difficult == 0 && blank_difficult[posY][posX].isFlag == 0)                 //��һ��������
                        {
                            firstclick_difficult = 1;
                            if (blank_difficult[posY][posX].NumMine != 0)
                            {
                                while (blank_difficult[posY][posX].NumMine != 0 || blank_difficult[posY][posX].IsMine == 1)
                                {
                                    Raise_Mines(3);
                                    getNumMinedifficult();
                                }
                                if (blank_difficult[posY][posX].NumMine == 0)
                                {
                                    ExpandEmptyCells_difficult(posY, posX);
                                }
                            }
                            else
                            {
                                ExpandEmptyCells_difficult(posY, posX);
                            }
                        }
                    }break;

                case WM_RBUTTONDOWN:
                    {
                        blank_difficult[posY][posX].flag();
                    }break;
            }
        }
    }
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        putimage(70, 0, &GameRestart, SRCCOPY);
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//����
            {
                return -1;
            }
            if (msg.x <= 134 && msg.x >= 70 && msg.y <= 64 && msg.y >= 0)
            {
                return -2;
            }
        }
    }
}

void SweeperGame::getNumMinesimple(void)
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            blank_simple[i][j].NumMine = 0;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (dx == 0 && dy == 0) continue; // �������ĸ���
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 1 && ni <= 9 && nj >= 1 && nj <= 9)
                    {
                        if (blank_simple[ni][nj].IsMine == 1)
                        {
                            blank_simple[i][j].NumMine++;
                        }
                    }
                }
            }
        }
    }
}

void SweeperGame::getNumMinemiddle(void)
{
    for (int i = 1; i <= 16; i++)
    {
        for (int j = 1; j <= 16; j++)
        {
            blank_middle[i][j].NumMine = 0;
        }
    }
    for (int i = 1; i <= 16; i++)
    {
        for (int j = 1; j <= 16; j++)
        {
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (dx == 0 && dy == 0) continue; // �������ĸ���
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 1 && ni <= 16 && nj >= 1 && nj <= 16)
                    {
                        if (blank_middle[ni][nj].IsMine == 1)
                        {
                            blank_middle[i][j].NumMine++;
                        }
                    }
                }
            }
        }
    }
}

void SweeperGame::getNumMinedifficult(void)
{
    for (int i = 1; i <= 16; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            blank_difficult[i][j].NumMine = 0;
        }
    }
    for (int i = 1; i <= 16; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (dx == 0 && dy == 0) continue; // �������ĸ���
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 1 && ni <= 16 && nj >= 1 && nj <= 30)
                    {
                        if (blank_difficult[ni][nj].IsMine == 1)
                        {
                            blank_difficult[i][j].NumMine++;
                        }
                    }
                }
            }
        }
    }
}

void SweeperGame::Raise_Mines(int num)
{
    // ʹ�þ�̬������������������ظ���ʼ��
    static mt19937 generator(chrono::system_clock::now().time_since_epoch().count());

    vector<vector<Blanks>>* targetGrid = nullptr;
    int rows = 0, cols = 0, mineCount = 0;

    // �����Ѷ�ѡ��Ŀ�����������
    switch (num)
    {
        case 1:
            targetGrid = &blank_simple;
            rows = 9; cols = 9; mineCount = 12;
            break;
        case 2:
            targetGrid = &blank_middle;
            rows = 16; cols = 16; mineCount = 64;
            break;
        case 3:
            targetGrid = &blank_difficult;
            rows = 16; cols = 30; mineCount = 120;
            break;
        default:
            return; // ��Ч�Ѷȼ���
    }

    // ���������еĵ���
    for (auto& row : *targetGrid)
        for (auto& cell : row)
            cell.IsMine = 0;

    // Fisher-Yates ϴ���㷨�������λ��
    vector<int> positions(rows * cols);
    for (int i = 0; i < rows * cols; ++i)
        positions[i] = i;

    // ֻ��Ҫ����ǰmineCount��Ԫ��
    for (int i = 0; i < mineCount; ++i)
    {
        uniform_int_distribution<int> distribution(i, rows * cols - 1);
        int j = distribution(generator);
        swap(positions[i], positions[j]);
    }

    // ���õ���
    for (int i = 0; i < mineCount; ++i)
    {
        int pos = positions[i];
        int x = pos / cols + 1; // +1 ��Ϊ�����1��ʼ
        int y = pos % cols + 1;
        (*targetGrid)[x][y].IsMine = 1;
    }
}

void SweeperGame::ExpandEmptyCells_simple(int y, int x)
{
    // �߽������Ч�Լ��
    if (x < 1 || x > 9 || y < 1 || y > 9) 
        return;
    if (blank_simple[y][x].isRevealed==1|| blank_simple[y][x].isFlag==1|| blank_simple[y][x].IsMine==1) 
        return;

    // ��ǵ�ǰ����Ϊ����ʾ
    blank_simple[y][x].isRevealed = true;

    // �����ǰ������Χ�е��ף�ֹͣ��չ
    if (blank_simple[y][x].NumMine != 0) return;

    // �ݹ���չ��Χ��8������
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0) continue; // ��������
            ExpandEmptyCells_simple(y + dy, x + dx);
        }
    }
}

void SweeperGame::ExpandEmptyCells_middle(int y, int x)
{
    // �߽������Ч�Լ��
    if (x < 1 || x > 16 || y < 1 || y > 16)
        return;
    if (blank_middle[y][x].isRevealed == 1 || blank_middle[y][x].isFlag == 1 || blank_middle[y][x].IsMine == 1)
        return;

    // ��ǵ�ǰ����Ϊ����ʾ
    blank_middle[y][x].isRevealed = true;

    // �����ǰ������Χ�е��ף�ֹͣ��չ
    if (blank_middle[y][x].NumMine != 0) return;

    // �ݹ���չ��Χ��8������
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0) continue; // ��������
            ExpandEmptyCells_middle(y + dy, x + dx);
        }
    }
}

void SweeperGame::ExpandEmptyCells_difficult(int y, int x)
{
    // �߽������Ч�Լ��
    if (x < 1 || x > 30 || y < 1 || y > 16)
        return;
    if (blank_difficult[y][x].isRevealed == 1 || blank_difficult[y][x].isFlag == 1 || blank_difficult[y][x].IsMine == 1)
        return;

    // ��ǵ�ǰ����Ϊ����ʾ
    blank_difficult[y][x].isRevealed = true;

    // �����ǰ������Χ�е��ף�ֹͣ��չ
    if (blank_difficult[y][x].NumMine != 0) return;

    // �ݹ���չ��Χ��8������
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0) continue; // ��������
            ExpandEmptyCells_difficult(y + dy, x + dx);
        }
    }
}