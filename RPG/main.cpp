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

	int startG;
	int slojnost;

	int PlayerLVL = 0;

	char Plname;
	bool a = false;





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



	cout << "negr";











	return 0;
}