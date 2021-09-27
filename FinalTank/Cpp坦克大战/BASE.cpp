#include "BASE.h"



//关卡菜单
int BASE::StageMenu()
{
	ClearScreen();
	WriteChar(Menu_X + 8, Menu_Y + 21, "1.输入你要开始的关卡", 0x02);
	DrawMenuStar();
	int Stage = 0;
	MessageBox(0, L"输入数字并回车:", L"提示", MB_OKCANCEL);
	WriteChar(50, 30, "输入: ");
	scanf("%d", &Stage);
	MessageBox(0, L"输入成功", L"提示", MB_OKCANCEL);
	return Stage;
}

//记分板的信息
void BASE::ScoreInfo()
{
	UltraWrite(44, 19, "AI 红", V_Tank[2].m_HP, V_Tank[2].m_Color);
	UltraWrite(44, 22, "AI 紫", V_Tank[3].m_HP, V_Tank[3].m_Color);
	UltraWrite(44, 25, "AI 黄", V_Tank[4].m_HP, V_Tank[4].m_Color);
	UltraWrite(44, 28, "AI 白", V_Tank[5].m_HP, V_Tank[5].m_Color);
	UltraWrite(44, 31, "玩家1", V_Tank[0].m_HP, V_Tank[0].m_Color);
	UltraWrite(44, 34, "玩家2", V_Tank[1].m_HP, V_Tank[1].m_Color);
	UltraWrite(44, 37, "得分:", V_Tank[0].m_Point, V_Tank[5].m_Color);
}

void BASE::InitTank()
{
	//玩家1的坦克
	V_Tank.push_back(TANK(14, 39, UP, 0, 0x02, 0, 999, 1, 0, 玩家1));
	//玩家2	
	V_Tank.push_back(TANK(34, 39, UP, 0, 0x03, 0, 999, 0, 1, 玩家2));
	//AI 红 紫 黄 白
	V_Tank.push_back(TANK(5, 2, DOWN, 0, 0x04, 0, 5, 0, 1, 敌人1));
	V_Tank.push_back(TANK(15, 2, DOWN, 0, 0x05, 0, 4, 0, 1, 敌人2));
	V_Tank.push_back(TANK(25, 2, DOWN, 0, 0x06, 0, 3, 0, 1, 敌人3));
	V_Tank.push_back(TANK(35, 2, DOWN, 0, 0x07, 0, 2, 0, 1, 敌人4));
}

void BASE::InitBullet()
{
	//玩家1的子弹 伤害=1 ME=1 STOP=0, HP = 0
	V_Bullet.push_back(BULLET(1, 1, 0, 0, 0x02, 友方子弹1));
	//第二个玩家的子弹
	V_Bullet.push_back(BULLET(1, 1, 0, 0, 0x03, 友方子弹2));
	//AI de 子弹 伤害=1 ME=0 STOP=0, HP = 0
	V_Bullet.push_back(BULLET(1, 0, 0, 0, 0x04, 敌方子弹1));
	V_Bullet.push_back(BULLET(1, 0, 0, 0, 0x05, 敌方子弹2));
	V_Bullet.push_back(BULLET(1, 0, 0, 0, 0x06, 敌方子弹3));
	V_Bullet.push_back(BULLET(1, 0, 0, 0, 0x07, 敌方子弹4));
}
//***没用
//int BASE::MainMenu()
//{
//Enter:
//	int Game = 0;
//	DrawWelcomePicture();
//	DrawFirstMenu();
//	DrawMenuStar();
//	char Menu_Selection = 0;
//	WriteChar(50, 30, "输入数字并回车:");
//	scanf_s("%c", &Menu_Selection);
//	switch (Menu_Selection)
//	{
//	case '1':  //新游戏
//	{
//		int Stage = StageMenu();
//		ClearScreen();
//		ReadMap(Stage);
//		InitTank();
//		InitBullet();
//		Game = 1;
//	}
//	break;
//	case '2':  //继续最近的游戏
//	{
//		ClearScreen();
//		MessageBox(0, L"最近的游戏默认存在0档", L"提示", MB_OKCANCEL);
//		ReadInfo(0);
//	}
//	break;
//	case '3':  //编辑地图
//	{
//		ClearScreen();
//		MessageLoop();
//		ClearScreen();
//		goto Enter;
//	}
//	break;
//	case '4':   //退出游戏
//	{
//		exit(0);
//	}
//	case '5':
//	{
//		MessageBox(0, L"以后的功能，暂未开放", L"提示", MB_OKCANCEL);
//	}
//	break;
//	}
//	ScoreBoard();
//	return 0;
//}

