#include"header.h"

void SweeperGame::InitGame()
{
	initgraph(setting.width, setting.height);                          //1200*600
<<<<<<< HEAD
	loadimage(&Title, _T("images/title.png"), 800, 120);       //±êÌâÍ¼Æ¬
	loadimage(&UnCell, _T("images/uncell.png"),30,30);          //Î´½Ò¿ª¸ñ×ÓÍ¼Æ¬
	loadimage(&Cell, _T("images/cell.png"), 30, 30);            //ÒÑ½Ò¿ª¸ñ×ÓÍ¼Æ¬
	loadimage(&HoverCell, _T("images/hover.png"), 30, 30);                     //Êó±êÐüÍ£¸ñ×ÓÍ¼Æ¬
	loadimage(&Landmine, _T("images/thounder.png"), 30, 30);              //À×Í¼Æ¬
    loadimage(&history_scores1, _T("images/history_scores1.png"), 256, 64);         //·ÖÊýÐüÍ£Í¼Æ¬
	loadimage(&history_scores, _T("images/history_scores.png"), 256, 64);         //·ÖÊýÍ¼Æ¬
	loadimage(&GameStart1, _T("images/start1.png"),256,64);              //ÓÎÏ·¿ªÊ¼Í¼Æ¬
	loadimage(&GameStart, _T("images/start.png"), 256, 64);              //ÓÎÏ·¿ªÊ¼ÐüÍ£Í¼Æ¬
	loadimage(&Gamewithdraw, _T("images/withdraw.png"));                    //ÓÎÏ··µ»ØÍ¼Æ¬
	loadimage(&GamePause, _T("images/pause.png"));           //ÓÎÏ·ÔÝÍ£Í¼Æ¬
	loadimage(&GameContinue, _T("images/go.png"));            //¼ÌÐøÓÎÏ·Í¼Æ¬
	loadimage(&GameRestart, _T("images/replay.png"));                   //ÖØÐÂ¿ªÊ¼Í¼Æ¬
	loadimage(&GameExit1, _T("images/end1.png"),256,64);               //ÍË³öÓÎÏ·°´Å¥Í¼Æ¬
	loadimage(&GameExit, _T("images/end.png"), 256, 64);               //ÍË³öÓÎÏ·°´Å¥ÐüÍ£Í¼Æ¬
	loadimage(&Flag, _T("images/flag.png"),30,30);             //ÆìÖÄÍ¼Æ¬
=======
	loadimage(&Title, _T("images/title.png"), 800, 120);       //æ ‡é¢˜å›¾ç‰‡
	loadimage(&UnCell, _T("images/uncell.png"),30,30);          //æœªæ­å¼€æ ¼å­å›¾ç‰‡
	loadimage(&Cell, _T("images/cell.png"), 30, 30);            //å·²æ­å¼€æ ¼å­å›¾ç‰‡
	loadimage(&HoverCell, _T("images/hover.png"), 30, 30);                     //é¼ æ ‡æ‚¬åœæ ¼å­å›¾ç‰‡
	loadimage(&Landmine, _T("images/thounder.png"), 30, 30);              //é›·å›¾ç‰?
    loadimage(&history_scores1, _T("images/history_scores1.png"), 256, 64);         //åˆ†æ•°æ‚¬åœå›¾ç‰‡
	loadimage(&history_scores, _T("images/history_scores.png"), 256, 64);         //åˆ†æ•°å›¾ç‰‡
	loadimage(&GameStart1, _T("images/start1.png"),256,64);              //æ¸¸æˆå¼€å§‹å›¾ç‰?
	loadimage(&GameStart, _T("images/start.png"), 256, 64);              //æ¸¸æˆå¼€å§‹æ‚¬åœå›¾ç‰?
	loadimage(&Gamewithdraw, _T("images/withdraw.png"));                    //æ¸¸æˆè¿”å›žå›¾ç‰‡
	loadimage(&GamePause, _T("images/pause.png"));           //æ¸¸æˆæš‚åœå›¾ç‰‡
	loadimage(&GameContinue, _T("images/go.png"));            //ç»§ç»­æ¸¸æˆå›¾ç‰‡
	loadimage(&GameRestart, _T("images/replay.png"));                   //é‡æ–°å¼€å§‹å›¾ç‰?
	loadimage(&GameExit1, _T("images/end1.png"),256,64);               //é€€å‡ºæ¸¸æˆæŒ‰é’®å›¾ç‰?
	loadimage(&GameExit, _T("images/end.png"), 256, 64);               //é€€å‡ºæ¸¸æˆæŒ‰é’®æ‚¬åœå›¾ç‰?
	loadimage(&Flag, _T("images/flag.png"),30,30);             //æ——å¸œå›¾ç‰‡
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
	loadimage(&num[0], _T("images/1.png"), 30, 30);
	loadimage(&num[1], _T("images/2.png"), 30, 30);
	loadimage(&num[2], _T("images/3.png"), 30, 30);
	loadimage(&num[3], _T("images/4.png"), 30, 30);
	loadimage(&num[4], _T("images/5.png"), 30, 30);
	loadimage(&num[5], _T("images/6.png"), 30, 30);
	loadimage(&num[6], _T("images/7.png"), 30, 30);
	loadimage(&num[7], _T("images/8.png"), 30, 30);
<<<<<<< HEAD
	loadimage(&BackGraound, _T("images/BackGround.png"), 1200, 600);                  //±³¾°Í¼Æ¬
	loadimage(&Simple1, _T("images/Simple1.png"), 256, 64);                                        //¼òµ¥Ä£Ê½Í¼Æ¬
	loadimage(&Medium1, _T("images/middle2.png"), 256, 64);                                //ÖÐµÈÄ£Ê½Í¼Æ¬
	loadimage(&Difficult1, _T("images/difficult2.png"), 256, 64);                                 //À§ÄÑÄ£Ê½Í¼Æ¬
    loadimage(&Simple, _T("images/Simple.png"), 256, 64);                                        //¼òµ¥Ä£Ê½ÐüÍ£Í¼Æ¬
    loadimage(&Medium, _T("images/middle1.png"), 256, 64);                                //ÖÐµÈÄ£Ê½ÐüÍ£Í¼Æ¬
    loadimage(&Difficult, _T("images/Difficult1.png"), 256, 64);                                 //À§ÄÑÄ£Ê½ÐüÍ£Í¼Æ¬
	loadimage(&Withdraw1, _T("images/Withdraw1.png"), 64, 64);                            //·µ»Ø°´Å¥Í¼Æ¬
    loadimage(&Withdraw, _T("images/Withdraw.png"), 64, 64);                            //·µ»Ø°´Å¥ÐüÍ£Í¼Æ¬
=======
	loadimage(&BackGraound, _T("images/BackGround.png"), 1200, 600);                  //èƒŒæ™¯å›¾ç‰‡
	loadimage(&Simple1, _T("images/Simple1.png"), 256, 64);                                        //ç®€å•æ¨¡å¼å›¾ç‰?
	loadimage(&Medium1, _T("images/middle2.png"), 256, 64);                                //ä¸­ç­‰æ¨¡å¼å›¾ç‰‡
	loadimage(&Difficult1, _T("images/difficult2.png"), 256, 64);                                 //å›°éš¾æ¨¡å¼å›¾ç‰‡
    loadimage(&Simple, _T("images/Simple.png"), 256, 64);                                        //ç®€å•æ¨¡å¼æ‚¬åœå›¾ç‰?
    loadimage(&Medium, _T("images/middle1.png"), 256, 64);                                //ä¸­ç­‰æ¨¡å¼æ‚¬åœå›¾ç‰‡
    loadimage(&Difficult, _T("images/Difficult1.png"), 256, 64);                                 //å›°éš¾æ¨¡å¼æ‚¬åœå›¾ç‰‡
	loadimage(&Withdraw1, _T("images/Withdraw1.png"), 64, 64);                            //è¿”å›žæŒ‰é’®å›¾ç‰‡
    loadimage(&Withdraw, _T("images/Withdraw.png"), 64, 64);                            //è¿”å›žæŒ‰é’®æ‚¬åœå›¾ç‰‡
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
}

