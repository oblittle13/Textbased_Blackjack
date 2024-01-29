#include <iostream>

#include "Player.h"

Player::Player() :
    name("Player"),
    active(false),
    index(0),
    score(0) {
    hand = new Hand();
    hands.push_back(hand);
}

Player::Player(std::string name) :
    name(name),
    active(false),
    index(0),
    score(0) {
    hand = new Hand();
    hands.push_back(hand);
}

Player::~Player() {
    for (Hand* hand : hands)
        delete hand;
}

std::string Player::getName() const {
    return name;
}

void Player::hit(Card* card) {
    hand->addCard(card);
}

void Player::split() {
    Hand* split = new Hand();

    Card* card = hand->removeCard();

    split->addCard(card);
    hands.push_back(split);
}

void Player::stand() {
    hand->setFinished(true);
}

bool Player::isBust() {
    int s = getHandScore();

    if (s > 21) {
        hand->setFinished(true);
        return true;
    }

    return false;
}

void Player::incrementScore() {
    score = score + 1;
}

void Player::setHand(int i) {
    hand = hands[i];
}

void Player::setActive(bool a) {
    active = a;
}

bool Player::isActive() {
    int count = 0;
    int size = getHandSize();

    for (Hand* hand : hands) {
        bool finished = hand->getFinished();
        if (finished) count = count + 1;
    }

    if (count == size) {
        active = false;
        return active;
    }

    active = true;
    return active;
}

std::vector<Hand*> Player::getHands() {
    return hands;
}

Hand* Player::getHand() {
    return hands[index];
}

bool Player::isBlackjack() {
    int s = getHandScore();

    if (s == 21) {
        hand->setFinished(true);
        return true;
    }

    return false;
}

int Player::getScore() {
    return score;
}

int Player::getHandScore() {
    return getHand()->getScore();
}

int Player::getHandIndex() {
    return index;
}

void Player::setHandIndex(int i) {
    index = i;
}

int Player::getHandSize() {
    return hands.size();
}

void Player::removeHand() {
    Hand* split = hands.back();
    hands.pop_back();

    delete split;
}
