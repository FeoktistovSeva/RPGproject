#pragma once

<<<<<<< HEAD
//������� � �������
=======
//çâÿçîíî ñ âðàãàìè
>>>>>>> 96f1a63bc7fd0c0a6a421b98629b3a828eeec3b2
int LVLvrag(const int slojnost, const int PlayerLVL, int EnemyLVL);
int HPvrag(int enemyHP, int EnemyLVL);



<<<<<<< HEAD
//�������� �������
=======
//çâÿçàííî áîåâêîé
>>>>>>> 96f1a63bc7fd0c0a6a421b98629b3a828eeec3b2
void fight_menu_cout(const int enemyHP, const char* Plname, const int PlayerHP, int AtakOrHP);
int FightGO(const int AtakOrHP, int enemyHP, const int PlayerLVL, int PlayerAttak, int miss);
int missPrint(const int miss);

//èíâåíòàðü
int InventoryPrint(int miniHeal, int BigHeal, int AttakBust, const int AtakOrHP, int change = 0);



//èãðîê
void printPlayer();


//firs enemy
void printAssasin();


//skeleton enemy
void printSkleton();

//first dragon boss
void printBossDragon();



//spider enemy
void printSpider();


//�������
void PrintShop();



