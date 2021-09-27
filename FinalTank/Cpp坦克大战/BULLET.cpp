#include "BULLET.h"


BULLET::BULLET(char Damage, char Me, char Stop, char HP,char Color,char ID)
{
	this->m_Damage = Damage;
	this->m_Me = Me;
	this->m_Stop = Stop;
	this->m_HP = HP;
	this->m_Color = Color;
	this->m_ID = ID;
}
BULLET::BULLET()
{
}
BULLET::~BULLET()
{
}

//AI�ƶ���������
char BULLET::AIBulletMovement2()
{
	char Who = 0;
	if (this->m_HP != 0)
	{
		switch (this->m_Direction)
		{
		case UP:
		{
			CleanBulletPos();
			this->m_Y = this->m_Y - 1;
			if (g_Map[this->m_X][this->m_Y + 1] == ��ǽ)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y + 1] = �յ�;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x00);
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y] = �յ�;
				WriteChar(this->m_X, this->m_Y, "  ", 0x02);
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				this->m_HP = 0;
				Who = 3;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
				Who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���2)
			{
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x00);
				this->m_HP = 0;
				Who = 2;
			}

			else if (g_Map[this->m_X][this->m_Y] == ����1 || g_Map[this->m_X][this->m_Y] == ����2 || g_Map[this->m_X][this->m_Y] == ����3 || g_Map[this->m_X][this->m_Y] == ����4)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}


			else
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
		}
		break;
		case DOWN:
		{
			CleanBulletPos();
			this->m_Y = this->m_Y + 1;
			if (g_Map[this->m_X][this->m_Y - 1] == ��ǽ)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y - 1] = �յ�;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y] = �յ�;
				WriteChar(this->m_X, this->m_Y, "  ", 0x02);
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				this->m_HP = 0;
				Who = 3;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1)  //�ӵ������1��
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
				Who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���2)
			{
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x00);
				this->m_HP = 0;
				Who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1 || g_Map[this->m_X][this->m_Y] == ����2 || g_Map[this->m_X][this->m_Y] == ����3 || g_Map[this->m_X][this->m_Y] == ����4)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
		}
		break;
		case LEFT:
		{
			CleanBulletPos();
			this->m_X = this->m_X - 1;
			if (g_Map[this->m_X + 1][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				g_Map[this->m_X + 1][this->m_Y] = �յ�;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y] = �յ�;
				WriteChar(this->m_X, this->m_Y, "  ", 0x02);
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				this->m_HP = 0;
				Who = 3;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1)  //�ӵ������1��
			{
				this->m_HP = 0;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
				Who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���2)
			{
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x00);
				this->m_HP = 0;
				Who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1 || g_Map[this->m_X][this->m_Y] == ����2 || g_Map[this->m_X][this->m_Y] == ����3 || g_Map[this->m_X][this->m_Y] == ����4)
			{
				this->m_HP = 0;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
		}
		break;
		case RIGHT:
		{
			CleanBulletPos();
			this->m_X = this->m_X + 1;
			if (g_Map[this->m_X - 1][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				g_Map[this->m_X - 1][this->m_Y] = �յ�;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y] = �յ�;
				WriteChar(this->m_X, this->m_Y, "  ", 0x02);
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				this->m_HP = 0;
				Who = 3;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1)  //�ӵ������1��
			{
				this->m_HP = 0;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
				Who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���2)
			{
				this->m_HP = 0;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x00);
				Who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1 || g_Map[this->m_X][this->m_Y] == ����2 || g_Map[this->m_X][this->m_Y] == ����3 || g_Map[this->m_X][this->m_Y] == ����4)
			{
				this->m_HP = 0;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
		}
		break;
		default:
			break;
		}
	}
	return Who;
} //����
//AI��һ���ӵ�
void BULLET::AIFirstBullet(char X, char Y, char Dir)
{
	Biu();
	this->m_Direction = Dir;
	if (this->m_Direction == UP)
	{
		this->m_HP = 1;
		this->m_X = X;
		this->m_Y = Y - 2;
	}
	else if (this->m_Direction == DOWN)
	{
		this->m_HP = 1;
		this->m_X  = X;
		this->m_Y  = Y + 2;
	}
	else if (this->m_Direction == LEFT)
	{
		this->m_HP = 1;
		this->m_X  = X - 2;
		this->m_Y  = Y;
	}
	else if (this->m_Direction == RIGHT)
	{
		this->m_HP = 1;
		this->m_X  = X + 2;
		this->m_Y  = Y;
	}
	WriteChar(this->m_X, this->m_Y, "��", 0x02);
}
//�ҵ��ӵ��ƶ�����
char BULLET::BulletMove()
{
	char who = 0;
	if (this->m_HP != 0)
	{
		switch (this->m_Direction)
		{
		case UP:
		{
			CleanBulletPos();
			this->m_Y = this->m_Y - 1;
			if (g_Map[this->m_X][this->m_Y + 1] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�1)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�2)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �з��ӵ�1 || g_Map[this->m_X][this->m_Y] == �з��ӵ�2 || g_Map[this->m_X][this->m_Y] == �з��ӵ�3 || g_Map[this->m_X][this->m_Y] == �з��ӵ�4)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				MessageBox(0, L"�ϼұ�������", L"�ܵ��˽���", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1)
			{
				ExplosiveSound();
				who = 11;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����2)
			{
				ExplosiveSound();
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����3)
			{
				ExplosiveSound();
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����4)
			{
				ExplosiveSound();
				who = 14;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1 || g_Map[this->m_X][this->m_Y] == ���2)
			{
				this->m_HP = 0;
			}
		}
		break;
		case DOWN:
		{
			CleanBulletPos();
			this->m_Y = this->m_Y + 1;
			if (g_Map[this->m_X][this->m_Y - 1] == ��ǽ )
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�1)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�2)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �з��ӵ�1 || g_Map[this->m_X][this->m_Y] == �з��ӵ�2 || g_Map[this->m_X][this->m_Y] == �з��ӵ�3 || g_Map[this->m_X][this->m_Y] == �з��ӵ�4)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;				
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				MessageBox(0, L"�ϼұ�������", L"�ܵ��˽���", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1)
			{
				ExplosiveSound();		
				who = 11;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����2)
			{
				ExplosiveSound();			
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����3)
			{
				ExplosiveSound();		
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����4)
			{
				ExplosiveSound();				
				who = 14;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1 || g_Map[this->m_X][this->m_Y] == ���2)
			{
				this->m_HP = 0;
			}
		}
		break;
		case LEFT:
		{
			CleanBulletPos();
			this->m_X = this->m_X - 1;
			if (g_Map[this->m_X + 1][this->m_Y] == ��ǽ )
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				MessageBox(0, L"�ϼұ�������", L"�ܵ��˽���", MB_OKCANCEL);
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�1)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�2)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �з��ӵ�1 || g_Map[this->m_X][this->m_Y] == �з��ӵ�2 || g_Map[this->m_X][this->m_Y] == �з��ӵ�3 || g_Map[this->m_X][this->m_Y] == �з��ӵ�4)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1) //��������
			{
				ExplosiveSound();							
				who = 11;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����2) //��������
			{
				ExplosiveSound();			
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����3) //��������
			{
				ExplosiveSound();		
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����4) //��������
			{
				ExplosiveSound();				
				who = 14;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1 || g_Map[this->m_X][this->m_Y] == ���2)
			{
				this->m_HP = 0;
			}
		}
		break;
		case RIGHT:
		{
			CleanBulletPos();
			this->m_X = this->m_X + 1;
			if (g_Map[this->m_X - 1][this->m_Y] == ��ǽ)
			{				
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{			
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				MessageBox(0, L"�ϼұ�������", L"�ܵ��˽���", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�1 )
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 1;
			}
			else if(g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�2)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �з��ӵ�1 || g_Map[this->m_X][this->m_Y] == �з��ӵ�2 || g_Map[this->m_X][this->m_Y] == �з��ӵ�3 || g_Map[this->m_X][this->m_Y] == �з��ӵ�4)
			{
				MessageBox(0, L"��", L"��", MB_OKCANCEL);
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1) //��������
			{
				ExplosiveSound();		
				who = 11;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����2) //��������
			{
				ExplosiveSound();	
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����3) //��������
			{
				ExplosiveSound();		
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����4) //��������
			{
				ExplosiveSound();
				who = 14;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1 || g_Map[this->m_X][this->m_Y] == ���2)
			{
				this->m_HP = 0;
			}
		}
		break;
		default:
			break;
		}
	}
	UpdateBulletPos();
	return who;
}
//�����ӵ�����
void BULLET::UpdateBulletPos()
{
	if(this->m_HP > 0)
		g_Map[this->m_X][this->m_Y] = this->m_ID;
}
//����ӵ�����ͷ���
void BULLET::CleanBulletPos()
{
	g_Map[this->m_X][this->m_Y] = �յ�;
	WriteChar(this->m_X, this->m_Y, "  ", 0x00);
}
//AI�ƶ�����
char BULLET::AIBulletMovement()
{
	char who = 0;
	if (this->m_HP != 0)
	{
		switch (this->m_Direction)
		{
		case UP:
		{
			CleanBulletPos();
			this->m_Y = this->m_Y - 1;
			if (g_Map[this->m_X][this->m_Y + 1] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�1 || g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�2)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �з��ӵ�1 || g_Map[this->m_X][this->m_Y] == �з��ӵ�2 || g_Map[this->m_X][this->m_Y] == �з��ӵ�3 || g_Map[this->m_X][this->m_Y] == �з��ӵ�4)
			{
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				MessageBox(0, L"�ϼұ�������", L"�ܵ��˽���", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1 || g_Map[this->m_X][this->m_Y] == ����2 || g_Map[this->m_X][this->m_Y] == ����3 || g_Map[this->m_X][this->m_Y] == ����4)
			{
				ExplosiveSound();
				who = 11;
			}
		/*	else if (g_Map[this->m_X][this->m_Y] == ����2)
			{
				ExplosiveSound();
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����3)
			{
				ExplosiveSound();
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����4)
			{
				ExplosiveSound();
				who = 14;
			}*/
			else if (g_Map[this->m_X][this->m_Y] == ���1)
			{
				ExplosiveSound();
				who = 4;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���2)
			{
				ExplosiveSound();
				who = 5;
			}
		}
		break;
		case DOWN:
		{
			CleanBulletPos();
			this->m_Y = this->m_Y + 1;
			if (g_Map[this->m_X][this->m_Y - 1] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�1)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�2)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �з��ӵ�1 || g_Map[this->m_X][this->m_Y] == �з��ӵ�2 || g_Map[this->m_X][this->m_Y] == �з��ӵ�3 || g_Map[this->m_X][this->m_Y] == �з��ӵ�4)
			{
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				MessageBox(0, L"�ϼұ�������", L"�ܵ��˽���", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1)
			{
				who = 4;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���2)
			{
				who = 5;
			}
			//else if (g_Map[this->m_X][this->m_Y] == ����1)
			//{
			//	ExplosiveSound();
			//	who = 11;
			//}
			else if (g_Map[this->m_X][this->m_Y] == ����1 || g_Map[this->m_X][this->m_Y] == ����2 || g_Map[this->m_X][this->m_Y] == ����3 || g_Map[this->m_X][this->m_Y] == ����4)
			{
				ExplosiveSound();
				who = 11;
			}
			/*	else if (g_Map[this->m_X][this->m_Y] == ����3)
				{
					ExplosiveSound();
					who = 13;
				}
				else if (g_Map[this->m_X][this->m_Y] == ����4)
				{
					ExplosiveSound();
					who = 14;
				}*/
		}
		break;
		case LEFT:
		{
			CleanBulletPos();
			this->m_X = this->m_X - 1;
			if (g_Map[this->m_X + 1][this->m_Y] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				MessageBox(0, L"�ϼұ�������", L"�ܵ��˽���", MB_OKCANCEL);
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�1 || g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�2)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �з��ӵ�1 || g_Map[this->m_X][this->m_Y] == �з��ӵ�2 || g_Map[this->m_X][this->m_Y] == �з��ӵ�3 || g_Map[this->m_X][this->m_Y] == �з��ӵ�4)
			{
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1 || g_Map[this->m_X][this->m_Y] == ����2 || g_Map[this->m_X][this->m_Y] == ����3 || g_Map[this->m_X][this->m_Y] == ����4) //��������
			{
				who = 11;
			}
			//else if (g_Map[this->m_X][this->m_Y] == ����2) //��������
			//{
			//	ExplosiveSound();
			//	who = 12;
			//}
			//else if (g_Map[this->m_X][this->m_Y] == ����3) //��������
			//{
			//	ExplosiveSound();
			//	who = 13;
			//}
			//else if (g_Map[this->m_X][this->m_Y] == ����4) //��������
			//{
			//	ExplosiveSound();
			//	who = 14;
			//}
			else if (g_Map[this->m_X][this->m_Y] == ���1)
			{
				who = 4;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���2)
			{
				who = 5;
			}
		}	
		break;
		case RIGHT:
		{
			CleanBulletPos();
			this->m_X = this->m_X + 1;
			if (g_Map[this->m_X - 1][this->m_Y] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == �յ�)
			{
				WriteChar(this->m_X, this->m_Y, "��", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == ����)
			{
				MessageBox(0, L"�ϼұ�������", L"�ܵ��˽���", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == ��ǽ)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�1 || g_Map[this->m_X][this->m_Y] == �ѷ��ӵ�2)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == �з��ӵ�1 || g_Map[this->m_X][this->m_Y] == �з��ӵ�2 || g_Map[this->m_X][this->m_Y] == �з��ӵ�3 || g_Map[this->m_X][this->m_Y] == �з��ӵ�4)
			{
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���1)
			{
				who = 4;
			}
			else if (g_Map[this->m_X][this->m_Y] == ���2)
			{
				who = 5;
			}
			else if (g_Map[this->m_X][this->m_Y] == ����1 || g_Map[this->m_X][this->m_Y] == ����2 || g_Map[this->m_X][this->m_Y] == ����3 || g_Map[this->m_X][this->m_Y] == ����4) //��������
			{
				ExplosiveSound();
				who = 11;
			}
			//else if (g_Map[this->m_X][this->m_Y] == ����2) //��������
			//{
			//	ExplosiveSound();
			//	who = 12;
			//}
			//else if (g_Map[this->m_X][this->m_Y] == ����3) //��������
			//{
			//	ExplosiveSound();
			//	who = 13;
			//}
			//else if (g_Map[this->m_X][this->m_Y] == ����4) //��������
			//{
			//	ExplosiveSound();
			//	who = 14;
			//}
		
		}
		break;
		default:
			break;
		}
	}
	UpdateBulletPos();
	return who;
}