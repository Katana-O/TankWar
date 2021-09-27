#include "BASE.h"



//�ؿ��˵�
int BASE::StageMenu()
{
	ClearScreen();
	WriteChar(Menu_X + 8, Menu_Y + 21, "1.������Ҫ��ʼ�Ĺؿ�", 0x02);
	DrawMenuStar();
	int Stage = 0;
	MessageBox(0, L"�������ֲ��س�:", L"��ʾ", MB_OKCANCEL);
	WriteChar(50, 30, "����: ");
	scanf("%d", &Stage);
	MessageBox(0, L"����ɹ�", L"��ʾ", MB_OKCANCEL);
	return Stage;
}

//�Ƿְ����Ϣ
void BASE::ScoreInfo()
{
	UltraWrite(44, 19, "AI ��", V_Tank[2].m_HP, V_Tank[2].m_Color);
	UltraWrite(44, 22, "AI ��", V_Tank[3].m_HP, V_Tank[3].m_Color);
	UltraWrite(44, 25, "AI ��", V_Tank[4].m_HP, V_Tank[4].m_Color);
	UltraWrite(44, 28, "AI ��", V_Tank[5].m_HP, V_Tank[5].m_Color);
	UltraWrite(44, 31, "���1", V_Tank[0].m_HP, V_Tank[0].m_Color);
	UltraWrite(44, 34, "���2", V_Tank[1].m_HP, V_Tank[1].m_Color);
	UltraWrite(44, 37, "�÷�:", V_Tank[0].m_Point, V_Tank[5].m_Color);
}

void BASE::InitTank()
{
	//���1��̹��
	V_Tank.push_back(TANK(14, 39, UP, 0, 0x02, 0, 999, 1, 0, ���1));
	//���2	
	V_Tank.push_back(TANK(34, 39, UP, 0, 0x03, 0, 999, 0, 1, ���2));
	//AI �� �� �� ��
	V_Tank.push_back(TANK(5, 2, DOWN, 0, 0x04, 0, 5, 0, 1, ����1));
	V_Tank.push_back(TANK(15, 2, DOWN, 0, 0x05, 0, 4, 0, 1, ����2));
	V_Tank.push_back(TANK(25, 2, DOWN, 0, 0x06, 0, 3, 0, 1, ����3));
	V_Tank.push_back(TANK(35, 2, DOWN, 0, 0x07, 0, 2, 0, 1, ����4));
}

void BASE::InitBullet()
{
	//���1���ӵ� �˺�=1 ME=1 STOP=0, HP = 0
	V_Bullet.push_back(BULLET(1, 1, 0, 0, 0x02, �ѷ��ӵ�1));
	//�ڶ�����ҵ��ӵ�
	V_Bullet.push_back(BULLET(1, 1, 0, 0, 0x03, �ѷ��ӵ�2));
	//AI de �ӵ� �˺�=1 ME=0 STOP=0, HP = 0
	V_Bullet.push_back(BULLET(1, 0, 0, 0, 0x04, �з��ӵ�1));
	V_Bullet.push_back(BULLET(1, 0, 0, 0, 0x05, �з��ӵ�2));
	V_Bullet.push_back(BULLET(1, 0, 0, 0, 0x06, �з��ӵ�3));
	V_Bullet.push_back(BULLET(1, 0, 0, 0, 0x07, �з��ӵ�4));
}
//***û��
//int BASE::MainMenu()
//{
//Enter:
//	int Game = 0;
//	DrawWelcomePicture();
//	DrawFirstMenu();
//	DrawMenuStar();
//	char Menu_Selection = 0;
//	WriteChar(50, 30, "�������ֲ��س�:");
//	scanf_s("%c", &Menu_Selection);
//	switch (Menu_Selection)
//	{
//	case '1':  //����Ϸ
//	{
//		int Stage = StageMenu();
//		ClearScreen();
//		ReadMap(Stage);
//		InitTank();
//		InitBullet();
//		Game = 1;
//	}
//	break;
//	case '2':  //�����������Ϸ
//	{
//		ClearScreen();
//		MessageBox(0, L"�������ϷĬ�ϴ���0��", L"��ʾ", MB_OKCANCEL);
//		ReadInfo(0);
//	}
//	break;
//	case '3':  //�༭��ͼ
//	{
//		ClearScreen();
//		MessageLoop();
//		ClearScreen();
//		goto Enter;
//	}
//	break;
//	case '4':   //�˳���Ϸ
//	{
//		exit(0);
//	}
//	case '5':
//	{
//		MessageBox(0, L"�Ժ�Ĺ��ܣ���δ����", L"��ʾ", MB_OKCANCEL);
//	}
//	break;
//	}
//	ScoreBoard();
//	return 0;
//}

