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
	char m_Direction;		//方向
	char m_Model;			//坦克模型
	char m_Color;			//颜色设置
	int m_Point;			//得分
	int m_HP;				//坦克生命值
	char m_Me;				//判断是否是玩家坦克
	char m_Stop;			//是否停止
	char m_ID;				//坦克身份证

public:
	//AI移动备用函数
	char AI2Move();
	//AI移动函数
	char AIMove();
	//清理坦克
	void CleanTank();
	//更新坦克坐标
	void UpdatePos();
	//画出坦克
	void Show();
	//清理死去的坦克
	void CleanDeadTank();
	//复活坦克
	void Revive();
	
	const char* Tank_Figure[4][3][4] = //坦克图案模型
	{
		{
			{"  ■  ", "■  ■", "  ■■", "■■  "},
			{"■●■", "■●■", "■●  ", "  ●■"},
			{"■  ■", "  ▉  ", "  ■■", "■■  "}
		},
		{
			{"┏┃┓", "┏┳┓", "┏┳┓", "┏┳┓"},
			{"┣●┫", "┣●┫", "━●┫", "┣●━"},
			{"┗┻┛", "┗┃┛", "┗┻┛", "┗┻┛"}
		},
		{
			{"┏┃┓", "◢━◣", "┏┳◣", "◢┳┓"},
			{"┣●┫", "┣●┫", "━●┃", "┃●━"},
			{"◥━◤", "┗┃┛", "┗┻◤", "◥┻┛"}
		},
		{
			{"╔┃╗", "╔╦╗", "╔╦╗", "╔╦╗"},
			{"╠█╣", "╠█╣", "━█╣", "╠█━"},
			{"╚╩╝", "╚┃╝", "╚╩╝", "╚╩╝"}
		}
	};
};
