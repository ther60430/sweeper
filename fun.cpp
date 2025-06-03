#include"header.h"

void SweeperGame::InitGame()
{
	initgraph(setting.width, setting.height);                          //1200*600
	loadimage(&Title, _T("images/title.png"), 800, 120);       //标题图片
	loadimage(&UnCell, _T("images/uncell.png"),30,30);          //未揭开格子图片
	loadimage(&Cell, _T("images/cell.png"), 30, 30);            //已揭开格子图片
	loadimage(&HoverCell, _T("images/hover.png"), 30, 30);                     //鼠标悬停格子图片
	loadimage(&Landmine, _T("images/thounder.png"), 30, 30);              //雷图片
    loadimage(&history_scores1, _T("images/history_scores1.png"), 256, 64);         //分数悬停图片
	loadimage(&history_scores, _T("images/history_scores.png"), 256, 64);         //分数图片
	loadimage(&GameStart1, _T("images/start1.png"),256,64);              //游戏开始图片
	loadimage(&GameStart, _T("images/start.png"), 256, 64);              //游戏开始悬停图片
	loadimage(&GamePause, _T("images/pause.png"));           //游戏暂停图片
	loadimage(&GameContinue, _T("images/go.png"));            //继续游戏图片
	loadimage(&GameRestart, _T("images/replay.png"),64,64);                   //重新开始图片
	loadimage(&GameExit1, _T("images/end1.png"),256,64);               //退出游戏按钮图片
	loadimage(&GameExit, _T("images/end.png"), 256, 64);               //退出游戏按钮悬停图片
	loadimage(&Flag, _T("images/flag.png"),30,30);             //旗帜图片
	loadimage(&num[0], _T("images/1.png"), 30, 30);
	loadimage(&num[1], _T("images/2.png"), 30, 30);
	loadimage(&num[2], _T("images/3.png"), 30, 30);
	loadimage(&num[3], _T("images/4.png"), 30, 30);
	loadimage(&num[4], _T("images/5.png"), 30, 30);
	loadimage(&num[5], _T("images/6.png"), 30, 30);
	loadimage(&num[6], _T("images/7.png"), 30, 30);
	loadimage(&num[7], _T("images/8.png"), 30, 30);
	loadimage(&BackGraound, _T("images/BackGround.png"), 1200, 600);                  //背景图片
	loadimage(&Simple1, _T("images/Simple1.png"), 256, 64);                                        //简单模式图片
	loadimage(&Medium1, _T("images/middle2.png"), 256, 64);                                //中等模式图片
	loadimage(&Difficult1, _T("images/difficult2.png"), 256, 64);                                 //困难模式图片
    loadimage(&Simple, _T("images/Simple.png"), 256, 64);                                        //简单模式悬停图片
    loadimage(&Medium, _T("images/middle1.png"), 256, 64);                                //中等模式悬停图片
    loadimage(&Difficult, _T("images/Difficult1.png"), 256, 64);                                 //困难模式悬停图片
	loadimage(&Withdraw1, _T("images/Withdraw1.png"), 64, 64);                            //返回按钮图片
    loadimage(&Withdraw, _T("images/Withdraw.png"), 64, 64);                            //返回按钮悬停图片
	loadimage(&GameDefeat, _T("images/Defeat.png"), 512, 128);                       //游戏失败图片
	loadimage(&GameWin, _T("images/Victory.png"), 512, 128);                            //游戏胜利图片
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
        displayscreen1();				//一级画面显示函数
        flag0 = hoverstart1();     //一级画面悬停及点击事件处理函数       1/2/3       
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
                displayscreen2a();                   //二级画面显示函数
                flag1 = hoverstart2a();                   // 二级画面悬停及点击事件处理函数             1/2/3/4
                switch (flag1)
                {
                    case 1:
                        {
                            while (1)
                            {
                                setdefeat();
                                int flag2;
                                displayscreen_simple();//简单难度展示及Blank类生成
                                Raise_Mines(1);
                                getNumMinesimple();
                                thread t(&SweeperGame::showtime, this);
                                t.detach();
                                flag2 = hoverstart_simple();
                                if(flag2 == -1) // 返回按钮被点击
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
                                if (flag2 == -1) // 返回按钮被点击
                                {
                                    win = true;
                                    back = true;
                                    vector<vector<Blanks>> temp;
                                    swap(temp, blank_middle);
                                    break;
                                }
                                if (flag2 == -2) // 返回按钮被点击
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

void SweeperGame::displayscreen1(void)                //一级画面显示函数
{
    cleardevice();                                          //清屏
    putimage(0, 0, &BackGraound, SRCCOPY);                  //背景图片
    putimage(200, 100, &Title, SRCCOPY);                    //标题图片
    putimage(472, 300, &GameStart1, SRCCOPY);               //游戏开始按钮
    putimage(472, 380, &history_scores1, SRCCOPY);          //分数按钮
    putimage(472, 460, &GameExit1, SRCCOPY);                //退出按钮
    FlushBatchDraw();                                       //刷新屏幕
}

void SweeperGame::displayscreen2a(void)                   //二级画面显示函数
{
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    putimage(0, 0, &Withdraw1, SRCCOPY);
    putimage(472, 300, &Simple1, SRCCOPY);
    putimage(472, 380, &Medium1, SRCCOPY);
    putimage(472, 460, &Difficult1, SRCCOPY);
}

int SweeperGame::hoverstart1(void)                      //一级画面悬停及点击事件处理函数
{
    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        // 检查鼠标是否在开始按钮上
        bool inStartButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 300 && msg.y <= 364);
        // 检查鼠标是否在分数按钮上
        bool inScoreButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 380 && msg.y <= 444);
        // 检查鼠标是否在退出按钮上
        bool inExitButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 460 && msg.y <= 524);
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
            // 处理分数按钮悬停
            if (inScoreButton)
            {
                putimage(472, 380, &history_scores1, SRCCOPY);
            }
            else
            {
                putimage(472, 380, &history_scores, SRCCOPY);
            }
            // 处理退出按钮悬停
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
            // 处理点击事件
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

int SweeperGame::hoverstart2a(void)                               // 二级画面悬停及点击事件处理函数
{
    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        // 检查鼠标是否在简单按钮上
        bool inSimpleButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 300 && msg.y <= 364);
        // 检查鼠标是否在中等按钮上
        bool inMediumButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 380 && msg.y <= 444);
        // 检查鼠标是否在困难按钮上
        bool inDifficultButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 460 && msg.y <= 524);
        // 检查鼠标是否在返回按钮上
        bool inWithdrawButton = (msg.x >= 0 && msg.x <= 64) && (msg.y >= 0 && msg.y <= 64);
        switch (msg.message)
        {
            case WM_MOUSEMOVE:
                {
                    // 处理简单按钮悬停
                    if (inSimpleButton)
                    {
                        putimage(472, 300, &Simple, SRCCOPY);
                    }
                    else
                    {
                        putimage(472, 300, &Simple1, SRCCOPY);
                    }
                    // 处理中等按钮悬停
                    if (inMediumButton)
                    {
                        putimage(472, 380, &Medium, SRCCOPY);
                    }
                    else
                    {
                        putimage(472, 380, &Medium1, SRCCOPY);
                    }
                    // 处理困难按钮悬停
                    if (inDifficultButton)
                    {
                        putimage(472, 460, &Difficult, SRCCOPY);
                    }
                    else
                    {
                        putimage(472, 460, &Difficult1, SRCCOPY);
                    }
                    // 处理返回按钮悬停
                    if (inWithdrawButton)
                    {
                        putimage(0, 0, &Withdraw, SRCCOPY);
                    }
                    else
                    {
                        putimage(0, 0, &Withdraw1, SRCCOPY);
                    }
                }break;
            case WM_LBUTTONDOWN:                        // 处理点击事件
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
                if (i == 0 || i == 10 || j == 0 || j == 10)           //边界格子不显示
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
                if(i == 0 || i == 17 || j == 0 || j == 17)           //边界格子不显示
                {
                    t_l.x = -100;
                    t_l.y = -100;
                    b_r.x = -100;
                    b_r.y = -100;
				}
                Blanks temp(&UnCell,&num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &Cell, &HoverCell, &Landmine, &Flag, t_l, b_r);
                    temp.select_show();                                //格子显示函数
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
                if (i == 0 || i == 17 || j == 0 || j == 31)           //边界格子不显示
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
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
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

		int score = 0; // 初始化计数器
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

        if (defeat == 1)                           //展示失败界面
        {
            putimage(344, 0, &GameDefeat, SRCCOPY);
            settextstyle(60, 60, _T("隶书"));
            settextcolor(RED);
            string score_str = "SCORE:"+to_string(score);
			outtextxy(400,540 , (score_str.c_str())); // 显示分数
            break;
        }

		int countblank = 0; // 计数未揭开的格子
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

        if(countblank==12) // 如果所有非雷格子都被揭开
        {
            win = 1;
            putimage(344, 0, &GameWin, SRCCOPY); // 显示胜利界面
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
                        if (firstclick_simple == 1)                //非第一次点击
                        {
                            if (blank_simple[posY][posX].isFlag == 0)
                            {
                                if (blank_simple[posY][posX].NumMine == 0)
                                {
                                    ExpandEmptyCells_simple(posY, posX);
                                }
                                blank_simple[posY][posX].isRevealed = 1;
                                if(blank_simple[posY][posX].IsMine == 1) //如果点到雷
                                {
                                    for (int i = 1; i <= 9; i++)
                                    {
                                        for (int j = 1; j <= 9; j++)
                                        {
                                            if(blank_simple[i][j].IsMine == 1) //显示所有雷
                                            {
                                                blank_simple[i][j].isRevealed = 1;
											}
                                        }
                                    }
                                    defeat = 1;                  //更改游戏状态为失败
								}
                            }
                        }
                        else if (firstclick_simple == 0&& blank_simple[posY][posX].isFlag==0)                 //第一次左键点击
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
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
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
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
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

        if (defeat == 1)                           //展示失败界面
        {
            putimage(344, 0, &GameDefeat, SRCCOPY);
            defeat = 0;
            break;
        }
        int countblank = 0; // 计数未揭开的格子
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

        if (countblank == 64) // 如果所有非雷格子都被揭开
        {
            putimage(344, 0, &GameWin, SRCCOPY); // 显示胜利界面
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
                        if (firstclick_middle == 1)                //非第一次点击
                        {
                            if (blank_middle[posY][posX].isFlag == 0)
                            {
                                blank_middle[posY][posX].isRevealed = 1;
                                if (blank_middle[posY][posX].NumMine == 0)
                                {
                                    ExpandEmptyCells_middle(posY, posX);
                                }
                                if (blank_middle[posY][posX].IsMine == 1) //如果点到雷
                                {
                                    for (int i = 1; i <= 16; i++)
                                    {
                                        for (int j = 1; j <= 16; j++)
                                        {
                                            if (blank_middle[i][j].IsMine == 1) //显示所有雷
                                            {
                                                blank_middle[i][j].isRevealed = 1;
                                            }
                                        }
                                    }
                                    defeat = 1;                  //更改游戏状态为失败
                                }
                            }
                        }
                            else if (firstclick_middle == 0 && blank_middle[posY][posX].isFlag == 0)                 //第一次左键点击
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
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
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
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
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

        if (defeat == 1)                           //展示失败界面
        {
            putimage(344, 0, &GameDefeat, SRCCOPY);
            defeat = 0;
            break;
        }

        int countblank = 0; // 计数未揭开的格子
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

        if (countblank == 120) // 如果所有非雷格子都被揭开
        {
            putimage(344, 0, &GameWin, SRCCOPY); // 显示胜利界面
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
						if (firstclick_difficult == 1)                         //非第一次点击
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
                                    defeat = 1;                  //更改游戏状态为失败
                                }
                            }
                        }
                        else if (firstclick_difficult == 0 && blank_difficult[posY][posX].isFlag == 0)                 //第一次左键点击
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
        if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
        {
            putimage(0, 0, &Withdraw, SRCCOPY);
        }
        else
        {
            putimage(0, 0, &Withdraw1, SRCCOPY);
        }
        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
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
                    if (dx == 0 && dy == 0) continue; // 跳过中心格子
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
                    if (dx == 0 && dy == 0) continue; // 跳过中心格子
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
                    if (dx == 0 && dy == 0) continue; // 跳过中心格子
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
    // 使用静态随机数生成器，避免重复初始化
    static mt19937 generator(chrono::system_clock::now().time_since_epoch().count());

    vector<vector<Blanks>>* targetGrid = nullptr;
    int rows = 0, cols = 0, mineCount = 0;

    // 根据难度选择目标网格和配置
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
            return; // 无效难度级别
    }

    // 重置网格中的地雷
    for (auto& row : *targetGrid)
        for (auto& cell : row)
            cell.IsMine = 0;

    // Fisher-Yates 洗牌算法生成随机位置
    vector<int> positions(rows * cols);
    for (int i = 0; i < rows * cols; ++i)
        positions[i] = i;

    // 只需要打乱前mineCount个元素
    for (int i = 0; i < mineCount; ++i)
    {
        uniform_int_distribution<int> distribution(i, rows * cols - 1);
        int j = distribution(generator);
        swap(positions[i], positions[j]);
    }

    // 设置地雷
    for (int i = 0; i < mineCount; ++i)
    {
        int pos = positions[i];
        int x = pos / cols + 1; // +1 因为网格从1开始
        int y = pos % cols + 1;
        (*targetGrid)[x][y].IsMine = 1;
    }
}

