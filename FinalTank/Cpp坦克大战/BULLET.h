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
	char m_Direction;			  //方向
	char m_Speed;				  //速度
	char m_Damage;				  //伤害
	char m_HP;					  //血量
	char m_Stop;				  //停止
	char m_Me;					  //我
	char m_Color;				  //颜色
	char m_ID;					  //子弹身份证
public:
	//AI第一颗子弹
	void AIFirstBullet(char X, char Y, char Dir);
	//AI备用子弹移动函数
	char AIBulletMovement2();
	//我的子弹移动函数
	char BulletMove();
	//更新子弹坐标
	void UpdateBulletPos();
	//清理子弹位置
	void CleanBulletPos();
	//AI子弹移动函数
	char AIBulletMovement();
};

