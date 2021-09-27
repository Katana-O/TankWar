#include "PUBLIC.h"
//***д��д���ֺ���
void UltraWrite(short x, short y, const char* pStr, int data, short color)
{
	COORD Position = { x * 2,y };
	HANDLE Houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Houtput, Position);
	SetConsoleTextAttribute(Houtput, color);
	printf("%s %d", pStr, data);
}
//***�Զ��������д�ֺ���***
void WriteChar(short x, short y, const char* pStr, short color)
{
	COORD Position = { x * 2,y };
	HANDLE Houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Houtput, Position);
	SetConsoleTextAttribute(Houtput, color);
	printf(pStr);
}
//��ը��Ч
void ExplosiveSound()
{
	PlaySoundA("��ը��.wav", NULL, SND_ASYNC | SND_NODEFAULT);
}
//��ӭ����
void WelcomeMusic()
{
	PlaySoundA("̹�˿�����Ч.wav", NULL, SND_ASYNC | SND_NODEFAULT);
}
//�ӵ���Ч
void Biu()
{
	PlaySoundA("Biu.wav", NULL, SND_ASYNC | SND_FILENAME);
}
//***���ع��***
void InvisibleCursor()
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOutput, &cci);
}
//***����ͼ***
void DrawMap()
{
	for (int i = 0; i < Map_X; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (i == 0 || j == 0 || i == Map_X - 1 || j == Map_Y - 1)
			{
				g_Map[i][j] = ��ǽ;
				WriteChar(i, j, "��", 0x02);
			}
			else
			{
				g_Map[i][j] = �յ�;
			}
		}
	}
	for (int j = 37; j <= 40; j++)
	{
		WriteChar(18, j, "��", 0x02); WriteChar(22, j, "��", 0x02);
		g_Map[18][j] = ��ǽ; g_Map[22][j] = ��ǽ;
	}
	for (int i = 18; i <= 22; i++)
	{
		WriteChar(i, 37, "��", 0x02);
		g_Map[i][37] = ��ǽ;
	}
	for (int i = 19; i < 22; ++i)
	{
		g_Map[i][38] = ����; WriteChar(19, 38, "���嗀", 0x04);
		g_Map[i][39] = ����; WriteChar(19, 39, "������", 0x04);
		g_Map[i][40] = ����; WriteChar(19, 40, "������", 0x04);
	}
	for (int i = Map_X; i < Map_X + 25; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (i == Map_X + 24 || i == Map_X || j == 0 || j == Map_Y - 1)
			{
				WriteChar(i, j, "��", 0x02);
			}
		}
	}
}
//***�������***
void OutPutPos(int X, int Y)
{
	char szBuf[100] = { 0 };
	sprintf_s(szBuf, sizeof(szBuf), "x=%3d, y=%3d", X / 2, Y);
	SetConsoleTitleA(szBuf);
	WriteChar(0, 0, szBuf, 0x50);
}
//***����¼�***
void MouseEventProc(MOUSE_EVENT_RECORD mer)
{
	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y, "����", 0x20);
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y + 1, "����", 0x20);
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y] = ��ǽ;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y] = ��ǽ;
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y + 1] = ��ǽ;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y + 1] = ��ǽ;
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y, "����", 0x20);
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y + 1, "����", 0x20);
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y] = ��ǽ;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y] = ��ǽ;
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y + 1] = ��ǽ;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y + 1] = ��ǽ;
		}
		else if (mer.dwButtonState == FROM_LEFT_2ND_BUTTON_PRESSED)
		{
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y, "�d�d", 0x50);
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y] = ��ʯ��;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y] = ��ʯ��;
		}
		/*else if (mer.dwButtonState == FROM_LEFT_3RD_BUTTON_PRESSED)
		{
			MessageBox(0, L"���1", L"���1", MB_OKCANCEL);
		}
		else if (mer.dwButtonState == FROM_LEFT_4TH_BUTTON_PRESSED)
		{
			MessageBox(0, L"���2", L"���2", MB_OKCANCEL);
		}*/
		break;
	case DOUBLE_CLICK:
	{
		WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y, "  ", 0x00);
		WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y + 1, "  ", 0x00);
	}
	break;
	case MOUSE_MOVED:
	{
		OutPutPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);
	}
	break;
	case MOUSE_WHEELED:
	{
		WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y, "  ", 0x00);
		WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y + 1, "  ", 0x00);
		g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y] = �յ�;
		g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y] = �յ�;
		g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y + 1] = �յ�;
		g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y + 1] = �յ�;
	}
	break;
	}
}
//***��������***
void ClearScreen()
{
	system("cls");
	WriteChar(0, 0, "  ", 0x00);
}
//***�޻��Եȴ��û����뺯��***
int WaitKey()
{
	if (_kbhit())
	{
		int Key = _getch();
		//return Key;
		if (Key == 224)
		{
			int Key2 = _getch();

			if (Key2 == 72)
			{
				return Key2;
			}  //��

			else if (Key2 == 80)
			{
				return Key2;
			}  //��

			else if (Key2 == 75)
			{
				return Key2;
			}  //��

			else if (Key2 == 77)
			{
				return Key2;
			}  //��
		}
		else
			return Key;
	}
	return 0;
}
//***��ӭ����***
void DrawWelcomePicture()
{
	system("mode con cols=160 lines=50");
	const char * Tank[8] =
	{
		{"Bong Bong   ��切�����������������~�|�|�|�|�|�|�|�{�{�{�{�{�|�~�~�~    ��    ��"},
		{"                         ����"},
		{"       ���{�������񨀨����������񨀨����{��"},
		{"     ��������������������������������������������"},
		{"  �{�|���������������������������������������������|�{�z"},
		{"����������������������������������������������������������"},
		{"����������������������������������������������������������"},
		{"  ����������������������������������������"}
	};
	for (int i = 0; i < 8; i++)
	{
		WriteChar(Menu_X, 2 + 2 * i, Tank[i], 0x02);
	}
	while (1)
	{
		WriteChar(1, 1, "��BackSpace������", 0x02);
		if (_kbhit())
		{
			break;
		}
		time_t currenttime;
		currenttime = time(NULL);
		if (currenttime % 2 == 0)
		{
			int Color = rand() % 15 + 1;
			Color << 4;
			for (int i = 0; i < 8; i++)
			{
				WriteChar(Menu_X, 2 + 2 * i, Tank[i], Color);
			}
		}
	}
}
//��Ϸ����
void GameOver()
{
	MessageBox(0, L"���ź�", L"������", MB_OKCANCEL);
}
//***�Ƿְ�***
void ScoreBoard()
{
	for (int i = Map_X; i < Map_X + 25; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (i == Map_X + 24 || i == Map_X || j == 0 || j == Map_Y - 1)
			{
				WriteChar(i, j, "��", 0x02);
			}
		}
	}
	WriteChar(52, 1, "�Ƿְ�", 0x02);
	WriteChar(44, 5, "o �ص����˵� ", 0x2);
	WriteChar(44, 8, "���1: ��: w ��: s ��: a  ��: d   ���: v ", 0x2);
	WriteChar(44, 11, "���2: ��:�� ��:�� ��: �� ��: ��  ���: m ", 0x2);
	WriteChar(44, 14, "����(��ͣ)��p", 0x2);
	WriteChar(44, 17, "����(����ȫ�� ������һ��)��k", 0x2);

}
//***�������***
void Random(char & Number, int i)
{
	srand((unsigned)time(NULL));
	char LuckyNumber1 = 0;
	char LuckyNumber2 = 0;
	int RandomArr2[6][4] = { { 0,1,2,3 },{1, 3, 2, 0}, { 2,3,1,0 }, { 1,0,2,3 }, { 2,1,3,0 }, { 2,1,0,3 } };
	int RandomArr3[6][4] = { { 1,2,3,0 },{1, 0, 2, 0}, { 1,3,1,0 }, { 3,0,2,3 }, { 2,3,3,0 }, { 0,1,0,3 } };
	int RandomArr4[6][4] = { { 2,3,0,1 },{0, 0, 2, 0}, { 2,3,1,0 }, { 1,0,2,3 }, { 2,1,1,0 }, { 3,1,0,2 } };
	int RandomArr5[6][4] = { { 3,0,1,2 },{2, 2, 3, 3}, { 2,1,1,1 }, { 2,0,0,1 }, { 3,3,1,2 }, { 3,3,0,2 } };
	LuckyNumber1 = 0;
	LuckyNumber2 = rand() % 4 + 0;
	if (i == ����1) //����1
		Number = RandomArr2[LuckyNumber1][LuckyNumber2];
	else if (i == ����2) //����2
		Number = RandomArr3[LuckyNumber1][LuckyNumber2];
	else if (i == ����3) //����3
		Number = RandomArr4[LuckyNumber1][LuckyNumber2];
	else if (i == ����4) //����4
		Number = RandomArr5[LuckyNumber1][LuckyNumber2];
}
//�����˵����Ǳ�
void DrawMenuStar()
{
	for (int i = 22; i <= 46; i++)
	{
		WriteChar(i, 20, "��", 0x02);
		WriteChar(i, 40, "��", 0x02);
	}
	for (int i = 20; i <= 40; i++)
	{
		WriteChar(22, i, "��", 0x02);
		WriteChar(46, i, "��", 0x02);
	}
}
//�����˵���һ��ѡ��ҳ��
void DrawFirstMenu()
{
	WriteChar(Menu_X + 12, Menu_Y + 19, "1.����Ϸ", 0x02);
	WriteChar(Menu_X + 12, Menu_Y + 22, "2.�����������Ϸ", 0x02);
	WriteChar(Menu_X + 12, Menu_Y + 25, "3.�༭��ͼ", 0x02);
	WriteChar(Menu_X + 12, Menu_Y + 28, "4.�˳���Ϸ", 0x02);
	WriteChar(Menu_X + 12, Menu_Y + 31, "5.�ؿ�ѡ��", 0x02);
}