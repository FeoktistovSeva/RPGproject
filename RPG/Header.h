#pragma once

//зв€зоно с врагами
int LVLvrag(const int slojnost, const int PlayerLVL, int EnemyLVL);
int HPvrag(int enemyHP, int EnemyLVL);



//зв€занно боевкой
void fight_menu_cout(const int enemyHP, const char* Plname, const int PlayerHP, int AtakOrHP);
int FightGO(const int AtakOrHP, int enemyHP, const int PlayerLVL, int PlayerAttak);

//инвентарь
int InventoryPrint(int miniHeal, int BigHeal, int AttakBust, const int AtakOrHP, int change = 0);
