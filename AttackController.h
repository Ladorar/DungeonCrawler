#include "Controller.h"
#include "DungeonMap.h"
#include <vector>
using namespace std;

#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H

class AttackController : public Controller
{
public:
    AttackController(Character* c, Character* t, DungeonMap* m);
    int move() override;
    char geticon() override;
    Character* isvisible();
    Character* fixedtarget();
private:
    Character* target;
    DungeonMap* m_map;

};

#endif /* ATTACKCONTROLLER_H */

