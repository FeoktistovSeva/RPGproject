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
	float PlayerLVL = 1;
	int PlayerHP = PlayerLVL * 10;
	char Plname[nameSIZE];
	int AtakOrHP = 0;
	int PlayerAttak;
	bool nextUroven = false;
	
	//переменные связанные с врагами
	float EnemyLVL = 1;
	int enemyHP = 0;


	//переменные связонные с инвентарем
	int miniHeal = 0;
	int BigHeal = 0;
	int AttakBust = 0;



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
	EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
	enemyHP = HPvrag(enemyHP, EnemyLVL);


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

	nextUroven = true;


	Sleep(1300);
	system("cls");





	PlayerAttak = (PlayerLVL * 3) / 2;

	//бой
	while (true)
	{
		for (;enemyHP > PlayerAttak;)
		{
	      system("cls");
	      enemyHP = FightGO(AtakOrHP, enemyHP, PlayerLVL);

  
	      fight_menu_cout(enemyHP, Plname, PlayerHP, AtakOrHP);
		  cout << endl << "ваш уровень: " << PlayerLVL << "\t     уровень врага: " << EnemyLVL;
	      cout << endl << "\t       Ввод: ";
	      cin >> AtakOrHP;
		  if (AtakOrHP == 2)
		  {
			 int change = InventoryPrint(miniHeal, BigHeal, AttakBust, AtakOrHP);
			 InventoryUse(miniHeal, BigHeal, AttakBust, AtakOrHP, change, PlayerHP, PlayerAttak);
		  }
		  
		  
		}

		system("cls");
		PlayerLVL += EnemyLVL / 5;
		PlayerHP = PlayerLVL * 10;

		cout << "\t враг повержен!";
		Sleep(800);
		system("cls");
		cout << "\t это еще не конец.";
		Sleep(300);
		cout << '.';
		Sleep(300);
		cout << '.';


		Sleep(700);
		



		EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
		enemyHP = HPvrag(enemyHP, EnemyLVL);
		PlayerAttak = (PlayerLVL * 3) / 2;
	}

	return 0;
}