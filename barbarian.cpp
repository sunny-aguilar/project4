/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22, 2019
** Description:     Barbarian class is derived from Character class.
**                  Barbarian has no special abilities to call.
*********************************************************************/
#include "barbarian.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables as follows:
**                  name / attack / defense / armor / strength
**                  Attack Dice: 2d6, Defense Dice: 2d6
*********************************************************************/
Barbarian::Barbarian(string name) : Character{name,0,0,0,12} {
    attackDice = new Dice*[2];
    defenseDice = new Dice*[2];
    initializeDice();
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Barbarian::~Barbarian() {
    // delete dynamically allocated pointers
    for (int row = 0; row < 1; row++) {
        delete [] attackDice[row];
    }
    //Free the array of pointers
    delete [] attackDice;

    // delete dynamically allocated pointers
    for (int row = 0; row < 1; row++) {
        delete [] defenseDice[row];
    }
    //Free the array of pointers
    delete [] defenseDice;
}

/*********************************************************************
** Description:     initializes dice based on character dice
**                  requirements. Attack dice 2d6, defense 2d6.
*********************************************************************/
void Barbarian::initializeDice() {
    attackDice[0] = new Dice[2];
    defenseDice[0] = new Dice[2];

    for (int index = 0; index < 2; index++) {
        attackDice[0][index] = Dice(6);
    }
    for (int index = 0; index < 2; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
int Barbarian::rollDice(std::string action) {
    int totalRolled = 0;
    if (action == "attack") {
        totalRolled += attackDice[0][0].randomInt();
        totalRolled += attackDice[0][1].randomInt();
    }
    else if (action == "defend") {
        totalRolled += defenseDice[0][0].randomInt();
        totalRolled += defenseDice[0][1].randomInt();
    }
    return totalRolled;
}

/*********************************************************************
** Description:     polymorphic function for attacking. Attack value
**                  is 2d6.
*********************************************************************/
void Barbarian::attackPlayer(Character *defender) {
    // reset attack power to zero
    attack = 0;
    // roll attack dice
    attack = rollDice("attack");
    cout << getName() << " Barbarian attacks!    -|---" << endl;
    cout << getName() << " Swings his mighty sword with an attack strength of " << attack << " points (2d6)" << endl << endl;

    // send attack value to defender object
    defender->setAttackVal(attack);
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Barbarian::defend() {
    cout << getName() << ">>Barbarian defends!    )))" << endl;
    cout << setw(2) << strength << " - Starting strength points " << endl << endl;
    int defendValue = 0;

    // roll dice
    defendValue = rollDice("defend");

    // calculate net damage received
    int damage = attack - defendValue - armor;
    if (damage < 0) { damage = 0; }

    // display damage received report
    cout << "Defense blocked " << defendValue << " attack points (2d6)\n";
    cout << setw(2) << attack << " - attack points\n";
    cout << setw(2) << defendValue << " - defense block\n";
    cout << setw(2) << armor << " - armor block\n";
    cout << setw(2) << damage << " - net damage inflicted\n";
    cout << setw(2) << strength - damage << " - ending strength points\n\n";

    // update player strength
    damageReceived = damage;
}

/*********************************************************************
** Description:     Barbarian has no special ability
*********************************************************************/
void Barbarian::specialAbility() {
    // barbarian has no special ability
}