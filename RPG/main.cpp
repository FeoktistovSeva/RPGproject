#include <iostream>
#include <cctype>
#include <ctime>
#include <windows.h>
#include <cstring>
#include <cstdlib>


using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	
	//���������� ��������� � ���� ����
	int startG;
	int slojnost;
    bool a = false;

	//���������� ��������� � �������
    const int nameSIZE = 100;
	int PlayerLVL = 0;
	int PlayerHP = 100;
	char Plname[nameSIZE];
	
	//���������� ��������� � �������
	int EnemyLVL;
	int enemyHP;



	if (slojnost == 1)
	{
		EnemyLVL = (PlayerLVL - 1) + rand() % ((PlayerLVL + 1) - (PlayerLVL - 1) + 1);
	}
	else if (slojnost == 2)
	{
		EnemyLVL = (PlayerLVL) + rand() % ((PlayerLVL + 2) - (PlayerLVL) + 1);
	}
	else
	{
		EnemyLVL = (PlayerLVL + 1) + rand() % ((PlayerLVL + 4) - (PlayerLVL + 1) + 1);
	}






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

	



	return 0;
}