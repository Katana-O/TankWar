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
//***��ͼ �˵�***
#define Map_X 42
#define Map_Y 42
#define Menu_X 20
#define Menu_Y 4
//**����**
enum DIR{UP=0,DOWN,LEFT,RIGHT=3};
//***��ͼԪ��***
enum ELE{�յ�=10,��ǽ,��ʯ��,����,��ǽ,�ݵ�};
//***ȫ�ֱ�����ͼ***
extern char g_Map[Map_X][Map_Y];
//***��ͼԪ��***
extern char g_EleMap[Map_X][Map_Y];
//**̹��
enum AllTank{���1=100,���2,����1,����2,����3,����4};
//**�ӵ�
enum ALLBullet
{
	�ѷ��ӵ�1=120, �ѷ��ӵ�2, �з��ӵ�1, �з��ӵ�2, �з��ӵ�3, �з��ӵ�4
};