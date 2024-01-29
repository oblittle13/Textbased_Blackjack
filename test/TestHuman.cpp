#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "Card.h"
#include "Hand.h"
#include "Human.h"

TEST(HumanTest, defaultConstructor) {
    Human* human = new Human();

    EXPECT_EQ(human->getName(), "Player");
    EXPECT_TRUE(human->isActive());
    EXPECT_EQ(human->getHandIndex(), 0);
    EXPECT_EQ(human->getScore(), 0);
    EXPECT_EQ(human->getHandSize(), 1);

    delete human;
}

TEST(HumanTest, nameConstructor) {
    std::string name = "John";
    Human* human = new Human(name);

    EXPECT_EQ(human->getName(), name);
    EXPECT_TRUE(human->isActive());
    EXPECT_EQ(human->getHandIndex(), 0);
    EXPECT_EQ(human->getScore(), 0);
    EXPECT_EQ(human->getHandSize(), 1);

    delete human;
}

TEST(HumanTest, stand) {
    std::string name = "John";
    Human* human = new Human(name);

    Card *aceSpade = new Card(Suit::SPADE, Rank::ACE);
    Card *nineHeart = new Card(Suit::HEART, Rank::NINE);

    human->hit(aceSpade);
    human->hit(nineHeart);

    human->stand();
    EXPECT_FALSE(human->isActive());

    delete human;
}

TEST(HumanTest, humanTurn) {
    Human* human = new Human("Human");

    human->setActive(true);
    EXPECT_TRUE(human->isActive());

    Card *aceSpade = new Card(Suit::SPADE, Rank::ACE);
    Card *aceHeart = new Card(Suit::HEART, Rank::ACE);

    human->hit(aceSpade);
    human->hit(aceHeart);
    EXPECT_EQ(human->getHandSize(), 1);

    std::vector<Hand*> hands = human->getHands();
    std::vector<Card*> cards = hands[0]->getCards();
    EXPECT_EQ(cards[0]->getRank(), Rank::ACE);
    EXPECT_EQ(cards[0]->getSuit(), Suit::SPADE);

    // Split
    human->split();
    EXPECT_EQ(human->getHandSize(), 2);

    // Bust on first hand
    Card* tenSpade = new Card(Suit::SPADE, Rank::TEN);
    Card* eightSpade = new Card(Suit::SPADE, Rank::EIGHT);
    Card* kingHeart = new Card(Suit::HEART, Rank::KING);

    human->hit(tenSpade);
    human->hit(eightSpade);
    human->hit(kingHeart);
    EXPECT_TRUE(human->isBust());
    EXPECT_EQ(human->getHandScore(), 29);
    EXPECT_EQ(human->getScore(), 0);
    EXPECT_FALSE(human->isBlackjack());

    // Blackjack on second hand
    Card* jackClub = new Card(Suit::CLUB, Rank::JACK);

    human->setHandIndex(1);
    human->setHand(1);
    human->hit(jackClub);

    EXPECT_EQ(human->getHandIndex(), 1);
    EXPECT_EQ(human->getHandScore(), 21);
    EXPECT_FALSE(human->isBust());
    EXPECT_TRUE(human->isBlackjack());

    human->incrementScore();
    EXPECT_EQ(human->getScore(), 1);

    // Delete the "split" hand
    human->removeHand();
    EXPECT_EQ(human->getHandSize(), 1);

    human->setActive(false);
    EXPECT_FALSE(human->isActive());

    delete human;
}
