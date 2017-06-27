

#include "Controller.h"

Controller::Controller(Character* c) {
    p_character = c;
}

Character* Controller::getCharacter() {
    return p_character;
}

void Controller::setCharacter(Character* c) {
    p_character = c;
}