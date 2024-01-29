#include "Card.h"

Card::Card(Suit suit, Rank rank) :
    suit(suit),
    rank(rank),
    ace(false) {
        int temp = static_cast<int>(rank);

        if (temp == 1) {
            ace = true;
        }

        if (temp > 10) {
            value = 10;
        } else {
            value = temp;
        }
    }

Rank Card::getRank() {
    return rank;
}

Suit Card::getSuit() {
    return suit;
}

int Card::getValue() {
    return value;
}

void Card::setValue(int v) {
    value = v;
}

bool Card::isAce() {
    return ace;
}

void Card::setAce(bool a) {
    ace = a;
}

char Card::convertRank() {
    switch (rank) {
        case Rank::ACE: return '1';
        case Rank::TWO: return '2';
        case Rank::THREE: return '3';
        case Rank::FOUR: return '4';
        case Rank::FIVE: return '5';
        case Rank::SIX: return '6';
        case Rank::SEVEN: return '7';
        case Rank::EIGHT: return '8';
        case Rank::NINE: return '9';
        case Rank::TEN: return 'T';
        case Rank::JACK: return 'J';
        case Rank::QUEEN: return 'Q';
        case Rank::KING: return 'K';
        default: return ' ';
    }
}

char Card::convertSuit() {
    switch (suit) {
        case Suit::SPADE: return 'S';
        case Suit::CLUB: return 'C';
        case Suit::HEART: return 'H';
        case Suit::DIAMOND: return 'D';
        default: return ' ';
    }
}

