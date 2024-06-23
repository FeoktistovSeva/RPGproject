#pragma once
#include <iostream>

//связоно с врагами
int LVLvrag(const int slojnost, const int PlayerLVL, int EnemyLVL);
int HPvrag(int EnemyLVL);




//связанно боевкой
void fight_menu_cout(const int enemyHP, const char* Plname, const int PlayerHP, int AtakOrHP, int RandEnemyPrint, int bossFIght);
int FightGO(const int AtakOrHP, int enemyHP, const int PlayerLVL, int PlayerAttak, int miss);


//инвентарь
int InventoryPrint(int miniHeal, int BigHeal, int AttakBust, const int AtakOrHP, int change = 0);



//ГЁГЈГ°Г®ГЄ
void printKnight();


//firs enemy
void printAssasin();


//skeleton enemy
void printSkeleton();

//first dragon boss
void printBossDragon();



//spider enemy
void printSpider();


//магазин
void PrintShop();



//смэрть
void PrintRIP();



