#include "Hand.h"

void Hand::addCard(Card* card) {
    cards.push_back(card);
}

Card* Hand::removeCard() {
    Card* card = cards.back();
    cards.pop_back();

    return card;
}

std::vector<Card*> Hand::getCards() {
    return cards;
}

int Hand::getScore() {
    int score = 0;
    int aces = 0;

    for (Card* card : cards) {
        int value = card->getValue();
        bool ace = card->isAce();

        if (ace) {
            value = 11;
            aces = aces + 1;
        }

        score = score + value;
    }

    for (int i = aces; i == 1; i--)
        if (score > 21) score = score - 10;

    return score;
}

void Hand::setScore(int s) {
    score = s;
}

void Hand::resetHand() {
    Card* card = cards.back();
    cards.pop_back();

    delete card;
}

void Hand::setFinished(bool s) {
    stand = s;
}

bool Hand::getFinished() {
    return stand;
}

int Hand::getSize() {
    return cards.size();
}

bool Hand::isSplittable() {
    if (cards.size() == 2) {
        Card* first = cards[0];
        int fv = first->getValue();

        Card* second = cards[1];
        int sv = second->getValue();

        if (fv == sv) return true;
    }

    return false;
}
