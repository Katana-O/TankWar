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

	//关卡菜单
	int StageMenu();
	//***主菜单
	/*int MainMenu();*/
	//判断敌人死光
	bool EnemyDead();
	//判断友方死光
	bool AllyDead();
	//读取所有元素，地图，坦克，子弹
	bool ReadInfo(char level);
	//保存所有元素，地图，坦克，子弹
	bool SaveInfo(char level);
	//自定义地图
	void MessageLoop();
	//***存档***
	void SaveMap(char level);
	//***读档***
	void ReadMap(char level);
	//游戏主引擎
	void GameStart();
	//获取玩家1键盘输入
	int GetUserInput(int Dir);
	//获取玩家2键盘输入
	int Get2UserInput(int Dir);
	//初始化坦克信息
	void InitTank();
	//初始化子弹信息
	void InitBullet();
	//记分板上的信息
	void ScoreInfo();


	BASE();
	~BASE();
};

