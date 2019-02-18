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
HeroList::HeroList() :
    headTeamOne{nullptr},
    headTeamTwo{nullptr},
    tailTeamOne{nullptr},
    tailTeamTwo{nullptr},
    losers{nullptr} {}

/*********************************************************************
** Description:     node list destructor
*********************************************************************/
HeroList::~HeroList() {}

/*********************************************************************
** Description:     adds heroes to the linked list for player 1 and
**                  player 2
*********************************************************************/
void HeroList::addHeroes(Player player, int heroType, string heroName) {
    switch (player) {
        case FIRSTPLAYER:
            // assign pickHero to the right team list
            addHeroNode(heroName, heroType);
            traverseForward(headTeamOne);
            break;
        case SECONDPLAYER:
            addHeroNode(heroName, heroType);
            traverseForward(headTeamTwo);
            break;
        default:
            cout << "Unable to determine player!\n";
    }
}

/*********************************************************************
** Description:     returns hero chosen
*********************************************************************/
Character *HeroList::pickHero(int heroType, string heroName) {
    switch (heroType) {
        case 1: return new Vampire(heroName);
        case 2: return new Barbarian(heroName);
        case 3: return new BlueMen(heroName);
        case 4: return new Medusa(heroName);
        case 5: return new HarryPotter(heroName);
        default:
            cout << "Unable to determine hero type!\n";
    }
}

/*********************************************************************
** Description:     adds a hero node to the back of the node list
*********************************************************************/
void HeroList::addHeroNode(string heroName, int heroType, HeroNode *team) {
    cout << "reached 1\n"; // error after this
    if (team == nullptr) {
        cout << "reached 1\n";
        team = new HeroNode( pickHero(heroType, heroName) );
    }
    else {
        cout << "reached 3\n";
        HeroNode *heroPtr = team;

        while (heroPtr->next != nullptr) {
            heroPtr = heroPtr->next;
        }

        heroPtr->next = new HeroNode( pickHero(heroType, heroName) );
    }

}

/*********************************************************************
** Description:     traverse the list forward
*********************************************************************/
void HeroList::traverseForward(HeroNode *team) {
    HeroNode *nodePtr = team;

    if (isEmpty(team)) {
        cout << "There are no players in the team!\n";
        return;
    }

    while (nodePtr != nullptr) {
        cout << "Hero name is " <<nodePtr->hero->getName() << endl;
        nodePtr = nodePtr->next;
    }
}

/*********************************************************************
** Description:     checks to see if a team list is empty
*********************************************************************/
bool HeroList::isEmpty(HeroNode *team) {
    if (!team) {
        return true;
    }
    else {
        return false;
    }
}


