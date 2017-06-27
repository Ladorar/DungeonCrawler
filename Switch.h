#include "Active.h"

#ifndef SWITCH_H
#define SWITCH_H

class Switch : public Active
{
public:
    Switch(Character* c);
    void print() override;
    void onLeave(Tile* toTile) override;
    void onEnter(Tile* fromTile, Character* c) override;
    bool isAccessable() override;
private:

};

#endif /* SWITCH_H */

