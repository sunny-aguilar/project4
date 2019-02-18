/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22, 2019
** Description:     Vampire class is derived from Character class.
**                  Vampire has the special ability of charming
**                  opponents into not attacking 50% of the time.
**                  Charm trumps Medusa's Glare. Vampire has 1d12
**                  attack dice and 1d6 defense dice.
*********************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire : public Character {
public:
    Vampire(string name);
    ~Vampire() override;
    void initializeDice() override;
    int rollDice(std::string action) override;
    void attackPlayer(Character *defender) override;
    void defend() override;
    void specialAbility() override;

private:

};

#endif //PROJECT4_VAMPIRE_HPP