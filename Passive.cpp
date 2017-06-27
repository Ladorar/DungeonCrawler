
#include "Passive.h"

Passive::Passive(): Tile(0) {
    status = false;
}

void Passive::setStatus(bool s) {
    status = s;
}

bool Passive::getStatus() {
    return status;
}


