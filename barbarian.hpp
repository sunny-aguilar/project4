/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
** Description:     Barbarian class is derived from Character class.
**                  Barbarian has no special abilities to call.
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character {
public:
    Barbarian();
    ~Barbarian() override;
    void initializeDice() override;
    int rollDice(std::string action) override;
    void attackPlayer(Character *defender) override;
    void defend() override;
    void specialAbility() override;

private:

};

#endif //PROJECT3_BARBARIAN_HPP