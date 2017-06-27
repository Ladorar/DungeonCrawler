using namespace std;
#include <iostream>

#include "Lever.h"


Lever::Lever(Character* c) {
    this->setStatus(false);
    this->setCharacter(c);
}

void Lever::onEnter(Tile* fromTile, Character* c) {
    Tile::setCharacter(c);
    if (Active::getStatus() == false) {
        Active::setStatus(true);
        Active::getPassive()->setStatus(true);
    }
    else {
        Active::setStatus(false);
        Active::getPassive()->setStatus(false);
    }
}

void Lever::onLeave(Tile* toTile) {
    Character* temp = Tile::getCharacter();
    Tile::setCharacter(0);
    toTile->onEnter(this, temp);
}

void Lever::print() {
    if (Tile::hasCharacter()==true) {
        cout << Tile::getCharacter()->geticon();
    }
    else {
        if (this->getStatus() == true) cout << "!";
        else cout << "?";
    }
}

bool Lever::isAccessable() {
    return true;
}



