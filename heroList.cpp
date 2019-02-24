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
    cout << "Team One List " << headTeamOne << endl;
    cout << "Team Two List " << headTeamTwo << endl;
    cout << "LTeam List " << losersList << endl;

    // display if characters exist
    // cout << "Characters team 1 " << headTeamOne->hero << endl;
    cout << "Characters team 2 " << headTeamTwo->hero << endl;



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
        addLoser(headTeamOne);
        moveBack(headTeamTwo);
    }
    else if (player == SECONDPLAYER) {
        addLoser(headTeamTwo);
        moveBack(headTeamOne);
    }
}

/*********************************************************************
** Description:     moves winner hero to the back of the queue
*********************************************************************/
void HeroList::moveBack(HeroNode *&winnerTeam) {
    HeroNode *head = winnerTeam;

    while (winnerTeam->next != nullptr) {
        winnerTeam = winnerTeam->next;
    }

    // restore player strength
    head->hero->setStrength( restoreHealth(head) );

    // make player last node on list
    winnerTeam->next = head;
    // next node
    winnerTeam = head->next;
    // point next pointer to null
    head->next = nullptr;

}

/*********************************************************************
** Description:     adds defeated hero to loser list implemented as
**                  a stack
*********************************************************************/
void HeroList::addLoser(HeroNode *&loserTeam) {
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
//    HeroNode *loserHead = losersList;
//    if (loserHead != nullptr) {
//        while (loserHead != nullptr) {
//            Character *garbage1 = loserHead->hero;
//            cout << "Deleting character " << garbage1->getName() << endl;
//            loserHead = loserHead->next;
//            delete garbage1;
//        }
//    }


    // delete loser node list
    HeroNode *head = losersList;
    if (head != nullptr) {
        while (head != nullptr) {
            HeroNode *garbage = head;
            Character *garbage1 = head->hero; // delete character
            head = head->next;
            cout << "Loser hero deleted - " << garbage->hero->getName() << endl; // delete chracter
            delete garbage1; // delete character
            delete garbage;
        }
    }
    losersList = nullptr;

    // TODO delete team 1 heroes
    HeroNode *headTeam1 = headTeamOne;
    if (headTeamOne != nullptr) {
        while (headTeam1 != nullptr) {
            Character *garbageT1 = headTeam1->hero;
            headTeam1 = headTeam1->next;
            cout << "T1 Hero deleted - " << garbageT1->getName() << endl;
            delete garbageT1;
            delete headTeam1;
        }
    }

    // TODO delete team 2 heroes
    HeroNode *headTeam2 = headTeamTwo;
    if (headTeamTwo != nullptr) {
        while (headTeam2 != nullptr) {
            Character *garbageT2 = headTeam2->hero;
            headTeam2 = headTeam2->next;
            cout << "T2 Hero deleted - " << garbageT2->getName() << endl;
            delete garbageT2;
            delete headTeam2;
        }
    }
    cout << "Team One List " << headTeamOne << endl;
    cout << "Team Two List " << headTeamTwo << endl;
}