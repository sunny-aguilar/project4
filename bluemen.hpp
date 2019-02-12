/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
** Description:     BlueMen class is derived from Character class.
**                  Blue men has a high defense that due to 3d6 dice
**                  however this special ability is eroded as its
**                  strength drops. Blue men loses 1 defense dice
**                  for every 4 points of damage received.
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class BlueMen : public Character {
public:
    BlueMen();
    ~BlueMen() override;
    void initializeDice() override;
    int rollDice(std::string action) override;
    void attackPlayer(Character *defender) override;
    void defend() override;
    void specialAbility() override;

private:

};

#endif //PROJECT3_BLUEMEN_HPP