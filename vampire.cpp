/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22, 2019
** Description:     Vampire class is derived from Character class.
**                  Vampire has the special ability of charming
**                  opponents into not attacking 50% of the time.
**                  Charm trumps Medusa's Glare. Vampire has 1d12
**                  attack dice and 1d6 defense dice.
*********************************************************************/
#include "vampire.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables as follows:
**                  name / attack / defense / armor / strength
**                  Attack Dice: 1d12, Defense Dice: 1d6
*********************************************************************/
Vampire::Vampire(string name) :
        Character{name,0,0,1,18} {
    attackDice = new Dice*[1];
    defenseDice = new Dice*[1];
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Vampire::~Vampire() {
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
**                  requirements. Attack dice 1d12, defense 1d6.
*********************************************************************/
void Vampire::initializeDice() {
    attackDice[0] = new Dice[1];
    defenseDice[0] = new Dice[1];

    for (int index = 0; index < 1; index++) {
        attackDice[0][index] = Dice(12);
    }

    for (int index = 0; index < 1; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

/*********************************************************************
** Description:     accepts a string parameter that chooses which
**                  dice to use (attack or defend), rolls the dice,
**                  and returns the total rolled value
*********************************************************************/
int Vampire::rollDice(std::string action) {
    int totalRolled = 0;
    if (action == "attack") {
        totalRolled += attackDice[0][0].randomInt();
    }
    else if (action == "defend") {
        totalRolled += defenseDice[0][0].randomInt();
    }
    return totalRolled;
}

/*********************************************************************
** Description:     polymorphic function for attacking. Attack value
**                  is 1d12. Functions calls roll dice function to
**                  obtain attack value. Attack value is sent to
**                  the defending player.
*********************************************************************/
void Vampire::attackPlayer(Character *defender) {
    // reset attack power to zero
    attack = 0;
    // roll attack dice
    attack = rollDice("attack");
    // display attack info
    cout << ">>Vampire attacks!    -|---" << endl;
    cout << "Sinks his fangs into his opponent with an attack power of " << attack << " points (1d12)" << endl << endl;

    // send attack value to defender object
    defender->setAttackVal(attack);
}

/*********************************************************************
** Description:     this function handles the players defense
**                  operations. The roll dice function is called to
**                  compute the player's defense and calculates the
**                  damage received by the player. A report is printed
**                  to show calculations. Since this character is the
**                  Vampire, the vampire calls its special Charm
**                  ability during its defense.
*********************************************************************/
void Vampire::defend() {
    cout << ">>Vampire defends!    )))" << endl;
    cout << strength << " - Starting strength points " << endl << endl;
    int defendValue = 0;

    // special defense **CHARM**
    specialAbility();

    // display damage received report
    if (useSpecial) {
        attack = 0;
        cout << "Vampire has charmed his opponent and was not attacked!\n";
        cout << strength << " - ending strength points\n\n";
        // reset special ability after use
        useSpecial = false;
    }
    else  {
        // roll dice
        defendValue = rollDice("defend");

        // calculate net damage received
        int damage = attack - defendValue - armor;
        if (damage < 0) { damage = 0; }

        // display damage received report
        cout << "Defense blocked " << defendValue << " attack points (1d6)\n";
        cout << setw(2) << attack << " - attack points\n";
        cout << setw(2) << defendValue << " - defense block (1d6)\n";
        cout << setw(2) << armor << " - armor block\n";
        cout << setw(2) << damage << " - net damage inflicted\n";
        cout << setw(2) << strength - damage << " - ending strength points\n\n";

        // update player strength
        damageReceived = damage;
    }
}

/*********************************************************************
** Description:     special ability that allows vampire to charm his
**                  opponents into not attacking each turn with a
**                  50% probability.
*********************************************************************/
void Vampire::specialAbility() {
    // create dice with two sides
    Dice dice(2);
    int num = dice.randomInt();
    // randomly pick a side
    if (num == 1) {
        useSpecial = true;
    }
    else if (num == 2) {
        useSpecial = false;
    }
}