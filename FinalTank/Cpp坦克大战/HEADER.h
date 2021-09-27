#pragma once
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <vector>
#include <list>
#pragma comment(lib,"winmm.lib")
using namespace std;
//***地图 菜单***
#define Map_X 42
#define Map_Y 42
#define Menu_X 20
#define Menu_Y 4
//**方向**
enum DIR{UP=0,DOWN,LEFT,RIGHT=3};
//***地图元素***
enum ELE{空地=10,铁墙,泥石流,基地,土墙,草地};
//***全局变量地图***
extern char g_Map[Map_X][Map_Y];
//***地图元素***
extern char g_EleMap[Map_X][Map_Y];
//**坦克
enum AllTank{玩家1=100,玩家2,敌人1,敌人2,敌人3,敌人4};
//**子弹
enum ALLBullet
{
	友方子弹1=120, 友方子弹2, 敌方子弹1, 敌方子弹2, 敌方子弹3, 敌方子弹4
};