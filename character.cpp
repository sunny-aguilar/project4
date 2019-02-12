/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
** Description:     Character class is an abstract class which is used
**                  by the various characters to inherit common traits
**                  as well as to implement their own versions of
**                  their virtual functions. Each character has their
**                  own set of dice (Dice class) embedded in them. All
**                  derived classes inherit publicly from Character.
*********************************************************************/
#include "character.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Character::Character() {}

/*********************************************************************
** Description:     constructor that sets the member variables
*********************************************************************/
Character::Character(string name, int attack, int defense, int armor, int strength) :
        name{name},
        characterName{},
        attack{attack},
        defense{defense},
        armor{armor},
        strength{strength},
        damageReceived{0},
        playerDead{false},
        useSpecial{false} {
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Character::~Character() {}

/*********************************************************************
** Description:     getter that returns the character name
*********************************************************************/
string Character::getName() {
    return name;
}

/*********************************************************************
** Description:     sets the attack damage received
*********************************************************************/
void Character::setAttackVal(int val) {
    attack = val;
}

/*********************************************************************
** Description:     getter for strength integer
*********************************************************************/
int Character::getStrength() { return strength; }

/*********************************************************************
** Description:     this function updates the damage inflicted on a
**                  player during combat and resets "damageReceived"
**                  back to zero after
*********************************************************************/
void Character::strengthUpdate() {
    strength -= damageReceived;

    // reset damaged received
    damageReceived = 0;
}

/*********************************************************************
** Description:     this function checks to see if a player's strength
**                  points are below 1 and if they are, sets
**                  the bool variable as true
*********************************************************************/
void Character::checkStrength() {
    if (strength < 1) {
        playerDead = true;
    }
}

/*********************************************************************
** Description:     getter that returns the bool value indicating if
**                  a player is dead
*********************************************************************/
bool Character::playerStatus() {
    return playerDead;
}