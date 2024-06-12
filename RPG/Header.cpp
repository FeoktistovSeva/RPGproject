#include "Header.h"
#include <iostream>
#include <cctype>
#include <ctime>
#include <windows.h>
#include <cstring>
#include <cstdlib>


using namespace std;


int LVLvrag(const int slojnost, const int PlayerLVL,int EnemyLVL)
{
	if (slojnost == 1)
	{
		EnemyLVL = (PlayerLVL)+rand() % ((PlayerLVL + 1) - (PlayerLVL)+1);
	}
	else if (slojnost == 2)
	{
		EnemyLVL = (PlayerLVL)+rand() % ((PlayerLVL + 2) - (PlayerLVL)+1);
	}
	else
	{
		EnemyLVL = (PlayerLVL + 1) + rand() % ((PlayerLVL + 4) - (PlayerLVL + 1) + 1);
	}
	return EnemyLVL;
}

int HPvrag(int enemyHP, int EnemyLVL)
{
	enemyHP = (EnemyLVL * 9) + rand() % (EnemyLVL * 12);
	return enemyHP;
}

void fight_menu_cout(const int enemyHP, const char* Plname, const int PlayerHP, int AtakOrHP)
{
	cout << '\n';

	cout << "\t\tЖизни врага: " << enemyHP << endl << endl;

	cout << "\tЖизни " << Plname << ": " << PlayerHP << endl;

	cout << endl << "\t1.Атака" << "    2.инвентарь";
}

int FightGO(const int AtakOrHP, int enemyHP, const int PlayerLVL)
{
	if (AtakOrHP == 1)
	{
		int miss = rand() % 10;
		if (miss >= 9)
		{
			return enemyHP;
		}
		else
		{
			return enemyHP - (PlayerLVL * 3) / 2;
		}
	}
	return enemyHP;
}

int InventoryPrint(int miniHeal, int BigHeal, int AttakBust, const int AtakOrHP, int change)
{
	if (AtakOrHP == 2)
	{
		system("cls");
		cout << "\t               Инвентарь: " << endl << endl;
		cout << "\t1.Маленькое зелье лечение: " << miniHeal << endl;
		cout << "\t2.Большое зелье лечение: " << BigHeal << endl;
		cout << "\t3.зелье силы: " << AttakBust << endl;
		cout << "\t4.Вернуться к бою" << endl;
		cout << "Ввод: ";
		cin >> change;
	}
	return change;
}

int InventoryUse(int miniHeal, int BigHeal, int AttakBust, int AtakOrHP, int change, int PlayerHP, int PlayerAttak)
{
	if (change == 1 && miniHeal != 0)
	{
		miniHeal--;
		return PlayerHP += 5;
	}
	else if (change == 2 && BigHeal != 0)
	{
		BigHeal--;
		return PlayerHP += 15;
	}
	else if (change == 3 && AttakBust != 0)
	{
		AttakBust--;
		return PlayerAttak += 2;
	}
	else if (change == 4)
	{
		return AtakOrHP = 1;
	}
	else
	{
		system("cls");
		cout << "\tошибка!";
		Sleep(500);
		return AtakOrHP = 1;
	}
	return 0;
}
