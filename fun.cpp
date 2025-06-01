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
	loadimage(&Gamewithdraw, _T("images/withdraw.png"));                    //游戏返回图片
	loadimage(&GamePause, _T("images/pause.png"));           //游戏暂停图片
	loadimage(&GameContinue, _T("images/go.png"));            //继续游戏图片
	loadimage(&GameRestart, _T("images/replay.png"));                   //重新开始图片
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
                int flag1;
                displayscreen2a();                   //二级画面显示函数
                flag1 = hoverstart2a();                   // 二级画面悬停及点击事件处理函数             1/2/3/4
                switch (flag1)
                {
                    case 1:
                        {
                            while (1)
                            {
                                int flag2;
                                displayscreen_simple();//简单难度展示及Blank类生成
                                Raise_Mines(1);
                                flag2 = hoverstart_simple();
                                vector<vector<Blanks>> temp;
                                swap(temp, blank_simple);
                                break;
                            }
                        }break;
                    case 2:
                        {
                            while (1)
                            {
                                int flag2;
                                displayscreen_middle();
                                Raise_Mines(2);
                                flag2 = hoverstart_middle();
                                vector<vector<Blanks>> temp;
                                swap(temp, blank_middle);
                                break;
                            }
                        }break;
                    case 3:
                        {
                            while (1)
                            {
                                int flag2;
                                displayscreen_difficult();
                                Raise_Mines(3);
                                flag2 = hoverstart_difficult();
                                vector<vector<Blanks>> temp;
                                swap(temp, blank_difficult);
                                break;
                            }
                        }break;
                }
                if (flag1 == 4)
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

void SweeperGame::displayscreen_simple(void)
{
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    if (blank_simple.size() != 9)
    {
        for (int i = 0; i < 9; i++)
        {
            vector<Blanks> blank1;
            for (int j = 0; j < 9; j++)
            {
                Ccoordinate t_l(465 + j * 30, 165 + i * 30);
                Ccoordinate b_r(495 + j * 30, 195 + i * 30);
                Blanks temp(&UnCell, &Cell, &HoverCell, &Landmine, &Flag, t_l, b_r);
                temp.show();
                blank1.push_back(temp);
            }
            blank_simple.push_back(blank1);
        }
    }
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
                Ccoordinate t_l(360 + j * 30, 30 + i * 30);
                Ccoordinate b_r(390 + j * 30, 60 + i * 30);
                Blanks temp(&UnCell, &Cell, &HoverCell, &Landmine, &Flag, t_l, b_r);
                temp.show();
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
    if (blank_difficult.size() != 16)
    {
        for (int i = 0; i < 16; i++)
        {
            vector<Blanks> blank1;
            for (int j = 0; j < 30; j++)
            {
                Ccoordinate t_l(150 + j * 30, 60 + i * 30);
                Ccoordinate b_r(180 + j * 30, 90 + i * 30);
                Blanks temp(&UnCell, &Cell, &HoverCell, &Landmine, &Flag, t_l, b_r);
                temp.show();
                blank1.push_back(temp);
            }
            blank_difficult.push_back(blank1);
        }
    }
}

