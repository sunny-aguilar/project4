/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Mar 1, 2019
** Description:     Game class holds various classes in it and is the
**                  main driver behind the game. The game flow is
**                  controlled with various functions here and
**                  the menu and character objects live inside the
**                  Game class. Enums are used to provide for more
**                  readable code where possible. The game class also
**                  implements a Queue list used for holding
**                  characters in a linked list.
*********************************************************************/
#include "game.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Game::Game() :
    fighterType{UNSET},
    teamOneQty{0},
    teamTwoQty{0},
    rounds{0},
    match{1},
    teamOneScore{0},
    teamTwoScore{0} {}

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

        // start combat
        //heroes.startTournament();
        while (!heroes.isTeamEmpty(FIRSTPLAYER) && !heroes.isTeamEmpty(SECONDPLAYER)) {
            // start combat rounds
            startCombat(heroes.getHero(FIRSTPLAYER), heroes.getHero(SECONDPLAYER));
            // next match count
            match++;

            // send heroes to their proper destination
            heroes.sortHeroes(roundLoser);

            // TODO reset round loser; delete if not needed
            roundLoser = NONE;

            // continue with rounds again
            rounds = 0;     // reset round number

        }

        // display team scores and winning team
        menu.menuDisplayScores(teamOneScore, teamTwoScore);

        // display loser list
        displayLoserList();

        // reset match
        match = 1;

        // reset team scores
        resetScore();

        // TODO - delete defeated heroes
        heroes.emptyLoserList();

    } while (playAgain());
}

/*********************************************************************
** Description:     this function allows a player to set up the teams
**                  for each side
*********************************************************************/
void Game::setTeam() {
    // prompt user to select team players
    menu.menuTotalFighters(1);
    teamOneQty = menu.validateNumber(1,100);
    menu.menuTotalFighters(2);
    teamTwoQty = menu.validateNumber(1,100);
}

/*********************************************************************
** Description:     this functions is called to allow a player to
**                  select their character. Each character is
**                  dynamically allocated depending on which one
**                  is chosen. Player one and player two are assigned
**                  to class data variables.
*********************************************************************/
void Game::selectPlayer() {
    string heroName;
    int heroType;
    for (int index = 0; index < teamOneQty; index++) {
        menu.menuSelectFighter(FIRSTPLAYER, index+1);
        heroType = menu.validateNumber(1,5);

        menu.menuEnterHeroName();
        getline(cin, heroName);
        heroes.addHeroes(FIRSTPLAYER, heroType, heroName);
    }


    for (int index = 0; index < teamTwoQty; index++) {
        menu.menuSelectFighter(SECONDPLAYER, index+1);
        heroType = menu.validateNumber(1,5);

        menu.menuEnterHeroName();
        getline(cin, heroName);
        heroes.addHeroes(SECONDPLAYER, heroType, heroName);
    }
}

/*********************************************************************
** Description:     this function performs the combat operations
**                  between the two players. A while loop is employed
**                  to continue combat until a player has died. Each
**                  player has a turn in attacking and defending.
**                  After the game has ended, the dynamically created
**                  players are deleted.
*********************************************************************/
void Game::startCombat(Character *playerOne, Character *playerTwo) {
    bool playerDead = false;
    bool playerOneWon = false;
    bool playerTwoWon = false;

    do {
        // TODO - COMMENT THIS MENU OUT -  display match banner
        //menu.menuDisplayMatch( playerOne->getName(),
                               //playerOne->getType(),
                               //playerTwo->getName(),
                               //playerTwo->getType(), match );

        // TODO - COMMENT THIS MENU OUT - display combat banner for each round played
        //rounds++;
        //menu.menuRound(rounds);

        // first player attacks
        if (!playerDead) {

            playerOne->attackPlayer(playerTwo);
            playerTwo->defend();
            playerTwo->strengthUpdate(); // issue is here
            playerTwo->checkStrength();
            playerDead = checkDeath(playerTwo);

            // report who won and who died
            if (playerDead) {
                playerOneWon = true;
            }
        }
        cout << endl;

        // second player attacks
        if (!playerDead) {
            playerTwo->attackPlayer(playerOne);
            playerOne->defend();
            playerOne->strengthUpdate();
            playerOne->checkStrength();
            playerDead = checkDeath(playerOne);

            // report who won and who died
            if (playerDead) {
                playerTwoWon = true;
            }
        }

        // calculate team scores
        teamScore(playerOneWon, playerTwoWon);

        // set round loser
        roundLoser = getLoser(playerOneWon, playerTwoWon);

        // TODO pause between rounds - COMMENT OUT
        // cout << "\nHit [ENTER] to continue to next round\n";
        // cin.ignore();

    } while (!playerDead);


    // display match winner and loser
    menu.menuWinnerLoser( playerOne->getName(), playerTwo->getName(),
                          playerOne->getType(), playerTwo->getType(),
                          playerOneWon, playerTwoWon);

}

/*********************************************************************
** Description:     this function checks to see if a player has died
**                  and returns true if yes and false if not
*********************************************************************/
bool Game::checkDeath(Character *defender) {
    bool playerDied = false;
    if (defender->playerStatus()) {
        //menu.menuDeath(defender->getName());
        playerDied = true;
    }
    return playerDied;
}

/*********************************************************************
** Description:     calculates the team score. Score can go negative
**                  if player has too many losses.
*********************************************************************/
void Game::teamScore(bool playerOneResult, bool playerTwoResult) {
    if (playerOneResult) {
        teamOneScore += 2;
        teamTwoScore -= 1;
    }
    else if (playerTwoResult) {
        teamTwoScore += 2;
        teamOneScore -= 1;
    }
}

/*********************************************************************
** Description:     resets team scores after game is over
*********************************************************************/
void Game::resetScore() {
    teamTwoScore = 0;
    teamTwoScore = 0;
}

/*********************************************************************
** Description:     returns enum that states which player lost the
**                  combat round
*********************************************************************/
Player Game::getLoser(bool playerOneResult, bool playerTwoResult) {
    if (!playerOneResult) {
        return FIRSTPLAYER;
    }
    else if (!playerTwoResult) {
        return SECONDPLAYER;
    }
}

/*********************************************************************
** Description:     prompts the user to see if they want to see the
**                  loser list by calling the appropriate functions
*********************************************************************/
void Game::displayLoserList() {
    menu.displayLosers();
    switch (menu.validateNumber(1,2)) {
        case 1:
            heroes.displayLoserList();
            break;
        case 2:
            return;
        default:
            cout << "Unable to determine list to display!\n";
    }
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