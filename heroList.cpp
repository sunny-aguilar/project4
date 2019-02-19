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

bool HeroList::isTeamEmpty(Player player) {
    switch (player) {
        case 0:
            if (!headTeamOne) {
                return true;
            }
            else {
                return false;
            }
        case 1:
            if (!headTeamTwo) {
                return true;
            }
            else {
                return false;
            }
        default: cout << "Unable to return hero\n";
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

/*********************************************************************
** Description:     returns a team hero from either team
*********************************************************************/
Character *HeroList::getHero(Player player) {
     switch (player) {
         case 0: return headTeamOne->hero;
         case 1: return headTeamTwo->hero;
         default: cout << "Unable to return hero\n";
     }
 }

/*********************************************************************
** Description:     removes losing hero from the team list
*********************************************************************/
void HeroList::removeHead(Player player) {
    // player list to use
    HeroNode *playerList = nullptr;
    if (player == 0) {
        playerList = headTeamOne;
    }
    else if (player == 1) {
        playerList = headTeamTwo;
    }

    // select node to delete
    if ( isEmpty( playerList ) ) {
        cout << "There are no nodes in the player list\n";
        return;
    }
    else if ( playerList->next == nullptr ) {

    }
    else {
        // assign new head node and assign it the next node from head
        HeroNode *oldHead = nullptr;
        HeroNode *newHead = nullptr;
        // select right player list to delete
        if (player == 0) {
            oldHead = headTeamOne;
            newHead = headTeamOne->next;
        }
        else if (player == 1) {
            oldHead = headTeamTwo;
            newHead = headTeamTwo->next;
        }


        // select right player list to delete
        if (player == 0) {

        }
        else if (player == 1) {

        }


        // if the next node is not the head node i.e., there is
        // only one node, then connect the last node to the new node
        // and connect the new node ->prev to the last node
        if (newHead != oldHead) {
            // connect new head node to last node
            newHead->prev = oldHead->prev;

            // connect last node to the new head node
            QueueNode *last = head->prev;
            last->next = newHead;

            // point head pointer to the new head
            head = newHead;
        }
        else {
            // if only one node, remove it
            head = nullptr;
        }
        delete oldHead;
    }
}


