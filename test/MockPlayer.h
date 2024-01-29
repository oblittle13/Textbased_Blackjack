#ifndef MOCKPLAYER_H
#define MOCKPLAYER_H

#include <string>
#include <vector>

#include "Player.h"

class MockPlayer : public Player {
 public:
    explicit MockPlayer() {}
    virtual ~MockPlayer() {}

    MOCK_METHOD0(getName, std::string());
    MOCK_METHOD1(hit, void(Card*));
    MOCK_METHOD0(split, void());
    MOCK_METHOD0(stand, void());
    MOCK_METHOD0(isBust, bool());
    MOCK_METHOD0(getRoundsWon, int());
    MOCK_METHOD0(winRound, void());
    MOCK_METHOD0(getTurnIsActive, bool());
    MOCK_METHOD0(getHand, Hand*());
    MOCK_METHOD0(getHands, std::vector<Hand*>());
    MOCK_METHOD0(getScore, int());
};

#endif
