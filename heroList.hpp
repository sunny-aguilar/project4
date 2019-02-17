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

class HeroList {
public:
    HeroList();

private:
    struct HeroNode {
        HeroNode(HeroNode *head, HeroNode *next = nullptr) {
            this->head = head;
            this->next = next;
        }
        HeroNode *head;
        HeroNode *next;
    };

};

#endif //PROJECT4_HEROLIST_HPP
