#include "Passive.h"

#ifndef TRAP_H
#define TRAP_H


class Trap : public Passive
{
public:
    Trap(Character* c);
    void onEnter(Tile* fromTile, Character* c) override;
    void onLeave(Tile* toTile) override;
    void print() override;
    bool isAccessable() override;
private:
    

};

#endif /* TRAP_H */

