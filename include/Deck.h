#ifndef DECK_H
#define DECK_H

#include <exception>
#include <vector>

#include "Card.h"

const int CARDS_PER_DECK = 52;
const int SUITS = 4;
const int CARDS_PER_SUIT = 13;

class DeckEmpty : public std::exception {
 public:
    const char* what() const throw() {
        return "The deck is empty.";
    }
};

class Deck {
 public:
    /**
    * Create a Deck object
    * @param cards : Vector of Card pointers to Cards that are in the deck
    */
    Deck(std::vector<Card*> cards);

    /**
     * Default Deck object constructor
    */
    Deck();

    /**
     * Destructor for Deck objects
    */
    virtual ~Deck() {
        for (Card* card : cards) {
            delete card;
        }
    }

    /**
    *  Randomize the order of the deck
    */
    virtual void shuffle();

    /**
    *  Return a random card from the deck to deal
    *  @return The randomly picked card object
    */
    virtual Card* dealCard();

    /**
    *  Add a Card to the deck
    *  @param card : The card being added
    */
    virtual void addCard(Card* card);

    /**
     * Determines if the Deck is empty
     * @return true if empty, otherwise false
    */
    virtual bool isEmpty();

 private:
    std::vector<Card*> cards; /**< List of cards in the deck */
};

#endif
