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
	int PlayerLVL = 1;
	int PlayerHP = PlayerLVL * 10;
	char Plname[nameSIZE];
	int AtakOrHP = 0;
	
	//���������� ��������� � �������
	int EnemyLVL = 1;
	int enemyHP = 0;
	int miss;






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
	LVLvrag(slojnost, PlayerLVL, EnemyLVL);
	HPvrag(enemyHP, EnemyLVL);


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
	


	Sleep(1300);
	system("cls");


	
	cout << endl << "\t1.�����" << "    2.�������";
	cout << endl << "\t       ����: ";
	cin >> AtakOrHP;

	//�����
	if (AtakOrHP == 1)
	{
		miss = rand() % 10;
		if (miss > 8)
		{
			cout << "�� ���������!";
		}
		else
		{
			enemyHP - (PlayerLVL * 10) / 2;
			cout << "���������!";
		}
	}

	return 0;
}