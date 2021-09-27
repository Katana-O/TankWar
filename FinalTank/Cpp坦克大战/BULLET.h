#pragma once
#include "HEADER.h"
#include "PUBLIC.h"

class BULLET
{
public:
	BULLET(char Damage, char Me, char Stop,char HP,char Color,char ID);
	BULLET();
	~BULLET();
	char m_X;					  //X
	char m_Y;					  //Y
	char m_Direction;			  //����
	char m_Speed;				  //�ٶ�
	char m_Damage;				  //�˺�
	char m_HP;					  //Ѫ��
	char m_Stop;				  //ֹͣ
	char m_Me;					  //��
	char m_Color;				  //��ɫ
	char m_ID;					  //�ӵ����֤
public:
	//AI��һ���ӵ�
	void AIFirstBullet(char X, char Y, char Dir);
	//AI�����ӵ��ƶ�����
	char AIBulletMovement2();
	//�ҵ��ӵ��ƶ�����
	char BulletMove();
	//�����ӵ�����
	void UpdateBulletPos();
	//�����ӵ�λ��
	void CleanBulletPos();
	//AI�ӵ��ƶ�����
	char AIBulletMovement();
};

