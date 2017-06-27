using namespace std;
#include <iostream>

#include "Wall.h"


Wall::Wall(Character* c) : Tile(c) {
    Tile::setCharacter(c);
}

void Wall::onEnter(Tile* fromTile, Character* c) {
    Tile::setCharacter(c);
    onLeave(fromTile);
}

void Wall::onLeave(Tile* toTile) {
    Character* temp = Tile::getCharacter();
    setCharacter(0);
    toTile->onEnter(this, temp);
}

void Wall::print() {
    cout << "#";
}

bool Wall::isTransparent(){
    return false;
}

bool Wall::isAccessable() {
    return false;
}
