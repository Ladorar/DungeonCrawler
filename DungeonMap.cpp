using namespace std;

#include "DungeonMap.h"
#include "Tile.h"
#include "Wall.h"
#include "Floor.h"
#include "Door.h"
#include "Switch.h"
#include "limits.h"
#include <algorithm>


Position::Position() {
    reihe = 1;
    spalte = 1;
}
Position::Position (int r, int s) {
    reihe = r;
    spalte = s;
}

DungeonMap::~DungeonMap() {
    
    for (int i = 0; i < hoehe; i++) {
        for ( int j = 0; j < breite; j++) {
        delete mapdata[i][j];
        }
        delete[] mapdata[i];
    }
    delete [] mapdata;
}
DungeonMap::DungeonMap(int height, int width) {
    mapdata = new Tile** [width];
    for (int i = 0; i < width; i++) {
        mapdata[i] = new Tile* [height];
    }
    for (int w = 0; w < width; w++) {
        for (int h = 0; h < height; h++) {
            mapdata[w][h] = new Floor(0);
        }
    }
    hoehe = height;
    breite = width;
    PCcounter = 0;
}

DungeonMap::DungeonMap(int height, int width, const vector<string>& data) {
    mapdata = new Tile** [width];
    for (int i = 0; i < width; i++) {
        mapdata[i] = new Tile* [height];
    }
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            if (data[h].at(w) == '#') mapdata[w][h] = new Wall(0);
            else if (data[h].at(w) == '?') mapdata[w][h] = new Switch(0);
            else if (data[h].at(w) == 'X') mapdata[w][h] = new Door(0);
            else mapdata[w][h] = new Floor(0);
        }
    }
    hoehe = height;
    breite = width;
    PCcounter = 0;
}

//void DungeonMap::place(Position pos, Character* c) {
 //   mapdata[pos.spalte][pos.reihe]->setCharacter(c);
 //   c_copy = c;
//}

Position DungeonMap::findTile(Tile* t) {
    Position pos;
    for (int w = 0; w < breite; w++) {
        for (int h = 0; h < hoehe; h++) {
            if (t == mapdata[w][h]) {
                pos.reihe = h;
                pos.spalte = w;
                return pos;
            }
                
        }
    }
    return pos;
}

Tile* DungeonMap::findTile(Position pos) {
    return mapdata[pos.spalte][pos.reihe];
    //return mapdata[pos.reihe][pos.spalte];
}

Position DungeonMap::findCharacter(Character* c) {
    Position pos;
    for (int w = 0; w < breite; w++) {
        for (int h = 0; h < hoehe; h++) {
            if (mapdata[w][h]->getCharacter() == c) {
                pos.reihe = h;
                pos.spalte = w;
                return pos;
            }
                
        }
    }
}

void DungeonMap::print(vector <Character*> vc) {
    Position tile;
    
    for (int h = 0; h < hoehe; h++) {
        for (int w = 0; w < breite; w++) {
            
            tile.spalte = w;
            tile.reihe = h;
            if (false) mapdata[w][h]->print();
            else if (PCcounter == 1) {
                if (hasLineOfSight(tile, findCharacter(vc[0]))) mapdata[w][h]->print();
                else cout << "#";
            }
            else if (PCcounter == 2) {
                if (hasLineOfSight(tile, findCharacter(vc[0])) || hasLineOfSight(tile, findCharacter(vc[1]))) mapdata[w][h]->print();
                else cout << "#";
            }
        }
        cout << endl;
    }
}

bool isNotStartTile(Position from, Position now){
    if (from.reihe == now.reihe && from.spalte == now.spalte)
        return false;
    else
        return true;
}

bool DungeonMap::hasLineOfSight(Position from,Position to)
{
    int x0,y0,x1,y1;
    y0 = from.spalte;
    x0 = from.reihe;
    y1 = to.spalte;
    x1 = to.reihe;
    
    
    int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = dx+dy, e2; /* error value e_xy */
    int counter = 0;

    while(1){
    //setPixel(x0,y0);
    Position p1;
    p1.spalte = y0;
    p1.reihe = x0;
    if (counter != 0){
        if (DungeonMap::findTile(p1)->isTransparent() == false)// && from.reihe != p1.reihe && from.spalte != p1.spalte)
           return false;
    }
    
    if (x0==x1 && y0==y1) break;
    e2 = 2*err;
    if (e2 > dy) { err += dy; x0 += sx; } 
    if (e2 < dx) { err += dx; y0 += sy; } 
    counter ++;
  }
}

vector<Position> DungeonMap::getPathTo(const Position from, const Position to) {
    vector<Position> pfad;
    set<Position> Q, Q2;
    map<Position, Position> prev;
    map<Position, int> dist;



    //Erstellen des Sets und insert aller Knoten
    Position pos(0, 0);
    for (pos; pos.reihe < hoehe; pos.reihe++) {
        for (pos; pos.spalte < breite; pos.spalte++) {
            if (mapdata[pos.spalte][pos.reihe]->isAccessable()) {
                Q.insert(pos); 
                dist[pos] = numeric_limits<int>::max()-1; 
                prev[pos] = Position(-1, -1);
            }
        }
        pos.spalte = 0;
    }
    Q2 = Q;

    
    dist[from] = 0;

    //Alle elemente in Q
    while (Q.size()!= 0) {
        Position u = (*Q.begin());
        for (auto itQ = Q.begin(); itQ != Q.end(); itQ++) { //for schleife für alle vorhandenen knoten
            if (dist[*itQ] < dist[u]) { //suchen nach knoten mit kürzester distanz zu from
                u = (*itQ); 
            }
        }

        
        Q.erase(u); //Knoten mit kürzester distanz entfernen

        //for schelife für alle nachbarn von knoten u
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                Position newPos = Position(u.reihe + i, u.spalte + j); //nachbar v von u der immernoch in Q ist
                auto newItPos = Q2.find(newPos); //überorüfen ob die position noch in q ist
                int newDist = dist[u] + 1; 
                if (newDist < dist[newPos] && newItPos != Q2.end()) {
                    dist[newPos] = newDist; 
                    prev[newPos] = u; 
                }
            }
        }

    }

    // return leeren vektor falls kein pfad
    if(dist[to] == numeric_limits<int>::max()-1)
        return pfad;
    
    Position currentPos = to;
    //positionen in path vektor pushen
    while (currentPos.reihe != from.reihe || currentPos.spalte != from.spalte){ //solange bis die nächste zu pushende position die from pos ist
        pfad.push_back(currentPos); 
        currentPos = prev[currentPos]; //vorgänger holen
    }
    return pfad;
}

vector<int> DungeonMap::getDimensions(){
    return vector<int>{hoehe, breite};
}
