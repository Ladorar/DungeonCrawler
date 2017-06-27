using namespace std;
#include "DungeonMap.h"
#include "Character.h"
#include <vector>


#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine
{
public:
    GameEngine(int height, int width, const vector<string>& data, const vector<string>& relation);
    ~GameEngine();
    DungeonMap DM;
    vector<Character*> m_character;
    bool finished();
    void turn();
    void run();
    void linker(const vector<string>& relation);
    void menu();
    void fight(Character* c, Tile* t);
    
private:

};

#endif /* GAMEENGINE_H */

