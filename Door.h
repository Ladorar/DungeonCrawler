#include "Passive.h"


#ifndef DOOR_H
#define DOOR_H

class Door : public Passive
{
public:
    Door(Character* c);
    void onEnter(Tile* fromTile, Character* c) override;
    void onLeave(Tile* toTile) override;
    void print() override;
    bool isTransparent() override;
    bool isAccessable() override;
private:

};

#endif /* DOOR_H */

