#include "Character.h"

#ifndef TILE_H
#define TILE_H



class Tile
{
public:
    Tile(Character* c);
    virtual ~Tile();
    Character* getCharacter();
    void setCharacter(Character* c);
    bool hasCharacter();
    virtual void onLeave(Tile *toTile) = 0;
    virtual void onEnter(Tile* fromTile, Character *c) = 0;
    virtual void print();
    virtual bool isTransparent();
    virtual bool isAccessable() = 0;
        
private:
    Character* p_character = 0;
};

#endif /* TILE_H */

