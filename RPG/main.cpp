#include <iostream>
#include <cctype>
#include <ctime>
#include <windows.h>
#include <cstring>
#include <cstdlib>
#include "Header.h"


using namespace std;




int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));


	//���� ����
	int startG;
	int slojnost = 1;
	bool a = false;

	//�����
	const int nameSIZE = 100;
	float PlayerLVL = 1;
	int PlayerHP = PlayerLVL * 10;
	char Plname[nameSIZE];
	int AtakOrHP = 0;
	int PlayerAttak;
	bool nextUroven = false;

	//����
	float EnemyLVL = 1;
	unsigned enemyHP = 0;
	int enemyChange;
	int miss = 0;


	//�������
	unsigned shop = 0;
	unsigned ChangeShop;
	unsigned money;



	//���������
	int miniHeal = 2;
	int BigHeal = 1;
	int AttakBust = 1;

	int RandItem = 0;



	cout << "\t������� 1 ����� ������ ����";
	cout << endl;
	cout << "\t������� 2 ����� ������� ��������� ���������";
	cout << endl;
	cout << "\t������� 3 ����� �����";

	cout << endl << endl;
	cout << "����: ";
	cin >> startG;

	system("cls");



	if (startG == 3)
	{
		exit(0);
	}
	else if (startG == 2)
	{
		cout << "\t�������� ���������: ";
		cout << endl;
		cout << "\t      1.Easy";
		cout << endl;
		cout << "\t      2.normal";
		cout << endl;
		cout << "\t      3.hard";


		cout << endl << endl;
		cout << "����: ";
		cin >> slojnost;
		system("cls");
		a = true;
	}

	//îïðåäåëåíèå ñëîæíîñòè èãðû, è ñèëû âðàãîâ
	EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
	enemyHP = HPvrag(enemyHP, EnemyLVL);
	int MAXenemyHP = enemyHP;

	if (startG == 1)
	{
		a = true;
	}



	if (a = true)
	{
		cout << "\t������� ���: ";
		cin >> Plname;
	}
	system("cls");



	cout << "\t����� ����������, " << Plname << "!";
	Sleep(1700);
	system("cls");



	cout << "\t�� ��� ������!";

	

	Sleep(1300);
	system("cls");





	PlayerAttak = (PlayerLVL * 3) / 2;

	//���
	while (true)
	{
		MAXenemyHP = HPvrag(enemyHP, EnemyLVL);
		for (; enemyHP > PlayerAttak;)
		{







			system("cls");
			enemyHP = FightGO(AtakOrHP, enemyHP, PlayerLVL, PlayerAttak, miss);




			fight_menu_cout(enemyHP, Plname, PlayerHP, AtakOrHP);


			cout << endl << "\t\t��� �������: " << PlayerLVL << "\t     ������� �����: " << EnemyLVL;
			cout << endl << "\t\t\t       ����: ";

			

			cin >> AtakOrHP;

			RandItem = rand() % 10;

			if (AtakOrHP == 2)
			{
				int change = InventoryPrint(miniHeal, BigHeal, AttakBust, AtakOrHP);


				if (change == 1 && miniHeal != 0)
				{
					PlayerHP += 5;
					miniHeal--;
				}
				else if (change == 2 && BigHeal != 0)
				{
					PlayerHP += 15;
					BigHeal--;
				}
				else if (change == 3 && AttakBust != 0)
				{
					if (change == 3 && AttakBust != 0)
					{
						AttakBust--;
						PlayerAttak += 3;
					}
				}
				else if (change == 4)
				{
					AtakOrHP = 0;
				}
				else
				{
					system("cls");
					cout << "\t������!";
					Sleep(500);
					AtakOrHP = 0;
				}

			}

			//�������� �����
			enemyChange = rand() % 10;
			system("cls");
			cout << "\t��� ����������...";
			Sleep(500);


			if (enemyChange > 5 && enemyHP < MAXenemyHP - 5)
			{
				cout << "\n\t���� �������";
				enemyHP += 5;
				Sleep(700);
			}
			else
			{
				cout << "\n\t���� �������";
				PlayerHP -= (EnemyLVL / 2) + 0.5;
				Sleep(600);
				cout << "\n\t���� ������� " << (EnemyLVL / 2) + 0.5 << " �����";
				cout << "\n\t������ � ��� " << PlayerHP << " �������";
				Sleep(700);

				if (PlayerHP == 0)
				{
					system("cls");
					cout << "\n\t\t" << Plname << " �����!";
					exit(0);
				}

			}

		}




	}


	system("cls");
	PlayerLVL += EnemyLVL / 5;
	PlayerHP = PlayerLVL * 10;

	cout << "\t ������!";
	Sleep(800);
	system("cls");
	cout << "\t �� ��� �� �����";
	Sleep(300);
	cout << '.';
	Sleep(300);
	cout << '.';


	Sleep(700);




	EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
	enemyHP = HPvrag(enemyHP, EnemyLVL);
	PlayerAttak = (PlayerLVL * 3) / 2;



	//��������� ���������� �������� � 30% ������
	if (RandItem <= 3 && RandItem != 0)
	{
		if (RandItem == 1)
		{
			miniHeal++;
		}
		else if (RandItem == 2)
		{
			BigHeal++;
		}
		else if (RandItem == 3)
		{
			AttakBust++;
		}
	}


	if (shop > 5)
	{
		PrintShop();
		cout << "\n����:";
		cin >> ChangeShop;
		if (ChangeShop == 1 && money >= 5)
		{
			miniHeal++;
			money -= 5;
			shop = 0;
		}
		if (ChangeShop == 2 && money >= 15)
		{
			BigHeal++;
			money -= 15;
			shop = 0;
		}
		if (ChangeShop == 3 && money >= 10)
		{
			AttakBust++;
			money -= 10;
			shop = 0;
		}
		if (ChangeShop == 4)
		{
			shop = 0;
		}
		else
		{
			system("cls");
			cout << "������!";
			shop = 5;
		}
	}


	return 0;
}










	


