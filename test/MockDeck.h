#ifndef MOCKDECK_H
#define MOCKDECK_H

#include "Deck.h"

class MockDeck : public Deck {
 public:
    explicit MockDeck() {}
    virtual ~MockDeck() {}

    MOCK_METHOD0(shuffle, void());
    MOCK_METHOD0(dealCard, Card*());
    MOCK_METHOD1(addCard, void(Card card));
};

#endif
