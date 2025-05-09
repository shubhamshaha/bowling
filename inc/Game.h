#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "Player.h"

class Game {
public:
    void start();
    void registerPlayers(); // Moved to public for testing purposes

private:
    std::vector<std::shared_ptr<Player>> players;

    void playGame();
    void playFrame(std::shared_ptr<Player> player, int frameNumber);
    int getValidatedScore(int maxPinsRemaining, std::shared_ptr<Player> player, int rollIndex, bool isTenthFrame);
    void printScores() const;
    void clearConsole() const;
};

#endif // GAME_H