int SweeperGame::hoverstart_simple(void)
{
    ExMessage msg;
    putimage(0,0,&Withdraw1, SRCCOPY);
    while (1)
    {
        msg = getmessage(EX_MOUSE);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                switch (msg.message)
                {
                    case WM_MOUSEMOVE:
                        {
                            if (msg.x >= blank_simple[i][j].top_left.x && msg.y >= blank_simple[i][j].top_left.y && msg.x <= blank_simple[i][j].bottom_right.x && msg.y <= blank_simple[i][j].bottom_right.y)
                            {
                                if (blank_simple[i][j].isRevealed ==0 && !blank_simple[i][j].isFlag)
                                    blank_simple[i][j].showUnCell();
                                else
                                    blank_simple[i][j].show();
                            }
                            else
                            {
                                blank_simple[i][j].show();
                            }
                            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
                            {
                                putimage(0, 0, &Withdraw, SRCCOPY);
                            }
                            else
                            {
                                putimage(0, 0, &Withdraw1, SRCCOPY);
                            }
                       }break;

                    case WM_LBUTTONDOWN:
                        {
                            if (msg.x >= blank_simple[i][j].top_left.x && msg.y >= blank_simple[i][j].top_left.y && msg.x <= blank_simple[i][j].bottom_right.x && msg.y <= blank_simple[i][j].bottom_right.y)
                            {
                                if(!blank_simple[i][j].isFlag)
                                    blank_simple[i][j].isRevealed = 1;
                            }
                            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
                            {
                                return -1;
                            }
                        }break;
                        
                    case WM_RBUTTONDOWN:
                        {
                            if (msg.x >= blank_simple[i][j].top_left.x && msg.y >= blank_simple[i][j].top_left.y && msg.x <= blank_simple[i][j].bottom_right.x && msg.y <= blank_simple[i][j].bottom_right.y)
                            {
                                blank_simple[i][j].flag();
                                break;
                            }
                        }
                }
            }
        }
    }
}

int SweeperGame::hoverstart_middle(void)
{
    ExMessage msg;
    putimage(0, 0, &Withdraw1, SRCCOPY);
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        bool inWithdrawButton = (msg.x >= 0 && msg.x <= 64) && (msg.y >= 0 && msg.y <= 64);
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                switch (msg.message)
                {
                    case WM_MOUSEMOVE:
                        {
                            if (msg.x >= blank_middle[i][j].top_left.x && msg.y >= blank_middle[i][j].top_left.y && msg.x <= blank_middle[i][j].bottom_right.x && msg.y <= blank_middle[i][j].bottom_right.y)
                            {
                                if (blank_middle[i][j].isRevealed == 0 && !blank_middle[i][j].isFlag)
                                    blank_middle[i][j].showUnCell();
                                else
                                    blank_middle[i][j].show();
                            }
                            else
                            {
                                blank_middle[i][j].show();
                            }
                            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
                            {
                                putimage(0, 0, &Withdraw, SRCCOPY);
                            }
                            else
                            {
                                putimage(0, 0, &Withdraw1, SRCCOPY);
                            }
                        }break;

                    case WM_LBUTTONDOWN:
                        {
                            if (msg.x >= blank_middle[i][j].top_left.x && msg.y >= blank_middle[i][j].top_left.y && msg.x <= blank_middle[i][j].bottom_right.x && msg.y <= blank_middle[i][j].bottom_right.y)
                            {
                                if (!blank_middle[i][j].isFlag)
                                    blank_middle[i][j].isRevealed = 1;
                            }
                            else if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)
                            {
                                return -1;
                            }
                        }break;
                    case WM_RBUTTONDOWN:
                        {
                            if (msg.x >= blank_middle[i][j].top_left.x && msg.y >= blank_middle[i][j].top_left.y && msg.x <= blank_middle[i][j].bottom_right.x && msg.y <= blank_middle[i][j].bottom_right.y)
                            {
                                blank_middle[i][j].flag();
                                break;
                            }
                        }
                }
            }
        }
    }
}

