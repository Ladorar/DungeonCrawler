#include "Tile.h"
#include "Passive.h"

#ifndef ACTIVE_H
#define ACTIVE_H

class Active : public Tile
{
public:
    Active();
    virtual bool getStatus();
    virtual void setStatus(bool s);
    virtual void setPassive(Passive* p);
    virtual Passive* getPassive();
private:
    bool status;
    Passive* p_passive;
};

#endif /* ACTIVE_H */

