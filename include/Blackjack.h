#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>

#include "Deck.h"
#include "Player.h"
#include "UI.h"


class Blackjack {
 public:
    /**
    * Create a Blackjack object
    * @param players : Vector of Player pointers to Players who are playing the
    * game
    * @param dealer : Player pointer indicating the Dealer of the game
    */
    Blackjack(std::vector<Player*> players, Player* dealer);

    /**
     * Destructore for a Blackjack object
    */
    virtual ~Blackjack() {
        for (Player* player : players)
            delete player;

        delete dealer;
        delete deck;
        delete ui;
    }

    /**
    * Start a game of blackjack
    */
    virtual void playGame();
    /**
    * Play a round of blackjack
    */
    virtual void playRound();

    /**
    * Reset the current round of blackjack to its default state
    */
    virtual void resetRound();

    /**
    * Deal a card to a specified player
    * @param player : The Player designated to recieve the dealt card
    */
    virtual void dealCard(Player* player);

    /**
    * Check to see if the game has been won
    */
    virtual void checkWin();

    /**
    * Dealer plays their turn
    */
    virtual void dealerPlay();

    /**
    * Human plays their turn
    */
    virtual void humanPlay();

    /**
    * Computer plays their turn
    */
    virtual void computerPlay();

    /**
    * Change the view for blackjack
    * @param ui : UI pointer that indicates the User interface to change to
    */
    virtual void setUI(UI* ui);

    /**
     * Sets the deck of cards that will be used for the game
     * @param deck : The deck of cards used for the game
    */
    virtual void setDeck(Deck* deck);

 private:
    /**< Dealer of the game */
    Player* dealer;
    /**< List of players in the game */
    std::vector<Player*> players;
    /**< Deck of cards to be used */
    Deck* deck = nullptr;
    /**< Current user interface */
    UI* ui = nullptr;
    /**< Currently active player */
    int index;
};

#endif