int SweeperGame::hoverstart_difficult(void)
{
    ExMessage msg;
    putimage(0, 0, &Withdraw1, SRCCOPY);
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        bool inWithdrawButton = (msg.x >= 0 && msg.x <= 64) && (msg.y >= 0 && msg.y <= 64);
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                switch (msg.message)
                {
                    case WM_MOUSEMOVE:
                        {
                            if (msg.x >= blank_difficult[i][j].top_left.x && msg.y >= blank_difficult[i][j].top_left.y && msg.x <= blank_difficult[i][j].bottom_right.x && msg.y <= blank_difficult[i][j].bottom_right.y)
                            {
                                if (blank_difficult[i][j].isRevealed == 0 && !blank_difficult[i][j].isFlag)
                                    blank_difficult[i][j].showUnCell();
                                else
                                    blank_difficult[i][j].show();
                            }
                            else
                            {
                                blank_difficult[i][j].show();
                            }
                            if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)//返回
                            {
                                putimage(0, 0, &Withdraw, SRCCOPY);
                            }
                            else
                            {
                                putimage(0, 0, &Withdraw1, SRCCOPY);
                            }
                        }break;

                    case WM_LBUTTONDOWN:
                        {
                            if (msg.x >= blank_difficult[i][j].top_left.x && msg.y >= blank_difficult[i][j].top_left.y && msg.x <= blank_difficult[i][j].bottom_right.x && msg.y <= blank_difficult[i][j].bottom_right.y)
                            {
                                if (!blank_difficult[i][j].isFlag)
                                    blank_difficult[i][j].isRevealed = 1;
                            }
                            else if (msg.x <= 64 && msg.x >= 0 && msg.y <= 64 && msg.y >= 0)
                            {
                                return -1;
                            }
                        }break;
                    case WM_RBUTTONDOWN:
                        {
                            if (msg.x >= blank_difficult[i][j].top_left.x && msg.y >= blank_difficult[i][j].top_left.y && msg.x <= blank_difficult[i][j].bottom_right.x && msg.y <= blank_difficult[i][j].bottom_right.y)
                            {
                                blank_difficult[i][j].flag();
                                break;
                            }
                        }
                }
            }
        }
    }
}

void SweeperGame::Raise_Mines(int num)
{
    size_t size = 0;
    switch (num)
    {
        case 1:size = blank_simple[0].size(); break;
        case 2:size = blank_middle[0].size(); break;
        case 3:size = blank_difficult[0].size(); break;
    }
    switch (size)
    {
        case 9:
            {
                int num = 12;
                vector<char> vec(81, '0');
                for (int i = 0; i < num; i++)
                    vec[i] = '1';
                for (int i = 80; i >0; i--)
                {
                    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
                    mt19937 generator(seed);  // Mersenne Twister算法

                    // 生成0-i的均匀分布整数
                    uniform_int_distribution<int> distribution(0, i);

                    // 生成并输出随机数
                    int j = distribution(generator);
                    
                    swap(vec[i], vec[j]);
                }
                int k = 0;
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if(vec[k++]=='1')
                            blank_simple[i][j].IsMine = 1;
                    }
                }
                
            }break;
        case 18:
            {
                int num = 64;
                vector<char> vec(324, '0');
                for (int i = 0; i < num; i++)
                    vec[i] = '1';
                for (int i = 323; i > 0; i--)
                {
                    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
                    mt19937 generator(seed);  // Mersenne Twister算法

                    // 生成0-i的均匀分布整数
                    uniform_int_distribution<int> distribution(0, i);

                    // 生成并输出随机数
                    int j = distribution(generator);

                    swap(vec[i], vec[j]);
                }
                int k = 0;
                for (int i = 0; i < 18; i++)
                {
                    for (int j = 0; j < 18; j++)
                    {
                        if (vec[k++] == '1')
                            blank_middle[i][j].IsMine = 1;
                    }
                }
            }break;
        case 30:
            {
                int num = 120;
                vector<char> vec(480, '0');
                for (int i = 0; i < num; i++)
                    vec[i] = '1';
                for (int i = 479; i > 0; i--)
                {
                    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
                    mt19937 generator(seed);  // Mersenne Twister算法

                    // 生成0-i的均匀分布整数
                    uniform_int_distribution<int> distribution(0, i);

                    // 生成并输出随机数
                    int j = distribution(generator);

                    swap(vec[i], vec[j]);
                }
                int k = 0;
                for (int i = 0; i < 16; i++)
                {
                    for (int j = 0; j < 30; j++)
                    {
                        if (vec[k++] == '1')
                            blank_difficult[i][j].IsMine = 1;
                    }
                }
            }break;
    }
}