#include "PUBLIC.h"
//***写字写数字函数
void UltraWrite(short x, short y, const char* pStr, int data, short color)
{
	COORD Position = { x * 2,y };
	HANDLE Houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Houtput, Position);
	SetConsoleTextAttribute(Houtput, color);
	printf("%s %d", pStr, data);
}
//***自定义坐标的写字函数***
void WriteChar(short x, short y, const char* pStr, short color)
{
	COORD Position = { x * 2,y };
	HANDLE Houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Houtput, Position);
	SetConsoleTextAttribute(Houtput, color);
	printf(pStr);
}
//爆炸音效
void ExplosiveSound()
{
	PlaySoundA("爆炸声.wav", NULL, SND_ASYNC | SND_NODEFAULT);
}
//欢迎音乐
void WelcomeMusic()
{
	PlaySoundA("坦克开场音效.wav", NULL, SND_ASYNC | SND_NODEFAULT);
}
//子弹音效
void Biu()
{
	PlaySoundA("Biu.wav", NULL, SND_ASYNC | SND_FILENAME);
}
//***隐藏光标***
void InvisibleCursor()
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOutput, &cci);
}
//***画地图***
void DrawMap()
{
	for (int i = 0; i < Map_X; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (i == 0 || j == 0 || i == Map_X - 1 || j == Map_Y - 1)
			{
				g_Map[i][j] = 铁墙;
				WriteChar(i, j, "※", 0x02);
			}
			else
			{
				g_Map[i][j] = 空地;
			}
		}
	}
	for (int j = 37; j <= 40; j++)
	{
		WriteChar(18, j, "□", 0x02); WriteChar(22, j, "□", 0x02);
		g_Map[18][j] = 土墙; g_Map[22][j] = 土墙;
	}
	for (int i = 18; i <= 22; i++)
	{
		WriteChar(i, 37, "□", 0x02);
		g_Map[i][37] = 土墙;
	}
	for (int i = 19; i < 22; ++i)
	{
		g_Map[i][38] = 基地; WriteChar(19, 38, "◣★◢", 0x04);
		g_Map[i][39] = 基地; WriteChar(19, 39, "███", 0x04);
		g_Map[i][40] = 基地; WriteChar(19, 40, "◢█◣", 0x04);
	}
	for (int i = Map_X; i < Map_X + 25; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (i == Map_X + 24 || i == Map_X || j == 0 || j == Map_Y - 1)
			{
				WriteChar(i, j, "※", 0x02);
			}
		}
	}
}
//***输出坐标***
void OutPutPos(int X, int Y)
{
	char szBuf[100] = { 0 };
	sprintf_s(szBuf, sizeof(szBuf), "x=%3d, y=%3d", X / 2, Y);
	SetConsoleTitleA(szBuf);
	WriteChar(0, 0, szBuf, 0x50);
}
//***鼠标事件***
void MouseEventProc(MOUSE_EVENT_RECORD mer)
{
	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y, "※※", 0x20);
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y + 1, "※※", 0x20);
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y] = 铁墙;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y] = 铁墙;
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y + 1] = 铁墙;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y + 1] = 铁墙;
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y, "□□", 0x20);
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y + 1, "□□", 0x20);
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y] = 土墙;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y] = 土墙;
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y + 1] = 土墙;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y + 1] = 土墙;
		}
		else if (mer.dwButtonState == FROM_LEFT_2ND_BUTTON_PRESSED)
		{
			WriteChar((mer.dwMousePosition.X / 2), mer.dwMousePosition.Y, "卍卍", 0x50);
			g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y] = 泥石流;
			g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y] = 泥石流;
		}
		/*else if (mer.dwButtonState == FROM_LEFT_3RD_BUTTON_PRESSED)
		{
			MessageBox(0, L"侧键1", L"侧键1", MB_OKCANCEL);
		}
		else if (mer.dwButtonState == FROM_LEFT_4TH_BUTTON_PRESSED)
		{
			MessageBox(0, L"侧键2", L"侧键2", MB_OKCANCEL);
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
		g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y] = 空地;
		g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y] = 空地;
		g_Map[mer.dwMousePosition.X / 2][mer.dwMousePosition.Y + 1] = 空地;
		g_Map[mer.dwMousePosition.X / 2 + 1][mer.dwMousePosition.Y + 1] = 空地;
	}
	break;
	}
}
//***清屏代码***
void ClearScreen()
{
	system("cls");
	WriteChar(0, 0, "  ", 0x00);
}
//***无回显等待用户输入函数***
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
			}  //上

			else if (Key2 == 80)
			{
				return Key2;
			}  //下

			else if (Key2 == 75)
			{
				return Key2;
			}  //左

			else if (Key2 == 77)
			{
				return Key2;
			}  //右
		}
		else
			return Key;
	}
	return 0;
}
//***欢迎界面***
void DrawWelcomePicture()
{
	system("mode con cols=160 lines=50");
	const char * Tank[8] =
	{
		{"Bong Bong   ★★█〓███████▇▅▅▅▅▅▅▅▄▄▄▄▄▅▇▇▇    ●    ●"},
		{"                         █●█"},
		{"       ◢▄██●★●█████●★●███▄◣"},
		{"     ◢〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓◣"},
		{"  ▄▅██████████████████████▅▄▃"},
		{"◢〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓◣"},
		{"◥███████████████████████████◤"},
		{"  ◥●▲●▲●▲●▲●▲●▲●▲●▲●▲●▲●▲●▲●◤"}
	};
	for (int i = 0; i < 8; i++)
	{
		WriteChar(Menu_X, 2 + 2 * i, Tank[i], 0x02);
	}
	while (1)
	{
		WriteChar(1, 1, "按BackSpace键跳过", 0x02);
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
//游戏结束
void GameOver()
{
	MessageBox(0, L"很遗憾", L"你输了", MB_OKCANCEL);
}
//***记分板***
void ScoreBoard()
{
	for (int i = Map_X; i < Map_X + 25; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (i == Map_X + 24 || i == Map_X || j == 0 || j == Map_Y - 1)
			{
				WriteChar(i, j, "※", 0x02);
			}
		}
	}
	WriteChar(52, 1, "记分板", 0x02);
	WriteChar(44, 5, "o 回到主菜单 ", 0x2);
	WriteChar(44, 8, "玩家1: 上: w 下: s 左: a  右: d   射击: v ", 0x2);
	WriteChar(44, 11, "玩家2: 上:↑ 下:↓ 左: ← 右: →  射击: m ", 0x2);
	WriteChar(44, 14, "保存(暂停)：p", 0x2);
	WriteChar(44, 17, "作弊(敌人全死 并到下一关)：k", 0x2);

}
//***随机函数***
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
	if (i == 敌人1) //敌人1
		Number = RandomArr2[LuckyNumber1][LuckyNumber2];
	else if (i == 敌人2) //敌人2
		Number = RandomArr3[LuckyNumber1][LuckyNumber2];
	else if (i == 敌人3) //敌人3
		Number = RandomArr4[LuckyNumber1][LuckyNumber2];
	else if (i == 敌人4) //敌人4
		Number = RandomArr5[LuckyNumber1][LuckyNumber2];
}
//画出菜单的星边
void DrawMenuStar()
{
	for (int i = 22; i <= 46; i++)
	{
		WriteChar(i, 20, "☆", 0x02);
		WriteChar(i, 40, "☆", 0x02);
	}
	for (int i = 20; i <= 40; i++)
	{
		WriteChar(22, i, "☆", 0x02);
		WriteChar(46, i, "☆", 0x02);
	}
}
//画出菜单第一个选择页面
void DrawFirstMenu()
{
	WriteChar(Menu_X + 12, Menu_Y + 19, "1.新游戏", 0x02);
	WriteChar(Menu_X + 12, Menu_Y + 22, "2.继续最近的游戏", 0x02);
	WriteChar(Menu_X + 12, Menu_Y + 25, "3.编辑地图", 0x02);
	WriteChar(Menu_X + 12, Menu_Y + 28, "4.退出游戏", 0x02);
	WriteChar(Menu_X + 12, Menu_Y + 31, "5.关卡选择", 0x02);
}