/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
** Description:     Game class holds various classes in it and is the
**                  main driver behind the game. The game flow is
**                  controlled with various functions here and
**                  the menu and character objects live inside the
**                  Game class. Enums are used to provide for more
**                  readable code where possible.
*********************************************************************/
#include "game.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Game::Game(): fighterType{UNSET}, teamQty{0}, rounds{0} {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Game::~Game() {}

/*********************************************************************
** Description:     this function is called from main to get the game
**                  started. This function calls another function that
**                  presents the main menu options. A user can start
**                  the game here or quit.
*********************************************************************/
void Game::playGame() {
    // show main menu
    menu.mainMenu();
    startGame();
}

/*********************************************************************
** Description:     this function assists with the game initialization
**                  process and routes the program flow to the next
**                  processes: character selection or quit game.
*********************************************************************/
void Game::startGame() {
    int sel = menu.validateNumber(1,2);
    switch (sel) {
        case 1:
            // play game
            gameFlow();
            break;
        case 2:
            // quit game
            exitGame();
            break;
        default:
            cout << "Unable to determine your selection!\n";
    }
}

/*********************************************************************
** Description:     this function controls the flow of the game. The
**                  functions calls other functions to initialize
**                  the players, initialize the dice, and start
**                  combat operations.
*********************************************************************/
void Game::gameFlow() {
    do {
        // select number of fighters for each team
        setTeam();

        // select player
        selectPlayer();

        // create combatant dice
        playerOne->initializeDice();
        playerTwo->initializeDice();

        // start combat
        startCombat();
    } while (playAgain());
}

/*********************************************************************
** Description:     this function allows a player to set up the teams
**                  for each side
**                  or false bool value.
*********************************************************************/
void Game::setTeam() {
    // prompt user to select team players
    menu.menuTotalFighters();


}

/*********************************************************************
** Description:     this functions is called to allow a player to
**                  select their character. Each character is
**                  dynamically allocated depending on which one
**                  is chosen. Player one and player two are assigned
**                  to class data variables.
*********************************************************************/
void Game::selectPlayer() {
// initialize fighters chosen to fight
    for (int player: {0,1}) {
        menu.menuSelectFighter(player+1);
        switch (menu.validateNumber(1,5)) {
            case 1:
            {
                fighterType[player] = VAMPIRE;
                if (player == 0) {
                    playerOne = new Vampire;
                }
                else if (player == 1) {
                    playerTwo = new Vampire;
                }
            }
                break;
            case 2:
            {
                fighterType[player] = BARBARIAN;
                if (player == 0) {
                    playerOne = new Barbarian;
                }
                else if (player == 1) {
                    playerTwo = new Barbarian;
                }
            }
                break;
            case 3:
            {
                fighterType[player] = BLUEMEN;
                if (player == 0) {
                    playerOne = new BlueMen;
                }
                else if (player == 1) {
                    playerTwo = new BlueMen;
                }
            }
                break;
            case 4:
            {
                fighterType[player] = MEDUSA;
                if (player == 0) {
                    playerOne = new Medusa;
                }
                else if (player == 1) {
                    playerTwo = new Medusa;
                }
            }
                break;
            case 5:
            {
                fighterType[player] = HARRYPOTTER;
                if (player == 0) {
                    playerOne = new HarryPotter;
                }
                else if (player == 1) {
                    playerTwo = new HarryPotter;
                }
            }
                break;
            default:
                cout << "Unable to determine fighter type\n";
        }
    }

    // confirm players with user
    int type[2] = {};
    for (int player: {0,1}) {
        type[player] = fighterType[player];
    }
    menu.menuDisplayPlayers(type[0], type[1]);

}

/*********************************************************************
** Description:     this function performs the combat operations
**                  between the two players. A while loop is employed
**                  to continue combat until a player has died. Each
**                  player has a turn in attacking and defending.
**                  After the game has ended, the dynamically created
**                  players are deleted.
*********************************************************************/
void Game::startCombat() {
    bool playerDead = false;

    do {
        // display banner for each round played
        rounds++;
        menu.menuRound(rounds);

        // first player attacks
        if (!playerDead) {
            playerOne->attackPlayer(playerTwo);
            playerTwo->defend();
            playerTwo->strengthUpdate(); // issue is here
            playerTwo->checkStrength();
            playerDead = checkDeath(playerTwo);
        }
        cout << endl;

        // second player attacks
        if (!playerDead) {
            playerTwo->attackPlayer(playerOne);
            playerOne->defend();
            playerOne->strengthUpdate();
            playerOne->checkStrength();
            playerDead = checkDeath(playerOne);
        }

        // pause between rounds
        cout << "\nHit [ENTER] to continue to next round\n";
        cin.ignore();

    } while (!playerDead);

    // free allocated memory for players created during each fight
    delete playerOne;
    delete playerTwo;
    playerOne = nullptr;
    playerTwo = nullptr;
}

/*********************************************************************
** Description:     this function checks to see if a player has died
**                  and returns true if yes and false if not
*********************************************************************/
bool Game::checkDeath(Character *defender) {
    bool playerDied = false;
    if (defender->playerStatus()) {
        menu.menuDeath(defender->getName());
        playerDied = true;
    }
    return playerDied;
}

/*********************************************************************
** Description:     this function controls if a player would like to
**                  play again after combat is over. Returns a true
**                  or false bool value.
*********************************************************************/
bool Game::playAgain() {
    bool selection = false;
    menu.menuPlayAgain();
    switch (menu.validateNumber(1,2)) {
        case 1:
            selection = true;
            rounds = 0;
            break;
        case 2:
            selection = false;
            break;
        default:
            cout << "Unable to determine your choice!\n";
    }
    return selection;
}

/*********************************************************************
** Description:     this functions prompts user that they have quit
**                  the game
*********************************************************************/
void Game::exitGame() {
    menu.menuExitGame();
}