

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Character;

class Controller
{
public:
    Controller(Character* c);
    virtual int move() = 0;
    Character* getCharacter();
    void setCharacter(Character* c);
    virtual char geticon() = 0;
private:
    Character* p_character;
};

#endif /* CONTROLLER_H */

