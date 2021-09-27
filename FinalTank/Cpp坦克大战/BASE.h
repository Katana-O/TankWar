#pragma once
#include "HEADER.h"
#include "PUBLIC.h"
#include "BULLET.h"
#include "TANK.h"

class BASE:public BULLET,public TANK
{
public:

	vector<TANK> V_Tank;

	vector<BULLET> V_Bullet;

	//�ؿ��˵�
	int StageMenu();
	//***���˵�
	/*int MainMenu();*/
	//�жϵ�������
	bool EnemyDead();
	//�ж��ѷ�����
	bool AllyDead();
	//��ȡ����Ԫ�أ���ͼ��̹�ˣ��ӵ�
	bool ReadInfo(char level);
	//��������Ԫ�أ���ͼ��̹�ˣ��ӵ�
	bool SaveInfo(char level);
	//�Զ����ͼ
	void MessageLoop();
	//***�浵***
	void SaveMap(char level);
	//***����***
	void ReadMap(char level);
	//��Ϸ������
	void GameStart();
	//��ȡ���1��������
	int GetUserInput(int Dir);
	//��ȡ���2��������
	int Get2UserInput(int Dir);
	//��ʼ��̹����Ϣ
	void InitTank();
	//��ʼ���ӵ���Ϣ
	void InitBullet();
	//�Ƿְ��ϵ���Ϣ
	void ScoreInfo();


	BASE();
	~BASE();
};

