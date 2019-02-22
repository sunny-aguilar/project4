/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22, 2019
** Description:     BlueMen class is derived from Character class.
**                  Blue men has a high defense that due to 3d6 dice
**                  however this special ability is eroded as its
**                  strength drops. Blue men loses 1 defense dice
**                  for every 4 points of damage received.
*********************************************************************/
#include "bluemen.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables as follows:
**                  name / attack / defense / armor / strength
**                  Attack Dice: 2d10, Defense Dice: 3d6
*********************************************************************/
BlueMen::BlueMen(string name) : Character{name,"Blue Men",0,0,3,12} {
    attackDice = new Dice*[2];
    defenseDice = new Dice*[3];
    initializeDice();
}

/*********************************************************************
** Description:     virtual destructor that de-allocates the dice
*********************************************************************/
BlueMen::~BlueMen() {
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
**                  requirements. Attack dice 2d10, defense 3d6.
*********************************************************************/
void BlueMen::initializeDice() {
    attackDice[0] = new Dice[2];
    defenseDice[0] = new Dice[3];

    //initialize attack dice
    for (int index = 0; index < 2; index++) {
        attackDice[0][index] = Dice(10);
    }
    // initialize defense dice
    for (int index = 0; index < 3; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

/*********************************************************************
** Description:     blue men start out with 3 defense dice and a dice
**                  is removed for every 4 points of damage received.
**                  Function returns the total roll value.
*********************************************************************/
int BlueMen::rollDice(std::string action) {
    int totalRolled = 0;
    if (action == "attack") {
        totalRolled += attackDice[0][0].randomInt();
        totalRolled += attackDice[0][1].randomInt();
    }
    else if (action == "defend") {
        if (strength > 8) {
            totalRolled += defenseDice[0][0].randomInt();
            totalRolled += defenseDice[0][1].randomInt();
            totalRolled += defenseDice[0][2].randomInt();
        }
        else if (strength <= 8 && strength > 4) {
            totalRolled += defenseDice[0][0].randomInt();
            totalRolled += defenseDice[0][1].randomInt();
        }
        else if (strength <= 4) {
            totalRolled += defenseDice[0][0].randomInt();
        }
    }
    return totalRolled;
}

/*********************************************************************
** Description:     polymorphic function for attacking. Attack value
**                  is 2d10. Functions calls roll dice function to
**                  obtain attack value. Attack value is sent to
**                  the defending player.
*********************************************************************/
void BlueMen::attackPlayer(Character *defender) {
    // reset attack power to zero
    attack = 0;
    // roll attack dice
    attack = rollDice("attack");
    // cout << ">>Blue Men attacks!    -|---" << endl;
    // cout << "Swarm their opponent with an attack power of " << attack
    //      << " points (2d10)" << endl << endl;

    // send attack value to defender object
    defender->setAttackVal(attack);
}

/*********************************************************************
** Description:     this function handles the players defense
**                  operations. The roll dice function is called to
**                  compute the player's defense and calculates the
**                  damage received by the player. A report is printed
**                  to show calculations. Since this character is the
**                  Blue men, their defensive abilities are updated
**                  to reduce their defensive dice.
*********************************************************************/
void BlueMen::defend() {
    // cout << ">>Blue Men defends!    )))" << endl;
    // cout << setw(2) << strength << " - Starting strength points " << endl << endl;
    int defendValue = 0;

    // special defense **Mob**
    // blue men loses 1 dice for every 4 points of damage
    specialAbility();

    // roll dice
    defendValue = rollDice("defend");

    // calculate net damage received
    int damage = attack - defendValue - armor;
    if (damage < 0) { damage = 0; }

    // display damage received report
    // cout << "Defense blocked " << defendValue << " attack points\n";
    // cout << setw(2) << attack << " - attack points\n";
    // cout << setw(2) << defendValue << " - defense block\n";
    // cout << setw(2) << armor << " - armor block\n";
    // cout << setw(2) << damage << " - net damage inflicted\n";
    // cout << setw(2) << strength - damage << " - ending strength points\n\n";

    // update player strength
    damageReceived = damage;
}

/*********************************************************************
** Description:     special ability allows Blue men to have up to 3d6
**                  dice however they lose a 1d6 dice for every 4
**                  strength points lost
*********************************************************************/
void BlueMen::specialAbility() {
    useSpecial = true;
    if (strength > 8) {
        cout << "Blue men defends with 3d6 defense dice\n";
    }
    else if (strength <= 8 && strength > 4) {
        cout << "Blue men defends with 2d6 defense dice\n";
    }
    else if (strength <= 4) {
        cout << "Blue men defends with 1d6 defense dice\n";
    }
}