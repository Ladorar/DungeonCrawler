

#include "GameEngine.h"
#include "DungeonMap.h"
#include "Tile.h"
#include "Character.h"
#include "Active.h"
#include "Floor.h"
#include "Trap.h"

GameEngine::~GameEngine() {
    for (int i = 0; i < m_character.size(); i++) {
        delete m_character[i];
    }
}
GameEngine::GameEngine(int height, int width, const vector<string>& data, const vector<string>& relation)
    :DM(height, width, data) {
    linker(relation);
}

bool GameEngine::finished() {
    if (DM.mapdata[1][1]->hasCharacter()) return true;
    else return false;
}

void GameEngine::turn() {
    DM.print(m_character);
    Position newpos;
    int direction;
    Position temppos;
    Tile* p_currenttile;
    Tile* p_newtile;
    for (int i = 0; i < m_character.size(); i++) {
        m_character[i]->adjusthp();
        direction = m_character[i]->move();
        temppos = DM.findCharacter(m_character[i]);
        newpos = temppos;
        p_currenttile = DM.findTile(temppos);
        switch (direction)
        {
        case 1: newpos.reihe++;
            newpos.spalte--;
            break;
        case 2: newpos.reihe++;
            break;
        case 3: newpos.reihe++;
            newpos.spalte++;
            break;
        case 4: newpos.spalte--;
            break;
        case 5: newpos.reihe = newpos.reihe;
            newpos.spalte = newpos.spalte;
            break;
        case 6: newpos.spalte++;
            break;
        case 7: newpos.reihe--;
            newpos.spalte--;
            break;
        case 8: newpos.reihe--;
            break;
        case 9: newpos.reihe--;
            newpos.spalte++;
            break;
        case 0: menu();
            return;
            break;
        default: return;
        break;
        }
        p_newtile = DM.findTile(newpos);
        if (p_newtile->hasCharacter() == false || p_newtile->getCharacter() == m_character[i]) p_currenttile->onLeave(p_newtile);
        else fight(m_character[i], p_newtile);
        
    }
}

void GameEngine::linker(const vector<string>& relation) {
    DungeonMap* map;
    map = &DM;
    Passive* passive;
    Active* active;
    Position pas;
    Position act;
    Position charac;
    char symb;
    int str;
    int stam;
    char controltyp;
    int counter = 0;
    int spos;
    string items;
    Position itempos;
    Floor* flooritem;
    for (int i = 0; i < relation.size(); i++) {
        if (static_cast<char> (relation[i].at(0)) == 'D') {
            
            pas.reihe = static_cast<int> (relation.at(i).at(1)) - 48;
            pas.spalte = static_cast<int> (relation.at(i).at(2)) - 48;
            passive = dynamic_cast<Passive*> (DM.findTile(pas));
            for (int j = 3; j <relation.at(i).size(); j=j+3) {
                if (static_cast<char> (relation[i].at(j)) == 'S') {
                    act.reihe = static_cast<int> (relation.at(i).at(j+1)) -48;
                    act.spalte = static_cast<int> (relation.at(i).at(j+2)) -48;
                    active = dynamic_cast<Active*> (DM.findTile(act));
                    active->setPassive(passive);
                }
                else {
                    act.reihe = static_cast<int> (relation.at(i).at(j+1)) -48;
                    act.spalte = static_cast<int> (relation.at(i).at(j+2)) -48;
                    delete[] DM.mapdata[act.reihe][act.spalte];
                    DM.mapdata[act.reihe][act.spalte] = new Trap(0);
                    active = dynamic_cast<Active*> (DM.findTile(act));
                    active->setPassive(passive);
                }
            }
        }
        else if (static_cast<char> (relation[i].at(0) == 'C')) {
            symb = relation[i].at(1);
            str = static_cast<int> (relation[i].at(2)) - 48;
            stam = static_cast<int> (relation[i].at(3)) - 48;
            controltyp = relation[i].at(4);
            charac.reihe = static_cast<int> (relation[i].at(5)) - 48;
            charac.spalte = static_cast<int> (relation[i].at(6)) - 48;
            m_character.push_back(new Character(str, stam, symb, controltyp, map));
            DM.mapdata[charac.spalte][charac.reihe]->setCharacter(m_character[counter]);
            counter++;
            if (controltyp == 'C') DM.PCcounter++;
        }
        else if (static_cast<char> (relation[i].at(0) == 'T')) {
            pas.reihe = static_cast<int> (relation[i].at(1)) - 48;
            pas.spalte = static_cast<int> (relation[i].at(2)) - 48;
            Tile* temp = DM.findTile(pas);
            delete temp;
            DM.mapdata[pas.spalte][pas.reihe] = new Trap(0);
        }
        else {
            spos = relation[i].find(".");
            items = relation[i].substr(0,spos);
            itempos.reihe = static_cast<int> (relation[i].at(spos+1)) - 48;
            itempos.spalte = static_cast<int> (relation[i].at(spos+2)) - 48;
            flooritem = dynamic_cast<Floor*>(DM.findTile(itempos));
            flooritem->setItem(items);
            
        }

    }
}

void GameEngine::fight(Character* c, Tile* t) {
    Character* target = t->getCharacter();
    target->losehp(c->getstr());
    if (target->gethp() > 0) c->losehp(target->getstr());
    else return;
}

void GameEngine::run() {
    while (!finished()){
        for (int cd = 0; cd < m_character.size(); cd++) {
            if (m_character[cd]->gethp() <= 0) {
            DM.findTile(DM.findCharacter(m_character[cd]))->setCharacter(0);
            m_character.erase(m_character.begin()+(cd));
            }
        }
        int alivecounter = 0;
        for (int a = 0; a < m_character.size(); a++) {
            if (m_character[a]->getController()->geticon() == 'C') alivecounter++;
        }
        if (alivecounter == 0) {
            DM.print(m_character);
            return;
        }
        else turn();
    }
    DM.print(m_character);
}

void GameEngine::menu() {
    int intput;
    cout << "<<<Spielermenü>>>" << endl;
    cout << "1. Spielerinfos anzeigen" << endl;
    cout << "2. Zurück zum Spiel" << endl;
    cout << "3. Spiel beenden" << endl;
    cin >> intput;
    switch (intput) {
    case 1: m_character[0]->showInfo();
        break;
    case 2: return;
        break;
    case 3: DM.mapdata[5][6]->setCharacter(m_character[0]); 
    }
} 