//***游戏开始***
void BASE::GameStart()
{
Enter:
	WelcomeMusic();
	DrawWelcomePicture();
	DrawFirstMenu();
	DrawMenuStar();
	int Stage = 0;
	int Game = 0;
	int Menu_Selection = 0;
	WriteChar(50, 30, "输入数字并回车:");
	scanf_s("%d", &Menu_Selection);
	switch (Menu_Selection)
	{
	case 1:  //新游戏
	{
		ClearScreen();
		Game = 1;
	}
	break;
	case 2:  //继续最近的游戏
		Game = 2;
		break;
	case 3:  //编辑地图
	{
		ClearScreen();
		MessageLoop();
		ClearScreen();
		goto Enter;
	}
	break;
	case 4:   //退出游戏
		exit(0);
	case 5:   //选择关卡
	{
		Stage = StageMenu();
		Game = 5;
	}
	break;
	}


SecondStart:
	static int Map = 1;
	//读取下一关地图
	if (Game == 1)
	{
		ClearScreen();
		InitBullet();
		InitTank();
		ReadMap(Map);
	}
	//读取最近的存档
	else if (Game == 2)
	{
		ClearScreen();
		ReadInfo(0);
	}
	//指定读取第几关的地图
	else if (Game == 5)
	{
		ClearScreen();
		InitBullet();
		InitTank();
		ReadMap(Stage);
	}

	ScoreBoard();

	for (int i = 0; i < V_Tank.size(); ++i) { V_Tank[i].Show(); }
	int n = clock();
	int g = clock();
	int h = clock();
	int GGG = 1;
	while (GGG == 1)
	{
		int Dir = WaitKey();
		if (Dir == 'w' || Dir == 's' || Dir == 'a' || Dir == 'd' || Dir == 'v' || Dir == 'W' || Dir == 'S' || Dir == 'A' || Dir == 'D' || Dir == 'V')
			GetUserInput(Dir);
		else if (Dir == 72 || Dir == 80 || Dir == 75 || Dir == 77 || Dir == 'n' || Dir == 'N')
			Get2UserInput(Dir);
		//暂停
		else if (Dir == 'p')
		{
			SaveInfo(0);
			MessageBox(0, L"保存到0文件", L"提示", MB_OKCANCEL);
		}
		else if (Dir == 'k') //敌方全死
		{
			for (int i = 2; i < V_Tank.size(); ++i)
			{
				V_Tank[i].m_HP = 0;
			}
		}
		else if (Dir == 'o') //回到最开始主菜单
		{
			V_Tank.clear();
			V_Bullet.clear();
			ClearScreen();
			goto Enter;
		}
		//友方子弹速度
		if (clock() - n >= 20)
		{
			for (int i = 0; i < 2; ++i)
			{
				if (V_Bullet[i].m_HP > 0)
				{
					char who = V_Bullet[i].BulletMove();
					if (who == 11)
					{
						V_Bullet[i].m_HP = 0;
						V_Tank[2].CleanDeadTank();
						V_Tank[2].Revive();
						V_Tank[0].m_Point += 500;
					}
					else if (who == 12)
					{
						V_Bullet[i].m_HP = 0;
						V_Tank[3].CleanDeadTank();
						V_Tank[3].Revive();
						V_Tank[0].m_Point += 300;
					}
					else if (who == 13)
					{
						V_Bullet[i].m_HP = 0;
						V_Tank[4].CleanDeadTank();
						V_Tank[4].Revive();
						V_Tank[0].m_Point += 200;
					}
					else if (who == 14)
					{
						V_Bullet[i].m_HP = 0;
						V_Tank[5].CleanDeadTank();
						V_Tank[5].Revive();
						V_Tank[0].m_Point += 100;
					}
					else if (who == 3)  //如果击中基地
					{
						V_Tank[0].m_HP = 0;
						V_Tank[1].m_HP = 0;
					}
					else if (who == 2) //友方子弹碰到敌方子弹
					{
						for (int i = 0; i < V_Bullet.size(); ++i)
						{
							for (int j = i; j < V_Bullet.size(); ++j)
							{
								if (V_Bullet[i].m_X == V_Bullet[j].m_X && V_Bullet[i].m_Y == V_Bullet[j].m_Y && V_Bullet[i].m_ID != V_Bullet[j].m_ID)
								{
									//擦掉子弹在地图的数据
									g_Map[V_Bullet[i].m_X][V_Bullet[i].m_Y] = 空地;
									WriteChar(V_Bullet[i].m_X, V_Bullet[i].m_Y, "  ");
									MessageBox(0, L"敌方子弹碰到友方子弹", L"提示", MB_OKCANCEL);
									V_Bullet[i].m_HP = 0;
									V_Bullet[j].m_HP = 0;
									break;
								}
							}
							break;
						}
					}
					else if (who == 1)
					{
						V_Bullet[0].CleanBulletPos();
						V_Bullet[1].CleanBulletPos();
						V_Bullet[0].m_HP = 0;
						V_Bullet[1].m_HP = 0;
					}
				}
			}
			n = clock();
		}
		//敌方移动速度
		if (clock() - g >= 100)
		{
			for (int i = 2; i < V_Tank.size(); ++i)
			{
				if (V_Tank[i].m_HP > 0)
				{
					char Rand = V_Tank[i].AIMove();
					if (
						V_Bullet[i].m_HP == 0 && Rand == i-2
						&& g_Map[V_Tank[i].m_X][V_Tank[i].m_Y - 2] != 铁墙
						&& g_Map[V_Tank[i].m_X][V_Tank[i].m_Y + 2] != 铁墙
						&& g_Map[V_Tank[i].m_X - 2][V_Tank[i].m_Y] != 铁墙
						&& g_Map[V_Tank[i].m_X + 2][V_Tank[i].m_Y] != 铁墙)
					{
						V_Bullet[i].AIFirstBullet(V_Tank[i].m_X, V_Tank[i].m_Y, V_Tank[i].m_Direction);
					}
				}
			}
			g = clock();
		}
		//敌方子弹速度
		if (clock() - h >= 60)
		{
			for (int i = 2; i < V_Bullet.size(); ++i)
			{
				if (V_Bullet[i].m_HP > 0)
				{
					char who = V_Bullet[i].AIBulletMovement();
					if (who == 1) //碰到敌方子弹碰到友方子弹
					{
						for (int i = 0; i < V_Bullet.size(); ++i)
						{
							for (int j = i; j < V_Bullet.size(); ++j)
							{
								if (V_Bullet[i].m_X == V_Bullet[j].m_X && V_Bullet[i].m_Y == V_Bullet[j].m_Y && V_Bullet[i].m_ID != V_Bullet[j].m_ID)
								{
									//擦掉子弹在地图的数据
									g_Map[V_Bullet[i].m_X][V_Bullet[i].m_Y] = 空地;
									WriteChar(V_Bullet[i].m_X, V_Bullet[i].m_Y, "  ");
									MessageBox(0, L"敌方子弹碰到友方子弹", L"提示", MB_OKCANCEL);
									V_Bullet[i].m_HP = 0;
									V_Bullet[j].m_HP = 0;
									break;
								}	
							}
							break;
						}
					}
					else if (who == 2)  //敌人子弹打中敌人子弹
					{
						for (int i = 0; i < V_Bullet.size(); ++i)
						{
							for (int j = i; j < V_Bullet.size(); ++j)
							{
								if (V_Bullet[i].m_X == V_Bullet[j].m_X && V_Bullet[i].m_Y == V_Bullet[j].m_Y && V_Bullet[i].m_ID != V_Bullet[j].m_ID)
								{
									//擦掉子弹在地图的数据
									g_Map[V_Bullet[i].m_X][V_Bullet[i].m_Y] = 空地;
									WriteChar(V_Bullet[i].m_X, V_Bullet[i].m_Y, "  ");
									MessageBox(0, L"敌方子弹碰到友方子弹", L"提示", MB_OKCANCEL);
									V_Bullet[i].m_HP = 0;
									V_Bullet[j].m_HP = 0;
								}
								break;
							}
							break;
						}
					}
					else if (who == 3)
					{
						V_Bullet[i].m_HP = 0;
						V_Tank[0].m_HP = 0;
						V_Tank[1].m_HP = 0;
					}
					else if (who == 11 || who == 12 || who == 13 || who == 14)
					{
						V_Bullet[i].m_HP = 0;
					}
					else if (who == 4)
					{
						V_Bullet[i].m_HP = 0;
						V_Tank[0].m_HP -= 1;
					}
					else if (who == 5)
					{
						V_Bullet[i].m_HP = 0;
						V_Tank[1].m_HP -= 1;
					}
				
				}
			}
			h = clock();
		}


		//实时更新的计分板信息
		ScoreInfo();

		//如果其中一方死了，循环都结束。
		if (EnemyDead() == TRUE)
		{
			GGG = 0;
		}
		else if (AllyDead() == TRUE)
		{
			GGG = 0;
		}
	}


	if (AllyDead() == TRUE)
	{
		GameOver();
		system("pause");
		ClearScreen();
		V_Tank.clear();
		V_Bullet.clear();
		goto Enter;
	}
	//如果是敌方死光，则加载下一张地图
	else if (EnemyDead() == TRUE)
	{
		V_Tank.clear();
		V_Bullet.clear();
		Map += 1;
		Game = 1;
		goto SecondStart;
	}
}

