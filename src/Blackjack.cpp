#include <string>
#include <vector>

#include "Blackjack.h"
#include "ComputationalIntelligence.h"
#include "Human.h"
#include "UI.h"

Blackjack::Blackjack(std::vector<Player*> players, Player* dealer) :
    players(players), dealer(dealer), index(0) {}

void Blackjack::playGame() {
    bool over = false;

    do {
        playRound();
        checkWin();

        // Check if user wants to play again
        bool again = ui->playAgain();

        if (again)
            resetRound();
        else
            over = true;
    } while (!over);
}

void Blackjack::playRound() {
    // Deal cards to players and dealer
    for (int i = 0; i < 2; i++) {
        for (Player* player : players) {
            dealCard(player);
        }

        dealCard(dealer);
    }

    // Player's turn
    for (int i = 0; i < players.size(); i++) {
        index = i;

        Player* player = players[index];
        Human* human = dynamic_cast<Human*>(player);

        if (human)
            humanPlay();
        else
            computerPlay();
    }

    // Dealer's turn
    dealerPlay();
}

void Blackjack::resetRound() {
    index = 0;

    // Reset player(s)
    for (Player* player : players) {
        player->setHandIndex(0);

        std::vector<Hand*> hands = player->getHands();

        for (Hand* hand : hands) {
            hand->setFinished(false);

            std::vector<Card*> cards = hand->getCards();

            if (hand->getSize() > 0) {
                for (Card* card : cards)
                    hand->resetHand();
            }
        }
    }

    // Reset dealer
    std::vector<Hand*> hands = dealer->getHands();

    for (Hand* hand : hands) {
        hand->setFinished(false);

        std::vector<Card*> cards = hand->getCards();

        if (hand->getSize() > 0) {
            for (Card* card : cards)
                hand->resetHand();
        }
    }

    dealer->setHandIndex(0);
}

void Blackjack::dealCard(Player* player) {
    bool success = false;

    Card* card;

    while (true) {
        if (success) break;

        try {
            card = deck->dealCard();
        } catch (DeckEmpty& de) {
            Deck* d = new Deck();
            setDeck(d);

            const char* message = de.what();
            ui->displayNewShoe(message);

            continue;
        }

        success = true;
    }

    player->hit(card);
}

void Blackjack::checkWin() {
    std::vector<Player*> winner{};

    int dealerScore = dealer->getHandScore();

    for (Player* player : players) {
        std::vector<Hand*> hands = player->getHands();

        for (Hand* hand : hands) {
            int handScore = hand->getScore();
            if (handScore > 21) continue;

            if (handScore > dealerScore && handScore <= 21 ||
                handScore <= 21 && dealerScore > 21) {
                player->incrementScore();
                winner.push_back(player);
            }
        }
    }

    ui->displayWinner(winner);
}

void Blackjack::dealerPlay() {
    do {
        bool won = dealer->isBlackjack();

        if (won) {
            ui->displayHand(dealer);
            ui->displayBlackjack(dealer);

            break;
        }

        // Display dealer's hand
        ui->displayHand(dealer);

        int score = dealer->getHandScore();

        if (score > 17) {
            dealer->stand();
            break;
        }

        // Dealer hits until score is 17 or higher
        dealCard(dealer);

        bool busted = dealer->isBust();

        if (busted) {
            ui->displayHand(dealer);
            ui->displayBust(dealer);

            break;
        }
    } while (dealer->isActive());
}

void Blackjack::humanPlay() {
    Player* player = players[index];
    Human* human = dynamic_cast<Human*>(player);

    do {
        bool won = human->isBlackjack();

        if (won) {
            ui->displayHand(human);
            ui->displayBlackjack(human);

            break;
        }

        // Display player's hand
        ui->displayHand(human);

        // Display the in-game menu
        ui->gameMenu();

        // Get player's input
        int input = ui->handleInput();

        switch (input) {
            case 1: {
                // Hit
                dealCard(human);

                bool busted = human->isBust();

                if (busted) {
                    ui->displayHand(human);
                    ui->displayBust(human);

                    break;
                }

                won = human->isBlackjack();

                if (won) {
                    ui->displayHand(human);
                    ui->displayBlackjack(human);

                    break;
                }

                continue;
            }

            case 2: {
               // Stand
               human->stand();
               break;
            }

            case 3: {
                // Split
                Hand* hand = human->getHand();
                bool splittable = hand->isSplittable();

                if (!splittable) {
                    ui->displayMessage("You do not have a splittable hand.");
                    continue;
                }

                human->split();

                int current = human->getHandIndex();

                do {
                    int size = human->getHandSize();
                    bool active = human->isActive();

                    if (current == size && !active)
                        break;

                    human->setHandIndex(current);
                    human->setHand(current);

                    ui->displayHand(human);

                    ui->splitMenu();
                    input = ui->handleInput();

                    switch (input) {
                        case 1: {
                            // Hit
                            dealCard(human);

                            won = human->isBlackjack();

                            if (won) {
                                current++;

                                ui->displayHand(human);
                                ui->displayBlackjack(human);
                            }

                            bool busted = human->isBust();

                            if (busted) {
                                current++;

                                ui->displayHand(human);
                                ui->displayBust(human);
                            }

                            if (current == size) break;
                            continue;
                        }

                        case 2: {
                            // Stand
                            human->stand();
                            current++;

                            if (current == size) break;
                            continue;
                        }

                        case 3: {
                            ui->help();
                            continue;
                        }

                        default: {
                            ui->invalid();
                            continue;
                        }
                    }

                    // Remove hand used in split
                    human->setHand(0);
                    human->removeHand();
                } while (human->isActive() && human->getHandSize() > 1);

                break;
            }

            case 4: {
                ui->displayScore(human);
                continue;
            }

            case 5: {
                ui->help();
                continue;
            }

            default: {
                ui->invalid();
                continue;
            }
        }
    } while (human->isActive());

    human->setHandIndex(0);
}

void Blackjack::computerPlay() {
    Player* player = players[index];

    ComputationalIntelligence* ci =
        dynamic_cast<ComputationalIntelligence*>(player);

    do {
        bool won = ci->isBlackjack();

        if (won) {
            ui->displayHand(ci);
            ui->displayBlackjack(ci);

            break;
        }

        // Display player's hand
        ui->displayHand(ci);

        // Hit
        dealCard(ci);

        bool busted = ci->isBust();

        if (busted) {
            ui->displayHand(ci);
            ui->displayBust(ci);

            break;
        }

        won = ci->isBlackjack();

        if (won) {
            ui->displayHand(ci);
            ui->displayBlackjack(ci);

            break;
        }

        continue;
    } while (ci->isActive());
}

void Blackjack::setDeck(Deck* d) {
    if (deck) delete deck;
    deck = d;
}

void Blackjack::setUI(UI* u) {
    if (ui) delete ui;
    ui = u;
}
