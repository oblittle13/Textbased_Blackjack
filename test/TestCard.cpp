#include "gtest/gtest.h"
#include "Card.h"

TEST(CardTest, getRank) {
    Card card(Suit::HEART, Rank::ACE);
    ASSERT_EQ(card.getRank(), Rank::ACE);
}

TEST(CardTest, getSuit) {
    Card card(Suit::HEART, Rank::ACE);
    ASSERT_EQ(card.getSuit(), Suit::HEART);
}

TEST(CardTest, getValue) {
    Card card(Suit::SPADE, Rank::KING);
    ASSERT_EQ(card.getValue(), 10);
}

TEST(CardTest, isAce) {
    Card card(Suit::SPADE, Rank::ACE);
    EXPECT_TRUE(card.isAce());
}

TEST(CardTest, setValue) {
    Card card(Suit::SPADE, Rank::KING);
    card.setValue(1);

    EXPECT_EQ(card.getValue(), 1);
}

TEST(CardTest, setAce) {
    Card card(Suit::SPADE, Rank::KING);
    card.setAce(true);

    EXPECT_TRUE(card.isAce());
}

TEST(CardTest, convertRank) {
    Card card1(Suit::HEART, Rank::ACE);
    EXPECT_EQ(card1.convertRank(), '1');

    Card card2(Suit::HEART, Rank::TWO);
    EXPECT_EQ(card2.convertRank(), '2');

    Card card3(Suit::HEART, Rank::THREE);
    EXPECT_EQ(card3.convertRank(), '3');

    Card card4(Suit::HEART, Rank::FOUR);
    EXPECT_EQ(card4.convertRank(), '4');

    Card card5(Suit::HEART, Rank::FIVE);
    EXPECT_EQ(card5.convertRank(), '5');

    Card card6(Suit::HEART, Rank::SIX);
    EXPECT_EQ(card6.convertRank(), '6');

    Card card7(Suit::HEART, Rank::SEVEN);
    EXPECT_EQ(card7.convertRank(), '7');

    Card card8(Suit::HEART, Rank::EIGHT);
    EXPECT_EQ(card8.convertRank(), '8');

    Card card9(Suit::HEART, Rank::NINE);
    EXPECT_EQ(card9.convertRank(), '9');

    Card card10(Suit::HEART, Rank::TEN);
    EXPECT_EQ(card10.convertRank(), 'T');

    Card card11(Suit::HEART, Rank::JACK);
    EXPECT_EQ(card11.convertRank(), 'J');

    Card card12(Suit::HEART, Rank::QUEEN);
    EXPECT_EQ(card12.convertRank(), 'Q');

    Card card13(Suit::HEART, Rank::KING);
    EXPECT_EQ(card13.convertRank(), 'K');

    Rank rank = static_cast<Rank>(20);
    Card card14(Suit::HEART, rank);
    EXPECT_EQ(card14.convertRank(), ' ');
}

TEST(CardTest, convertSuit) {
    Card card1(Suit::SPADE, Rank::ACE);
    EXPECT_EQ(card1.convertSuit(), 'S');

    Card card2(Suit::CLUB, Rank::ACE);
    EXPECT_EQ(card2.convertSuit(), 'C');

    Card card3(Suit::HEART, Rank::ACE);
    EXPECT_EQ(card3.convertSuit(), 'H');

    Card card4(Suit::DIAMOND, Rank::ACE);
    EXPECT_EQ(card4.convertSuit(), 'D');

    Suit suit = static_cast<Suit>(20);
    Card card5(suit, Rank::ACE);
    EXPECT_EQ(card5.convertSuit(), ' ');
}
