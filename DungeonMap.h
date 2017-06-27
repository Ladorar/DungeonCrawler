using namespace std;
#include "Character.h"
#include "Tile.h"
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <list>

#ifndef DUNGEONMAP_H
#define DUNGEONMAP_H


struct Position {
    int reihe;
    int spalte;
    Position();
    Position (int r, int s);
    bool operator<(const Position& rechts) const{
    if (this->reihe < rechts.reihe)
        return true;
    if (this->spalte < rechts.spalte && this->reihe == rechts.reihe)
        return true;
    else
        return false;
    }

    inline bool operator>(const Position& rechts) const{
        return (*this < rechts);
    }

    Position operator-(const Position& rechts){
        return Position((this->reihe-rechts.reihe), (this->spalte-rechts.spalte));
    }

    Position operator+(const Position& rechts){
        return Position((this->reihe+rechts.reihe), (this->spalte+rechts.spalte));
    }

    bool operator==(const Position& rhs) {
        if (this->reihe == rhs.reihe && this->spalte == rhs.spalte) return true;
        else false;
    }

    bool operator!=(const Position& rhs) {
        if (this->reihe != rhs.reihe || this->spalte != rhs.spalte) return true;
        else false;
    }

};





class DungeonMap
{
public:
    DungeonMap(int height, int width);
    DungeonMap(int height, int width, const vector<string>& data);
    ~DungeonMap();
    Tile*** mapdata;
    //void place(Position pos, Character* c);
    Position findTile(Tile* t);
    Tile* findTile(Position pos);
    Position findCharacter(Character* c);
    void print(vector <Character*> vc);
    int hoehe;
    int breite;
    int PCcounter;
    bool hasLineOfSight(Position, Position);
    bool isNotStartTile(Position, Position);
    vector<Position> getPathTo(Position from, Position to);
    vector<int> getDimensions();
private:
    
};




#endif /* DUNGEONMAP_H */

