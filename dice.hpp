/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
** Description:     Dice are implemented using a class which allows
**                  each character to have their own type of dice
**                  as an object inside of them. This allows characters
**                  to have their own own quantity of dice for both
**                  attack and defense activities without any external
**                  logic dictating how many dice they should use.
**                  Dice are created by the constructor with N sides
**                  which is handled in the character class.
*********************************************************************/
#ifndef DICE_HPP
#define DICE_HPP

#include <iostream>
#include <ctime>
#include <vector>
using std::vector;

class Dice {
public:
    Dice();                         // default constructor
    Dice(int num);                  // 1-arg constructor
    ~Dice();                        // destructor
    int randomInt();                // returns a random integer
    void setSides(int sides);       // setter that sets die sides
    int getSides();                 // getter that returns die sides

protected:
    int N;                          // number of sides on the die
};

#endif //PROJECT3_DICE_HPP
