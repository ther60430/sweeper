#include"header.h"

IMAGE Title;            //����
IMAGE UnCell;         //δ��������ͼƬ
IMAGE Cell;             //�ѷ�������ͼƬ              O
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
IMAGE Simple, Simple1;//��ģʽ
IMAGE Medium, Medium1;//�е�ģʽ
IMAGE Difficult, Difficult1;//����ģʽ
IMAGE Withdraw;//������һҳ

int main()
{
	SweeperGame sg;
	sg.InitGame();
	sg.run_game();

}