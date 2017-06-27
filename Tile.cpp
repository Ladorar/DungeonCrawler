#include <iostream>
using namespace std;
#include "Tile.h"

Tile::Tile(Character* c) {
    Tile::setCharacter(c);
}

Tile::~Tile() {
    p_character = 0;
}

Character* Tile::getCharacter() {
    return p_character;
}


bool Tile::hasCharacter() {
    if(p_character != 0) return true;
    else return false;
}

void Tile::setCharacter(Character* c) {
    p_character = c;
}

void Tile::onEnter(Tile* fromTile, Character* c) {
    p_character = c;
}

void Tile::onLeave(Tile* toTile) {
    if (toTile->hasCharacter() == false) {
        Character* temp = p_character;
        setCharacter(0);
        toTile->onEnter(this, temp);
    }
    else cout << "Zug nicht möglich" << endl;
}

void Tile::print() {
    cout << "?";
}

bool Tile::isTransparent(){
    return true;
}

bool Tile::isAccessable() {
    return true;
}
