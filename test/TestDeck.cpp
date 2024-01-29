#include <vector>

#include "gtest/gtest.h"
#include "Card.h"
#include "Deck.h"

TEST(DeckTest, defaultConstructor) {
    Deck* deck = new Deck();
    deck->shuffle();

    EXPECT_FALSE(deck->isEmpty());

    for (int i = 0; i < 52; i++) {
        Card* card = deck->dealCard();
        delete card;
    }

    EXPECT_TRUE(deck->isEmpty());

    delete deck;
}

TEST(DeckTest, cardConstructor) {
    std::vector<Card*> cards;
    Deck* deck = new Deck(cards);
    deck->shuffle();

    Card *c1, *c2, *c3, *c4;
    c1 = new Card(Suit::SPADE, Rank::TEN);
    c2 = new Card(Suit::SPADE, Rank::EIGHT);
    c3 = new Card(Suit::HEART, Rank::KING);

    deck->addCard(c1);
    deck->addCard(c2);
    deck->addCard(c3);

    c4 = deck->dealCard();
    EXPECT_EQ(c4->getRank(), c3->getRank());
    EXPECT_EQ(c4->getSuit(), c3->getSuit());

    c4 = deck->dealCard();
    EXPECT_EQ(c4->getRank(), c2->getRank());
    EXPECT_EQ(c4->getSuit(), c2->getSuit());

    c4 = nullptr;

    delete deck;
    delete c2;
    delete c3;
}

TEST(DeckTest, shuffleEmpty) {
    std::vector<Card*> cards;
    std::vector<Card*> dealt;
    Deck* deck = new Deck(cards);

    Card *c1, *c2, *c3;
    c1 = new Card(Suit::SPADE, Rank::TEN);
    c2 = new Card(Suit::SPADE, Rank::EIGHT);
    c3 = new Card(Suit::SPADE, Rank::ACE);

    deck->addCard(c1);
    deck->addCard(c2);
    deck->addCard(c3);

    EXPECT_FALSE(deck->isEmpty());

    deck->shuffle();

    dealt.push_back(deck->dealCard());
    dealt.push_back(deck->dealCard());
    dealt.push_back(deck->dealCard());

    EXPECT_TRUE(deck->isEmpty());

    delete deck;
    delete c1;
    delete c2;
    delete c3;
}

TEST(DeckTest, throwEmpty) {
    Card *c1, *c2, *c3;
    c1 = new Card(Suit::SPADE, Rank::TEN);
    c2 = new Card(Suit::SPADE, Rank::EIGHT);
    c3 = new Card(Suit::SPADE, Rank::ACE);

    std::vector<Card*> cards;

    cards.push_back(c1);
    cards.push_back(c2);
    cards.push_back(c3);

    Deck* deck = new Deck(cards);

    EXPECT_FALSE(deck->isEmpty());

    Card* c4 = deck->dealCard();
    Card* c5 = deck->dealCard();
    Card* c6 = deck->dealCard();

    EXPECT_TRUE(deck->isEmpty());

    EXPECT_THROW(deck->dealCard(), DeckEmpty);

    delete deck;
    delete c4;
    delete c5;
    delete c6;
}
