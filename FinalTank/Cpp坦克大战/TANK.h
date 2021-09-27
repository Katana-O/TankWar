#pragma once
#include "HEADER.h"
#include "PUBLIC.h"


class TANK
{
public:
	TANK();

	~TANK();
	
	TANK(short X, short Y, char Dir,char Model,char Color, int Point, int HP, char ME,char Stop, char ID);


public:

	char m_X;				//X
	char m_Y;				//Y
	char m_Direction;		//����
	char m_Model;			//̹��ģ��
	char m_Color;			//��ɫ����
	int m_Point;			//�÷�
	int m_HP;				//̹������ֵ
	char m_Me;				//�ж��Ƿ������̹��
	char m_Stop;			//�Ƿ�ֹͣ
	char m_ID;				//̹�����֤

public:
	//AI�ƶ����ú���
	char AI2Move();
	//AI�ƶ�����
	char AIMove();
	//����̹��
	void CleanTank();
	//����̹������
	void UpdatePos();
	//����̹��
	void Show();
	//������ȥ��̹��
	void CleanDeadTank();
	//����̹��
	void Revive();
	
	const char* Tank_Figure[4][3][4] = //̹��ͼ��ģ��
	{
		{
			{"  ��  ", "��  ��", "  ����", "����  "},
			{"�����", "�����", "����  ", "  ���"},
			{"��  ��", "  ��  ", "  ����", "����  "}
		},
		{
			{"������", "���ש�", "���ש�", "���ש�"},
			{"�ǡ��", "�ǡ��", "�����", "�ǡ�"},
			{"���ߩ�", "������", "���ߩ�", "���ߩ�"}
		},
		{
			{"������", "������", "���ר�", "���ש�"},
			{"�ǡ��", "�ǡ��", "����", "����"},
			{"������", "������", "���ߨ�", "���ߩ�"}
		},
		{
			{"�X���[", "�X�j�[", "�X�j�[", "�X�j�["},
			{"�d���g", "�d���g", "�����g", "�d����"},
			{"�^�m�a", "�^���a", "�^�m�a", "�^�m�a"}
		}
	};
};
