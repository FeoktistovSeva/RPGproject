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

	
	//���������� ��������� � ���� ����
	int startG;
	int slojnost = 1;
    bool a = false;

	//���������� ��������� � �������
    const int nameSIZE = 100;
	float PlayerLVL = 1;
	int PlayerHP = PlayerLVL * 10;
	char Plname[nameSIZE];
	int AtakOrHP = 0;
	int PlayerAttak;
	bool nextUroven = false;
	
	//���������� ��������� � �������
	float EnemyLVL = 1;
	int enemyHP = 0;


	//���������� ��������� � ����������
	int miniHeal = 0;
	int BigHeal = 0;
	int AttakBust = 0;



	cout << "\t�������� 1 ����� ������";
	cout << endl;
	cout << "\t�������� 2 ����� ������� ���������";
	cout << endl;
	cout << "\t�������� 3 ����� �����";

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
		cout << "\t����� ������ ���������";
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

	//����������� ��������� ����, � ���� ������
	EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
	enemyHP = HPvrag(enemyHP, EnemyLVL);


	if (startG == 1)
	{
		a = true;
	}



	if(a = true)
	{
		cout << "\t��� ��� ��������: ";
		cin >> Plname;
	}
	system("cls");



	cout << "\t����� ����������, " << Plname << "!";
	Sleep(1700);
	system("cls");

	

	cout << "\t� ";
	Sleep(100);
	cout << '�';
	Sleep(100);
	cout << '�';
	Sleep(100);
	cout << "� ";
	Sleep(500);
	cout << '�';
	Sleep(100);
	cout << "� ";
	Sleep(100);
	cout << '�';
	Sleep(100);
	cout << '�';
	Sleep(100);
	cout << "� ";
	Sleep(100);
	cout << '�';
	Sleep(100);
	cout << '�';
	Sleep(100);
	cout << '�';
	Sleep(100);
	cout << '�';
	Sleep(100);
	cout << '�';
	Sleep(100);
	cout << '�';

	nextUroven = true;


	Sleep(1300);
	system("cls");





	PlayerAttak = (PlayerLVL * 3) / 2;

	//���
	while (true)
	{
		for (;enemyHP > PlayerAttak;)
		{
	      system("cls");
	      enemyHP = FightGO(AtakOrHP, enemyHP, PlayerLVL);

  
	      fight_menu_cout(enemyHP, Plname, PlayerHP, AtakOrHP);
		  cout << endl << "��� �������: " << PlayerLVL << "\t     ������� �����: " << EnemyLVL;
	      cout << endl << "\t       ����: ";
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

		cout << "\t ���� ��������!";
		Sleep(800);
		system("cls");
		cout << "\t ��� ��� �� �����.";
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