/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22, 2019
** Description:     HereList class holds the nodes that hold the
**                  characters for each team. The nodes are created
**                  as a linked list queue.
*********************************************************************/
#ifndef HEROLIST_HPP
#define HEROLIST_HPP

#include "menu.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

enum Player {FIRSTPLAYER, SECONDPLAYER};

class HeroList {
public:
    HeroList();
    ~HeroList();
    void addHeroes(Player player, int heroType, string heroName);
    Character *pickHero(int heroType, string heroName);
    void addHeroNode(string name, int heroType);

private:
    struct HeroNode {
        HeroNode(Character *hero = nullptr, HeroNode *next = nullptr) {
            this->hero = hero;
            this->next = next;
        }

        HeroNode *next;
        Character *hero;
    };

    Player player;
    HeroNode *headTeamOne;
    HeroNode *headTeamTwo;
    HeroNode *tailTeamOne;
    HeroNode *tailTeamTwo;
    HeroNode *teamOne;
    HeroNode *teamTwo;
    HeroNode *losers;

};

#endif //PROJECT4_HEROLIST_HPP
