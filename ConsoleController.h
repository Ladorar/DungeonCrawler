#include "Controller.h"

#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

class ConsoleController : public Controller
{
public:
    ConsoleController(Character* c);
    int move() override;
    char geticon() override;
private:
};

#endif /* CONSOLECONTROLLER_H */

