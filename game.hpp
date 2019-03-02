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
#ifndef GAME_HPP
#define GAME_HPP

#include "menu.hpp"
#include "heroList.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "heroList.hpp"
#include <ctime>

enum Fighter {UNSET, VAMPIRE, BARBARIAN, BLUEMEN, MEDUSA, HARRYPOTTER};

class Game {
public:
    Game();
    ~Game();
    void playGame();
    void startGame();
    void gameFlow();
    void setTeam();
    void selectPlayer();
    void startCombat(Character *playerOne, Character *playerTwo);
    bool checkDeath(Character *defender);
    void teamScore(bool playerOneResult, bool playerTwoResult);
    void resetScore();
    Player getLoser(bool playerOneResult, bool playerTwoResult);
    void displayLoserList();
    bool playAgain();
    void exitGame();

private:
    Menu menu;
    HeroList heroes;
    Fighter fighterType[2];
    int teamOneQty;
    int teamTwoQty;
    int rounds;
    int match;
    int teamOneScore;
    int teamTwoScore;
    Player roundLoser;
};

#endif //PROJECT4_GAME_HPP