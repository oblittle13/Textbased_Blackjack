#ifndef MOCKHAND_H
#define MOCKHAND_H

#include <vector>

#include "Hand.h"

class MockHand : public Hand {
 public:
    explicit MockHand() {}
    virtual ~MockHand() {}

    MOCK_METHOD0(getCards, std::vector<Card*>());
    MOCK_METHOD1(addCard, void(Card * card));
    MOCK_METHOD0(removeCard, Card*());
    MOCK_METHOD0(getScore, int());
    MOCK_METHOD1(setScore, void(int num));
    MOCK_METHOD1(setFinished, void(bool stand));
    MOCK_METHOD0(getFinished, bool());
};

#endif