void SweeperGame::ExpandEmptyCells_simple(int y, int x)
{
    // 边界检查和有效性检查
    if (x < 1 || x > 9 || y < 1 || y > 9) 
        return;
    if (blank_simple[y][x].isRevealed==1|| blank_simple[y][x].isFlag==1|| blank_simple[y][x].IsMine==1) 
        return;

    // 标记当前格子为已显示
    blank_simple[y][x].isRevealed = true;

    // 如果当前格子周围有地雷，停止扩展
    if (blank_simple[y][x].NumMine != 0) return;

    // 递归扩展周围的8个方向
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0) continue; // 跳过自身
            ExpandEmptyCells_simple(y + dy, x + dx);
        }
    }
}

void SweeperGame::ExpandEmptyCells_middle(int y, int x)
{
    // 边界检查和有效性检查
    if (x < 1 || x > 16 || y < 1 || y > 16)
        return;
    if (blank_middle[y][x].isRevealed == 1 || blank_middle[y][x].isFlag == 1 || blank_middle[y][x].IsMine == 1)
        return;

    // 标记当前格子为已显示
    blank_middle[y][x].isRevealed = true;

    // 如果当前格子周围有地雷，停止扩展
    if (blank_middle[y][x].NumMine != 0) return;

    // 递归扩展周围的8个方向
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0) continue; // 跳过自身
            ExpandEmptyCells_middle(y + dy, x + dx);
        }
    }
}

void SweeperGame::ExpandEmptyCells_difficult(int y, int x)
{
    // 边界检查和有效性检查
    if (x < 1 || x > 30 || y < 1 || y > 16)
        return;
    if (blank_difficult[y][x].isRevealed == 1 || blank_difficult[y][x].isFlag == 1 || blank_difficult[y][x].IsMine == 1)
        return;

    // 标记当前格子为已显示
    blank_difficult[y][x].isRevealed = true;

    // 如果当前格子周围有地雷，停止扩展
    if (blank_difficult[y][x].NumMine != 0) return;

    // 递归扩展周围的8个方向
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0) continue; // 跳过自身
            ExpandEmptyCells_difficult(y + dy, x + dx);
        }
    }
}