#ifndef MOCKCARD_H
#define MOCKCARD_H

#include "Card.h"

class MockCard : public Card {
 public:
    explicit MockCard(Suit suit, Rank rank) {}
    explicit MockCard() {}
    virtual ~MockCard() {}

    MOCK_METHOD0(getRank, Rank());
    MOCK_METHOD0(getValue, int());
};

#endif

