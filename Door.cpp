using namespace std;
#include <iostream>

#include "Door.h"

#include "Tile.h"

Door::Door(Character* c) {
    this->setStatus(false);
    this->setCharacter(c);
}

void Door::onEnter(Tile* fromTile, Character* c) {
    if (Passive::getStatus() == false) {
        this->setCharacter(c);
        onLeave(fromTile);
    }
    else Tile::setCharacter(c);
}

void Door::onLeave(Tile* toTile) {
    Character* temp = Tile::getCharacter();
    setCharacter(0);
    Tile* tempTile = this;
    toTile->onEnter(tempTile, temp);
}

void Door::print() {
    if (Tile::hasCharacter()==true) {
        cout << Tile::getCharacter()->geticon();
    }
    else {
        if (this->getStatus() == true) cout << "/";
        else cout << "X";
    }
    
}

bool Door::isTransparent(){
    if (this->getStatus() == true){
        return true;
    }else{
        return false;
    }
}

bool Door::isAccessable() {
    if (this->getStatus() == true) return true;
    else return false;
}

