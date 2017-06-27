

#ifndef ITEM_H
#define ITEM_H

class ArmingSword;
class GreatSword;
class Club;
class RapierDagger;
class Gambeson;
class MailArmour;
class Shield;
class FullPlateArmour;



class Item
{
public:
    Item();
    virtual int modifyStrength(int str);
    virtual int modifyStamina(int stam);
private:

};

class ArmingSword : public Item
{
public:
    ArmingSword();
    int modifyStrength(int str) override;
    int modifyStamina(int stam) override;
private:
       
};

class GreatSword : public Item
{
public:
    GreatSword();
    int modifyStrength(int str) override;
    int modifyStamina(int stam) override;
private:
       
};

class Club : public Item
{
public:
    Club();
    int modifyStrength(int str) override;
    int modifyStamina(int stam) override;
private:
       
};

class RapierDagger : public Item
{
public:
    RapierDagger();
    int modifyStrength(int str) override;
    int modifyStamina(int stam) override;
private:
       
};

class Gambeson : public Item
{
public:
    Gambeson();
    int modifyStrength(int str) override;
    int modifyStamina(int stam) override;
private:
       
};

class MailArmour : public Item
{
public:
    MailArmour();
    int modifyStrength(int str) override;
    int modifyStamina(int stam) override;
private:
       
};

class Shield : public Item
{
public:
    Shield();
    int modifyStrength(int str) override;
    int modifyStamina(int stam) override;
private:
       
};

class FullPlateArmour : public Item
{
public:
    FullPlateArmour();
    int modifyStrength(int str) override;
    int modifyStamina(int stam) override;
private:
       
};


#endif /* ITEM_H */

