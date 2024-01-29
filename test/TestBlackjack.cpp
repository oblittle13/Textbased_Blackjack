#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Blackjack.h"
#include "Card.h"
#include "Hand.h"
#include "MockDeck.h"
#include "MockHand.h"
#include "MockPlayer.h"
#include "MockUI.h"

using ::testing::Expectation;
using ::testing::InSequence;
using ::testing::Return;
using ::testing::_;

TEST(TestBlackjack, DISABLED_playGame) {
    // Setup
    MockPlayer player1, player2, dealer;
    std::vector<Player*> players;
    players.push_back(&player1);
    players.push_back(&player2);
    MockDeck deck;
    MockUI ui;

    Card c1(Suit::HEART, Rank::ACE);
    Card c2(Suit::CLUB, Rank::NINE);
    Card c3(Suit::DIAMOND, Rank::NINE);
    Card c4(Suit::DIAMOND, Rank::ACE);
    Card c5(Suit::SPADE, Rank::FOUR);
    Card c6(Suit::SPADE, Rank::EIGHT);
    Card c7(Suit::SPADE, Rank::QUEEN);

    MockHand hand1, hand2, hand3;

    std::vector<Hand*> player1Hand;
    player1Hand.push_back(&hand1);
    player1Hand.push_back(&hand2);

    // Shuffle deck
    Expectation e0 = EXPECT_CALL(deck, shuffle())
    .Times(1)
    .WillOnce(Return());

    // Deal cards
    Expectation e1 = EXPECT_CALL(deck, dealCard())
    .Times(6)
    .After(e0)
    .WillOnce(Return(&c1))
    .WillOnce(Return(&c2))
    // player2
    .WillOnce(Return(&c3))
    // dealer
    .WillOnce(Return(&c4))
    // dealer
    .WillOnce(Return(&c5))
    // dealer
    .WillOnce(Return(&c6));

    EXPECT_CALL(player1, hit(&c1)).Times(1);
    EXPECT_CALL(player2, hit(&c2)).Times(1);
    EXPECT_CALL(dealer, hit(&c3)).Times(1);
    EXPECT_CALL(player1, hit(&c4)).Times(1);
    EXPECT_CALL(player2, hit(&c5)).Times(1);
    EXPECT_CALL(dealer, hit(&c6)).Times(1);

    // Player1's play
    Expectation e2 = EXPECT_CALL(ui, displayHand(_))
    .Times(1)
    .After(e1);

    Expectation e3 = EXPECT_CALL(ui, handleInput())
    .Times(1)
    .After(e2)
    // split
    .WillOnce(Return(3));

    Expectation e4 = EXPECT_CALL(player1, split())
    .Times(1)
    .After(e3)
    .WillOnce(Return());

    Expectation e5 = EXPECT_CALL(player1, getTurnIsActive())
    .Times(1)
    .After(e4)
    .WillOnce(Return(true));

    Expectation e6 = EXPECT_CALL(ui, displayHand(_))
    .Times(1)
    .After(e5);

    Expectation e7 = EXPECT_CALL(ui, handleInput())
    .Times(1)
    .After(e6)
    // stand
    .WillOnce(Return(2));

    Expectation e8 = EXPECT_CALL(player1, stand())
    .Times(1)
    .After(e7)
    .WillOnce(Return());

    Expectation e9 = EXPECT_CALL(player1, getTurnIsActive())
    .Times(1)
    .After(e8)
    .WillOnce(Return(true));

    Expectation e10 = EXPECT_CALL(ui, displayHand(_))
    .Times(1)
    .After(e9);

    Expectation e11 = EXPECT_CALL(ui, handleInput())
    .Times(1)
    .After(e10)
    // stand
    .WillOnce(Return(2));

    Expectation e12 = EXPECT_CALL(player1, stand())
    .Times(1)
    .After(e11)
    .WillOnce(Return());

    Expectation e13 = EXPECT_CALL(player1, getTurnIsActive())
    .Times(1)
    .After(e12)
    .WillOnce(Return(false));

    // Player2's play
    Expectation e14 = EXPECT_CALL(ui, displayHand(_))
    .Times(1)
    .After(e13);

    Expectation e15 = EXPECT_CALL(ui, handleInput())
    .Times(1)
    .After(e14)
    .WillOnce(Return(1));

    Expectation e16 = EXPECT_CALL(deck, dealCard())
    .Times(1)
    .After(e15)
    .WillOnce(Return(&c7));

    Expectation e17 = EXPECT_CALL(player2, hit(&c7))
    .Times(1)
    .After(e16);

    Expectation e18 = EXPECT_CALL(player2, isBust())
    .Times(1)
    .After(e17)
    .WillOnce(Return(true));

    Expectation e20 = EXPECT_CALL(player2, getTurnIsActive())
    .Times(1)
    .After(e18)
    .WillOnce(Return(false));

    // Dealer's play
    Expectation e21 = EXPECT_CALL(ui, displayHand(_))
    .Times(1)
    .After(e20);

    Expectation e22 = EXPECT_CALL(dealer, getScore())
    .Times(1)
    .After(e21)
    .WillOnce(Return(17));

    Expectation e23 = EXPECT_CALL(dealer, stand())
    .Times(1)
    // stand
    .After(e22).WillOnce(Return());

    Expectation e24 = EXPECT_CALL(dealer, getTurnIsActive())
    .Times(1)
    .After(e23)
    .WillOnce(Return(false));

    // checkWin
    Expectation e25 = EXPECT_CALL(dealer, getScore())
    .Times(1)
    .After(e24)
    .WillOnce(Return(17));

    Expectation checkPlayer1Bust = EXPECT_CALL(player1, isBust())
    .Times(1)
    .After(e25)
    .WillOnce(Return(false));

    Expectation getPlayer1Hand = EXPECT_CALL(player1, getHands())
    .Times(1)
    .After(checkPlayer1Bust)
    .WillOnce(Return(player1Hand));

    Expectation player1Hand1Score = EXPECT_CALL(hand1, getScore())
    .Times(1)
    .After(getPlayer1Hand)
    .WillOnce(Return(18));

    Expectation player1Hand1ScoreWin = EXPECT_CALL(player1, winRound())
    .Times(1)
    .After(player1Hand1Score)
    .WillOnce(Return());

    Expectation player1Hand2Score = EXPECT_CALL(hand2, getScore())
    .Times(1)
    .After(player1Hand1ScoreWin)
    .WillOnce(Return(21));

    Expectation player1Hand2ScoreWin = EXPECT_CALL(player1, winRound())
    .Times(1)
    .After(player1Hand2Score)
    .WillOnce(Return());

    Expectation checkPlayer2Bust = EXPECT_CALL(player2, isBust())
    .Times(1)
    .After(player1Hand2ScoreWin)
    .WillOnce(Return(true));

    Expectation displayWinners = EXPECT_CALL(ui, displayWinner(_))
    .Times(1).After(checkPlayer2Bust)
    .WillOnce(Return());

    EXPECT_CALL(ui, playAgain())
    .Times(1)
    .After(displayWinners)
    .WillOnce(Return(false));

    Blackjack blackjack(players, &dealer);
    blackjack.playGame();
}