bool BASE::AllyDead()
{
	if (V_Tank[0].m_HP == 0 && V_Tank[1].m_HP == 0)
		return TRUE;
	else
		return FALSE;
}

bool BASE::EnemyDead()
{
	if (V_Tank[2].m_HP == 0 && V_Tank[3].m_HP == 0 && V_Tank[4].m_HP == 0 && V_Tank[5].m_HP == 0)
		return TRUE;
	else
		return FALSE;
}

int BASE::GetUserInput(int Dir)
{
	switch (Dir)
	{
	case 'w':case 'W':
	{
		V_Tank[0].CleanTank();
		if (V_Tank[0].m_Direction == UP && g_Map[V_Tank[0].m_X][V_Tank[0].m_Y - 2] == 空地
			&& g_Map[V_Tank[0].m_X - 1][V_Tank[0].m_Y - 2] == 空地
			&& g_Map[V_Tank[0].m_X + 1][V_Tank[0].m_Y - 2] == 空地)
		{
			V_Tank[0].m_Y--;
		}
		else
		{
			V_Tank[0].m_Direction = UP;
		}
	}
	break;
	case 's':case 'S':
	{
		V_Tank[0].CleanTank();
		if (V_Tank[0].m_Direction == DOWN && g_Map[V_Tank[0].m_X][V_Tank[0].m_Y + 2] == 空地 && g_Map[V_Tank[0].m_X - 1][V_Tank[0].m_Y + 2] == 空地 && g_Map[V_Tank[0].m_X + 1][V_Tank[0].m_Y + 2] == 空地)
		{
			V_Tank[0].m_Y++;
		}
		else
		{
			V_Tank[0].m_Direction = DOWN;
		}
	}
	break;
	case 'a':case 'A':
	{
		V_Tank[0].CleanTank();
		if (V_Tank[0].m_Direction == LEFT && g_Map[V_Tank[0].m_X - 2][V_Tank[0].m_Y] == 空地
			&& g_Map[V_Tank[0].m_X - 2][V_Tank[0].m_Y + 1] == 空地
			&& g_Map[V_Tank[0].m_X - 2][V_Tank[0].m_Y - 1] == 空地)
		{
			V_Tank[0].m_X--;
		}
		else
		{
			V_Tank[0].m_Direction = LEFT;
		}
	}
	break;
	case 'd':case 'D':
	{
		V_Tank[0].CleanTank();
		if (V_Tank[0].m_Direction == RIGHT && g_Map[V_Tank[0].m_X + 2][V_Tank[0].m_Y] == 空地
			&& g_Map[V_Tank[0].m_X + 2][V_Tank[0].m_Y + 1] == 空地
			&& g_Map[V_Tank[0].m_X + 2][V_Tank[0].m_Y - 1] == 空地)
		{
			V_Tank[0].m_X++;
		}
		else
		{
			V_Tank[0].m_Direction = RIGHT;
		}
	}
	break;
	case 'v':case'V':
	{
		Biu();
		V_Bullet[0].m_HP = 1;
		V_Bullet[0].m_Direction = V_Tank[0].m_Direction;
		if (V_Bullet[0].m_Direction == UP && g_Map[V_Tank[0].m_X][V_Tank[0].m_Y - 2] != 铁墙)
		{
			V_Bullet[0].m_X = V_Tank[0].m_X;
			V_Bullet[0].m_Y = V_Tank[0].m_Y - 2;
		}
		else if (V_Bullet[0].m_Direction == DOWN && g_Map[V_Tank[0].m_X][V_Tank[0].m_Y + 2] != 铁墙)
		{
			V_Bullet[0].m_X = V_Tank[0].m_X;
			V_Bullet[0].m_Y = V_Tank[0].m_Y + 2;
		}
		else if (V_Bullet[0].m_Direction == LEFT && g_Map[V_Tank[0].m_X - 2][V_Tank[0].m_Y] != 铁墙)
		{
			V_Bullet[0].m_X = V_Tank[0].m_X - 2;
			V_Bullet[0].m_Y = V_Tank[0].m_Y;
		}
		else if (V_Bullet[0].m_Direction == RIGHT && g_Map[V_Tank[0].m_X + 2][V_Tank[0].m_Y] != 铁墙)
		{
			V_Bullet[0].m_X = V_Tank[0].m_X + 2;
			V_Bullet[0].m_Y = V_Tank[0].m_Y;
		}
		WriteChar(V_Bullet[0].m_X, V_Bullet[0].m_Y, "⊙", 0x02);
	}
	break;
	default:
		break;
	}
	V_Tank[0].Show();
	V_Tank[0].UpdatePos();
	return V_Tank[0].m_Direction;
}

