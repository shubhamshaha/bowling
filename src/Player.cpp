#include "Player.h"
#include "Frame.h"

Player::Player(const std::string& name) : name(name) {}

const std::string& Player::getName() const {
    return name;
}

void Player::addFrame(std::shared_ptr<Frame> frame) {
    frames.push_back(frame);
}

const std::vector<std::shared_ptr<Frame>>& Player::getFrames() const {
    return frames;
}
