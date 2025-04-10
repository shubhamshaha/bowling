#ifndef SCORE_CALCULATOR_H
#define SCORE_CALCULATOR_H

#include "Player.h"

class ScoreCalculator {
public:
    static int calculateTotalScore(const Player& player);
};

#endif // SCORE_CALCULATOR_H
