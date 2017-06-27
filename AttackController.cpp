#include "AttackController.h"



AttackController::AttackController(Character* c, Character* t, DungeonMap* m) : Controller(c) {
    Controller::setCharacter(c);
    m_map = m;
    target = t;  
}

int AttackController::move() {
    Position currentpos, newpos;
    target = AttackController::fixedtarget();
    //target = AttackController::isvisible();                                   //LoS funktioniert nicht fürs targeting
    if (target == 0) return 5;
    currentpos = m_map->findCharacter(Controller::getCharacter());
    vector<Position> path = m_map->getPathTo(currentpos, m_map->findCharacter(target));
    newpos = path[path.size()-1];
    if (path.size() == 0) return 5;
    if (newpos.reihe > currentpos.reihe && newpos.spalte < currentpos.spalte) return 1;
    else if (newpos.reihe > currentpos.reihe && newpos.spalte == currentpos.spalte) return 2;
    else if (newpos.reihe > currentpos.reihe && newpos.spalte > currentpos.spalte) return 3;
    else if (newpos.reihe == currentpos.reihe && newpos.spalte < currentpos.spalte) return 4;
    else if (newpos.reihe == currentpos.reihe && newpos.spalte > currentpos.spalte) return 6;
    else if (newpos.reihe < currentpos.reihe && newpos.spalte < currentpos.spalte) return 7;
    else if (newpos.reihe < currentpos.reihe && newpos.spalte == currentpos.spalte) return 8;
    else if (newpos.reihe < currentpos.reihe && newpos.spalte > currentpos.spalte) return 9;
}  

Character* AttackController::fixedtarget() {
    for (int i = 0; i < m_map->hoehe; i++) {
        for (int j = 0; j < m_map->breite; j++) {
            if (m_map->mapdata[i][j]->hasCharacter()) {
                if (m_map->mapdata[i][j]->getCharacter() != Controller::getCharacter()) return m_map->mapdata[i][j]->getCharacter();
            }               
        }
    }
    return 0;
}

Character* AttackController::isvisible() {
    Character* tempc;
    tempc = target;
    Position temppos;
    if (target != 0) {
        if (m_map->hasLineOfSight(m_map->findCharacter(Controller::getCharacter()), m_map->findCharacter(target)))
            return tempc; 
    }
    else {
        for (int i = 0; i < m_map->hoehe; i++) {
            for (int j = 0; j < m_map->breite; j++) {
                temppos.reihe = i;
                temppos.spalte = j;
                if (m_map->mapdata[i][j]->hasCharacter()) {
                    if (m_map->mapdata[i][j]->getCharacter() != Controller::getCharacter()) {
                        if (m_map->hasLineOfSight(m_map->findCharacter(Controller::getCharacter()), temppos)) return m_map->mapdata[i][j]->getCharacter();
                    }
                }
            }
        }
        return 0;
    }
}


char AttackController::geticon() {
    return 'A';
}