int BASE::Get2UserInput(int Dir)
{
	switch (Dir)
	{
	case 72:
	{
		V_Tank[1].CleanTank();
		if (V_Tank[1].m_Direction == UP && g_Map[V_Tank[1].m_X][V_Tank[1].m_Y - 2] == 空地
			&& g_Map[V_Tank[1].m_X - 1][V_Tank[1].m_Y - 2] == 空地
			&& g_Map[V_Tank[1].m_X + 1][V_Tank[1].m_Y - 2] == 空地)
		{
			V_Tank[1].m_Y--;
		}
		else
		{
			V_Tank[1].m_Direction = UP;
		}
	}
	break;

	case 80:
	{
		V_Tank[1].CleanTank();
		if (V_Tank[1].m_Direction == DOWN && g_Map[V_Tank[1].m_X][V_Tank[1].m_Y + 2] == 空地 && g_Map[V_Tank[1].m_X - 1][V_Tank[1].m_Y + 2] == 空地 && g_Map[V_Tank[1].m_X + 1][V_Tank[1].m_Y + 2] == 空地)
		{
			V_Tank[1].m_Y++;
		}
		else
		{
			V_Tank[1].m_Direction = DOWN;
		}
	}
	break;

	case 75:
	{
		V_Tank[1].CleanTank();
		if (V_Tank[1].m_Direction == LEFT && g_Map[V_Tank[1].m_X - 2][V_Tank[1].m_Y] == 空地
			&& g_Map[V_Tank[1].m_X - 2][V_Tank[1].m_Y + 1] == 空地
			&& g_Map[V_Tank[1].m_X - 2][V_Tank[1].m_Y - 1] == 空地)
		{
			V_Tank[1].m_X--;
			V_Tank[1].m_Direction = LEFT;
		}
		else
		{
			V_Tank[1].m_Direction = LEFT;
		}
	}
	break;

	case 77:
	{
		V_Tank[1].CleanTank();
		if (V_Tank[1].m_Direction == RIGHT && g_Map[V_Tank[1].m_X + 2][V_Tank[1].m_Y] == 空地
			&& g_Map[V_Tank[1].m_X + 2][V_Tank[1].m_Y + 1] == 空地
			&& g_Map[V_Tank[1].m_X + 2][V_Tank[1].m_Y - 1] == 空地)
		{
			V_Tank[1].m_X++;
			V_Tank[1].m_Direction = RIGHT;
		}
		else
		{
			V_Tank[1].m_Direction = RIGHT;
		}
	}
	break;

	case 'n':case 'N':
	{
		Biu();
		V_Bullet[1].m_HP = 1;
		V_Bullet[1].m_Direction = V_Tank[1].m_Direction;
		if (V_Bullet[1].m_Direction == UP && g_Map[V_Tank[1].m_X][V_Tank[1].m_Y - 2] != 铁墙)
		{
			V_Bullet[1].m_X = V_Tank[1].m_X;
			V_Bullet[1].m_Y = V_Tank[1].m_Y - 2;
		}
		else if (V_Bullet[1].m_Direction == DOWN && g_Map[V_Tank[1].m_X][V_Tank[1].m_Y + 2] != 铁墙)
		{
			V_Bullet[1].m_X = V_Tank[1].m_X;
			V_Bullet[1].m_Y = V_Tank[1].m_Y + 2;
		}
		else if (V_Bullet[1].m_Direction == LEFT && g_Map[V_Tank[1].m_X - 2][V_Tank[1].m_Y] != 铁墙)
		{
			V_Bullet[1].m_X = V_Tank[1].m_X - 2;
			V_Bullet[1].m_Y = V_Tank[1].m_Y;
		}
		else if (V_Bullet[1].m_Direction == RIGHT && g_Map[V_Tank[1].m_X + 2][V_Tank[1].m_Y] != 铁墙)
		{
			V_Bullet[1].m_X = V_Tank[1].m_X + 2;
			V_Bullet[1].m_Y = V_Tank[1].m_Y;
		}
		WriteChar(V_Bullet[1].m_X, V_Bullet[1].m_Y, "⊙", 0x02);
	}
	break;
	//case'p':
	//{
	//	_getch();
	//	while (_getch() != 'p')			//如果输入的是p，那么就继续游戏，如果不是,则一直在循环里判断是否是'p'.
	//	{
	//		continue;
	//	}
	//}
	break;
	default:
		break;
	}
	V_Tank[1].Show();
	V_Tank[1].UpdatePos();
	return V_Tank[1].m_Direction;
}

