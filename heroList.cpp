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
    losers{nullptr} {}

/*********************************************************************
** Description:     node list destructor
*********************************************************************/
HeroList::~HeroList() {
    HeroNode *garbage = nullptr;

    // delete player one
    if (headTeamOne != nullptr) {
        while (headTeamOne != nullptr) {
            garbage = headTeamOne;
            headTeamOne = headTeamOne->next;
            delete garbage;
        }
    }

    // delete player two
    if (headTeamTwo != nullptr) {
        while (headTeamTwo != nullptr) {
            garbage = headTeamTwo;
            headTeamTwo = headTeamTwo->next;
            delete garbage;
        }
    }

    // delete loser list
    if (losers != nullptr) {
        while (losers != nullptr) {
            garbage = losers;
            losers = losers->next;
            delete garbage;
        }
    }

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
            traverseForward(headTeamOne);   // delete this function
            break;
        case SECONDPLAYER:
            addHeroNode(heroType, heroName, headTeamTwo);
            traverseForward(headTeamTwo);   // delete, not needed
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
        cout << "There are no losers in the list!\n";
        return;
    }
    else {
        cout << "\n BRAVE HEROES THAT FOUGHT BRAVELY - RIP\n"
                "+--------------------------------------------------+\n";
        while (nodePtr != nullptr) {
            cout << "Hero name is " << nodePtr->hero->getName() << endl;
            nodePtr = nodePtr->next;
        }
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
void HeroList::sortHeros(Player player) {
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
    cout << "move hero back fx called\n";
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
** Description:     adds loser hero to loser list implemented as a
**                  stack
*********************************************************************/
void HeroList::addLoser(HeroNode *&loserTeam) {
    // implement a stack for the losers list


    cout << "add losing hero to list fx\n";
    HeroNode *head = loserTeam;

    loserTeam = head->next;

    head->next = nullptr;

    if (losers == nullptr) {
        losers = head;
    }
    else {
        HeroNode *loserHead = losers;

        while (losers->next != nullptr) {
            losers = losers->next;
        }

        losers->next = head;

        losers = loserHead;
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
** Description:     displays loser list
*********************************************************************/
void HeroList::displayLoserList() {
    traverseForward(losers);
}
