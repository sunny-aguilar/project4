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
            addHeroNode(heroType, heroName, headTeamOne);
            traverseForward(headTeamOne);
            break;
        case SECONDPLAYER:
            addHeroNode(heroType, heroName, headTeamTwo);
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
void HeroList::addHeroNode(int heroType, string heroName, HeroNode *&team) {
    if (team == nullptr) {
        cout << "No heroes in the list\n";
        team = new HeroNode( pickHero(heroType, heroName) );
    }
    else {
        cout << "Heroes already in the list\n";
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

/*********************************************************************
** Description:     runs the tournament operations
*********************************************************************/
void HeroList::startTournament() {
    // start hero combat
    //heroFight();
}

/*********************************************************************
** Description:     combat operations
*********************************************************************/
 void HeroList::heroFight() {

     while (headTeamOne != nullptr && headTeamTwo != nullptr) {

     }

 }


Character *HeroList::getHero(Player player) {
     switch (player) {
         case 0: return headTeamOne->hero;
         case 1: return headTeamTwo->hero;
         default: cout << "Unable to return hero\n";
     }
 }

HeroList *HeroList::getTeamList() {

 }
