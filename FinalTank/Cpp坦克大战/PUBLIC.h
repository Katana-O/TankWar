#pragma once
#include "HEADER.h"

//***自定义坐标的写字 写数据 函数***
void UltraWrite(short x, short y, const char* pStr, int data, short color);
//写字的
void WriteChar(short x, short y, const char* pStr, short color=3|8);
//选择菜单第一页
void DrawFirstMenu();
//记分板
void ScoreBoard();
//GG
void GameOver();
//欢迎音乐
void WelcomeMusic();
//画菜单的星星
void DrawMenuStar();
//画地图
void DrawMap();
//随机函数
void Random(char & Number,int i);
//子弹声
void Biu();
//爆炸声
void ExplosiveSound();
//***隐藏光标***
void InvisibleCursor();
//***输出位置***
void OutPutPos(int X, int Y);
//***鼠标事件***
void MouseEventProc(MOUSE_EVENT_RECORD mer);
//***清屏代码***
void ClearScreen();
//***无回显等待用户输入***
int WaitKey();
//欢迎页面
void DrawWelcomePicture();
