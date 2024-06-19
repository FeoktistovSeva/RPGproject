#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "Header.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL)); // Инициализация переменных
    int startG;
    int slojnost = 1;
    bool a = false;
    // Игрок
    const int nameSIZE = 100;
    float PlayerLVL = 1;
    int PlayerHP = PlayerLVL * 10;
    char Plname[nameSIZE];
    int AtakOrHP = 0;
    int PlayerAttak;
    bool nextUroven = false;
    // Враг
    float EnemyLVL = 1;
    unsigned int enemyHP = 0;
    int enemyChange;
    int miss = 0;
    // Магазин
    unsigned int shop = 0;
    unsigned int ChangeShop;
    unsigned int money = 0;
    // Инвентарь
    int miniHeal = 2;
    int BigHeal = 1;
    int AttakBust = 1;
    int RandItem = 0;
    // Меню игры
    cout << "\tВведите 1, чтобы начать игру" << endl;
    cout << "\tВведите 2, чтобы открыть настройки сложности" << endl;
    cout << "\tВведите 3, чтобы выйти" << endl;
    cout << "Ввод: ";
    cin >> startG;
    system("cls");
    if (startG == 3) {
        exit(0);
    }
    else if (startG == 2) {
        cout << "\tВыберите сложность: " << endl;
        cout << "\t1. Easy" << endl;
        cout << "\t2. Normal" << endl;
        cout << "\t3. Hard" << endl << endl;
        cout << "Ввод: ";
        cin >> slojnost;
        system("cls");
        a = true;
    }
    if (a == true) {
        cout << "\tВведите имя: ";
        cin >> Plname;
    }
    system("cls");
    cout << "\tДобро пожаловать, " << Plname << "!" << endl;
    Sleep(1700);
    system("cls");
    // Начало боя
    while (true) {
        EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
        enemyHP = HPvrag(enemyHP, EnemyLVL);
        int MAXenemyHP = enemyHP;
        cout << "\tНа вас напали!";
        Sleep(1300);
        system("cls");
        PlayerAttak = (PlayerLVL * 3) / 2;
        // Бой
        while (enemyHP > PlayerAttak) {
            shop++;
            system("cls");
            enemyHP = FightGO(AtakOrHP, enemyHP, PlayerLVL, PlayerAttak, miss);
            fight_menu_cout(enemyHP, Plname, PlayerHP, AtakOrHP);
            cout << endl << "\t\tВаш уровень: " << PlayerLVL << "\tУровень врага: " << EnemyLVL;
            cout << endl << "\t\t\t Ввод: ";
            cin >> AtakOrHP;
            RandItem = rand() % 10;
            if (AtakOrHP == 2) {
                int change = InventoryPrint(miniHeal, BigHeal, AttakBust, AtakOrHP);
                if (change == 1 && miniHeal != 0) {
                    PlayerHP += 5;
                    miniHeal--;
                }
                else if (change == 2 && BigHeal != 0) {
                    PlayerHP += 15;
                    BigHeal--;
                }
                else if (change == 3 && AttakBust != 0) {
                    AttakBust--;
                    PlayerAttak += 3;
                }
                else if (change == 4) {
                    AtakOrHP = 0;
                }
                else {
                    system("cls");
                    cout << "\tОшибка!";
                    Sleep(500);
                    AtakOrHP = 0;
                }
            }
            // Действия врага
            enemyChange = rand() % 10;
            system("cls");
            cout << "\tХод противника...";
            Sleep(500);
            if (enemyChange > 5 && enemyHP < MAXenemyHP - 5) {
                cout << "\n\tВраг лечится";
                enemyHP += 5;
                Sleep(700);
            }
            else {
                cout << "\n\tВраг атакует";
                cout << "\n\tВраг наносит " << (EnemyLVL / 2) + 0.5 << " урона";
                Sleep(600);
                PlayerHP -= (EnemyLVL / 2) + 0.5;
                cout << "\n\tТеперь у вас " << PlayerHP << " жизней";
                Sleep(700);
                if (PlayerHP <= 0) {
                    system("cls");
                    cout << "\n\t\t" << Plname << " погиб!";
                    return 0;
                }
            }
        }
        // Победа
        cout << "\tПобеда!" << endl;
        Sleep(800);
        system("cls");
        cout << "\t" << Plname << " выиграл!";
        Sleep(800);
        system("cls");
        cout << "\tНо еще не конец";
        Sleep(300);
        cout << '.';
        Sleep(300);
        cout << '.';
        Sleep(700);
        // Получение уровня и обновление переменных
        PlayerLVL += EnemyLVL / 5;
        cout << "\n\n\t" << Plname << " выиграл и получил уровень! Новый уровень: " << PlayerLVL;
        Sleep(800);
        PlayerHP = PlayerLVL * 10;
        money++;
        Sleep(700);
        EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
        enemyHP = HPvrag(enemyHP, EnemyLVL);
        PlayerAttak = (PlayerLVL * 3) / 2;
        // Выпадение рандомного предмета с 30% шансом
        if (RandItem <= 3 && RandItem != 0) {
            if (RandItem == 1) {
                miniHeal++;
            }
            else if (RandItem == 2) {
                BigHeal++;
            }
            else if (RandItem == 3) {
                AttakBust++;
            }
        }
        // Магазин
        if (shop > 5) {
            PrintShop();
            cout << "\n\tВаши деньги: " << money;
            cout << "\nВвод: ";
            cin >> ChangeShop;
            if (ChangeShop == 1 && money >= 5) {
                miniHeal++;
                money -= 5;
                shop = 0;
            }
            else if (ChangeShop == 2 && money >= 15) {
                BigHeal++;
                money -= 15;
                shop = 0;
            }
            else if (ChangeShop == 3 && money >= 10) {
                AttakBust++;
                money -= 10;
                shop = 0;
            }
            else if (ChangeShop == 4) {
                shop = 0;
            }
            else {
                system("cls");
                cout << "Ошибка!";
                shop = 5;
            }
        }
    }
    return 0;
}