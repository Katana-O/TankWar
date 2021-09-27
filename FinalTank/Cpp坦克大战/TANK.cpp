#include "TANK.h"


TANK::TANK(short X, short Y, char Dir, char Model, char Color, int Point, int HP, char ME, char Stop, char ID)
{
	this->m_X = X;
	this->m_Y = Y;
	this->m_Direction = Dir;
	this->m_Model = Model;
	this->m_Color = Color;
	this->m_HP = HP;
	this->m_Me = ME;
	this->m_Stop = Stop;
	this->m_ID = ID;
	this->m_Point = Point;
}
TANK::TANK()
{

}
TANK::~TANK()
{

}

char TANK::AIMove()
{
	char RandDirection = 0;
	srand((unsigned)time(NULL));
	Random(RandDirection, this->m_ID);
	this->CleanTank();
	if (this->m_Direction != RandDirection)
	{
		this->m_Direction = RandDirection;
	}
	else if (this->m_Direction == RandDirection)
	{
		if (this->m_Direction == UP && g_Map[this->m_X][this->m_Y - 2] != ��ǽ
			&& g_Map[this->m_X][this->m_Y - 2] == �յ�
			&& g_Map[this->m_X - 1][this->m_Y - 2] == �յ�
			&& g_Map[this->m_X + 1][this->m_Y - 2] == �յ�)
		{
			this->m_Y--;
		}
		else if (this->m_Direction == DOWN && g_Map[this->m_X][this->m_Y + 2] != ��ǽ
			&& g_Map[this->m_X][this->m_Y + 2] == �յ�
			&& g_Map[this->m_X - 1][this->m_Y + 2] == �յ�
			&& g_Map[this->m_X + 1][this->m_Y + 2] == �յ�)
		{
			this->m_Y++;
		}
		else if (this->m_Direction == LEFT && g_Map[this->m_X - 2][this->m_Y] != ��ǽ
			&& g_Map[this->m_X - 2][this->m_Y] == �յ�
			&& g_Map[this->m_X - 2][this->m_Y + 1] == �յ�
			&& g_Map[this->m_X - 2][this->m_Y - 1] == �յ�)
		{
			this->m_X--;
		}
		else if (this->m_Direction == RIGHT && g_Map[this->m_X + 2][this->m_Y] != ��ǽ
			&& g_Map[this->m_X + 2][this->m_Y] == �յ�
			&& g_Map[this->m_X + 2][this->m_Y + 1] == �յ�
			&& g_Map[this->m_X + 2][this->m_Y - 1] == �յ�)
		{
			this->m_X++;
		}
	}
	char Rand = 0;
	Random(Rand, this->m_ID);
	this->UpdatePos();
	this->Show();
	return Rand;
}

void TANK::CleanTank()
{
	for (int i = this->m_X - 1; i < (this->m_X - 1) + 3; i++)
	{
		for (int j = this->m_Y - 1; j < (this->m_Y - 1) + 3; j++)
		{
			g_Map[i][j] = �յ�;
			WriteChar(i, j, "  ", 0x00);
		}
	}
}

void TANK::UpdatePos()
{
	if (this->m_Direction == UP)
	{
		//**����
		g_Map[this->m_X][this->m_Y] = this->m_ID;
		//***��������***	  
		g_Map[this->m_X][this->m_Y - 1] = this->m_ID;
		//***�������***	  
		g_Map[this->m_X - 1][this->m_Y] = this->m_ID;
		//***�����ұ�***	  
		g_Map[this->m_X + 1][this->m_Y] = this->m_ID;
		//**��������***	 
		g_Map[this->m_X - 1][this->m_Y + 1] = this->m_ID;
		//***����***
		g_Map[this->m_X + 1][this->m_Y + 1] = this->m_ID;
	}
	else if (this->m_Direction == DOWN)
	{
		//**����
		g_Map[this->m_X][this->m_Y] = this->m_ID;
		//***�������� 
		g_Map[this->m_X][this->m_Y + 1] = this->m_ID;
		//***��������	  
		g_Map[this->m_X + 1][this->m_Y] = this->m_ID;
		//***��������	  
		g_Map[this->m_X - 1][this->m_Y] = this->m_ID;
		//**��������	
		g_Map[this->m_X - 1][this->m_Y - 1] = this->m_ID;
		//***��������
		g_Map[this->m_X + 1][this->m_Y - 1] = this->m_ID;
	}
	else if (this->m_Direction == LEFT)
	{
		//**��
		g_Map[this->m_X][this->m_Y] = this->m_ID;
		//**�� 	  
		g_Map[this->m_X - 1][this->m_Y] = this->m_ID;
		//**����
		g_Map[this->m_X][this->m_Y - 1] = this->m_ID;
		//**����	
		g_Map[this->m_X][this->m_Y + 1] = this->m_ID;
		//**����**
		g_Map[this->m_X + 1][this->m_Y - 1] = this->m_ID;
		//***����*
		g_Map[this->m_X + 1][this->m_Y + 1] = this->m_ID;
	}
	else if (this->m_Direction == RIGHT)
	{
		//**��
		g_Map[this->m_X][this->m_Y] = this->m_ID;
		//***����	  
		g_Map[this->m_X][this->m_Y + 1] = this->m_ID;
		//***����	  
		g_Map[this->m_X][this->m_Y - 1] = this->m_ID;
		//***��***	  
		g_Map[this->m_X + 1][this->m_Y] = this->m_ID;
		//**����	 
		g_Map[this->m_X - 1][this->m_Y - 1] = this->m_ID;
		//***����***	 .
		g_Map[this->m_X - 1][this->m_Y + 1] = this->m_ID;
	}
}

