#ifndef INCLUDE_HAND_H_
#define INCLUDE_HAND_H_

#include <vector>

#include "Card.h"

class Hand {
 public:
    /**
     * Default Hand object constructor
    */
    Hand() :
        stand(false),
        score(0) {}

  /**
   * Create a Hand object
   * @param cards: vector of card pointers pointing to cards in the hand
   */
    Hand(std::vector<Card*> cards) :
        cards(cards),
        stand(false) {}

    /**
     * Destructor for Hand objects
    */
    virtual ~Hand() {
        for (Card* card : cards)
            delete card;
    }

    /**
    * Gets cards in a hand and returns them as a vector
    * @return a vector of cards
    */
    virtual std::vector<Card*> getCards();

    /**
    * Adds a card to a hand
    * @param card: a card pointer
    */
    virtual void addCard(Card* card);

    /**
     * Removes a card from the Hand, and returns it
     * @return Card* of card that was removed
    */
    virtual Card* removeCard();

    /**
    * Returns the score
    * @return the score as an integer
    */
    virtual int getScore();

    /**
    * Removes a card from the hand
    */
    virtual void resetHand();

    /**
    * Sets the score data member of the hand
    * @param s The integer to set the score to
    */
    virtual void setScore(int s);

    /**
    * Sets the hand to finished and not draw a card (when stand is called or the hand goes bust)
    * @param s: bool for whether the hand is finished or not
    */
    virtual void setFinished(bool s);

    /**
    * Gets the finished status of the hand
    * @return true if finished, otherwise false
    */
    virtual bool getFinished();

    /**
    * Gets the size of the hand
    * @return integer indicating size of the hand
    */
    virtual int getSize();

    /**
    * Is the hand splittable?
    * @return true if it is, otherwise false
    */
    virtual bool isSplittable();

 private:
    std::vector<Card*> cards; /**< List of cards in the hand */
    int score; /**< Score of the hand*/
    bool stand; /**< If the hand is in stand state*/
};

#endif /* INCLUDE_HAND_H_ */
