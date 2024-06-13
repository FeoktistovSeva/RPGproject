#include <iostream>
#include <cctype>
#include <ctime>
#include <windows.h>
#include <cstring>
#include <cstdlib>
#include "Header.h"


using namespace std;

void printPlayer();


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	
	//ïåðåìåííûå ñâÿçàííûå ñ ìåíþ èãðû
	int startG;
	int slojnost = 1;
    bool a = false;

	//ïåðåìåííûå ñâÿçàííûå ñ èãðîêîì
    const int nameSIZE = 100;
	float PlayerLVL = 1;
	int PlayerHP = PlayerLVL * 10;
	char Plname[nameSIZE];
	int AtakOrHP = 0;
	int PlayerAttak;
	bool nextUroven = false;
	
	//ïåðåìåííûå ñâÿçàííûå ñ âðàãàìè
	float EnemyLVL = 1;
	unsigned enemyHP = 0;


	//ïåðåìåííûå ñâÿçîííûå ñ èíâåíòàðåì
	int miniHeal = 0;
	int BigHeal = 0;
	int AttakBust = 0;

	int RandItem = 0;



	cout << "\tíàïèøèòå 1 ÷òîáû íà÷àòü";
	cout << endl;
	cout << "\tíàïèøèòå 2 ÷òîáû îòêðûòü íàñòðîéêè";
	cout << endl;
	cout << "\tíàïèøèòå 3 ÷òîáû âûéòè";

	cout << endl << endl;
	cout << "Ââîä: ";
	cin >> startG;

	system("cls");
	


	if (startG == 3)
	{
		exit(0);
	}
	else if (startG == 2)
	{
		cout << "\tÂûáîð óðîâíÿ ñëîæíîñòè";
		cout << endl;
		cout << "\t      1.Easy";
		cout << endl;
		cout << "\t      2.normal";
		cout << endl;
		cout << "\t      3.hard";


		cout << endl << endl;
		cout << "Ââîä: ";
		cin >> slojnost;
		system("cls");
		a = true;
	}

	//îïðåäåëåíèå ñëîæíîñòè èãðû, è ñèëû âðàãîâ
	EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
	enemyHP = HPvrag(enemyHP, EnemyLVL);


	if (startG == 1)
	{
		a = true;
	}



	if(a = true)
	{
		cout << "\têàê âàñ íàçûâàòü: ";
		cin >> Plname;
	}
	system("cls");



	cout << "\täîáðî ïîæàëîâàòü, " << Plname << "!";
	Sleep(1700);
	system("cls");

	

	cout << "\tî ";
	Sleep(100);
	cout << 'í';
	Sleep(100);
	cout << 'å';
	Sleep(100);
	cout << "ò ";
	Sleep(500);
	cout << 'í';
	Sleep(100);
	cout << "à ";
	Sleep(100);
	cout << 'â';
	Sleep(100);
	cout << 'à';
	Sleep(100);
	cout << "ñ ";
	Sleep(100);
	cout << 'í';
	Sleep(100);
	cout << 'à';
	Sleep(100);
	cout << 'ï';
	Sleep(100);
	cout << 'à';
	Sleep(100);
	cout << 'ë';
	Sleep(100);
	cout << 'è';

	nextUroven = true;


	Sleep(1300);
	system("cls");





	PlayerAttak = (PlayerLVL * 3) / 2;

	//áîé
	while (true)
	{
		for (;enemyHP > PlayerAttak;)
		{
	      system("cls");
	      enemyHP = FightGO(AtakOrHP, enemyHP, PlayerLVL, PlayerAttak);

  
	      fight_menu_cout(enemyHP, Plname, PlayerHP, AtakOrHP);
		  cout << endl << "âàø óðîâåíü: " << PlayerLVL << "\t     óðîâåíü âðàãà: " << EnemyLVL;
	      cout << endl << "\t       Ââîä: ";
	      cin >> AtakOrHP;

		  RandItem = 3;//rand() % 10;

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
				 cout << "\tîøèáêà!";
				 Sleep(500);
				 AtakOrHP = 0;
			 }
		  }
		}

		system("cls");
		PlayerLVL += EnemyLVL / 5;
		PlayerHP = PlayerLVL * 10;

		cout << "\t âðàã ïîâåðæåí!";
		Sleep(800);
		system("cls");
		cout << "\t ýòî åùå íå êîíåö.";
		Sleep(300);
		cout << '.';
		Sleep(300);
		cout << '.';


		Sleep(700);
		



		EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
		enemyHP = HPvrag(enemyHP, EnemyLVL);
		PlayerAttak = (PlayerLVL * 3) / 2;



		//âîçìîæíîå ïîëó÷åíèÿ ñëó÷àéíîãî ïðåäìåòà ñ 30% øàíñîì
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

