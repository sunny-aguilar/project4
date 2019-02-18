/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 22, 2019
** Description:     HereList class holds the nodes that hold the
**                  characters for each team. The nodes are created
**                  as a linked list queue.
*********************************************************************/
#include "heroList.hpp"

/*********************************************************************
** Description:     no-args default constructor
*********************************************************************/
HeroList::HeroList() {}

void HeroList::addHeroes(Player player, int heroType) {
    switch (player) {
        case FIRSTPLAYER:
            pickHero();
            break;
        case SECONDPLAYER:
            pickHero();
            break;
        default:
            cout << "Unable to determine player!\n";
    }
}

Character *HeroList::pickHero(int heroType) {
    switch (heroType) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout << "Unable to determine hero type!\n";
    }
}