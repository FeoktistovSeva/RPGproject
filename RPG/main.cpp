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

	
	//переменные связанные с меню игры
	int startG;
	int slojnost = 1;
    bool a = false;

	//переменные связанные с игроком
    const int nameSIZE = 100;
	int PlayerLVL = 1;
	int PlayerHP = PlayerLVL * 10;
	char Plname[nameSIZE];
	int AtakOrHP = 0;
	
	//переменные связанные с врагами
	int EnemyLVL = 1;
	int enemyHP = 0;
	int miss;






	cout << "\tнапишите 1 чтобы начать";
	cout << endl;
	cout << "\tнапишите 2 чтобы открыть настройки";
	cout << endl;
	cout << "\tнапишите 3 чтобы выйти";

	cout << endl << endl;
	cout << "Ввод: ";
	cin >> startG;

	system("cls");
	


	if (startG == 3)
	{
		exit(0);
	}
	else if (startG == 2)
	{
		cout << "\tВыбор уровня сложности";
		cout << endl;
		cout << "\t      1.Easy";
		cout << endl;
		cout << "\t      2.normal";
		cout << endl;
		cout << "\t      3.hard";


		cout << endl << endl;
		cout << "Ввод: ";
		cin >> slojnost;
		system("cls");
		a = true;
	}

	//определение сложности игры, и силы врагов
	LVLvrag(slojnost, PlayerLVL, EnemyLVL);
	HPvrag(enemyHP, EnemyLVL);


	if (startG == 1)
	{
		a = true;
	}



	if(a = true)
	{
		cout << "\tкак вас называть: ";
		cin >> Plname;
	}
	system("cls");



	cout << "\tдобро пожаловать, " << Plname << "!";
	Sleep(1700);
	system("cls");

	

	cout << "\tо ";
	Sleep(100);
	cout << 'н';
	Sleep(100);
	cout << 'е';
	Sleep(100);
	cout << "т ";
	Sleep(500);
	cout << 'н';
	Sleep(100);
	cout << "а ";
	Sleep(100);
	cout << 'в';
	Sleep(100);
	cout << 'а';
	Sleep(100);
	cout << "с ";
	Sleep(100);
	cout << 'н';
	Sleep(100);
	cout << 'а';
	Sleep(100);
	cout << 'п';
	Sleep(100);
	cout << 'а';
	Sleep(100);
	cout << 'л';
	Sleep(100);
	cout << 'и';
	


	Sleep(1300);
	system("cls");


	
	cout << endl << "\t1.Атака" << "    2.лечение";
	cout << endl << "\t       Ввод: ";
	cin >> AtakOrHP;

	//атака
	if (AtakOrHP == 1)
	{
		miss = rand() % 10;
		if (miss > 8)
		{
			cout << "Вы промазоли!";
		}
		else
		{
			enemyHP - (PlayerLVL * 10) / 2;
			cout << "попадание!";
		}
	}

	return 0;
}