/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Mar 1, 2019
** Description:     Dice are implemented using a class which allows
**                  each character to have their own type of dice
**                  as an object inside of them. This allows characters
**                  to have their own own quantity of dice for both
**                  attack and defense activities without any external
**                  logic dictating how many dice they should use.
**                  Dice are created by the constructor with N sides
**                  which is handled in the character class.
*********************************************************************/
#include "dice.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the number
**                  of sides on the die
*********************************************************************/
Dice::Dice() : N{0} {}

/*********************************************************************
** Description:     1-arg constructor that takes an int parameter to
**                  set the number of sides on the die
*********************************************************************/
Dice::Dice(int num) : N{num} {}

/*********************************************************************
** Description:     returns a random integer from 1 to N
*********************************************************************/
Dice::~Dice() {}

/*********************************************************************
** Description:     returns a random integer from 1 to N
*********************************************************************/
int Dice::randomInt() {
    int randomNum;              // hold random number
    randomNum = rand() % N + 1; // computer random # from 1 to N
    return randomNum;           // return random integer
}

/*********************************************************************
** Description:     setter that takes an int parameter to set the
**                  sides of N
*********************************************************************/
void Dice::setSides(int sides) {
    N = sides;
}

/*********************************************************************
** Description:     getter that returns N
*********************************************************************/
int Dice::getSides() {
    return N;
}