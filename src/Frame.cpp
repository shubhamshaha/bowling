#include "Frame.h"

Frame::Frame(bool isTenthFrame) : tenthFrame(isTenthFrame) {}

void Frame::addRoll(int pins) {
    if (rolls.size() < (tenthFrame ? 3 : 2)) {
        rolls.push_back(pins);
    }
}

const std::vector<int>& Frame::getRolls() const {
    return rolls;
}

int Frame::getRoll(int index) const {
    if (index < rolls.size()) return rolls[index];
    return 0;
}

int Frame::getRollCount() const {
    return rolls.size();
}

int Frame::getRawScore() const {
    int score = 0;
    for (int pins : rolls) score += pins;
    return score;
}

bool Frame::isStrike() const {
    return rolls.size() >= 1 && rolls[0] == 10;
}

bool Frame::isSpare() const {
    return rolls.size() >= 2 && (rolls[0] + rolls[1] == 10) && !isStrike();
}

bool Frame::isComplete() const {
    if (tenthFrame) {
        if (rolls.size() == 3) return true;
        if (rolls.size() == 2 && getRawScore() < 10) return true;
        return false;
    }

    return isStrike() || rolls.size() == 2;
}

bool Frame::isTenth() const {
    return tenthFrame;
}
