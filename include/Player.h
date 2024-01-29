#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>
#include <vector>

#include "Card.h"
#include "Hand.h"

class Player {
 public:
    Player();

    /**
    * Constructor
    * @param name : The player's name
    */
    Player(std::string name);

    /**
     * Destructor for Player objects
    */
    virtual ~Player();

    /**
    * Gets the player's name
    * @returns the player's name
    */
    virtual std::string getName() const;

    /**
    * Make the player recieve a hit from the dealer
    * @param card : The card given to the player
    */
    virtual void hit(Card* card);

    /**
    * Initiates a split on the player's hand
    */
    virtual void split();

    /**
    *  Sets the current hand in play to stand status
    */
    virtual void stand();

    /**
    * Checks if the player has gone bust
    * @return true if bust, else false
    */
    virtual bool isBust();

    /**
    * Increments the rounds won by the player
    */
    virtual void incrementScore();

    /**
    * Changes which hand is the next used by player
    * @param int : integer to set the player hand
    */
    virtual void setHand(int h);

    /**
     * Retrieve the index that points to which hand the user is using
     * @return Index for current hand
    */
    virtual int getHandIndex();

    /**
     * Sets the index of the current hand
     * @param i : the index to set for the current hand
    */
    virtual void setHandIndex(int i);

    /**
    * Retrieves the active status of the Hand
    * @return the turnIsActive status, which is true if the the player still has
    * non busted hands that the player has not stood
    */
    virtual bool isActive();

    /**
     * Sets the active status of a Hand
     * @param a : boolean corresponding to active status 
    */
    virtual void setActive(bool a);

    /**
    * Gets the players hands
    * @return a vector of the player's current hands
    */
    virtual std::vector<Hand*> getHands();

    /**
     * Retrieves the Hand the user has
     * @return Hand* for players current Hand
    */
    virtual Hand* getHand();

    /**
     * Returns the size of the players current hand
     * @return Integer for the size of the current hand
    */
    virtual int getHandSize();

    /**
     * Returns the score of the players current hand
     * @return Integer for the score of the current hand
    */
    virtual int getHandScore();

    /**
    * Gets the players score
    * @return an int of the player's score
    */
    virtual int getScore();

    /**
     * Returns if the players current hand is a blackjack
     * @returns True if it is blackjack, otherwise false
    */
    virtual bool isBlackjack();

    /**
     * Removes current hand from the players
    */
    virtual void removeHand();

 private:
    std::string name; /**< String indicating players name*/
    std::vector<Hand*> hands; /**< Vector of hands the player is playing*/
    Hand* hand; /**< Pointer to currently selected player hand*/
    int score; /**< Score of the player*/
    int index; /**< Index for the players current hand*/
    bool active; /**< Boolean for active status of player*/
};

#endif
