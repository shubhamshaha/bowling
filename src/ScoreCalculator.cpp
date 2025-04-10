#include "ScoreCalculator.h"
#include "Frame.h"

int ScoreCalculator::calculateTotalScore(const Player& player) {
    const auto& frames = player.getFrames();
    int total = 0;

    for (size_t i = 0; i < frames.size(); ++i) {
        const auto& current = frames[i];
        int frameScore = current->getRawScore();

        if (current->isStrike()) {
            // Bonus: next two rolls
            int bonus = 0;
            if (i + 1 < frames.size()) {
                const auto& next = frames[i + 1];
                bonus += next->getRoll(0);
                if (next->getRollCount() > 1) {
                    bonus += next->getRoll(1);
                } else if (i + 2 < frames.size()) {
                    bonus += frames[i + 2]->getRoll(0);
                }
            }
            frameScore += bonus;

        } else if (current->isSpare()) {
            // Bonus: next roll
            if (i + 1 < frames.size()) {
                frameScore += frames[i + 1]->getRoll(0);
            }
        }

        total += frameScore;
    }

    return total;
}
