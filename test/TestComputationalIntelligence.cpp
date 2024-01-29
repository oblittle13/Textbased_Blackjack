#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "Card.h"
#include "Hand.h"
#include "ComputationalIntelligence.h"


TEST(CITest, defaultConstructor) {
    ComputationalIntelligence* ci =
        new ComputationalIntelligence();

    EXPECT_EQ(ci->getName(), "Player");
    EXPECT_TRUE(ci->isActive());
    EXPECT_EQ(ci->getHandIndex(), 0);
    EXPECT_EQ(ci->getScore(), 0);
    EXPECT_EQ(ci->getHandSize(), 1);

    delete ci;
}

TEST(CITest, nameConstructor) {
    std::string name = "John";
    ComputationalIntelligence* ci =
        new ComputationalIntelligence(name);

    EXPECT_EQ(ci->getName(), name);
    EXPECT_TRUE(ci->isActive());
    EXPECT_EQ(ci->getHandIndex(), 0);
    EXPECT_EQ(ci->getScore(), 0);
    EXPECT_EQ(ci->getHandSize(), 1);

    delete ci;
}

TEST(CITest, stand) {
    std::string name = "John";
    ComputationalIntelligence* ci = new ComputationalIntelligence(name);

    Card *aceSpade = new Card(Suit::SPADE, Rank::ACE);
    Card *nineHeart = new Card(Suit::HEART, Rank::NINE);

    ci->hit(aceSpade);
    ci->hit(nineHeart);

    ci->stand();
    EXPECT_FALSE(ci->isActive());

    delete ci;
}

TEST(CITest, ciTurn) {
    ComputationalIntelligence* ci =
        new ComputationalIntelligence("ComputationalIntelligence");

    ci->setActive(true);
    EXPECT_TRUE(ci->isActive());

    Card *aceSpade = new Card(Suit::SPADE, Rank::ACE);
    Card *aceHeart = new Card(Suit::HEART, Rank::ACE);

    ci->hit(aceSpade);
    ci->hit(aceHeart);
    EXPECT_EQ(ci->getHandSize(), 1);

    std::vector<Hand*> hands = ci->getHands();
    std::vector<Card*> cards = hands[0]->getCards();
    EXPECT_EQ(cards[0]->getRank(), Rank::ACE);
    EXPECT_EQ(cards[0]->getSuit(), Suit::SPADE);

    // Split
    ci->split();
    EXPECT_EQ(ci->getHandSize(), 2);

    // Bust on first hand
    Card* tenSpade = new Card(Suit::SPADE, Rank::TEN);
    Card* eightSpade = new Card(Suit::SPADE, Rank::EIGHT);
    Card* kingHeart = new Card(Suit::HEART, Rank::KING);

    ci->hit(tenSpade);
    ci->hit(eightSpade);
    ci->hit(kingHeart);
    EXPECT_EQ(ci->isBust(), true);
    EXPECT_EQ(ci->getHandScore(), 29);
    EXPECT_EQ(ci->getScore(), 0);

    // Blackjack on second hand
    Card* jackClub = new Card(Suit::CLUB, Rank::JACK);

    ci->setHandIndex(1);
    ci->setHand(1);
    ci->hit(jackClub);

    EXPECT_EQ(ci->getHandIndex(), 1);
    EXPECT_EQ(ci->getHandScore(), 21);
    EXPECT_EQ(ci->isBust(), false);
    EXPECT_EQ(ci->isBlackjack(), true);

    ci->incrementScore();
    EXPECT_EQ(ci->getScore(), 1);

    // Delete the "split" hand
    ci->removeHand();
    EXPECT_EQ(ci->getHandSize(), 1);

    ci->setActive(false);
    EXPECT_FALSE(ci->isActive());

    delete ci;
}
