#include <algorithm>
#include <iostream>
#include <random>

#include "Deck.h"

Deck::Deck() {
    cards.reserve(CARDS_PER_DECK);

    for (int i = 1; i <= SUITS; i++) {
        for (int j = 1; j <= CARDS_PER_SUIT; j++) {
            Suit suit = static_cast<Suit>(i);
            Rank rank = static_cast<Rank>(j);

            Card* card = new Card(suit, rank);

            cards.push_back(card);
        }
    }
}

Deck::Deck(std::vector<Card*> cards) : cards(cards) {}

void Deck::shuffle() {
    auto device = std::random_device {}();
    auto mt = std::mt19937{ device };

    std::shuffle(cards.begin(), cards.end(), mt);
}

Card* Deck::dealCard() {
    if (cards.size() == 0) {
        throw DeckEmpty();
    }

    Card* card = cards.front();
    cards.erase(cards.begin());

    return card;
}

void Deck::addCard(Card* card) {
    cards.insert(cards.begin(), card);
}

bool Deck::isEmpty() {
    bool empty = cards.empty();

    if (empty) return true;
    return false;
}
