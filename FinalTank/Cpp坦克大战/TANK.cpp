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
		if (this->m_Direction == UP && g_Map[this->m_X][this->m_Y - 2] != 铁墙
			&& g_Map[this->m_X][this->m_Y - 2] == 空地
			&& g_Map[this->m_X - 1][this->m_Y - 2] == 空地
			&& g_Map[this->m_X + 1][this->m_Y - 2] == 空地)
		{
			this->m_Y--;
		}
		else if (this->m_Direction == DOWN && g_Map[this->m_X][this->m_Y + 2] != 铁墙
			&& g_Map[this->m_X][this->m_Y + 2] == 空地
			&& g_Map[this->m_X - 1][this->m_Y + 2] == 空地
			&& g_Map[this->m_X + 1][this->m_Y + 2] == 空地)
		{
			this->m_Y++;
		}
		else if (this->m_Direction == LEFT && g_Map[this->m_X - 2][this->m_Y] != 铁墙
			&& g_Map[this->m_X - 2][this->m_Y] == 空地
			&& g_Map[this->m_X - 2][this->m_Y + 1] == 空地
			&& g_Map[this->m_X - 2][this->m_Y - 1] == 空地)
		{
			this->m_X--;
		}
		else if (this->m_Direction == RIGHT && g_Map[this->m_X + 2][this->m_Y] != 铁墙
			&& g_Map[this->m_X + 2][this->m_Y] == 空地
			&& g_Map[this->m_X + 2][this->m_Y + 1] == 空地
			&& g_Map[this->m_X + 2][this->m_Y - 1] == 空地)
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
			g_Map[i][j] = 空地;
			WriteChar(i, j, "  ", 0x00);
		}
	}
}

void TANK::UpdatePos()
{
	if (this->m_Direction == UP)
	{
		//**中心
		g_Map[this->m_X][this->m_Y] = this->m_ID;
		//***中心上面***	  
		g_Map[this->m_X][this->m_Y - 1] = this->m_ID;
		//***中心左边***	  
		g_Map[this->m_X - 1][this->m_Y] = this->m_ID;
		//***中心右边***	  
		g_Map[this->m_X + 1][this->m_Y] = this->m_ID;
		//**中心左下***	 
		g_Map[this->m_X - 1][this->m_Y + 1] = this->m_ID;
		//***右下***
		g_Map[this->m_X + 1][this->m_Y + 1] = this->m_ID;
	}
	else if (this->m_Direction == DOWN)
	{
		//**中心
		g_Map[this->m_X][this->m_Y] = this->m_ID;
		//***中心往下 
		g_Map[this->m_X][this->m_Y + 1] = this->m_ID;
		//***中心往右	  
		g_Map[this->m_X + 1][this->m_Y] = this->m_ID;
		//***中心往左	  
		g_Map[this->m_X - 1][this->m_Y] = this->m_ID;
		//**中心左上	
		g_Map[this->m_X - 1][this->m_Y - 1] = this->m_ID;
		//***中心右上
		g_Map[this->m_X + 1][this->m_Y - 1] = this->m_ID;
	}
	else if (this->m_Direction == LEFT)
	{
		//**中
		g_Map[this->m_X][this->m_Y] = this->m_ID;
		//**左 	  
		g_Map[this->m_X - 1][this->m_Y] = this->m_ID;
		//**中上
		g_Map[this->m_X][this->m_Y - 1] = this->m_ID;
		//**中下	
		g_Map[this->m_X][this->m_Y + 1] = this->m_ID;
		//**右上**
		g_Map[this->m_X + 1][this->m_Y - 1] = this->m_ID;
		//***右下*
		g_Map[this->m_X + 1][this->m_Y + 1] = this->m_ID;
	}
	else if (this->m_Direction == RIGHT)
	{
		//**中
		g_Map[this->m_X][this->m_Y] = this->m_ID;
		//***中下	  
		g_Map[this->m_X][this->m_Y + 1] = this->m_ID;
		//***中上	  
		g_Map[this->m_X][this->m_Y - 1] = this->m_ID;
		//***右***	  
		g_Map[this->m_X + 1][this->m_Y] = this->m_ID;
		//**左上	 
		g_Map[this->m_X - 1][this->m_Y - 1] = this->m_ID;
		//***右下***	 .
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
			g_Map[i][j] = 空地;
			WriteChar(i, j, "  ", 0x00);
		}
	}
}

void TANK::Revive()
{
	this->m_HP -= 1;
	if (this->m_HP > 0)
	{
		if (this->m_ID == 敌人1)
		{
			this->m_X = 5;
			this->m_Y = 5;
			this->m_Direction = DOWN;
		}
		else if (this->m_ID == 敌人2)
		{
			this->m_X = 15;
			this->m_Y = 5;
			this->m_Direction = DOWN;
		}
		else if (this->m_ID == 敌人3)
		{
			this->m_X = 25;
			this->m_Y = 5;
			this->m_Direction = DOWN;
		}
		else if (this->m_ID == 敌人4)
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
		if (this->m_Direction == UP && g_Map[this->m_X][this->m_Y - 2] != 铁墙
			&& g_Map[this->m_X][this->m_Y - 2] == 空地
			&& g_Map[this->m_X - 1][this->m_Y - 2] == 空地
			&& g_Map[this->m_X + 1][this->m_Y - 2] == 空地)
		{
			this->m_Y--;
		}

		else if (this->m_Direction == DOWN && g_Map[this->m_X][this->m_Y + 2] != 铁墙
			&& g_Map[this->m_X][this->m_Y + 2] == 空地
			&& g_Map[this->m_X - 1][this->m_Y + 2] == 空地
			&& g_Map[this->m_X + 1][this->m_Y + 2] == 空地)
		{
			this->m_Y++;
		}
		else if (this->m_Direction == LEFT && g_Map[this->m_X - 2][this->m_Y] != 铁墙
			&& g_Map[this->m_X - 2][this->m_Y] == 空地
			&& g_Map[this->m_X - 2][this->m_Y + 1] == 空地
			&& g_Map[this->m_X - 2][this->m_Y - 1] == 空地)
		{
			this->m_X--;
		}
		else if (this->m_Direction == RIGHT && g_Map[this->m_X + 2][this->m_Y] != 铁墙
			&& g_Map[this->m_X + 2][this->m_Y] == 空地
			&& g_Map[this->m_X + 2][this->m_Y + 1] == 空地
			&& g_Map[this->m_X + 2][this->m_Y - 1] == 空地)
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
