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

//AI移动函数备份
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
			if (g_Map[this->m_X][this->m_Y + 1] == 土墙)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y + 1] = 空地;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x00);
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y] = 空地;
				WriteChar(this->m_X, this->m_Y, "  ", 0x02);
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				this->m_HP = 0;
				Who = 3;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
				Who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x00);
				this->m_HP = 0;
				Who = 2;
			}

			else if (g_Map[this->m_X][this->m_Y] == 敌人1 || g_Map[this->m_X][this->m_Y] == 敌人2 || g_Map[this->m_X][this->m_Y] == 敌人3 || g_Map[this->m_X][this->m_Y] == 敌人4)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}


			else
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
				WriteChar(this->m_X, this->m_Y + 1, "  ", 0x02);
			}
		}
		break;
		case DOWN:
		{
			CleanBulletPos();
			this->m_Y = this->m_Y + 1;
			if (g_Map[this->m_X][this->m_Y - 1] == 土墙)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y - 1] = 空地;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y] = 空地;
				WriteChar(this->m_X, this->m_Y, "  ", 0x02);
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				this->m_HP = 0;
				Who = 3;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1)  //子弹打到玩家1了
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
				Who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x00);
				this->m_HP = 0;
				Who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1 || g_Map[this->m_X][this->m_Y] == 敌人2 || g_Map[this->m_X][this->m_Y] == 敌人3 || g_Map[this->m_X][this->m_Y] == 敌人4)
			{
				this->m_HP = 0;
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
			else
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
				WriteChar(this->m_X, this->m_Y - 1, "  ", 0x02);
			}
		}
		break;
		case LEFT:
		{
			CleanBulletPos();
			this->m_X = this->m_X - 1;
			if (g_Map[this->m_X + 1][this->m_Y] == 土墙)
			{
				this->m_HP = 0;
				g_Map[this->m_X + 1][this->m_Y] = 空地;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y] = 空地;
				WriteChar(this->m_X, this->m_Y, "  ", 0x02);
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				this->m_HP = 0;
				Who = 3;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1)  //子弹打到玩家1了
			{
				this->m_HP = 0;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
				Who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x00);
				this->m_HP = 0;
				Who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1 || g_Map[this->m_X][this->m_Y] == 敌人2 || g_Map[this->m_X][this->m_Y] == 敌人3 || g_Map[this->m_X][this->m_Y] == 敌人4)
			{
				this->m_HP = 0;
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
			else
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
				WriteChar(this->m_X + 1, this->m_Y, "  ", 0x02);
			}
		}
		break;
		case RIGHT:
		{
			CleanBulletPos();
			this->m_X = this->m_X + 1;
			if (g_Map[this->m_X - 1][this->m_Y] == 土墙)
			{
				this->m_HP = 0;
				g_Map[this->m_X - 1][this->m_Y] = 空地;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				this->m_HP = 0;
				g_Map[this->m_X][this->m_Y] = 空地;
				WriteChar(this->m_X, this->m_Y, "  ", 0x02);
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				this->m_HP = 0;
				Who = 3;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1)  //子弹打到玩家1了
			{
				this->m_HP = 0;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
				Who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				this->m_HP = 0;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x00);
				Who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1 || g_Map[this->m_X][this->m_Y] == 敌人2 || g_Map[this->m_X][this->m_Y] == 敌人3 || g_Map[this->m_X][this->m_Y] == 敌人4)
			{
				this->m_HP = 0;
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
			else
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
				WriteChar(this->m_X - 1, this->m_Y, "  ", 0x02);
			}
		}
		break;
		default:
			break;
		}
	}
	return Who;
} //备份
//AI第一发子弹
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
	WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
}
//我的子弹移动函数
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
			if (g_Map[this->m_X][this->m_Y + 1] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹1)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹2)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌方子弹1 || g_Map[this->m_X][this->m_Y] == 敌方子弹2 || g_Map[this->m_X][this->m_Y] == 敌方子弹3 || g_Map[this->m_X][this->m_Y] == 敌方子弹4)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				MessageBox(0, L"老家被击中了", L"受到了进攻", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1)
			{
				ExplosiveSound();
				who = 11;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人2)
			{
				ExplosiveSound();
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人3)
			{
				ExplosiveSound();
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人4)
			{
				ExplosiveSound();
				who = 14;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1 || g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				this->m_HP = 0;
			}
		}
		break;
		case DOWN:
		{
			CleanBulletPos();
			this->m_Y = this->m_Y + 1;
			if (g_Map[this->m_X][this->m_Y - 1] == 土墙 )
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹1)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹2)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌方子弹1 || g_Map[this->m_X][this->m_Y] == 敌方子弹2 || g_Map[this->m_X][this->m_Y] == 敌方子弹3 || g_Map[this->m_X][this->m_Y] == 敌方子弹4)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;				
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				MessageBox(0, L"老家被击中了", L"受到了进攻", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1)
			{
				ExplosiveSound();		
				who = 11;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人2)
			{
				ExplosiveSound();			
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人3)
			{
				ExplosiveSound();		
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人4)
			{
				ExplosiveSound();				
				who = 14;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1 || g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				this->m_HP = 0;
			}
		}
		break;
		case LEFT:
		{
			CleanBulletPos();
			this->m_X = this->m_X - 1;
			if (g_Map[this->m_X + 1][this->m_Y] == 土墙 )
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				MessageBox(0, L"老家被击中了", L"受到了进攻", MB_OKCANCEL);
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹1)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹2)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌方子弹1 || g_Map[this->m_X][this->m_Y] == 敌方子弹2 || g_Map[this->m_X][this->m_Y] == 敌方子弹3 || g_Map[this->m_X][this->m_Y] == 敌方子弹4)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1) //碰到敌人
			{
				ExplosiveSound();							
				who = 11;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人2) //碰到敌人
			{
				ExplosiveSound();			
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人3) //碰到敌人
			{
				ExplosiveSound();		
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人4) //碰到敌人
			{
				ExplosiveSound();				
				who = 14;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1 || g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				this->m_HP = 0;
			}
		}
		break;
		case RIGHT:
		{
			CleanBulletPos();
			this->m_X = this->m_X + 1;
			if (g_Map[this->m_X - 1][this->m_Y] == 土墙)
			{				
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{			
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				MessageBox(0, L"老家被击中了", L"受到了进攻", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹1 )
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 1;
			}
			else if(g_Map[this->m_X][this->m_Y] == 友方子弹2)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌方子弹1 || g_Map[this->m_X][this->m_Y] == 敌方子弹2 || g_Map[this->m_X][this->m_Y] == 敌方子弹3 || g_Map[this->m_X][this->m_Y] == 敌方子弹4)
			{
				MessageBox(0, L"啊", L"啊", MB_OKCANCEL);
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1) //碰到敌人
			{
				ExplosiveSound();		
				who = 11;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人2) //碰到敌人
			{
				ExplosiveSound();	
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人3) //碰到敌人
			{
				ExplosiveSound();		
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人4) //碰到敌人
			{
				ExplosiveSound();
				who = 14;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1 || g_Map[this->m_X][this->m_Y] == 玩家2)
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
//更新子弹坐标
void BULLET::UpdateBulletPos()
{
	if(this->m_HP > 0)
		g_Map[this->m_X][this->m_Y] = this->m_ID;
}
//清除子弹坐标和符号
void BULLET::CleanBulletPos()
{
	g_Map[this->m_X][this->m_Y] = 空地;
	WriteChar(this->m_X, this->m_Y, "  ", 0x00);
}
//AI移动函数
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
			if (g_Map[this->m_X][this->m_Y + 1] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹1 || g_Map[this->m_X][this->m_Y] == 友方子弹2)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌方子弹1 || g_Map[this->m_X][this->m_Y] == 敌方子弹2 || g_Map[this->m_X][this->m_Y] == 敌方子弹3 || g_Map[this->m_X][this->m_Y] == 敌方子弹4)
			{
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				MessageBox(0, L"老家被击中了", L"受到了进攻", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1 || g_Map[this->m_X][this->m_Y] == 敌人2 || g_Map[this->m_X][this->m_Y] == 敌人3 || g_Map[this->m_X][this->m_Y] == 敌人4)
			{
				ExplosiveSound();
				who = 11;
			}
		/*	else if (g_Map[this->m_X][this->m_Y] == 敌人2)
			{
				ExplosiveSound();
				who = 12;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人3)
			{
				ExplosiveSound();
				who = 13;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人4)
			{
				ExplosiveSound();
				who = 14;
			}*/
			else if (g_Map[this->m_X][this->m_Y] == 玩家1)
			{
				ExplosiveSound();
				who = 4;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家2)
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
			if (g_Map[this->m_X][this->m_Y - 1] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹1)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹2)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌方子弹1 || g_Map[this->m_X][this->m_Y] == 敌方子弹2 || g_Map[this->m_X][this->m_Y] == 敌方子弹3 || g_Map[this->m_X][this->m_Y] == 敌方子弹4)
			{
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				MessageBox(0, L"老家被击中了", L"受到了进攻", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1)
			{
				who = 4;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				who = 5;
			}
			//else if (g_Map[this->m_X][this->m_Y] == 敌人1)
			//{
			//	ExplosiveSound();
			//	who = 11;
			//}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1 || g_Map[this->m_X][this->m_Y] == 敌人2 || g_Map[this->m_X][this->m_Y] == 敌人3 || g_Map[this->m_X][this->m_Y] == 敌人4)
			{
				ExplosiveSound();
				who = 11;
			}
			/*	else if (g_Map[this->m_X][this->m_Y] == 敌人3)
				{
					ExplosiveSound();
					who = 13;
				}
				else if (g_Map[this->m_X][this->m_Y] == 敌人4)
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
			if (g_Map[this->m_X + 1][this->m_Y] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				MessageBox(0, L"老家被击中了", L"受到了进攻", MB_OKCANCEL);
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹1 || g_Map[this->m_X][this->m_Y] == 友方子弹2)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌方子弹1 || g_Map[this->m_X][this->m_Y] == 敌方子弹2 || g_Map[this->m_X][this->m_Y] == 敌方子弹3 || g_Map[this->m_X][this->m_Y] == 敌方子弹4)
			{
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1 || g_Map[this->m_X][this->m_Y] == 敌人2 || g_Map[this->m_X][this->m_Y] == 敌人3 || g_Map[this->m_X][this->m_Y] == 敌人4) //碰到敌人
			{
				who = 11;
			}
			//else if (g_Map[this->m_X][this->m_Y] == 敌人2) //碰到敌人
			//{
			//	ExplosiveSound();
			//	who = 12;
			//}
			//else if (g_Map[this->m_X][this->m_Y] == 敌人3) //碰到敌人
			//{
			//	ExplosiveSound();
			//	who = 13;
			//}
			//else if (g_Map[this->m_X][this->m_Y] == 敌人4) //碰到敌人
			//{
			//	ExplosiveSound();
			//	who = 14;
			//}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1)
			{
				who = 4;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				who = 5;
			}
		}	
		break;
		case RIGHT:
		{
			CleanBulletPos();
			this->m_X = this->m_X + 1;
			if (g_Map[this->m_X - 1][this->m_Y] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 土墙)
			{
				CleanBulletPos();
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 空地)
			{
				WriteChar(this->m_X, this->m_Y, "⊙", 0x02);
			}
			else if (g_Map[this->m_X][this->m_Y] == 基地)
			{
				MessageBox(0, L"老家被击中了", L"受到了进攻", MB_OKCANCEL);
				this->m_HP = 0;
				who = 3;
			}
			else if (g_Map[this->m_X][this->m_Y] == 铁墙)
			{
				this->m_HP = 0;
			}
			else if (g_Map[this->m_X][this->m_Y] == 友方子弹1 || g_Map[this->m_X][this->m_Y] == 友方子弹2)
			{
				who = 1;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌方子弹1 || g_Map[this->m_X][this->m_Y] == 敌方子弹2 || g_Map[this->m_X][this->m_Y] == 敌方子弹3 || g_Map[this->m_X][this->m_Y] == 敌方子弹4)
			{
				who = 2;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家1)
			{
				who = 4;
			}
			else if (g_Map[this->m_X][this->m_Y] == 玩家2)
			{
				who = 5;
			}
			else if (g_Map[this->m_X][this->m_Y] == 敌人1 || g_Map[this->m_X][this->m_Y] == 敌人2 || g_Map[this->m_X][this->m_Y] == 敌人3 || g_Map[this->m_X][this->m_Y] == 敌人4) //碰到敌人
			{
				ExplosiveSound();
				who = 11;
			}
			//else if (g_Map[this->m_X][this->m_Y] == 敌人2) //碰到敌人
			//{
			//	ExplosiveSound();
			//	who = 12;
			//}
			//else if (g_Map[this->m_X][this->m_Y] == 敌人3) //碰到敌人
			//{
			//	ExplosiveSound();
			//	who = 13;
			//}
			//else if (g_Map[this->m_X][this->m_Y] == 敌人4) //碰到敌人
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