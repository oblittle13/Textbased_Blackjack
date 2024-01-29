#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "UI.h"

void UI::displayHand(Player* player) {
    std::cout << "[Hand]" << std::endl;

    Hand* hand = player->getHand();
    std::vector<Card*> cards = hand->getCards();

    for (Card* card : cards) {
        char rank = card->convertRank();
        char suit = card->convertSuit();

        std::cout << rank << suit << std::endl;
    }

    std::string name = player->getName();
    int score = player->getHandScore();

    std::cout << std::endl;
    std::cout << name << " has " << score << std::endl;
    std::cout << std::endl;
}

void UI::displayWinner(std::vector<Player*> players) {
    int size = players.size();

    if (size == 0) {
        std::cout << "The dealer won." << std::endl;
        return;
    }

    for (Player* player : players) {
        std::string name = player->getName();
        std::cout << name << " beat the dealer." << std::endl;
    }
}

void UI::displayBust(Player* player) {
    std::string name = player->getName();
    std::cout << name << " busted." << std::endl;
    std::cout << std::endl;
}

void UI::displayBlackjack(Player* player) {
    std::string name = player->getName();
    std::cout << name << " got blackjack." << std::endl;
    std::cout << std::endl;
}

void UI::displayScore(Player* player) {
    std::string name = player->getName();
    int score = player->getScore();

    std::cout << name << " won " << score << " times" << std::endl;
    std::cout << std::endl;
}

void UI::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
    std::cout << std::endl;
}

void UI::displayNewShoe(const char* message) {
    std::cout << message << std::endl;
    std::cout << std::endl;
}

void UI::gameMenu() {
    open("menu/ingame.txt");
    std::cout << "Please enter an option: ";
}

void UI::splitMenu() {
    open("menu/split.txt");
    std::cout << "Please enter an option: ";
}

void UI::help() {
    open("menu/help.txt");
}

void UI::invalid() {
    open("menu/invalid.txt");
}

bool UI::playAgain() {
    std::cout << std::endl;

    while (true) {
        open("menu/again.txt");
        int input = this->handleInput();

        switch (input) {
        case 1:
            return true;
        case 2:
            return false;
        default:
            this->invalid();
        }
    }
}

int UI::handleInput() {
    std::string input;
    getline(std::cin, input);

    if (input.length() > 1) return -1;
    input = input.substr(0, 1);

    std::cout << std::endl;

    try {
        return stoi(input);
    } catch (...) {
        return -1;
    }
}

void UI::open(const std::string& filename) {
    std::ifstream file;
    file.open(filename);

    if (!file) {
        std::cout << "Unable to open file." << std::endl;
        return;
    }

    std::string input;

    while (getline(file, input))
        std::cout << input << std::endl;

    std::cout << std::endl;
    file.close();
}

