/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
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
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
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
    void startCombat();
    bool checkDeath(Character *defender);
    bool playAgain();
    void exitGame();

private:
    Menu menu;
    Fighter fighterType[2];
    Character *playerOne;
    Character *playerTwo;
    int rounds;

};

#endif //PROJECT3_GAME_HPP