#ifndef FRAME_H
#define FRAME_H

#include <vector>

class Frame {
public:
    Frame(bool isTenthFrame = false);

    void addRoll(int pins);
    const std::vector<int>& getRolls() const;
    int getRoll(int index) const;
    int getRollCount() const;
    int getRawScore() const;

    bool isStrike() const;
    bool isSpare() const;
    bool isComplete() const;
    bool isTenth() const;

private:
    std::vector<int> rolls;
    bool tenthFrame;
};

#endif // FRAME_H