bool BASE::SaveInfo(char level)
{
	FILE * pf;
	char szBuf[100] = { 0 };
	sprintf(szBuf, "Level_%d", level);
	errno_t err = fopen_s(&pf, szBuf, "wb+");
	if (err)
	{
		MessageBox(0, L"保存文件失败", L"错误", MB_OKCANCEL);
		return false;
	}
	//***保存地图***
	fwrite(g_Map, sizeof(char), 42 * 42, pf);
	MessageBox(0, L"保存地图成功", L"提示", MB_OKCANCEL);

	//保存vector坦克里的坦克数量
	int SizeTank = V_Tank.size();
	fwrite(&SizeTank, sizeof(int), 1, pf);
	MessageBox(0, L"保存坦克数量成功", L"提示", MB_OKCANCEL);

	//***保存Vector坦克里的每个坦克对象***
	for (int i = 0; i < V_Tank.size(); ++i)
	{
		fwrite(&V_Tank[i], sizeof(V_Tank[i]), 1, pf);
	}
	MessageBox(0, L"保存坦克对象成功", L"提示", MB_OKCANCEL);

	//保存vector子弹里的子弹数量
	int SizeBullet = V_Bullet.size();
	fwrite(&SizeBullet, sizeof(int), 1, pf);
	MessageBox(0, L"保存子弹数量成功", L"提示", MB_OKCANCEL);

	//***保存Vector子弹里的每个子弹对象
	for (int i = 0; i < V_Bullet.size(); ++i)
	{
		fwrite(&V_Bullet[i], sizeof(V_Bullet[i]), 1, pf);
	}
	MessageBox(0, L"保存子弹对象成功", L"提示", MB_OKCANCEL);
	fclose(pf);
	return true;
}

