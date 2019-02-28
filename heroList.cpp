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
    losersList{nullptr} {}

/*********************************************************************
** Description:     node list destructor
*********************************************************************/
HeroList::~HeroList() {
    // display if lists exists
    cout << "Team One List before destructor " << headTeamOne << endl;
    cout << "Team Two List before destructor " << headTeamTwo << endl;
    cout << "LTeam List before destructor " << losersList << endl;

    // display if characters exist
    // cout << "Characters team 1 " << headTeamOne->hero << endl;
    // cout << "Characters team 2 " << headTeamTwo->hero << endl;



    HeroNode *garbage = nullptr;
    // delete player one
    if (headTeamOne != nullptr) {
        while (headTeamOne != nullptr) {
            garbage = headTeamOne;
            headTeamOne = headTeamOne->next;
            delete garbage;
        }
    }
    headTeamOne = nullptr;

    // delete player two
    if (headTeamTwo != nullptr) {
        while (headTeamTwo != nullptr) {
            garbage = headTeamTwo;
            headTeamTwo = headTeamTwo->next;
            delete garbage;
        }
    }
    headTeamTwo = nullptr;

    // delete loser list
    if (losersList != nullptr) {
        while (losersList != nullptr) {
            garbage = losersList;
            losersList = losersList->next;
            delete garbage;
        }
    }
    losersList = nullptr;

    // display any remaining nodes
    cout << "Team One List after destructor " << headTeamOne << endl;
    cout << "Team Two List after destructor " << headTeamTwo << endl;
    cout << "LTeam List after destructor " << losersList << endl;
}

