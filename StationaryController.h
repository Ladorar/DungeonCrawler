#include "Controller.h"

#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H

class StationaryController : public Controller
{
public:
    StationaryController(Character* c);
    int move() override;
    char geticon() override;
private:

};

#endif /* STATIONARYCONTROLLER_H */

