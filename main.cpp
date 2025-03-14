/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Mar 1, 2019
** Description:     PROJECT 4 - this program is a fantasy combat
**                  simulation where two teams fight using
**                  various attack power and special abilities.
**                  The characters are implemented using an abstract
**                  base class where each type of character is derived
**                  from it. There are a total of 5 different
**                  characters in the game. Two additional classes are
**                  incorporated to implement dice as well as a menu
**                  class. Teams are implemented using linked lists.
*********************************************************************/
#include "game.hpp"

int main() {
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);                // create random number generator
    Game game;                  // create game object
    game.playGame();            // play the game
    return 0;
}