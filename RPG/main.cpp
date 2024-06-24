#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "Header.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL)); 
    
    // ����
    int startG;
    int slojnost = 1;
    bool PlameCout = false;

    // �����
    const int nameSIZE = 40;
    float PlayerLVL = 1;
    float PlayerHP = PlayerLVL * 10;
    char Plname[nameSIZE];
    int AtakOrHP = 0;
    int PlayerAttak;
    


    // ����
    float EnemyLVL = 1;
    unsigned enemyHP = 0;
    int enemyChange;
    int miss = 0;

    // �������
    unsigned shop = 0;
    unsigned ChangeShop;
    unsigned money = 0;

    // ���������
    int miniHeal = 2;
    int BigHeal = 1;
    int AttakBust = 1;
    int RandItem = 0;

    //����
    int bossFight = 0;
    unsigned bossLVL;
    unsigned bossHP;




    // ���� ����
    cout << "\t������� 1, ����� ������ ����" << endl;
    cout << "\t������� 2, ����� ������� ��������� ���������" << endl;
    cout << "\t������� 3, ����� �����" << endl;
    cout << "����: ";
    cin >> startG;
    system("cls");

    if (startG == 3) 
    {
        exit(0);
    }
    else if (startG == 2) 
    {
        cout << "\t�������� ���������: " << endl;
        cout << "\t1. Easy" << endl;
        cout << "\t2. Normal" << endl;
        cout << "\t3. Hard" << endl << endl;
        cout << "����: ";
        cin >> slojnost;
        system("cls");
        PlameCout = true;
    }

    else if (startG == 1)
    {
        PlameCout = true;
    }

    if (PlameCout == true)
    {
        cout << "\t������� ���: ";
        cin >> Plname;
    }



    system("cls");
    cout << "\t����� ����������, " << Plname << "!" << endl;
    Sleep(1700);
    system("cls");

    bool Alive = true;
    // ������ ���
    while (Alive) 
    {
        EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
        enemyHP = HPvrag(EnemyLVL);
        int MAXenemyHP = enemyHP;
        cout << "\n\t�� ��� ������!";
        Sleep(1300);
        system("cls");
        PlayerAttak = (PlayerLVL * 3) / 2;
        unsigned RandEnemyPrint = 1 + rand() % 4;

        //����
        if (bossFight == 5)
        {
            bossLVL = EnemyLVL * 2;
            bossHP = enemyHP * 2;

            EnemyLVL = bossLVL;
            enemyHP = bossHP;
        }
        


        // ���
        while (enemyHP > PlayerAttak) 
        {
           
            system("cls");
            enemyHP = FightGO(AtakOrHP, enemyHP, PlayerLVL, PlayerAttak, miss);
            fight_menu_cout(enemyHP, Plname, PlayerHP, AtakOrHP, RandEnemyPrint, bossFight);
            cout << endl << "\t\t��� �������: " << PlayerLVL << "\t������� �����: " << EnemyLVL;
            cout << endl << "\t\t\t ����: ";
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
                    cout << "\t������!";
                    Sleep(500);
                    AtakOrHP = 0;
                }
            }
            // �������� �����
            enemyChange = rand() % 10;
            system("cls");
            cout << "\t��� ����������...";
            Sleep(500);
            if (enemyChange > 5 && enemyHP < MAXenemyHP - 5) 
            {
                cout << "\n\t���� �������";
                enemyHP += 5;
                Sleep(700);
            }
            else 
            {
                cout << "\n\t���� �������";
                cout << "\n\t���� ������� " << (EnemyLVL / 2) + 0.5 << " �����";
                Sleep(600);
                PlayerHP -= (EnemyLVL / 2) + 0.5;
                cout << "\n\t������ � ��� " << PlayerHP << " ������";
                Sleep(700);
                if (PlayerHP <= 0) {
                    Alive = false;
                    system("cls");
                    cout << "\n\t\t\t\t\t\t" << Plname << " �����!";
                    PrintRIP();
                    return 0;
                }
            }
        }

        // ������
        system("cls");
        cout << "\n\t������!" << endl;
        Sleep(800);
        system("cls");
        cout << "\n\t" << Plname << " �������!";
        Sleep(800);
        system("cls");
        cout << "\n\t�� ��� �� �����";
        Sleep(300);
        cout << '.';
        Sleep(300);
        cout << '.';
        Sleep(700);

        shop++;
        bossFight++;

        // ��������� ������ 
        PlayerLVL += EnemyLVL / 5;
        cout << "\n\n\t" << Plname << " ������� � ������� �������! ����� �������: " << PlayerLVL;
        Sleep(800);
        PlayerHP = PlayerLVL * 10;
        money++;
        Sleep(700);
        EnemyLVL = LVLvrag(slojnost, PlayerLVL, EnemyLVL);
        enemyHP = HPvrag(EnemyLVL);
        PlayerAttak = (PlayerLVL * 3) / 2;

        // ��������� ���������� �������� � 30% ������
        if (RandItem <= 3 && RandItem != 0) 
        {
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


        // �������
        if (shop % 5 == 0) 
        {
            PrintShop();
            cout << "\n\t���� ������: " << money;
            cout << "\n����: ";
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
                cout << "\t\t������!\n";
                shop = 5;
            }
        }
    }
    return 0;
}