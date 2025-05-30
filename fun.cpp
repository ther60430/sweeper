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
	loadimage(&Medium1, _T("images/middle2.png"), 256, 64);                                //�е�ģʽͼƬ
	loadimage(&Difficult1, _T("images/difficult2.png"), 256, 64);                                 //����ģʽͼƬ
    loadimage(&Simple, _T("images/Simple.png"), 256, 64);                                        //��ģʽ��ͣͼƬ
    loadimage(&Medium, _T("images/middle1.png"), 256, 64);                                //�е�ģʽ��ͣͼƬ
    loadimage(&Difficult, _T("images/Difficult1.png"), 256, 64);                                 //����ģʽ��ͣͼƬ
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
                int flag1;
                displayscreen2a();                   //����������ʾ����
                flag1 = hoverstart2a();                   // ����������ͣ������¼�������             1/2/3/4
                switch (flag1)
                {
                    case 1:
                        {
                            while (1)
                            {
                                int flag2;
                                displayscreen_simple();//���Ѷ�չʾ��Blank������
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

void SweeperGame::displayscreen_simple(void)
{
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    if (blank_simple.size() != 9)
    {
        for (int i = 0; i < 9; i++)
        {
            vector<Blanks> blank2;
            for (int j = 0; j < 9; j++)
            {
                Ccoordinate t_l(465 + j * 30, 165 + i * 30);
                Ccoordinate b_r(495 + j * 30, 195 + i * 30);
                Blanks temp(UnCell, Cell, HoverCell, Landmine, Flag, t_l, b_r);
                temp.show();
                blank2.push_back(temp);
            }
            blank_simple.push_back(blank2);
        }
    }
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

void SweeperGame::displayscreen_middle(void)
{
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    if (blank_middle.size() != 16)
    {
		blank_middle.clear(); // ���������
        for (int i = 0; i <=15; ++i)
        {
            vector<Blanks> blank1;
            for (int j = 0; j <=15; ++j)
            {
                Ccoordinate t_l(360 + j * 30, 60 + i * 30);
                Ccoordinate b_r(390 + j * 30, 90 + i * 30);
                Blanks blank2(UnCell, Cell, HoverCell, Landmine, Flag, t_l, b_r);
                blank2.show();
                blank1.push_back(blank2);
            }
            blank_middle.push_back(blank1);
        }
    }
}

void SweeperGame::displayscreen_difficult(void)
{
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    if (blank_difficult.size() != 20)
    {
        blank_difficult.clear(); // ���������
        for (int i = 0; i <= 19; ++i)
        {
            vector<Blanks> blank1;
            for (int j = 0; j <= 19; ++j)
            {
                Ccoordinate t_l(360 + j * 30, 60 + i * 30);
                Ccoordinate b_r(390 + j * 30, 90 + i * 30);
                Blanks blank2(UnCell, Cell, HoverCell, Landmine, Flag, t_l, b_r);
                blank2.show();
                blank1.push_back(blank2);
            }
            blank_difficult.push_back(blank1);
        }
    }
}

int SweeperGame::hoverstart_simple(void)
{
    ExMessage msg;
    putimage(0, 0, &Withdraw1, SRCCOPY);

    // ���vector�Ƿ��ѳ�ʼ��
    if (blank_simple.empty() || blank_simple.size() != 9 ||
        any_of(blank_simple.begin(), blank_simple.end(),
            [](const auto& row) { return row.size() != 9; })) {
        std::cerr << "Error: blank_simple not initialized correctly!" << std::endl;
        return -1;
    }

    while (true)
    {
        msg = getmessage(EX_MOUSE);
        bool inWithdrawButton = (msg.x >= 0 && msg.x <= 64) && (msg.y >= 0 && msg.y <= 64);

        // ���·��ذ�ť״̬
        putimage(0, 0, inWithdrawButton ? &Withdraw : &Withdraw1, SRCCOPY);

        // ��ǰ����Ƿ������ذ�ť
        if (msg.message == WM_LBUTTONDOWN && inWithdrawButton) {
            return -1;
        }

        // ����������ڵĸ���
        int mouseRow = -1, mouseCol = -1;
        if (msg.x >= blank_simple[0][0].top_left.x &&
            msg.y >= blank_simple[0][0].top_left.y &&
            msg.x <= blank_simple[8][8].bottom_right.x &&
            msg.y <= blank_simple[8][8].bottom_right.y) {

            mouseRow = (msg.y - blank_simple[0][0].top_left.y) / 30;
            mouseCol = (msg.x - blank_simple[0][0].top_left.x) / 30;

            // ȷ����������Ч��Χ��
            if (mouseRow >= 0 && mouseRow < 9 && mouseCol >= 0 && mouseCol < 9) {
                // ��������¼�
                switch (msg.message)
                {
                    case WM_MOUSEMOVE:
                        if (!blank_simple[mouseRow][mouseCol].isRevealed &&
                            !blank_simple[mouseRow][mouseCol].isFlag) {
                            blank_simple[mouseRow][mouseCol].showUnCell();
                        }
                        else {
                            blank_simple[mouseRow][mouseCol].show();
                        }
                        break;

                    case WM_LBUTTONDOWN:
                        if (blank_simple[mouseRow][mouseCol].isFlag == 0)
                        {
                            blank_simple[mouseRow][mouseCol].isRevealed = 1;
                            blank_simple[mouseRow][mouseCol].show();
                        }
                        break;

                    case WM_RBUTTONDOWN:
                        blank_simple[mouseRow][mouseCol].flag();
                        blank_simple[mouseRow][mouseCol].show();
                        break;
                }
            }
        }

        // �ػ���������
        if (msg.message == WM_MOUSEMOVE) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (i != mouseRow || j != mouseCol) {
                        blank_simple[i][j].show();
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

    // ���vector�Ƿ��ѳ�ʼ��
    if (blank_middle.empty() || blank_middle.size() != 16 ||
        any_of(blank_middle.begin(), blank_middle.end(),
            [](const auto& row) { return row.size() != 16; })) {
        std::cerr << "Error: blank_middle not initialized correctly!" << std::endl;
        return -1;
    }

    while (true)
    {
        msg = getmessage(EX_MOUSE);
        bool inWithdrawButton = (msg.x >= 0 && msg.x <= 64) && (msg.y >= 0 && msg.y <= 64);

        // ���·��ذ�ť״̬
        putimage(0, 0, inWithdrawButton ? &Withdraw : &Withdraw1, SRCCOPY);

        // ��ǰ����Ƿ������ذ�ť
        if (msg.message == WM_LBUTTONDOWN && inWithdrawButton) {
            return -1;
        }

        // ����������ڵĸ���
        int mouseRow = -1, mouseCol = -1;
        if (msg.x >= blank_middle[0][0].top_left.x &&
            msg.y >= blank_middle[0][0].top_left.y &&
            msg.x <= blank_middle[15][15].bottom_right.x &&
            msg.y <= blank_middle[15][15].bottom_right.y) {

            mouseRow = (msg.y - blank_middle[0][0].top_left.y) / 30;
            mouseCol = (msg.x - blank_middle[0][0].top_left.x) / 30;

            // ȷ����������Ч��Χ��
            if (mouseRow >= 0 && mouseRow < 16 && mouseCol >= 0 && mouseCol < 16) {
                // ��������¼�
                switch (msg.message)
                {
                    case WM_MOUSEMOVE:
                        if (!blank_simple[mouseRow][mouseCol].isRevealed &&
                            !blank_simple[mouseRow][mouseCol].isFlag) {
                            blank_simple[mouseRow][mouseCol].showUnCell();
                        }
                        else {
                            blank_simple[mouseRow][mouseCol].show();
                        }
                        break;

                    case WM_LBUTTONDOWN:
                        if (blank_simple[mouseRow][mouseCol].isFlag == 0)
                        {
                            blank_simple[mouseRow][mouseCol].isRevealed = 1;
                            blank_simple[mouseRow][mouseCol].show();
                        }
                        break;

                    case WM_RBUTTONDOWN:
                        blank_simple[mouseRow][mouseCol].flag();
                        blank_simple[mouseRow][mouseCol].show();
                        break;
                }
            }
        }

        // �ػ���������
        if (msg.message == WM_MOUSEMOVE) {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    if (i != mouseRow || j != mouseCol) {
                        blank_middle[i][j].show();
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

    // ���vector�Ƿ��ѳ�ʼ��
    if (blank_difficult.empty() || blank_difficult.size() != 16 ||
        any_of(blank_difficult.begin(), blank_difficult.end(),
            [](const auto& row) { return row.size() != 30; })) {
        std::cerr << "Error: blank_difficult not initialized correctly!" << std::endl;
        return -1;
    }

    while (true)
    {
        msg = getmessage(EX_MOUSE);
        bool inWithdrawButton = (msg.x >= 0 && msg.x <= 64) && (msg.y >= 0 && msg.y <= 64);

        // ���·��ذ�ť״̬
        putimage(0, 0, inWithdrawButton ? &Withdraw : &Withdraw1, SRCCOPY);

        // ��ǰ����Ƿ������ذ�ť
        if (msg.message == WM_LBUTTONDOWN && inWithdrawButton) {
            return -1;
        }

        // ����������ڵĸ���
        int mouseRow = -1, mouseCol = -1;
        if (msg.x >= blank_difficult[0][0].top_left.x &&
            msg.y >= blank_difficult[0][0].top_left.y &&
            msg.x <= blank_difficult[15][29].bottom_right.x &&
            msg.y <= blank_difficult[15][29].bottom_right.y) {

            mouseRow = (msg.y - blank_difficult[0][0].top_left.y) / 30;  
            mouseCol = (msg.x - blank_difficult[0][0].top_left.x) / 30;

            // ȷ����������Ч��Χ��
            if (mouseRow >= 0 && mouseRow < 16 && mouseCol >= 0 && mouseCol < 30) {
                // ��������¼�
                switch (msg.message)
                {
                    case WM_MOUSEMOVE:
                        if (!blank_simple[mouseRow][mouseCol].isRevealed &&
                            !blank_simple[mouseRow][mouseCol].isFlag) {
                            blank_simple[mouseRow][mouseCol].showUnCell();
                        }
                        else {
                            blank_simple[mouseRow][mouseCol].show();
                        }
                        break;

                    case WM_LBUTTONDOWN:
                        if (blank_simple[mouseRow][mouseCol].isFlag == 0)
                        {
                            blank_simple[mouseRow][mouseCol].isRevealed = 1;
                            blank_simple[mouseRow][mouseCol].show();
                        }
                        break;

                    case WM_RBUTTONDOWN:
                        blank_simple[mouseRow][mouseCol].flag();
                        blank_simple[mouseRow][mouseCol].show();
                        break;
                }
            }
        }

        // �ػ���������
        if (msg.message == WM_MOUSEMOVE) {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 30; j++) {
                    if (i != mouseRow || j != mouseCol) {
                        blank_difficult[i][j].show();
                    }
                }
            }
        }
    }
}

void SweeperGame::Raise_Mines(int num)
{
    int size = 0;
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
                    mt19937 generator(seed);  // Mersenne Twister�㷨

                    // ����0-i�ľ��ȷֲ�����
                    uniform_int_distribution<int> distribution(0, i);

                    // ���ɲ���������
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
        case 16:
            {
                int num = 51;
                vector<char> vec(256, '0');
                for (int i = 0; i < num; i++)
                    vec[i] = '1';
                for (int i = 255; i > 0; i--)
                {
                    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
                    mt19937 generator(seed);  // Mersenne Twister�㷨

                    // ����0-i�ľ��ȷֲ�����
                    uniform_int_distribution<int> distribution(0, i);

                    // ���ɲ���������
                    int j = distribution(generator);

                    swap(vec[i], vec[j]);
                }
                int k = 0;
                for (int i = 0; i < 16; i++)
                {
                    for (int j = 0; j < 16; j++)
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
                    mt19937 generator(seed);  // Mersenne Twister�㷨

                    // ����0-i�ľ��ȷֲ�����
                    uniform_int_distribution<int> distribution(0, i);

                    // ���ɲ���������
                    int j = distribution(generator);

                    swap(vec[i], vec[j]);
                }
                int k = 0;
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (vec[k++] == '1')
                            blank_difficult[i][j].IsMine = 1;
                    }
                }
            }break;
    }
}