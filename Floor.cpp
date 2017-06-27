
using namespace std;
#include <iostream>

#include "Floor.h"
#include "Tile.h"
#include "Character.h"
#include "Item.h"



Floor::Floor(Character* c) : Tile(c) {
    Tile::setCharacter(c);
    Floor::p_item = 0;
}

void Floor::onEnter(Tile* fromTile, Character* c) {
    Tile::setCharacter(c);
    if (p_item != 0) {
        c->addItem(p_item);
        p_item = 0;
    }
}

void Floor::onLeave(Tile* toTile) {
    Character* temp = Tile::getCharacter();
    setCharacter(0);
    Tile* tempTile = this;
    toTile->onEnter(tempTile, temp);
}

void Floor::print() {
    if (Tile::hasCharacter()==true) {
        cout << Tile::getCharacter()->geticon();
    }
    else if (p_item != 0) cout << "*";
    else cout << ".";    
}

void Floor::setItem(string itemname) {
    if(itemname == "ArmingSword") p_item = new ArmingSword();
    else if (itemname == "GreatSword") p_item = new GreatSword();
    else if (itemname == "Cub") p_item = new Club();
    else if (itemname == "RapierDagger") p_item = new RapierDagger();
    else if (itemname == "Gambeson") p_item = new Gambeson();
    else if (itemname == "MailArmour") p_item = new MailArmour();
    else if (itemname == "Shield") p_item = new Shield();
    else if (itemname == "FullPlateArmour") p_item = new FullPlateArmour();
    
}

bool Floor::isAccessable() {
    return true;
}