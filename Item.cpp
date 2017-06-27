

#include "Item.h"

Item::Item() {
    
}

int Item::modifyStamina(int stam) {
    return 0;
}

int Item::modifyStrength(int str) {
    return 0;
}

ArmingSword::ArmingSword() {
    
}

int ArmingSword::modifyStamina(int stam) {
    return 0;
}

int ArmingSword::modifyStrength(int str) {
    return 3;
}

GreatSword::GreatSword() {
    
}

int GreatSword::modifyStamina(int stam) {
    return -1;
}

int GreatSword::modifyStrength(int str) {
    return 5;
}

Club::Club() {
    
}

int Club::modifyStamina(int stam) {
    return 0;
}

int Club::modifyStrength(int str) {
    return (str*1,5);
}

RapierDagger::RapierDagger() {
    
}

int RapierDagger::modifyStamina(int stam) {
    return 1;
}

int RapierDagger::modifyStrength(int str) {
    return 2;
}

Gambeson::Gambeson() {
    
}

int Gambeson::modifyStamina(int stam) {
    return 1;
}

int Gambeson::modifyStrength(int str) {
    return 0;
}

MailArmour::MailArmour() {
    
}

int MailArmour::modifyStamina(int stam) {
    return 3;
}

int MailArmour::modifyStrength(int str) {
    return 0;
}

Shield::Shield() {
    
}

int Shield::modifyStamina(int stam) {
    return (stam*2);
}

int Shield::modifyStrength(int str) {
    return -1;
}

FullPlateArmour::FullPlateArmour() {
    
}

int FullPlateArmour::modifyStamina(int stam) {
    return 6;
}

int FullPlateArmour::modifyStrength(int str) {
    return -2;
}