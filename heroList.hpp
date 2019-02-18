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
    void setHeroes(Character *heroType, Player player);
    void addHeroNode();

private:
    struct HeroNode {
        HeroNode(Character *hero = nullptr, HeroNode *head = nullptr, HeroNode *next = nullptr) {
            this->hero = hero;
            this->head = head;
            this->next = next;
        }
        HeroNode *head;
        HeroNode *next;
        Character *hero;
    };

    Player player;
    Character *teamOne;
    Character *teamTwo;
    Character *losers;

};

#endif //PROJECT4_HEROLIST_HPP
