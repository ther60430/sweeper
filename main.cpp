#include"header.h"
IMAGE Cell;          //����ͼƬ
IMAGE Landmine; //��ͼƬ
IMAGE Flag;          //����ͼƬ
class SweeperGame
{
    private:
		int width, height;                  //��Ļ���
		int count_thounder;               //����
		bool is_game_over;               //��Ϸ�Ƿ����
		bool first_click;                     //�Ƿ��һ�ε��
	public:
		void CreateWindows();              //��������
		void InitGame();                        //��ʼ����Ϸ
		void HandleInput();                  //��������
		void reveal(int x, int y);             //�ҿ�����
		void mark(int x, int y);              //�����
		void backgroundmusic();         //��������
};