bool BASE::ReadInfo(char level)
{
	TANK  TempTank;
	BULLET TempBullet;

	const char* TempFigure[4][3][4] =
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

	memmove(TempTank.Tank_Figure, TempFigure, sizeof(TempFigure));

	FILE * pf;
	char szBuf[100] = { 0 };
	sprintf(szBuf, "Level_%d", level);
	errno_t err = fopen_s(&pf, szBuf, "rb");
	if (err)
	{
		MessageBox(0, L"读取文件失败", L"错误", MB_OKCANCEL);
		return false;
	}
	//读取地图
	fread(g_Map, sizeof(char), 42 * 42, pf);
	MessageBox(0, L"读取地图成功", L"提示", MB_OKCANCEL);

	//读取坦克的数量
	int SizeTank = 0;
	fread(&SizeTank, sizeof(int), 1, pf);
	MessageBox(0, L"读取坦克数量成功", L"提示", MB_OKCANCEL);

	//将每个临时坦克对象 推进 到  vector坦克数组里去
	for (int i = 0; i < SizeTank; ++i)
	{
		fread(&TempTank, sizeof(TANK), 1, pf);
		V_Tank.push_back(TempTank);
	}
	MessageBox(0, L"临时坦克对象推进vector成功", L"提示", MB_OKCANCEL);

	//读取子弹的数量
	int SizeBullet = 0;
	fread(&SizeBullet, sizeof(int), 1, pf);
	MessageBox(0, L"读取子弹数量成功", L"提示", MB_OKCANCEL);

	//将每个临时子弹对象 推进到 vector子弹数组里去
	for (int i = 0; i < SizeBullet; ++i)
	{
		fread(&TempBullet, sizeof(BULLET), 1, pf);
		V_Bullet.push_back(TempBullet);
	}
	MessageBox(0, L"临时子弹对象推进vector成功", L"提示", MB_OKCANCEL);

	//关闭文件
	fclose(pf);
	//打印地图和元素
	for (int i = 0; i < Map_X; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (g_Map[i][j] == 空地)
			{
				WriteChar(i, j, "  ");
			}
			else if (g_Map[i][j] == 铁墙)
			{
				WriteChar(i, j, "※");
			}
			else if (g_Map[i][j] == 土墙)
			{
				WriteChar(i, j, "□");
			}
			else if (g_Map[i][j] == 泥石流)
			{
				WriteChar(i, j, "卍");
			}
			else
				g_Map[i][j] = 空地;
		}
	}
	WriteChar(19, 38, "◣★◢", 0x04);
	WriteChar(19, 39, "███", 0x04);
	WriteChar(19, 40, "◢█◣", 0x04);
	MessageBox(0, L"画好地图了", L"成功", MB_OKCANCEL);
	return true;
}
//***存档***
void BASE::SaveMap(char level)
{
	FILE * pf;
	char szBuf[100] = { 0 };
	sprintf(szBuf, "Level_%d", level);
	errno_t err = fopen_s(&pf, szBuf, "w+");
	if (err)
	{
		MessageBox(0, L"保存文件失败", L"错误", MB_OKCANCEL);
		return;
	}
	fwrite(g_Map, sizeof(char), 42 * 42, pf);

	MessageBox(0, L"保存成功", L"成功", MB_OKCANCEL);
	fclose(pf);
}
//***读档***
void BASE::ReadMap(char level)
{
	FILE * pf;
	char szBuf[100] = { 0 };
	sprintf(szBuf, "Level_%d", level);
	errno_t err = fopen_s(&pf, szBuf, "r");
	if (err)
	{
		MessageBox(0, L"读取文件失败", L"错误", MB_OKCANCEL);
		MessageBox(0, L"或者不够地图了e", L"错误", MB_OKCANCEL);
		return;
	}
	//扫描文件
	fread(g_Map, sizeof(char), 42 * 42, pf);

	//关闭文件
	fclose(pf);
	//打印地图和元素
	for (int i = 0; i < Map_X; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (g_Map[i][j] == 空地)
			{
				WriteChar(i, j, "  ");
			}
			else if (g_Map[i][j] == 铁墙)
			{
				WriteChar(i, j, "※");
			}
			else if (g_Map[i][j] == 土墙)
			{
				WriteChar(i, j, "□");
			}
			else if (g_Map[i][j] == 泥石流)
			{
				WriteChar(i, j, "卍");
			}
			else
				g_Map[i][j] = 空地;
		}
	}
	WriteChar(19, 38, "◣★◢", 0x04);
	WriteChar(19, 39, "███", 0x04);
	WriteChar(19, 40, "◢█◣", 0x04);
	MessageBox(0, L"读取成功", L"成功", MB_OKCANCEL);
}
//***自定义地图***
void BASE::MessageLoop()
{
	DrawMap();
	WriteChar(52, 5, "编辑地图", 0x02);
	WriteChar(44, 10, "铁墙: ※  左键单击", 0x02);
	WriteChar(44, 14, "土墙: □  右键单击", 0x02);
	WriteChar(44, 22, "泥石流: 卍  滚轮单击", 0x03);
	WriteChar(44, 26, "擦除:	 滚轮滑动", 0x02);
	HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	GetConsoleMode(hStdIn, &dwRead);
	SetConsoleMode(hStdIn, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | dwRead);
	while (1)
	{
		ReadConsoleInput(hStdIn, &stcRecord, 1, &dwRead);
		if (stcRecord.EventType == KEY_EVENT)					//如果是键盘事件,输入了上方向,就回到外面执行保存
		{
			if (stcRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
				break;
		}
		else if (stcRecord.EventType == MOUSE_EVENT)			//如果是鼠标点击事件
		{
			MouseEventProc(stcRecord.Event.MouseEvent);
		}
	}
	WriteChar(42, 30, "输入:");
	MessageBox(0, L"右下角输入你要存的挡位数字", L"提示", MB_OKCANCEL);
	int Stage = 0;
	scanf("%d", &Stage); getchar();
	SaveMap(Stage);
}



BASE::BASE()
{
}
BASE::~BASE()
{
}
