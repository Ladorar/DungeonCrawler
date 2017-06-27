

#include "Active.h"

Active::Active(): Tile(0) {
    status = false;
}

bool Active::getStatus() {
    return status;
}

void Active::setStatus(bool s) {
    status = s;
}

void Active::setPassive(Passive* p) {
    p_passive = p;
}

Passive* Active::getPassive() {
    return p_passive;
}