#include <iostream>

#include "Blackjack.h"
#include "ComputationalIntelligence.h"
#include "Deck.h"
#include "Human.h"
#include "Player.h"
#include "UI.h"

int main() {
    UI* ui = new UI();

    Human* human = new Human("Human");
    ComputationalIntelligence* dealer = new ComputationalIntelligence("Dealer");
    ComputationalIntelligence* john = new ComputationalIntelligence("John");

    std::vector<Player*> players{human, john};

    Deck* deck = new Deck();
    deck->shuffle();

    Blackjack* game = new Blackjack(players, dealer);
    game->setUI(ui);
    game->setDeck(deck);
    game->playGame();

    delete game;
}
