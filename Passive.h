#include "Tile.h"

#ifndef PASSIVE_H
#define PASSIVE_H

class Passive : public Tile
{
public:
    Passive();
    virtual bool getStatus();
    virtual void setStatus(bool s);
private:
    bool status;

};

#endif /* PASSIVE_H */

