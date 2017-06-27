using namespace std;

#include <iostream>
#include "Trap.h"
#include "Tile.h"


Trap::Trap(Character* c) {
    Passive::setStatus(false);
    Tile::setCharacter(c);
}



void Trap::onEnter(Tile* fromTile, Character* c) {
    Tile::setCharacter(c);
    if (Passive::getStatus() == false) {
        c->losehp(20);
        Passive::setStatus(true);
    }
    
}

void Trap::onLeave(Tile* toTile) {
    Character* temp = Tile::getCharacter();
    setCharacter(0);
    Tile* tempTile = this;
    toTile->onEnter(tempTile, temp);
}

void Trap::print() {
    if (Tile::hasCharacter() == true) {
        cout << Tile::getCharacter()->geticon();
    }
    else if (Passive::getStatus() == true) cout << "T";
    else cout << ".";    
}

bool Trap::isAccessable() {
    return true;
}