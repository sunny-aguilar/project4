/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22 , 2019
** Description:     Character class is an abstract class which is used
**                  by the various characters to inherit common traits
**                  as well as to implement their own versions of
**                  their virtual functions. Each character has their
**                  own set of dice (Dice class) embedded in them. All
**                  derived classes inherit publicly from Character.
*********************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "dice.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;

class Character {
public:
    Character();
    Character(string name, int attack, int defense, int armor, int strength);
    virtual ~Character();
    string getName();
    virtual void initializeDice() = 0;
    virtual int rollDice(std::string action) = 0;
    virtual void attackPlayer(Character *defender) = 0;
    void setAttackVal(int val);
    virtual void defend() = 0;
    int getStrength();
    void strengthUpdate();
    void checkStrength();
    bool playerStatus();
    virtual void specialAbility() = 0;

protected:
    string name;
    string characterName;
    int attack;
    int defense;
    int armor;
    int strength;
    int damageReceived;
    bool playerDead;
    bool useSpecial;
    Dice **attackDice;
    Dice **defenseDice;

private:

};

#endif //PROJECT4_CHARACTER_HPP