#pragma once
#include <iostream>

//������� � �������
int LVLvrag(const int slojnost, const int PlayerLVL, int EnemyLVL);
int HPvrag(int EnemyLVL);




//�������� �������
void fight_menu_cout(const int enemyHP, const char* Plname, const int PlayerHP, int AtakOrHP, int RandEnemyPrint, int bossFIght);
int FightGO(const int AtakOrHP, int enemyHP, const int PlayerLVL, int PlayerAttak, int miss);


//���������
int InventoryPrint(int miniHeal, int BigHeal, int AttakBust, const int AtakOrHP, int change = 0);



//èãðîê
void printKnight();


//firs enemy
void printAssasin();


//skeleton enemy
void printSkeleton();

//first dragon boss
void printBossDragon();



//spider enemy
void printSpider();


//�������
void PrintShop();



//������
void PrintRIP();