//***��Ϸ��ʼ***
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
	WriteChar(50, 30, "�������ֲ��س�:");
	scanf_s("%d", &Menu_Selection);
	switch (Menu_Selection)
	{
	case 1:  //����Ϸ
	{
		ClearScreen();
		Game = 1;
	}
	break;
	case 2:  //�����������Ϸ
		Game = 2;
		break;
	case 3:  //�༭��ͼ
	{
		ClearScreen();
		MessageLoop();
		ClearScreen();
		goto Enter;
	}
	break;
	case 4:   //�˳���Ϸ
		exit(0);
	case 5:   //ѡ��ؿ�
	{
		Stage = StageMenu();
		Game = 5;
	}
	break;
	}


SecondStart:
	static int Map = 1;
	//��ȡ��һ�ص�ͼ
	if (Game == 1)
	{
		ClearScreen();
		InitBullet();
		InitTank();
		ReadMap(Map);
	}
	//��ȡ����Ĵ浵
	else if (Game == 2)
	{
		ClearScreen();
		ReadInfo(0);
	}
	//ָ����ȡ�ڼ��صĵ�ͼ
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
		//��ͣ
		else if (Dir == 'p')
		{
			SaveInfo(0);
			MessageBox(0, L"���浽0�ļ�", L"��ʾ", MB_OKCANCEL);
		}
		else if (Dir == 'k') //�з�ȫ��
		{
			for (int i = 2; i < V_Tank.size(); ++i)
			{
				V_Tank[i].m_HP = 0;
			}
		}
		else if (Dir == 'o') //�ص��ʼ���˵�
		{
			V_Tank.clear();
			V_Bullet.clear();
			ClearScreen();
			goto Enter;
		}
		//�ѷ��ӵ��ٶ�
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
					else if (who == 3)  //������л���
					{
						V_Tank[0].m_HP = 0;
						V_Tank[1].m_HP = 0;
					}
					else if (who == 2) //�ѷ��ӵ������з��ӵ�
					{
						for (int i = 0; i < V_Bullet.size(); ++i)
						{
							for (int j = i; j < V_Bullet.size(); ++j)
							{
								if (V_Bullet[i].m_X == V_Bullet[j].m_X && V_Bullet[i].m_Y == V_Bullet[j].m_Y && V_Bullet[i].m_ID != V_Bullet[j].m_ID)
								{
									//�����ӵ��ڵ�ͼ������
									g_Map[V_Bullet[i].m_X][V_Bullet[i].m_Y] = �յ�;
									WriteChar(V_Bullet[i].m_X, V_Bullet[i].m_Y, "  ");
									MessageBox(0, L"�з��ӵ������ѷ��ӵ�", L"��ʾ", MB_OKCANCEL);
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
		//�з��ƶ��ٶ�
		if (clock() - g >= 100)
		{
			for (int i = 2; i < V_Tank.size(); ++i)
			{
				if (V_Tank[i].m_HP > 0)
				{
					char Rand = V_Tank[i].AIMove();
					if (
						V_Bullet[i].m_HP == 0 && Rand == i-2
						&& g_Map[V_Tank[i].m_X][V_Tank[i].m_Y - 2] != ��ǽ
						&& g_Map[V_Tank[i].m_X][V_Tank[i].m_Y + 2] != ��ǽ
						&& g_Map[V_Tank[i].m_X - 2][V_Tank[i].m_Y] != ��ǽ
						&& g_Map[V_Tank[i].m_X + 2][V_Tank[i].m_Y] != ��ǽ)
					{
						V_Bullet[i].AIFirstBullet(V_Tank[i].m_X, V_Tank[i].m_Y, V_Tank[i].m_Direction);
					}
				}
			}
			g = clock();
		}
		//�з��ӵ��ٶ�
		if (clock() - h >= 60)
		{
			for (int i = 2; i < V_Bullet.size(); ++i)
			{
				if (V_Bullet[i].m_HP > 0)
				{
					char who = V_Bullet[i].AIBulletMovement();
					if (who == 1) //�����з��ӵ������ѷ��ӵ�
					{
						for (int i = 0; i < V_Bullet.size(); ++i)
						{
							for (int j = i; j < V_Bullet.size(); ++j)
							{
								if (V_Bullet[i].m_X == V_Bullet[j].m_X && V_Bullet[i].m_Y == V_Bullet[j].m_Y && V_Bullet[i].m_ID != V_Bullet[j].m_ID)
								{
									//�����ӵ��ڵ�ͼ������
									g_Map[V_Bullet[i].m_X][V_Bullet[i].m_Y] = �յ�;
									WriteChar(V_Bullet[i].m_X, V_Bullet[i].m_Y, "  ");
									MessageBox(0, L"�з��ӵ������ѷ��ӵ�", L"��ʾ", MB_OKCANCEL);
									V_Bullet[i].m_HP = 0;
									V_Bullet[j].m_HP = 0;
									break;
								}	
							}
							break;
						}
					}
					else if (who == 2)  //�����ӵ����е����ӵ�
					{
						for (int i = 0; i < V_Bullet.size(); ++i)
						{
							for (int j = i; j < V_Bullet.size(); ++j)
							{
								if (V_Bullet[i].m_X == V_Bullet[j].m_X && V_Bullet[i].m_Y == V_Bullet[j].m_Y && V_Bullet[i].m_ID != V_Bullet[j].m_ID)
								{
									//�����ӵ��ڵ�ͼ������
									g_Map[V_Bullet[i].m_X][V_Bullet[i].m_Y] = �յ�;
									WriteChar(V_Bullet[i].m_X, V_Bullet[i].m_Y, "  ");
									MessageBox(0, L"�з��ӵ������ѷ��ӵ�", L"��ʾ", MB_OKCANCEL);
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


		//ʵʱ���µļƷְ���Ϣ
		ScoreInfo();

		//�������һ�����ˣ�ѭ����������
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
	//����ǵз����⣬�������һ�ŵ�ͼ
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
		if (V_Tank[0].m_Direction == UP && g_Map[V_Tank[0].m_X][V_Tank[0].m_Y - 2] == �յ�
			&& g_Map[V_Tank[0].m_X - 1][V_Tank[0].m_Y - 2] == �յ�
			&& g_Map[V_Tank[0].m_X + 1][V_Tank[0].m_Y - 2] == �յ�)
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
		if (V_Tank[0].m_Direction == DOWN && g_Map[V_Tank[0].m_X][V_Tank[0].m_Y + 2] == �յ� && g_Map[V_Tank[0].m_X - 1][V_Tank[0].m_Y + 2] == �յ� && g_Map[V_Tank[0].m_X + 1][V_Tank[0].m_Y + 2] == �յ�)
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
		if (V_Tank[0].m_Direction == LEFT && g_Map[V_Tank[0].m_X - 2][V_Tank[0].m_Y] == �յ�
			&& g_Map[V_Tank[0].m_X - 2][V_Tank[0].m_Y + 1] == �յ�
			&& g_Map[V_Tank[0].m_X - 2][V_Tank[0].m_Y - 1] == �յ�)
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
		if (V_Tank[0].m_Direction == RIGHT && g_Map[V_Tank[0].m_X + 2][V_Tank[0].m_Y] == �յ�
			&& g_Map[V_Tank[0].m_X + 2][V_Tank[0].m_Y + 1] == �յ�
			&& g_Map[V_Tank[0].m_X + 2][V_Tank[0].m_Y - 1] == �յ�)
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
		if (V_Bullet[0].m_Direction == UP && g_Map[V_Tank[0].m_X][V_Tank[0].m_Y - 2] != ��ǽ)
		{
			V_Bullet[0].m_X = V_Tank[0].m_X;
			V_Bullet[0].m_Y = V_Tank[0].m_Y - 2;
		}
		else if (V_Bullet[0].m_Direction == DOWN && g_Map[V_Tank[0].m_X][V_Tank[0].m_Y + 2] != ��ǽ)
		{
			V_Bullet[0].m_X = V_Tank[0].m_X;
			V_Bullet[0].m_Y = V_Tank[0].m_Y + 2;
		}
		else if (V_Bullet[0].m_Direction == LEFT && g_Map[V_Tank[0].m_X - 2][V_Tank[0].m_Y] != ��ǽ)
		{
			V_Bullet[0].m_X = V_Tank[0].m_X - 2;
			V_Bullet[0].m_Y = V_Tank[0].m_Y;
		}
		else if (V_Bullet[0].m_Direction == RIGHT && g_Map[V_Tank[0].m_X + 2][V_Tank[0].m_Y] != ��ǽ)
		{
			V_Bullet[0].m_X = V_Tank[0].m_X + 2;
			V_Bullet[0].m_Y = V_Tank[0].m_Y;
		}
		WriteChar(V_Bullet[0].m_X, V_Bullet[0].m_Y, "��", 0x02);
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
		if (V_Tank[1].m_Direction == UP && g_Map[V_Tank[1].m_X][V_Tank[1].m_Y - 2] == �յ�
			&& g_Map[V_Tank[1].m_X - 1][V_Tank[1].m_Y - 2] == �յ�
			&& g_Map[V_Tank[1].m_X + 1][V_Tank[1].m_Y - 2] == �յ�)
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
		if (V_Tank[1].m_Direction == DOWN && g_Map[V_Tank[1].m_X][V_Tank[1].m_Y + 2] == �յ� && g_Map[V_Tank[1].m_X - 1][V_Tank[1].m_Y + 2] == �յ� && g_Map[V_Tank[1].m_X + 1][V_Tank[1].m_Y + 2] == �յ�)
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
		if (V_Tank[1].m_Direction == LEFT && g_Map[V_Tank[1].m_X - 2][V_Tank[1].m_Y] == �յ�
			&& g_Map[V_Tank[1].m_X - 2][V_Tank[1].m_Y + 1] == �յ�
			&& g_Map[V_Tank[1].m_X - 2][V_Tank[1].m_Y - 1] == �յ�)
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
		if (V_Tank[1].m_Direction == RIGHT && g_Map[V_Tank[1].m_X + 2][V_Tank[1].m_Y] == �յ�
			&& g_Map[V_Tank[1].m_X + 2][V_Tank[1].m_Y + 1] == �յ�
			&& g_Map[V_Tank[1].m_X + 2][V_Tank[1].m_Y - 1] == �յ�)
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
		if (V_Bullet[1].m_Direction == UP && g_Map[V_Tank[1].m_X][V_Tank[1].m_Y - 2] != ��ǽ)
		{
			V_Bullet[1].m_X = V_Tank[1].m_X;
			V_Bullet[1].m_Y = V_Tank[1].m_Y - 2;
		}
		else if (V_Bullet[1].m_Direction == DOWN && g_Map[V_Tank[1].m_X][V_Tank[1].m_Y + 2] != ��ǽ)
		{
			V_Bullet[1].m_X = V_Tank[1].m_X;
			V_Bullet[1].m_Y = V_Tank[1].m_Y + 2;
		}
		else if (V_Bullet[1].m_Direction == LEFT && g_Map[V_Tank[1].m_X - 2][V_Tank[1].m_Y] != ��ǽ)
		{
			V_Bullet[1].m_X = V_Tank[1].m_X - 2;
			V_Bullet[1].m_Y = V_Tank[1].m_Y;
		}
		else if (V_Bullet[1].m_Direction == RIGHT && g_Map[V_Tank[1].m_X + 2][V_Tank[1].m_Y] != ��ǽ)
		{
			V_Bullet[1].m_X = V_Tank[1].m_X + 2;
			V_Bullet[1].m_Y = V_Tank[1].m_Y;
		}
		WriteChar(V_Bullet[1].m_X, V_Bullet[1].m_Y, "��", 0x02);
	}
	break;
	//case'p':
	//{
	//	_getch();
	//	while (_getch() != 'p')			//����������p����ô�ͼ�����Ϸ���������,��һֱ��ѭ�����ж��Ƿ���'p'.
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
		MessageBox(0, L"�����ļ�ʧ��", L"����", MB_OKCANCEL);
		return false;
	}
	//***�����ͼ***
	fwrite(g_Map, sizeof(char), 42 * 42, pf);
	MessageBox(0, L"�����ͼ�ɹ�", L"��ʾ", MB_OKCANCEL);

	//����vector̹�����̹������
	int SizeTank = V_Tank.size();
	fwrite(&SizeTank, sizeof(int), 1, pf);
	MessageBox(0, L"����̹�������ɹ�", L"��ʾ", MB_OKCANCEL);

	//***����Vector̹�����ÿ��̹�˶���***
	for (int i = 0; i < V_Tank.size(); ++i)
	{
		fwrite(&V_Tank[i], sizeof(V_Tank[i]), 1, pf);
	}
	MessageBox(0, L"����̹�˶���ɹ�", L"��ʾ", MB_OKCANCEL);

	//����vector�ӵ�����ӵ�����
	int SizeBullet = V_Bullet.size();
	fwrite(&SizeBullet, sizeof(int), 1, pf);
	MessageBox(0, L"�����ӵ������ɹ�", L"��ʾ", MB_OKCANCEL);

	//***����Vector�ӵ����ÿ���ӵ�����
	for (int i = 0; i < V_Bullet.size(); ++i)
	{
		fwrite(&V_Bullet[i], sizeof(V_Bullet[i]), 1, pf);
	}
	MessageBox(0, L"�����ӵ�����ɹ�", L"��ʾ", MB_OKCANCEL);
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
		{"  ��  ", "��  ��", "  ����", "����  "},
		{"�����", "�����", "����  ", "  ���"},
		{"��  ��", "  ��  ", "  ����", "����  "}
	},
	{
		{"������", "���ש�", "���ש�", "���ש�"},
		{"�ǡ��", "�ǡ��", "�����", "�ǡ�"},
		{"���ߩ�", "������", "���ߩ�", "���ߩ�"}
	},
	{
		{"������", "������", "���ר�", "���ש�"},
		{"�ǡ��", "�ǡ��", "����", "����"},
		{"������", "������", "���ߨ�", "���ߩ�"}
	},
	{
		{"�X���[", "�X�j�[", "�X�j�[", "�X�j�["},
		{"�d���g", "�d���g", "�����g", "�d����"},
		{"�^�m�a", "�^���a", "�^�m�a", "�^�m�a"}
	}
	};

	memmove(TempTank.Tank_Figure, TempFigure, sizeof(TempFigure));

	FILE * pf;
	char szBuf[100] = { 0 };
	sprintf(szBuf, "Level_%d", level);
	errno_t err = fopen_s(&pf, szBuf, "rb");
	if (err)
	{
		MessageBox(0, L"��ȡ�ļ�ʧ��", L"����", MB_OKCANCEL);
		return false;
	}
	//��ȡ��ͼ
	fread(g_Map, sizeof(char), 42 * 42, pf);
	MessageBox(0, L"��ȡ��ͼ�ɹ�", L"��ʾ", MB_OKCANCEL);

	//��ȡ̹�˵�����
	int SizeTank = 0;
	fread(&SizeTank, sizeof(int), 1, pf);
	MessageBox(0, L"��ȡ̹�������ɹ�", L"��ʾ", MB_OKCANCEL);

	//��ÿ����ʱ̹�˶��� �ƽ� ��  vector̹��������ȥ
	for (int i = 0; i < SizeTank; ++i)
	{
		fread(&TempTank, sizeof(TANK), 1, pf);
		V_Tank.push_back(TempTank);
	}
	MessageBox(0, L"��ʱ̹�˶����ƽ�vector�ɹ�", L"��ʾ", MB_OKCANCEL);

	//��ȡ�ӵ�������
	int SizeBullet = 0;
	fread(&SizeBullet, sizeof(int), 1, pf);
	MessageBox(0, L"��ȡ�ӵ������ɹ�", L"��ʾ", MB_OKCANCEL);

	//��ÿ����ʱ�ӵ����� �ƽ��� vector�ӵ�������ȥ
	for (int i = 0; i < SizeBullet; ++i)
	{
		fread(&TempBullet, sizeof(BULLET), 1, pf);
		V_Bullet.push_back(TempBullet);
	}
	MessageBox(0, L"��ʱ�ӵ������ƽ�vector�ɹ�", L"��ʾ", MB_OKCANCEL);

	//�ر��ļ�
	fclose(pf);
	//��ӡ��ͼ��Ԫ��
	for (int i = 0; i < Map_X; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (g_Map[i][j] == �յ�)
			{
				WriteChar(i, j, "  ");
			}
			else if (g_Map[i][j] == ��ǽ)
			{
				WriteChar(i, j, "��");
			}
			else if (g_Map[i][j] == ��ǽ)
			{
				WriteChar(i, j, "��");
			}
			else if (g_Map[i][j] == ��ʯ��)
			{
				WriteChar(i, j, "�d");
			}
			else
				g_Map[i][j] = �յ�;
		}
	}
	WriteChar(19, 38, "���嗀", 0x04);
	WriteChar(19, 39, "������", 0x04);
	WriteChar(19, 40, "������", 0x04);
	MessageBox(0, L"���õ�ͼ��", L"�ɹ�", MB_OKCANCEL);
	return true;
}
//***�浵***
void BASE::SaveMap(char level)
{
	FILE * pf;
	char szBuf[100] = { 0 };
	sprintf(szBuf, "Level_%d", level);
	errno_t err = fopen_s(&pf, szBuf, "w+");
	if (err)
	{
		MessageBox(0, L"�����ļ�ʧ��", L"����", MB_OKCANCEL);
		return;
	}
	fwrite(g_Map, sizeof(char), 42 * 42, pf);

	MessageBox(0, L"����ɹ�", L"�ɹ�", MB_OKCANCEL);
	fclose(pf);
}
//***����***
void BASE::ReadMap(char level)
{
	FILE * pf;
	char szBuf[100] = { 0 };
	sprintf(szBuf, "Level_%d", level);
	errno_t err = fopen_s(&pf, szBuf, "r");
	if (err)
	{
		MessageBox(0, L"��ȡ�ļ�ʧ��", L"����", MB_OKCANCEL);
		MessageBox(0, L"���߲�����ͼ��e", L"����", MB_OKCANCEL);
		return;
	}
	//ɨ���ļ�
	fread(g_Map, sizeof(char), 42 * 42, pf);

	//�ر��ļ�
	fclose(pf);
	//��ӡ��ͼ��Ԫ��
	for (int i = 0; i < Map_X; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (g_Map[i][j] == �յ�)
			{
				WriteChar(i, j, "  ");
			}
			else if (g_Map[i][j] == ��ǽ)
			{
				WriteChar(i, j, "��");
			}
			else if (g_Map[i][j] == ��ǽ)
			{
				WriteChar(i, j, "��");
			}
			else if (g_Map[i][j] == ��ʯ��)
			{
				WriteChar(i, j, "�d");
			}
			else
				g_Map[i][j] = �յ�;
		}
	}
	WriteChar(19, 38, "���嗀", 0x04);
	WriteChar(19, 39, "������", 0x04);
	WriteChar(19, 40, "������", 0x04);
	MessageBox(0, L"��ȡ�ɹ�", L"�ɹ�", MB_OKCANCEL);
}
//***�Զ����ͼ***
void BASE::MessageLoop()
{
	DrawMap();
	WriteChar(52, 5, "�༭��ͼ", 0x02);
	WriteChar(44, 10, "��ǽ: ��  �������", 0x02);
	WriteChar(44, 14, "��ǽ: ��  �Ҽ�����", 0x02);
	WriteChar(44, 22, "��ʯ��: �d  ���ֵ���", 0x03);
	WriteChar(44, 26, "����:	 ���ֻ���", 0x02);
	HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	GetConsoleMode(hStdIn, &dwRead);
	SetConsoleMode(hStdIn, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | dwRead);
	while (1)
	{
		ReadConsoleInput(hStdIn, &stcRecord, 1, &dwRead);
		if (stcRecord.EventType == KEY_EVENT)					//����Ǽ����¼�,�������Ϸ���,�ͻص�����ִ�б���
		{
			if (stcRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP)
				break;
		}
		else if (stcRecord.EventType == MOUSE_EVENT)			//�����������¼�
		{
			MouseEventProc(stcRecord.Event.MouseEvent);
		}
	}
	WriteChar(42, 30, "����:");
	MessageBox(0, L"���½�������Ҫ��ĵ�λ����", L"��ʾ", MB_OKCANCEL);
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
