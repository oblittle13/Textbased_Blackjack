#ifndef UI_H
#define UI_H

#include <string>
#include <vector>

#include "Player.h"

class UI {
 public:
    virtual ~UI() {}

    /**
    * Displays the hand of a player
    * @param player the player who owns the hand to be displayed
    */
    virtual void displayHand(Player* player);

    /**
    * Displays the winner(s) to the UI
    */
    virtual void displayWinner(std::vector<Player*>);

    /**
    * Display the busted message
    */
    virtual void displayBust(Player* player);

    /**
    * Display the Blackjack message
    */
    virtual void displayBlackjack(Player* player);

    /**
    * Display the player's wins
    */
    virtual void displayScore(Player* player);

    /**
    * Display the player's wins
    */
    virtual void displayMessage(const std::string&);

    /**
    * Display the player's wins
    */
    virtual void displayNewShoe(const char* message);

    /**
    * Display the in-game menu to the player
    */
    virtual void gameMenu();

    /**
    * Display the split menu to the player
    */
    virtual void splitMenu();

    /**
    * Displays helpful information to the UI
    */
    virtual void help();

    /**
    * Inform the player of incorrect input
    */
    virtual void invalid();

    /**
    * Asks player if they want to play again
    * @return true : if Players choice is to play again, false otherwise
    */
    virtual bool playAgain();

    /**
    * Function which handles the input for a player during their turn
    * @return the choice of the player
    */
    virtual int handleInput();

    /**
    * Open a file and print out the contents.
    * @param[in] f the filename of the file.
    */
    virtual void open(const std::string& f);
};

#endif
