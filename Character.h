#include "ConsoleController.h"
#include "vector"
#include "Item.h"
using namespace std;

class DungeonMap;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
    Character(int str, int stam, char ico, char controltyp, DungeonMap* map);
    char geticon();
    int move();
    Controller* getController();
    void setController(Controller* c);
    int getstr();
    int getstam();
    int gethp();
    void setstr(int v);
    void setstam(int v);
    void sethp(int v);
    int getMaxHP();
    void showInfo();
    void addItem(Item* i);
    vector<Item*> getInventory();
    void losehp(int dmg);
    void adjusthp();
private:
    char icon;
    Controller* control;
    int strength;
    int stamina;
    int hitpoints;
    vector<Item*> inventory;
};

#endif /* CHARACTER_H */