void TANK::Show()
{
	for (int i = 0; i < 3; ++i)
	{
		WriteChar(this->m_X - 1, this->m_Y - 1 + i, this->Tank_Figure[this->m_Model][i][this->m_Direction], this->m_Color);
	}
}

void TANK::CleanDeadTank()
{
	for (int i = this->m_X - 1; i < (this->m_X - 1) + 3; i++)
	{
		for (int j = this->m_Y - 1; j < (this->m_Y - 1) + 3; j++)
		{
			g_Map[i][j] = �յ�;
			WriteChar(i, j, "  ", 0x00);
		}
	}
}

void TANK::Revive()
{
	this->m_HP -= 1;
	if (this->m_HP > 0)
	{
		if (this->m_ID == ����1)
		{
			this->m_X = 5;
			this->m_Y = 5;
			this->m_Direction = DOWN;
		}
		else if (this->m_ID == ����2)
		{
			this->m_X = 15;
			this->m_Y = 5;
			this->m_Direction = DOWN;
		}
		else if (this->m_ID == ����3)
		{
			this->m_X = 25;
			this->m_Y = 5;
			this->m_Direction = DOWN;
		}
		else if (this->m_ID == ����4)
		{
			this->m_X = 35;
			this->m_Y = 5;
			this->m_Direction = DOWN;
		}
	}
}

char TANK::AI2Move()
{
	char RandDirection = 0;
	srand((unsigned)time(NULL));
	Random(RandDirection, this->m_ID);
	this->CleanTank();
	if (this->m_Direction != RandDirection)
	{
		this->m_Direction = RandDirection;
	}
	else if (this->m_Direction == RandDirection)
	{
		if (this->m_Direction == UP && g_Map[this->m_X][this->m_Y - 2] != ��ǽ
			&& g_Map[this->m_X][this->m_Y - 2] == �յ�
			&& g_Map[this->m_X - 1][this->m_Y - 2] == �յ�
			&& g_Map[this->m_X + 1][this->m_Y - 2] == �յ�)
		{
			this->m_Y--;
		}

		else if (this->m_Direction == DOWN && g_Map[this->m_X][this->m_Y + 2] != ��ǽ
			&& g_Map[this->m_X][this->m_Y + 2] == �յ�
			&& g_Map[this->m_X - 1][this->m_Y + 2] == �յ�
			&& g_Map[this->m_X + 1][this->m_Y + 2] == �յ�)
		{
			this->m_Y++;
		}
		else if (this->m_Direction == LEFT && g_Map[this->m_X - 2][this->m_Y] != ��ǽ
			&& g_Map[this->m_X - 2][this->m_Y] == �յ�
			&& g_Map[this->m_X - 2][this->m_Y + 1] == �յ�
			&& g_Map[this->m_X - 2][this->m_Y - 1] == �յ�)
		{
			this->m_X--;
		}
		else if (this->m_Direction == RIGHT && g_Map[this->m_X + 2][this->m_Y] != ��ǽ
			&& g_Map[this->m_X + 2][this->m_Y] == �յ�
			&& g_Map[this->m_X + 2][this->m_Y + 1] == �յ�
			&& g_Map[this->m_X + 2][this->m_Y - 1] == �յ�)
		{
			this->m_X++;
		}
	}
	char Rand = 0;
	Random(Rand, this->m_ID);
	this->UpdatePos();
	this->Show();
	return Rand;
}
