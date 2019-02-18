/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22, 2019
** Description:     Menu class holds the main menu and user prompts
**                  for the program. The menu class lives inside of
**                  the Game class and the menus are called
**                  as needed from within the Game class.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include "character.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
using std::string;
using std::setw;
using std::left;
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    void mainMenu();
    void menuTotalFighters(int team);
    void menuSelectFighter(int player, int heroNum);
    void menuEnterHeroName();
    int validateNumber(int min, int max);
    void menuDisplayPlayers(int fighter1, int fighter2);
    void menuRound(int round);
    void menuDeath(string type);
    void menuPlayAgain();
    void menuExitGame();

private:
};

#endif //PROJECT4_MENU_HPP