void printPlayer()
{
    cout << "                                 -=+#*=" << '\n';
    cout << "                              :+=:.:**##+" << '\n';
    cout << "                              -+=:  :+**+=== " << '\n';
    cout << "                             :=+-.  .++=:.:--" << '\n';
    cout << "                             -*#***+*##**+==: " << '\n';
    cout << "                             :###**+****++=+" << '\n';
    cout << "                             .######*###*+=+" << '\n';
    cout << "                             :####***##*+++*:-== " << '\n';
    cout << "                           -*=###*+=-+*=+#%%=.:= " << '\n';
    cout << "                    ......:-==+%#*=:.:=#@@%=..=**++==-- " << '\n';
    cout << "                 .:-----:-::..:*%#**+*%%%%#-=****#****++=: " << '\n';
    cout << "              .:::.     ...::..*%#++*%%%%###*********++==-=: " << '\n';
    cout << "            .:-::.:.:..:...:::+*-:.:+**#*#*****##****++=:.:: " << '\n';
    cout << "           .==:.            .::-=...:=+++#***####*******+-.   " << '\n';
    cout << "         .=####*=:            =+     -==+**####****++****++---= " << '\n';
    cout << "         .+%%%%%#*=-:.       =%#.   .+****###****+===+*#%%%%%%#= " << '\n';
    cout << "    .=-:  .-*###+-. :-=--:-+%%+  .   **#####**+++=-=*#%%%##*++: " << '\n';
    cout << "    :**+.   .==:::--:-*%#%%%*-. .:   **#%###%##**+#@%%%@%%#==%# " << '\n';
    cout << "     :-=    :-.   .:#@@%#*++=-::-:...**########*+-%@@@*#%#*+-:=. " << '\n';
    cout << "     -++.   +=-::-#%%%@@#*=======-::-*####**##**+=%#@@@####+:.:.. " << '\n';
    cout << "  ---=+**+=++-:.-%%%%%%##+===+==----=*######****++%%%%%%%#+=++++:. " << '\n';
    cout << "  **#%%%%%*=+-=*%%%%%%%+#*++=--:::--=*#####***++=*+=-#%%%%%%%%#+.. " << '\n';
    cout << " :+*###%##****++*#%%%%- .*+=--:..::-=***##***++==*+  .*%%%%###*+:=:. " << '\n';
    cout << " .+****##%+++######%#-   =*+=-:...::-+******++==+#:   :#%%**+++*++-. " << '\n';
    cout << "  =**####%%#####%%#%-    .**+=-:...:-=++****++++**.   .=##**=---..:. " << '\n';
    cout << "  .=**%%%##**+**#%#-     .++=-:....::=++***+++*=*#=.  .=*##+.  -:.:. " << '\n';
    cout << "    :=*%%#====+**=.      =#*=-:.:-:--=++**#####**#:     :-**-  .--:= " << '\n';
    cout << "      :*#=              .+*+**+*#**+=+**######*#***       .=*-..-=+=-" << '\n';
    cout << "  .:=+++++=-.           =+#: =+#=....-=++*###*-:###*-.     .=*--=**=+" << '\n';
    cout << "  -:..-+**--==:.       -#*#--**%-    .-==+*##-#++%%*##+-.   .*#+=+#*==: " << '\n';
    cout << "       =*+:   :-     :##%#+-+++%:....-==++*##*###%##%*:+=    :##**#**++= " << '\n';
    cout << "       :*+-          +#%%+-:##%##+==+###%#*##%#%#%##%#.       :*#*#**+*-" << '\n';
    cout << "       .*+=         :*#%*--+++==*####%%%%=**#*##==*%%%.       .*##%#+*-" << '\n';
    cout << "        +++         +#*++*#%*####*%%%%%%%=+***++=-+%%%-       .***-#***: " << '\n';
    cout << "        +*+.       :*###%%%%%%%%@%@%@@@@@+****++==*%%%-        -=..+#*#: " << '\n';
    cout << "        =*+:       #%%%%%%%***#@@@@@@@%%*+*******##%%#+        :+++###- " << '\n';
    cout << "        :*+-.     #%%%%*+-:...=@@@@@@#:=*+**####%%%%%#+        .--==-" << '\n';
    cout << "        .**+=     #%#*=-:... .*@@@@@%. .%%#####%%%%%%#*.             " << '\n';
    cout << "         +*+      #**+++++++*#%@@@@%-   #%%%%%%%%%%%#**.             " << '\n';
    cout << "         =*+.      :*%#*=+#%%%%%%%%-    =%%%%%#=-#%%%%#:               " << '\n';
    cout << "         -*+:      :##*+=*##%%%%%%#      #%%%+. .+##+:+=.             " << '\n';
    cout << "         :++:      -##*++*#%%%%%%%*      -%##+---=##*==**.    " << '\n';
}