/*********************************************************************
** Description:     adds heroes to the linked list for player 1 and
**                  player 2
*********************************************************************/
void HeroList::addHeroes(Player player, int heroType, string heroName) {
    switch (player) {
        case FIRSTPLAYER:
            // assign pickHero to the right team list
            addHeroNode(heroType, heroName, headTeamOne);
            break;
        case SECONDPLAYER:
            addHeroNode(heroType, heroName, headTeamTwo);
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
** Description:     adds a hero node to the back of the node list for
**                  a hero team
*********************************************************************/
void HeroList::addHeroNode(int heroType, string heroName, HeroNode *&team) {
    if (team == nullptr) {
        team = new HeroNode( pickHero(heroType, heroName) );
    }
    else {
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
        cout << " There are no losers in the list!\n"
                "+--------------------------------------------------+\n";
        return;
    }
    else {
        cout << "\n WE HONOR THE BRAVE FALLEN HEROES - RIP\n"
                "+--------------------------------------------------+\n";
        while (nodePtr != nullptr) {
            // display hero name and type
            cout << "    " << nodePtr->hero->getName() << " - "
                 << nodePtr->hero->getType() <<endl;
            // get next fallen hero, if any
            nodePtr = nodePtr->next;
        }
        cout << endl << endl;
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
** Description:     checks to see whether a particular team list is
**                  empty
*********************************************************************/
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
    return false; // unused return value
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
** Description:     sends winner and loser hero to the right list.
**                  Function takes an enum variable that lets the
**                  function know who lost the round. The hero that
**                  lost is send to the losers list and removed from
**                  the team list and the winner is sent to the back
**                  of their team list.
*********************************************************************/
void HeroList::sortHeroes(Player player) {
    if (player == FIRSTPLAYER) {
        cout << "sortHeroes() Loser: " << headTeamOne->hero->getName() << endl;
        addLoser(headTeamOne);
        moveBack(headTeamTwo);
    }
    else if (player == SECONDPLAYER) {
        cout << "sortHeroes() Loser: " << headTeamTwo->hero->getName() << endl;
        addLoser(headTeamTwo);
        moveBack(headTeamOne);
    }
}

/*********************************************************************
** Description:     moves winner hero to the back of the queue
*********************************************************************/
void HeroList::moveBack(HeroNode *&winnerTeam) {
    // TODO - delete this after debugged
    HeroNode *oldHead = winnerTeam;
    cout << "Original winner list\n";
    while (oldHead != nullptr) {
        cout << oldHead->hero->getName() << " - ";
        oldHead = oldHead->next;
    }
    cout << endl;


    HeroNode *head = winnerTeam;
    cout << "Winner to move back " << head->hero->getName() << endl;

    while (winnerTeam->next != nullptr) {
        cout << "Move back ops, Scrolling past list " << winnerTeam->hero->getName() << endl;
        winnerTeam = winnerTeam->next;
    }

    // restore player strength
    head->hero->setStrength( restoreHealth(head) );

    // make player last node on list
    winnerTeam->next = head;
    // point back to head
    winnerTeam = head->next;
    // point next pointer to null
    head->next = nullptr;




    // TODO - delete this after debugged
    HeroNode *newHead = winnerTeam;
    cout << "Updated winner list\n";
    while (newHead != nullptr) {
        cout << newHead->hero->getName() << " - ";
        newHead = newHead->next;
    }
    cout << endl;


}

/*********************************************************************
** Description:     adds defeated hero to loser list implemented as
**                  a stack
*********************************************************************/
void HeroList::addLoser(HeroNode *&loserTeam) {
    // TODO - delete this after debuggged
    cout << "\naddLoser() Match loser " << loserTeam->hero->getName() << endl;



    // remove defeated hero from team
    HeroNode *head = loserTeam;
    loserTeam = head->next;
    head->next = nullptr;

    // add defeat hero to top of stack
    if (losersList == nullptr) {
        losersList = head;
    }
    else {
        HeroNode *loserHead = losersList;
        head->next = loserHead;
        losersList = head;
    }



    // TODO - delete this after debugged
    HeroNode *loserHead = losersList;
    cout << "addLoser() Loser list heroes traversal\n";
    while (loserHead != nullptr) {
        cout << loserHead->hero->getName() << " - ";
        loserHead = loserHead->next;
    }


    // TODO - delete this after debugged
    HeroNode *newHead = loserTeam;
    cout << "\n\naddLoser() Updated team with loser removed\n";
    if (newHead == nullptr) { cout << "loserTeam is now empty\n"; }
    while (newHead != nullptr) {
        cout << newHead->hero->getName() << " - ";
        newHead = newHead->next;
    }
    cout << endl << endl;

}

/*********************************************************************
** Description:     calculates health to restore. Takes in a constant
**                  player hero and calculates the max health a
**                  player can have. Then health to restore is
**                  randomly selected and calculated. Functions
**                  returns the total player health to restore.
*********************************************************************/
int HeroList::restoreHealth(const HeroList::HeroNode *player) {
    int restoreHealth = 0;
    int maxHealth = 0;

    // set hero max strength allowed
    if ( player->hero->getType() == "Vampire" ) { maxHealth = 18; }
    if ( player->hero->getType() == "Barbarian" ) { maxHealth = 18; }
    if ( player->hero->getType() == "Blue Men" ) { maxHealth = 18; }
    if ( player->hero->getType() == "Medusa" ) { maxHealth = 18; }
    if ( player->hero->getType() == "Harry Potter" ) { maxHealth = 18; }

    // determine health lost
    int strengthLost = maxHealth - player->hero->getStrength();
    // calculate health to restore not to exceed strength lost
    restoreHealth = ((rand() % 10 + 1) / 10.0) * strengthLost;
    // increase player health
    restoreHealth += player->hero->getStrength();

    // return player health to restore
    return restoreHealth;
}

/*********************************************************************
** Description:     displays loser list by traversing the list
*********************************************************************/
void HeroList::displayLoserList() {
    traverseForward(losersList);
}

/*********************************************************************
** Description:     empties the loser list
*********************************************************************/
void HeroList::emptyLoserList() {
    // TODO - make sure this deletes the characters
    cout << "Team One List " << headTeamOne << endl;
    cout << "Team Two List " << headTeamTwo << endl;
    cout << "Loser List " << losersList << endl << endl;

    // delete loser node list
    cout << "DELETING loserList:\n";
    if (losersList != nullptr) {
        while (losersList != nullptr) {
            HeroNode *headLoser = losersList;
            Character *garbageHero = headLoser->hero; // delete character
            cout << "Loser hero deleted " << headLoser->hero->getName() << endl;
            losersList = losersList->next;
            //cout << "emptyLoserList() Loser hero deleted - " << garbageHero->getName() << endl; // delete character
            delete garbageHero; // delete character
            delete headLoser;
        }
    }
    //losersList = nullptr;
    cout << endl;

    // TODO delete team 1 heroes
    cout << "\nDELETING Team One list:\n";
    if (headTeamOne != nullptr) {
        while (headTeamOne != nullptr) {
            HeroNode *headTeam1 = headTeamOne;
            Character *garbageHero = headTeam1->hero;
            cout << "Team One Hero deleted - " << headTeam1->hero->getName() << endl;
            headTeamOne = headTeamOne->next;
            delete garbageHero;
            delete headTeam1;
        }
    }

    // TODO delete team 2 heroes
    cout << "\nDELETING Team Two list:\n";
    if (headTeamTwo != nullptr) {
        while (headTeamTwo != nullptr) {
            HeroNode *headTeam2 = headTeamTwo;
            Character *garbageHero = headTeam2->hero;
            cout << "emptyLoserList() T2 Hero deleted - " << headTeam2->hero->getName() << endl;
            headTeamTwo = headTeamTwo->next;
            delete garbageHero;
            delete headTeam2;
        }
    }


    cout << "Team One List " << headTeamOne << endl;
    cout << "Team Two List " << headTeamTwo << endl;
    cout << "Loser List " << losersList << endl << endl;
}