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

void HeroList::addHeroes(Player player, int heroType, string heroName) {
    switch (player) {
        case FIRSTPLAYER:
            pickHero(heroType, heroName);
            break;
        case SECONDPLAYER:
            pickHero(heroType);
            break;
        default:
            cout << "Unable to determine player!\n";
    }
}

Character *HeroList::pickHero(int heroType, string heroName) {
    switch (heroType) {
        case 1:
            return new Vampire(heroName);
        case 2:
            return new Barbarian();
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