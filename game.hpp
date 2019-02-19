/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22, 2019
** Description:     Game class holds various classes in it and is the
**                  main driver behind the game. The game flow is
**                  controlled with various functions here and
**                  the menu and character objects live inside the
**                  Game class. Enums are used to provide for more
**                  readable code where possible.
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
    void teamScore();
    bool playAgain();
    void exitGame();

private:
    Menu menu;
    HeroList heroes;
    Fighter fighterType[2];
    //Character *playerOne;
    //Character *playerTwo;
    int teamOneQty;
    int teamTwoQty;
    int rounds;
    int teamOneScore;
    int teamTwoScore;
};

#endif //PROJECT4_GAME_HPP