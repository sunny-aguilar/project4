/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22, 2019
** Description:     HarryPotter class is derived from Character class.
**                  HarryPotter has the special ability to revive after
**                  health drops below 0 but only one time. HarryPotter
**                  revives with strength of 20. HarryPotter has 2d6
**                  attack dice and 2d6 defense dice.
*********************************************************************/
#include "harrypotter.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables as follows:
**                  name / attack / defense / armor / strength
**                  Attack Dice: 2d6, Defense Dice: 2d6
*********************************************************************/
HarryPotter::HarryPotter(string name) :
        Character{name,0,0,0,10},
        hogwartsUsed{false} {
    attackDice = new Dice*[2];
    defenseDice = new Dice*[2];
}

/*********************************************************************
** Description:     virtual destructor that de-allocates the dice
*********************************************************************/
HarryPotter::~HarryPotter() {
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
void HarryPotter::initializeDice() {
    attackDice[0] = new Dice[2];
    defenseDice[0] = new Dice[2];

    //initialize attack dice - 2d6
    for (int index = 0; index < 2; index++) {
        attackDice[0][index] = Dice(6);
    }
    // initialize defense dice - 2d6
    for (int index = 0; index < 2; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

/*********************************************************************
** Description:     accepts a string parameter that chooses which
**                  dice to use (attack or defend), rolls the dice,
**                  and returns the total rolled value
*********************************************************************/
int HarryPotter::rollDice(std::string action) {
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
**                  is 2d6. Functions calls roll dice function to
**                  obtain attack value. Attack value is sent to
**                  the defending player.
*********************************************************************/
void HarryPotter::attackPlayer(Character *defender) {
    // reset attack power to zero
    attack = 0;
    // roll attack dice
    attack = rollDice("attack");
    cout << ">>Harry Potter attacks!    -|---" << endl;
    cout << "Conjures a spell with an attack strength of " << attack << " points (2d6)" << endl << endl;

    // send attack value to defender object
    defender->setAttackVal(attack);
}

/*********************************************************************
** Description:     this function handles the players defense
**                  operations. The roll dice function is called to
**                  compute the player's defense and calculates the
**                  damage received by the player. A report is printed
**                  to show calculations. Since this character is
**                  Harry Potter, his special ability Hogwarts can be
**                  called during its defense.
*********************************************************************/
void HarryPotter::defend() {
    cout << ">>Harry Potter defends!    )))" << endl;
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
    cout << setw(2) << damage << " - damage inflicted\n";
    cout << setw(2) << strength - damage << " - net ending strength points\n\n";

    // special defense **Hogwarts**
    if ((strength - damage < 1) && !hogwartsUsed) {
        specialAbility();
        cout << "Harry Potter's strength points have dropped below 1 and has died!\n";
        cout << "Harry Potter has used Hogwarts and is alive again with strength 20!\n";
        strength = 20;
        hogwartsUsed = true;
    }
    else {
        // update player strength
        damageReceived = damage;

        // if Hogwarts ability already used, prompt user
        if (hogwartsUsed) {
            cout << "Harry Potter cannot used Hogwarts again!\n";
        }
    }
}

/*********************************************************************
** Description:     special ability allows Harry Potter to come back
**                  to life once with 20 strength points. Ability can
**                  only be used once.
*********************************************************************/
void HarryPotter::specialAbility() {
    useSpecial = true;
}