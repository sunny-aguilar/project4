/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Mar 1, 2019
** Description:     Medusa class is derived from Character. Medusa
**                  has a special offensive ability that allows her
**                  to immediately defeat her opponents upon rolling
**                  an attack dice of 12. Medusa has attack dice of
**                  2d6 and defense dice of 1d6. Vampire's charm
**                  trumps Medusa's glare.
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"

class Medusa : public Character {
public:
    Medusa(string name);
    ~Medusa() override;
    void initializeDice() override;
    int rollDice(std::string action) override;
    void attackPlayer(Character *defender) override;
    void defend() override;
    void specialAbility() override;

private:

};

#endif //PROJECT4_MEDUSA_HPP