void SweeperGame::run_game(void)
{
    int flag0 = -1;
    while (1)
    {
<<<<<<< HEAD
        displayscreen1();				//Ò»¼¶»­ÃæÏÔÊ¾º¯Êý
        flag0 = hoverstart1();     //Ò»¼¶»­ÃæÐüÍ£¼°µã»÷ÊÂ¼þ´¦Àíº¯Êý       1/2/3                    
=======
        displayscreen1();				//ä¸€çº§ç”»é¢æ˜¾ç¤ºå‡½æ•?
        flag0 = hoverstart1();     //ä¸€çº§ç”»é¢æ‚¬åœåŠç‚¹å‡»äº‹ä»¶å¤„ç†å‡½æ•°       1/2/3                    
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
        switch (flag0)
        {
        case 1:
        {
            while (1)
            {
                int flag1;
<<<<<<< HEAD
                displayscreen2a();                   //¶þ¼¶»­ÃæÏÔÊ¾º¯Êý
                flag1 = hoverstart2a();                   // ¶þ¼¶»­ÃæÐüÍ£¼°µã»÷ÊÂ¼þ´¦Àíº¯Êý             1/2/3/4
=======
                displayscreen2a();                   //äºŒçº§ç”»é¢æ˜¾ç¤ºå‡½æ•°
                flag1 = hoverstart2a();                   // äºŒçº§ç”»é¢æ‚¬åœåŠç‚¹å‡»äº‹ä»¶å¤„ç†å‡½æ•?            1/2/3/4
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
                switch (flag1)
                {
                    case 1:
                        {
                            while (1)
                            {
                                int flag2;
                                displayscreen_simple();//¼òµ¥ÄÑ¶ÈÕ¹Ê¾¼°BlankÀàÉú³É
<<<<<<< HEAD
=======
                                Raise_Mines();
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
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
<<<<<<< HEAD
=======
                                Raise_Mines();
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
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
<<<<<<< HEAD
=======
                                Raise_Mines();
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
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

<<<<<<< HEAD
void SweeperGame::displayscreen1(void)                //Ò»¼¶»­ÃæÏÔÊ¾º¯Êý
{
    cleardevice();                                          //ÇåÆÁ
    putimage(0, 0, &BackGraound, SRCCOPY);                  //±³¾°Í¼Æ¬
    putimage(200, 100, &Title, SRCCOPY);                    //±êÌâÍ¼Æ¬
    putimage(472, 300, &GameStart1, SRCCOPY);               //ÓÎÏ·¿ªÊ¼°´Å¥
    putimage(472, 380, &history_scores1, SRCCOPY);          //·ÖÊý°´Å¥
    putimage(472, 460, &GameExit1, SRCCOPY);                //ÍË³ö°´Å¥
    FlushBatchDraw();                                       //Ë¢ÐÂÆÁÄ»
=======
void SweeperGame::displayscreen1(void)                //ä¸€çº§ç”»é¢æ˜¾ç¤ºå‡½æ•?
{
    cleardevice();                                          //æ¸…å±
    putimage(0, 0, &BackGraound, SRCCOPY);                  //èƒŒæ™¯å›¾ç‰‡
    putimage(200, 100, &Title, SRCCOPY);                    //æ ‡é¢˜å›¾ç‰‡
    putimage(472, 300, &GameStart1, SRCCOPY);               //æ¸¸æˆå¼€å§‹æŒ‰é’?
    putimage(472, 380, &history_scores1, SRCCOPY);          //åˆ†æ•°æŒ‰é’®
    putimage(472, 460, &GameExit1, SRCCOPY);                //é€€å‡ºæŒ‰é’?
    FlushBatchDraw();                                       //åˆ·æ–°å±å¹•
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
}

void SweeperGame::displayscreen2a(void)                   //¶þ¼¶»­ÃæÏÔÊ¾º¯Êý
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

int SweeperGame::hoverstart1(void)                      //Ò»¼¶»­ÃæÐüÍ£¼°µã»÷ÊÂ¼þ´¦Àíº¯Êý
{
    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        // ¼ì²éÊó±êÊÇ·ñÔÚ¿ªÊ¼°´Å¥ÉÏ
        bool inStartButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 300 && msg.y <= 364);
<<<<<<< HEAD
        // ¼ì²éÊó±êÊÇ·ñÔÚ·ÖÊý°´Å¥ÉÏ
=======
        // æ£€æŸ¥é¼ æ ‡æ˜¯å¦åœ¨åˆ†æ•°æŒ‰é’®ä¸?
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
        bool inScoreButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 380 && msg.y <= 444);
        // ¼ì²éÊó±êÊÇ·ñÔÚÍË³ö°´Å¥ÉÏ
        bool inExitButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 460 && msg.y <= 524);
        switch (msg.message)
        {
        case WM_MOUSEMOVE:
<<<<<<< HEAD
            // ´¦Àí¿ªÊ¼°´Å¥ÐüÍ£
=======
            // å¤„ç†å¼€å§‹æŒ‰é’®æ‚¬å?
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
            if (inStartButton)
            {
                putimage(472, 300, &GameStart, SRCCOPY);
            }
            else
            {
                putimage(472, 300, &GameStart1, SRCCOPY);
            }
            // ´¦Àí·ÖÊý°´Å¥ÐüÍ£
            if (inScoreButton)
            {
                putimage(472, 380, &history_scores1, SRCCOPY);
            }
            else
            {
                putimage(472, 380, &history_scores, SRCCOPY);
            }
<<<<<<< HEAD
            // ´¦ÀíÍË³ö°´Å¥ÐüÍ£
=======
            // å¤„ç†é€€å‡ºæŒ‰é’®æ‚¬å?
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
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
            // ´¦Àíµã»÷ÊÂ¼þ
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

<<<<<<< HEAD
int SweeperGame::hoverstart2a(void)                               // ¶þ¼¶»­ÃæÐüÍ£¼°µã»÷ÊÂ¼þ´¦Àíº¯Êý
=======
int SweeperGame::hoverstart2a(void)                               // äºŒçº§ç”»é¢æ‚¬åœåŠç‚¹å‡»äº‹ä»¶å¤„ç†å‡½æ•?
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
{
    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);
        // ¼ì²éÊó±êÊÇ·ñÔÚ¼òµ¥°´Å¥ÉÏ
        bool inSimpleButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 300 && msg.y <= 364);
<<<<<<< HEAD
        // ¼ì²éÊó±êÊÇ·ñÔÚÖÐµÈ°´Å¥ÉÏ
        bool inMediumButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 380 && msg.y <= 444);
        // ¼ì²éÊó±êÊÇ·ñÔÚÀ§ÄÑ°´Å¥ÉÏ
        bool inDifficultButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 460 && msg.y <= 524);
        // ¼ì²éÊó±êÊÇ·ñÔÚ·µ»Ø°´Å¥ÉÏ
=======
        // æ£€æŸ¥é¼ æ ‡æ˜¯å¦åœ¨ä¸­ç­‰æŒ‰é’®ä¸?
        bool inMediumButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 380 && msg.y <= 444);
        // æ£€æŸ¥é¼ æ ‡æ˜¯å¦åœ¨å›°éš¾æŒ‰é’®ä¸?
        bool inDifficultButton = (msg.x >= 472 && msg.x <= 728) && (msg.y >= 460 && msg.y <= 524);
        // æ£€æŸ¥é¼ æ ‡æ˜¯å¦åœ¨è¿”å›žæŒ‰é’®ä¸?
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
        bool inWithdrawButton = (msg.x >= 0 && msg.x <= 64) && (msg.y >= 0 && msg.y <= 64);
        switch (msg.message)
        {
            case WM_MOUSEMOVE:
                {
<<<<<<< HEAD
                    // ´¦Àí¼òµ¥°´Å¥ÐüÍ£
=======
                    // å¤„ç†ç®€å•æŒ‰é’®æ‚¬å?
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
                    if (inSimpleButton)
                    {
                        putimage(472, 300, &Simple, SRCCOPY);
                    }
                    else
                    {
                        putimage(472, 300, &Simple1, SRCCOPY);
                    }
                    // ´¦ÀíÖÐµÈ°´Å¥ÐüÍ£
                    if (inMediumButton)
                    {
                        putimage(472, 380, &Medium, SRCCOPY);
                    }
                    else
                    {
                        putimage(472, 380, &Medium1, SRCCOPY);
                    }
                    // ´¦ÀíÀ§ÄÑ°´Å¥ÐüÍ£
                    if (inDifficultButton)
                    {
                        putimage(472, 460, &Difficult, SRCCOPY);
                    }
                    else
                    {
                        putimage(472, 460, &Difficult1, SRCCOPY);
                    }
                    // ´¦Àí·µ»Ø°´Å¥ÐüÍ£
                    if (inWithdrawButton)
                    {
                        putimage(0, 0, &Withdraw, SRCCOPY);
                    }
                    else
                    {
                        putimage(0, 0, &Withdraw1, SRCCOPY);
                    }
                }break;
            case WM_LBUTTONDOWN:                        // ´¦Àíµã»÷ÊÂ¼þ
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
		blank_middle.clear(); // Çå³ý¾ÉÊý¾Ý
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
<<<<<<< HEAD
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);
    if (blank_difficult.size() != 20)
    {
        blank_difficult.clear(); // Çå³ý¾ÉÊý¾Ý
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
=======
    const int START_X = 150;
    const int START_Y = 60;
    const int CELL_SIZE = 30;
    // æ¸…é™¤å±å¹•å¹¶ç»˜åˆ¶èƒŒæ™?
    cleardevice();
    putimage(0, 0, &BackGraound, SRCCOPY);

    // å®Œå…¨é‡ç½®ç½‘æ ¼è€Œä¸æ˜¯éƒ¨åˆ†æ£€æŸ?
    if (blank_difficult.size() != 16 ||
        any_of(blank_difficult.begin(), blank_difficult.end(),
            [](const auto& row) { return row.size() != 30; })) {

        // æ¸…é™¤æ—§æ•°æ?
        blank_difficult.clear();
        blank_difficult.reserve(16);

        // åˆ›å»ºæ–°ç½‘æ ?
        for (int i = 0; i < 16; i++) {
            vector<Blanks> row;
            row.reserve(30);

            for (int j = 0; j < 30; j++) {
                // åæ ‡è®¡ç®— - ä½¿ç”¨å¸¸é‡æ›¿ä»£ç¡¬ç¼–ç å€?
                Ccoordinate t_l(START_X + j * CELL_SIZE, START_Y + i * CELL_SIZE);
                Ccoordinate b_r(START_X + (j + 1) * CELL_SIZE, START_Y + (i + 1) * CELL_SIZE);

                // åˆ›å»ºæ ¼å­å¹¶æ·»åŠ åˆ°è¡?
                Blanks blank(UnCell, Cell, HoverCell, Landmine, Flag, t_l, b_r);
                row.push_back(blank);
            }

            // æ·»åŠ è¡Œåˆ°ç½‘æ ¼
            blank_difficult.push_back(row);
        }

        // æ˜¾ç¤ºæ‰€æœ‰æ ¼å­?
        for (auto& row : blank_difficult) {
            for (auto& cell : row) {
                cell.show();
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
            }
            blank_difficult.push_back(blank1);
        }
    }
}

int SweeperGame::hoverstart_simple(void)
{
    ExMessage msg;
    putimage(0, 0, &Withdraw1, SRCCOPY);

    // ¼ì²évectorÊÇ·ñÒÑ³õÊ¼»¯
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

<<<<<<< HEAD
        // ¸üÐÂ·µ»Ø°´Å¥×´Ì¬
        putimage(0, 0, inWithdrawButton ? &Withdraw : &Withdraw1, SRCCOPY);

        // ÌáÇ°¼ì²éÊÇ·ñµã»÷·µ»Ø°´Å¥
=======
        // æ›´æ–°è¿”å›žæŒ‰é’®çŠ¶æ€?
        putimage(0, 0, inWithdrawButton ? &Withdraw : &Withdraw1, SRCCOPY);

        // æå‰æ£€æŸ¥æ˜¯å¦ç‚¹å‡»è¿”å›žæŒ‰é’?
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
        if (msg.message == WM_LBUTTONDOWN && inWithdrawButton) {
            return -1;
        }

        // ²éÕÒÊó±êËùÔÚµÄ¸ñ×Ó
        int mouseRow = -1, mouseCol = -1;
        if (msg.x >= blank_simple[0][0].top_left.x &&
            msg.y >= blank_simple[0][0].top_left.y &&
            msg.x <= blank_simple[8][8].bottom_right.x &&
            msg.y <= blank_simple[8][8].bottom_right.y) {

            mouseRow = (msg.y - blank_simple[0][0].top_left.y) / 30;
            mouseCol = (msg.x - blank_simple[0][0].top_left.x) / 30;

            // È·±£Ë÷ÒýÔÚÓÐÐ§·¶Î§ÄÚ
            if (mouseRow >= 0 && mouseRow < 9 && mouseCol >= 0 && mouseCol < 9) {
                // ´¦ÀíÊó±êÊÂ¼þ
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

        // ÖØ»æÆäËû¸ñ×Ó
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

    // ¼ì²évectorÊÇ·ñÒÑ³õÊ¼»¯
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

<<<<<<< HEAD
        // ¸üÐÂ·µ»Ø°´Å¥×´Ì¬
        putimage(0, 0, inWithdrawButton ? &Withdraw : &Withdraw1, SRCCOPY);

        // ÌáÇ°¼ì²éÊÇ·ñµã»÷·µ»Ø°´Å¥
=======
        // æ›´æ–°è¿”å›žæŒ‰é’®çŠ¶æ€?
        putimage(0, 0, inWithdrawButton ? &Withdraw : &Withdraw1, SRCCOPY);

        // æå‰æ£€æŸ¥æ˜¯å¦ç‚¹å‡»è¿”å›žæŒ‰é’?
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
        if (msg.message == WM_LBUTTONDOWN && inWithdrawButton) {
            return -1;
        }

        // ²éÕÒÊó±êËùÔÚµÄ¸ñ×Ó
        int mouseRow = -1, mouseCol = -1;
        if (msg.x >= blank_middle[0][0].top_left.x &&
            msg.y >= blank_middle[0][0].top_left.y &&
            msg.x <= blank_middle[15][15].bottom_right.x &&
            msg.y <= blank_middle[15][15].bottom_right.y) {

            mouseRow = (msg.y - blank_middle[0][0].top_left.y) / 30;
            mouseCol = (msg.x - blank_middle[0][0].top_left.x) / 30;

            // È·±£Ë÷ÒýÔÚÓÐÐ§·¶Î§ÄÚ
            if (mouseRow >= 0 && mouseRow < 16 && mouseCol >= 0 && mouseCol < 16) {
                // ´¦ÀíÊó±êÊÂ¼þ
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

        // ÖØ»æÆäËû¸ñ×Ó
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

    // ¼ì²évectorÊÇ·ñÒÑ³õÊ¼»¯
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

<<<<<<< HEAD
        // ¸üÐÂ·µ»Ø°´Å¥×´Ì¬
        putimage(0, 0, inWithdrawButton ? &Withdraw : &Withdraw1, SRCCOPY);

        // ÌáÇ°¼ì²éÊÇ·ñµã»÷·µ»Ø°´Å¥
=======
        // æ›´æ–°è¿”å›žæŒ‰é’®çŠ¶æ€?
        putimage(0, 0, inWithdrawButton ? &Withdraw : &Withdraw1, SRCCOPY);

        // æå‰æ£€æŸ¥æ˜¯å¦ç‚¹å‡»è¿”å›žæŒ‰é’?
>>>>>>> bff72e9fcd7ee37f1bfaa9fe5e9d3d902490f277
        if (msg.message == WM_LBUTTONDOWN && inWithdrawButton) {
            return -1;
        }

        // ²éÕÒÊó±êËùÔÚµÄ¸ñ×Ó
        int mouseRow = -1, mouseCol = -1;
        if (msg.x >= blank_difficult[0][0].top_left.x &&
            msg.y >= blank_difficult[0][0].top_left.y &&
            msg.x <= blank_difficult[15][29].bottom_right.x &&
            msg.y <= blank_difficult[15][29].bottom_right.y) {

            mouseRow = (msg.y - blank_difficult[0][0].top_left.y) / 30;  
            mouseCol = (msg.x - blank_difficult[0][0].top_left.x) / 30;

            // È·±£Ë÷ÒýÔÚÓÐÐ§·¶Î§ÄÚ
            if (mouseRow >= 0 && mouseRow < 16 && mouseCol >= 0 && mouseCol < 30) {
                // ´¦ÀíÊó±êÊÂ¼þ
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

        // ÖØ»æÆäËû¸ñ×Ó
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
                    mt19937 generator(seed);  // Mersenne TwisterËã·¨

                    // Éú³É0-iµÄ¾ùÔÈ·Ö²¼ÕûÊý
                    uniform_int_distribution<int> distribution(0, i);

                    // Éú³É²¢Êä³öËæ»úÊý
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
                    mt19937 generator(seed);  // Mersenne TwisterËã·¨

                    // Éú³É0-iµÄ¾ùÔÈ·Ö²¼ÕûÊý
                    uniform_int_distribution<int> distribution(0, i);

                    // Éú³É²¢Êä³öËæ»úÊý
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
                    mt19937 generator(seed);  // Mersenne TwisterËã·¨

                    // Éú³É0-iµÄ¾ùÔÈ·Ö²¼ÕûÊý
                    uniform_int_distribution<int> distribution(0, i);

                    // Éú³É²¢Êä³öËæ»úÊý
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