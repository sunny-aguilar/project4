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
    void menuDisplayMatch( string p1Name, string p1Type,
                           string p2Name, string p2Type, int match);
    void menuRound(int round);
    void menuDeath(string type);
    void menuWinnerLoser( Character *p1, Character *p2,
                          bool p1Result, bool p2Result );
    void menuDisplayScores(int p1Score, int p2Score);
    void displayLosers();
    void menuPlayAgain();
    void menuExitGame();

private:
};

#endif //PROJECT4_MENU_HPP