#include <vector>

#include "gtest/gtest.h"
#include "Card.h"
#include "Hand.h"

TEST(HandTest, constructor) {
    Hand* hand = new Hand();

    EXPECT_EQ(hand->getScore(), 0);
    EXPECT_FALSE(hand->getFinished());

    delete hand;
}

TEST(HandTest, addCard) {
    Card* c1 = new Card(Suit::SPADE, Rank::TEN);
    Hand* hand = new Hand();

    hand->addCard(c1);
    EXPECT_EQ(hand->getSize(), 1);

    delete hand;
}

TEST(HandTest, getScore) {
    Card* c1 = new Card(Suit::SPADE, Rank::TEN);
    Card* c2 = new Card(Suit::HEART, Rank::TEN);

    Hand* hand = new Hand();

    hand->addCard(c1);
    hand->addCard(c2);

    EXPECT_EQ(hand->getScore(), 20);

    delete hand;
}

TEST(HandTest, setScore) {
    Card* c1 = new Card(Suit::SPADE, Rank::TEN);
    Card* c2 = new Card(Suit::HEART, Rank::TEN);

    Hand* hand = new Hand();

    hand->addCard(c1);
    hand->addCard(c2);

    hand->setScore(20);
    EXPECT_EQ(hand->getScore(), 20);

    delete hand;
}

TEST(HandTest, resetHand) {
    Card* c1 = new Card(Suit::SPADE, Rank::TEN);
    Card* c2 = new Card(Suit::HEART, Rank::TEN);

    Hand* hand = new Hand();

    hand->addCard(c1);
    hand->addCard(c2);

    hand->resetHand();

    EXPECT_EQ(hand->getSize(), 1);

    delete hand;
}

TEST(HandTest, setFinished) {
    Hand* hand = new Hand();
    hand->setFinished(true);

    EXPECT_TRUE(hand->getFinished());

    delete hand;
}

TEST(HandTest, isSplittable) {
    Card* c1 = new Card(Suit::SPADE, Rank::TEN);
    Card* c2 = new Card(Suit::HEART, Rank::TEN);
    Card* c3 = new Card(Suit::HEART, Rank::ACE);

    Hand* hand1 = new Hand();
    Hand* hand2 = new Hand();

    hand1->addCard(c1);
    hand1->addCard(c2);

    hand2->addCard(c3);

    EXPECT_TRUE(hand1->isSplittable());
    EXPECT_FALSE(hand2->isSplittable());

    delete hand1;
    delete hand2;
}

TEST(HandTest, handRemove) {
    std::vector<Card*> cards;
    Hand* hand = new Hand(cards);

    Card *c1, *c2, *c3, *c4;
    c1 = new Card(Suit::SPADE, Rank::TEN);
    c2 = new Card(Suit::SPADE, Rank::EIGHT);
    c3 = new Card(Suit::HEART, Rank::KING);

    hand->addCard(c1);
    hand->addCard(c2);
    hand->addCard(c3);

    EXPECT_EQ(hand->getCards().size(), 3);

    hand->removeCard();

    c4 = hand->getCards()[0];
    EXPECT_EQ(c4->getRank(), c1->getRank());
    EXPECT_EQ(c4->getSuit(), c1->getSuit());

    c4 = hand->getCards()[1];
    EXPECT_EQ(c4->getRank(), c2->getRank());
    EXPECT_EQ(c4->getSuit(), c2->getSuit());

    c4 = nullptr;

    delete hand;
    delete c3;
}
