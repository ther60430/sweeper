#include"header.h"

<<<<<<< HEAD
IMAGE Title;            //����
IMAGE UnCell;         //δ��������ͼƬ
IMAGE Cell;             //�ѷ�������ͼƬ              
IMAGE HoverCell;   //�����������ͼƬ
IMAGE Landmine;   //����ͼƬ
IMAGE Flag;            //����ͼƬ
IMAGE Gamewithdraw; //��Ϸ����ͼƬ
IMAGE Win;            //��Ϸʤ��ͼƬ
IMAGE GameStart1, GameStart;  //��Ϸ��ʼͼƬ
IMAGE GamePause;  //��Ϸ��ͣͼƬ
IMAGE GameContinue; //������ϷͼƬ
IMAGE GameRestart;  //���¿�ʼͼƬ
IMAGE GameExit1, GameExit;    //�˳���ϷͼƬ
IMAGE num[8];     //����ͼƬ1 - 8
IMAGE history_scores1, history_scores;          //����ͼƬ
IMAGE BackGraound;//����ͼƬ
IMAGE Simple1, Simple;//��ģʽ
IMAGE Medium1, Medium;//�е�ģʽ
IMAGE Difficult1, Difficult;//����ģʽ
IMAGE Withdraw,Withdraw1;//������һҳ

=======
>>>>>>> ee2a68d697a3e81f13b0b2d0ba34e0ae8d4a7d38

int main()
{
	SweeperGame sg;
	sg.InitGame();
	mciSendString(L"open \"bgm.mp3\"", NULL, 0, NULL);
	mciSendString(L"play bgm.mp3 repeat", NULL, 0, NULL);
	sg.run_game();
}