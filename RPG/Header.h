#pragma once

//������� � �������
int LVLvrag(const int slojnost, const int PlayerLVL, int EnemyLVL);
int HPvrag(int enemyHP, int EnemyLVL);



//�������� �������
void fight_menu_cout(const int enemyHP, const char* Plname, const int PlayerHP, int AtakOrHP);
int FightGO(const int AtakOrHP, int enemyHP, const int PlayerLVL);

//���������
int InventoryPrint(int miniHeal, int BigHeal, int AttakBust, const int AtakOrHP, int change = 0);
int InventoryUse(int miniHeal, int BigHeal, int AttakBust, const int AtakOrHP, int change, int PlayerHP, int PlayerAttak);