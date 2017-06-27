using namespace std;

#include <iostream>
#include "Switch.h"
#include "Tile.h"
#include "Active.h"
#include "Passive.h"

Switch::Switch(Character* c) {
    this->setStatus(false);
    this->setCharacter(c);
}

void Switch::onEnter(Tile* fromTile, Character* c) {
    Tile::setCharacter(c);
    Active::setStatus(true);
    Active::getPassive()->setStatus(true);
}

void Switch::onLeave(Tile* toTile) {
    Character* temp = Tile::getCharacter();
    Tile::setCharacter(0);
    toTile->onEnter(this, temp);
}

void Switch::print() {
    if (Tile::hasCharacter()==true) {
        cout << Tile::getCharacter()->geticon();
    }
    else {
        if (this->getStatus() == true) cout << "!";
        else cout << "?";
    }
}

bool Switch::isAccessable() {
    return true;
}

