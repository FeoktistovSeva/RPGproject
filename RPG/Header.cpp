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

	cout << "\t\t\t\t\t\tЖизни врага: " << enemyHP << endl << endl;

	cout << "\t\t\tЖизни " << Plname << ": " << PlayerHP << endl;
	printPlayer();

	cout << endl << "\t\t\t1.Атака" << "    2.инвентарь";
}

int FightGO(const int AtakOrHP, int enemyHP, const int PlayerLVL, int PlayerAttak, int miss)
{
	if (AtakOrHP == 1)
	{
		miss = rand() % 10;
		if (miss >= 9)
		{
			return enemyHP;
		}
		else
		{
			return enemyHP - PlayerAttak;
		}
	}
	return enemyHP;
}





int missPrint(const int miss)
{
	if (miss >= 9)
	{
		system("cls");
		cout << "\n\n\tвраг увернулся!";
	}
	return 0;
}





int InventoryPrint(int miniHeal, int BigHeal, int AttakBust, const int AtakOrHP, int change)
{
	if (AtakOrHP == 2)
	{
		system("cls");
		cout << "\t\t\t               Инвентарь: " << endl << endl;
		cout << "\t\t\t1.Маленькое зелье лечение: " << miniHeal << endl;
		cout << "\t\t\t2.Большое зелье лечение: " << BigHeal << endl;
		cout << "\t\t\t3.зелье силы: " << AttakBust << endl;
		cout << "\t\t\t4.Вернуться к бою" << endl;
		cout << "Ввод: ";
		cin >> change;
	}
	return change;
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

void PrintShop()
{
	system("cls");
	cout << "\tМАГАЗИН";
	cout << "\n\n\t1.маленькое зелье лечение - 5монет";
	cout << "\n\t2.большое зелье лечение - 15монет";
	cout << "\n\t3.зелье силы - 10монет";
	cout << "\n\t  4.выход";
}
