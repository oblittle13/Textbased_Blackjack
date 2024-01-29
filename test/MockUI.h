#ifndef MOCKUI_H
#define MOCKUI_H

#include <string>
#include <vector>

#include "UI.h"

class MockUI : public UI {
 public:
    explicit MockUI() {}
    virtual ~MockUI() {}

    MOCK_METHOD1(displayHand, void(Player* player));
    MOCK_METHOD1(displayWinner, void(Player* player));
    MOCK_METHOD1(displayBust, void(Player* player));
    MOCK_METHOD1(displayBlackjack, void(Player* player));
    MOCK_METHOD1(displayScore, void(Player* player));
    MOCK_METHOD0(gameMenu, void());
    MOCK_METHOD0(splitMenu, void());
    MOCK_METHOD0(help, void());
    MOCK_METHOD0(invalid, void());
    MOCK_METHOD0(playAgain, bool());
    MOCK_METHOD0(handleInput, int());
    MOCK_METHOD1(open, void(const std::string& f));
};

#endif
