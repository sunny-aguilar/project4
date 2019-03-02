/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Mar 1, 2019
** Description:     Barbarian class is derived from Character class.
**                  Barbarian has no special abilities to call.
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character {
public:
    Barbarian(string name);
    ~Barbarian() override;
    void initializeDice() override;
    int rollDice(std::string action) override;
    void attackPlayer(Character *defender) override;
    void defend() override;
    void specialAbility() override;

private:

};

#endif //PROJECT4_BARBARIAN_HPP