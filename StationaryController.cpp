using namespace std;

#include "StationaryController.h"

StationaryController::StationaryController(Character* c): Controller(c) {
    Controller::setCharacter(c);
}

int StationaryController::move() {
    return 5;
}

char StationaryController::geticon() {
    return 'S';
}