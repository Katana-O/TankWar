#pragma once
#include "HEADER.h"

//***�Զ��������д�� д���� ����***
void UltraWrite(short x, short y, const char* pStr, int data, short color);
//д�ֵ�
void WriteChar(short x, short y, const char* pStr, short color=3|8);
//ѡ��˵���һҳ
void DrawFirstMenu();
//�Ƿְ�
void ScoreBoard();
//GG
void GameOver();
//��ӭ����
void WelcomeMusic();
//���˵�������
void DrawMenuStar();
//����ͼ
void DrawMap();
//�������
void Random(char & Number,int i);
//�ӵ���
void Biu();
//��ը��
void ExplosiveSound();
//***���ع��***
void InvisibleCursor();
//***���λ��***
void OutPutPos(int X, int Y);
//***����¼�***
void MouseEventProc(MOUSE_EVENT_RECORD mer);
//***��������***
void ClearScreen();
//***�޻��Եȴ��û�����***
int WaitKey();
//��ӭҳ��
void DrawWelcomePicture();
