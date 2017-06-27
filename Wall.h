#include "Tile.h"
#include "Character.h"

#ifndef WALL_H
#define WALL_H

class Wall: public Tile
{
public:
    Wall(Character* c);
    void onLeave(Tile *toTile) override;
    void onEnter(Tile* fromTile, Character *c) override;
    void print() override;
    bool isTransparent() override;
    bool isAccessable() override;
private:
};

#endif /* WALL_H */

