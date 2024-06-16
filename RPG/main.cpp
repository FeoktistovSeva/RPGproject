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


	//меню игры
	int startG;
	int slojnost = 1;
	bool a = false;

	//игрок
	const int nameSIZE = 100;
	float PlayerLVL = 1;
	int PlayerHP = PlayerLVL * 10;
	char Plname[nameSIZE];
	int AtakOrHP = 0;
	int PlayerAttak;
	bool nextUroven = false;

	//враг
	float EnemyLVL = 1;
	unsigned enemyHP = 0;
	int enemyChange;
	unsigned enemyAttak = 0;


	//инвентарь
	int miniHeal = 2;
	int BigHeal = 1;
	int AttakBust = 1;

	int RandItem = 0;



	cout << "\tвведите 1 чтобы начать игру";
	cout << endl;
	cout << "\tвведите 2 чтобы открыть настройки сложности";
	cout << endl;
	cout << "\tвведите 3 чтобы выйти";

	cout << endl << endl;
	cout << "ввод: ";
	cin >> startG;

	system("cls");



	if (startG == 3)
	{
		exit(0);
	}
	else if (startG == 2)
	{
		cout << "\tвыберите сложность: ";
		cout << endl;
		cout << "\t      1.Easy";
		cout << endl;
		cout << "\t      2.normal";
		cout << endl;
		cout << "\t      3.hard";


		cout << endl << endl;
		cout << "ввод: ";
		cin >> slojnost;
		system("cls");
		a = true;
	}

	//Г®ГЇГ°ГҐГ¤ГҐГ«ГҐГ­ГЁГҐ Г±Г«Г®Г¦Г­Г®Г±ГІГЁ ГЁГЈГ°Г», ГЁ Г±ГЁГ«Г» ГўГ°Г ГЈГ®Гў
	EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
	enemyHP = HPvrag(enemyHP, EnemyLVL);
	int MAXenemyHP = enemyHP;

	if (startG == 1)
	{
		a = true;
	}



	if (a = true)
	{
		cout << "\tвведите имя: ";
		cin >> Plname;
	}
	system("cls");



	cout << "\tдобро пожаловать, " << Plname << "!";
	Sleep(1700);
	system("cls");



	cout << "\tна вас напали!";

	nextUroven = true;


	Sleep(1300);
	system("cls");





	PlayerAttak = (PlayerLVL * 3) / 2;

	//бой
	while (true)
	{
		MAXenemyHP = HPvrag(enemyHP, EnemyLVL);
		for (; enemyHP > PlayerAttak;)
		{
			enemyAttak++;
			
			




			system("cls");
			enemyHP = FightGO(AtakOrHP, enemyHP, PlayerLVL, PlayerAttak);




			fight_menu_cout(enemyHP, Plname, PlayerHP, AtakOrHP);


			cout << endl << "\t\tваш уровень: " << PlayerLVL << "\t     уровень врага: " << EnemyLVL;
			cout << endl << "\t\t\t       Ввод: ";



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
					cout << "\tошибка!";
					Sleep(500);
					AtakOrHP = 0;
				}

			}


			if (enemyAttak > 0)
			{
				enemyChange = rand() % 10;
				system("cls");
				cout << "\tход противника...";
				Sleep(500);


				if (enemyChange > 5 && enemyHP < MAXenemyHP - 5)
				{
					cout << "\n\tВраг лечится";
					enemyHP += 5;
					Sleep(700);
				}
				else
				{
					cout << "\n\tВраг атакует";
					PlayerHP -= EnemyLVL / 2;
					Sleep(700);

					if (PlayerHP == 0)
					{
						system("cls");
						cout << "\n\t\t" << Plname << " погиб!";
						exit(0);
					}

				}
				enemyAttak--;
			}

			


		}


		system("cls");
		PlayerLVL += EnemyLVL / 5;
		PlayerHP = PlayerLVL * 10;

		cout << "\t Попеда­!";
		Sleep(800);
		system("cls");
		cout << "\t но еще не конец";
		Sleep(300);
		cout << '.';
		Sleep(300);
		cout << '.';


		Sleep(700);




		EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
		enemyHP = HPvrag(enemyHP, EnemyLVL);
		PlayerAttak = (PlayerLVL * 3) / 2;



		//выпадение рандомного предмета с 30% шансом
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

	}







	return 0;

}
