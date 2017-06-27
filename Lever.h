#include "Tile.h"
#include "Active.h"

#ifndef LEVER_H
#define LEVER_H


class Lever : public Active
{
public:
    Lever(Character* c);
    void print() override;
    void onLeave(Tile* toTile) override;
    void onEnter(Tile* fromTile, Character* c) override;
    bool isAccessable() override;
private:

};

#endif /* LEVER_H */

