#include "Game.h"
#include "Frame.h"
#include "ScoreCalculator.h"
#include <iostream>
#include <limits>

void Game::start() {
    clearConsole();
    std::cout << "🎳 Welcome to Bowling Game!\n";
    registerPlayers();
    playGame();
}

void Game::registerPlayers() {
    int playerCount = 0;
    while (playerCount < 4) {
        std::string name;
        std::cout << "Enter name for Player " << (playerCount + 1) << ": ";
        std::getline(std::cin, name);

        if (name.empty()) {
            std::cout << "Name cannot be empty. Try again.\n";
            continue;
        }

        bool duplicate = false;
        for (const auto& p : players) {
            if (p->getName() == name) {
                std::cout << "Duplicate name not allowed.\n";
                duplicate = true;
                break;
            }
        }

        if (!duplicate) {
            players.push_back(std::make_shared<Player>(name));
            ++playerCount;
        }

        if (playerCount < 4) {
            std::string more;
            std::cout << "Add another player? (y/n): ";
            std::getline(std::cin, more);
            if (more != "y" && more != "Y") break;
        }
    }
}

void Game::playGame() {
    for (int frame = 1; frame <= 10; ++frame) {
        std::cout << "\n=== Frame " << frame << " ===\n";
        for (auto& player : players) {
            playFrame(player, frame);
        }
        printScores();
    }
    std::cout << "\n🎉 Final Scores:\n";
    printScores();
}

void Game::playFrame(std::shared_ptr<Player> player, int frameNumber) {
    std::cout << "\n" << player->getName() << "'s turn:\n";
    auto frame = std::make_shared<Frame>(frameNumber == 10);
    int pinsRemaining = 10;

    for (int roll = 0; roll < (frame->isTenth() ? 3 : 2); ++roll) {
        int pins = getValidatedScore(pinsRemaining, player, roll, frame->isTenth());
        frame->addRoll(pins);

        if (!frame->isTenth()) {
            if (roll == 0 && pins == 10) break; // strike in regular frame
            pinsRemaining -= pins;
        } else {
            if (roll == 0 && pins == 10) {
                // strike in 10th frame: reset pins
                pinsRemaining = 10;
            } else if (roll == 1 && (frame->getRoll(0) + frame->getRoll(1) == 10)) {
                // spare in 10th: allow third roll
                pinsRemaining = 10;
            } else if (roll == 1 && (frame->getRoll(0) + frame->getRoll(1) < 10)) {
                break; // no bonus roll if no spare/strike
            } else {
                pinsRemaining -= pins;
            }
        }
    }

    player->addFrame(frame);
}

int Game::getValidatedScore(int maxPinsRemaining, std::shared_ptr<Player> player, int rollIndex, bool isTenthFrame) {
    int score = -1;
    while (true) {
        std::cout << "Enter pins knocked down (0–" << maxPinsRemaining << "): ";
        std::string input;
        std::getline(std::cin, input);

        try {
            score = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid number. Try again.\n";
            continue;
        }

        if (score < 0 || score > maxPinsRemaining) {
            std::cout << "Score must be between 0 and " << maxPinsRemaining << ".\n";
        } else {
            break;
        }
    }

    std::string confirm;
    std::cout << "You entered: " << score << ". Confirm? (y to confirm, anything else to re-enter): ";
    std::getline(std::cin, confirm);
    if (confirm != "y" && confirm != "Y") {
        return getValidatedScore(maxPinsRemaining, player, rollIndex, isTenthFrame);
    }

    return score;
}

void Game::printScores() const {
    std::cout << "\n📊 Scores:\n";
    for (const auto& player : players) {
        std::cout << player->getName() << ": " << ScoreCalculator::calculateTotalScore(*player) << "\n";
    }
}

void Game::clearConsole() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
