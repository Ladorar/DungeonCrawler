using namespace std;
#include <iostream>

#include "ConsoleController.h"

ConsoleController::ConsoleController(Character* c): Controller(c) {
    Controller::setCharacter(c);
}

int ConsoleController::move() {
    int direction;
    cout << "In welche Richtung wollen sie gehen?" << endl;
    cin >> direction;
    return direction;
}

char ConsoleController::geticon() {
    return 'C';
}