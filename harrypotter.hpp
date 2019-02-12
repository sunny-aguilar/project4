/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
** Description:     HarryPotter class is derived from Character class.
**                  HarryPotter has the special ability to revive after
**                  health drops below 0 but only one time. HarryPotter
**                  revives with strength of 20. HarryPotter has 2d6
**                  attack dice and 2d6 defense dice.
*********************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"

class HarryPotter : public Character {
public:
    HarryPotter();
    ~HarryPotter() override;
    void initializeDice() override;
    int rollDice(std::string action) override;
    void attackPlayer(Character *defender) override;
    void defend() override;
    void specialAbility() override;

private:
    bool hogwartsUsed;
};

#endif //PROJECT3_HARRYPOTTER_HPP
