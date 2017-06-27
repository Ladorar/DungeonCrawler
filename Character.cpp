using namespace std;

#include <iostream>
#include "AttackController.h"
#include "Character.h"
#include "Controller.h"
#include "Item.h"
#include "StationaryController.h"

Character::Character(int str, int stam, char ico, char controltyp, DungeonMap* map) {
    strength = str;
    stamina = stam;
    hitpoints = Character::getMaxHP();
    icon = ico;
    if (controltyp == 'C') control = new ConsoleController(this);
    else if ( controltyp == 'A') control = new AttackController(this, 0, map);
    else control = new StationaryController(this);
}

char Character::geticon() {
    return icon;
}

int Character::move() {
    return control->move();
}

Controller* Character::getController() {
    return control;
}

void Character::setController(Controller* c) {
    control = c;
}

int Character::getstr() {
    int itemstr = 0;
    for (int i = 0; i < inventory.size(); i++) {
        itemstr = itemstr + inventory[i]->modifyStrength(strength);
    }
    return itemstr+strength;
}

int Character::getstam() {
    int itemstam = 0;
    for (int i = 0; i < inventory.size(); i++) {
        itemstam = itemstam + inventory[i]->modifyStamina(stamina);
    }
    return itemstam+stamina;
}

int Character::gethp() {
    return hitpoints;
}

void Character::setstr(int v) {
    strength = v;
}

void Character::setstam(int v) {
    stamina = v;
}

void Character::sethp(int v) {
    hitpoints = v;
}

int Character::getMaxHP() {
    return (20+(Character::getstam()*5));
}

vector<Item*> Character::getInventory() {
    return inventory;
}

void Character::showInfo() {
    cout << "<<<Status des Characters>>>" << endl;
    cout << "Strength: " << Character::getstr() << endl;
    cout << "Stamina: " << Character::getstam() << endl;
    cout << "Hitpoints: " << hitpoints << "/" << Character::getMaxHP() << endl;
}

void Character::addItem(Item* i) {
    inventory.push_back(i);
}

void Character::losehp(int dmg) {
    hitpoints = hitpoints - dmg;
}

void Character::adjusthp() {
    if (hitpoints > Character::getMaxHP()) hitpoints = Character::getMaxHP();
}