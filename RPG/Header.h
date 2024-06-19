#pragma once

<<<<<<< HEAD
//связоно с врагами
=======
//Г§ГўГїГ§Г®Г­Г® Г± ГўГ°Г ГЈГ Г¬ГЁ
>>>>>>> 96f1a63bc7fd0c0a6a421b98629b3a828eeec3b2
int LVLvrag(const int slojnost, const int PlayerLVL, int EnemyLVL);
int HPvrag(int enemyHP, int EnemyLVL);



<<<<<<< HEAD
//связанно боевкой
=======
//Г§ГўГїГ§Г Г­Г­Г® ГЎГ®ГҐГўГЄГ®Г©
>>>>>>> 96f1a63bc7fd0c0a6a421b98629b3a828eeec3b2
void fight_menu_cout(const int enemyHP, const char* Plname, const int PlayerHP, int AtakOrHP);
int FightGO(const int AtakOrHP, int enemyHP, const int PlayerLVL, int PlayerAttak, int miss);
int missPrint(const int miss);

//ГЁГ­ГўГҐГ­ГІГ Г°Гј
int InventoryPrint(int miniHeal, int BigHeal, int AttakBust, const int AtakOrHP, int change = 0);



//ГЁГЈГ°Г®ГЄ
void printPlayer();


//firs enemy
void printAssasin();


//skeleton enemy
void printSkleton();

//first dragon boss
void printBossDragon();



//spider enemy
void printSpider();


//магазин
void PrintShop();



