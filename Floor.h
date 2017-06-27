#include "Tile.h"

#ifndef FLOOR_H
#define FLOOR_H

class Floor: public Tile
{
public:
    Floor(Character* c);
    void onLeave(Tile *toTile) override;
    void onEnter(Tile* fromTile, Character* c) override;
    void print() override;
    void setItem(string itemname);
    bool isAccessable() override;
private:
    Item* p_item;
    

};

#endif /* FLOOR_H */

