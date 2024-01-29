#ifndef CARD_H
#define CARD_H

/**
 * Enumeration for card ranks
*/
enum Rank {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

/**
 * Enumeration for card suits
*/
enum Suit {
    CLUB = 1,
    SPADE,
    HEART,
    DIAMOND
};

class Card {
 public:
    /**
    * Create a Card object
    * @param suit : The suit (symbol) the card has
    * @param rank : The rank (number or letter) the card has
    */
    Card(Suit suit, Rank rank);

    /**
     * Default Card object constructor
    */
    Card() {}

    /**
     * Destructor for Card objects
    */
    virtual ~Card() {}

    /**
    * Retrieve the rank of the card
    * @return The rank of the card
    */
    Rank getRank();

    /**
    * Return the value of the card. A card's value is the rank they
    * have. If the rank is a J/Q/K, their value is 10. If the Rank
    * is an Ace, run aceValue to determine its value.
    * @return The value of the card
    */
    int getValue();

    /**
     * Sets the Card attribute Ace to true if the card is an ace,
     * otherwise false
    */
    void setAce(bool a);

    /**
     * Determines if the card is an ace
     * @return true if the card is an ace, false otherwise
    */
    bool isAce();

    /**
     * Sets the value of a card
     * @param int : integer to be the cards value
    */
    void setValue(int);

    /**
    * Retrieves the suit of the card
    * @return The suit of the card
    */
    Suit getSuit();

    /**
     * Converts the rank into a char
     * @return char that corresponds to the rank
    */
    char convertRank();

    /**
     * Converts the sui into a char
     * @return char that corresponds to the suit
    */
    char convertSuit();

 private:
    Suit suit;
    Rank rank;
    int value;
    bool ace;
};

#endif
