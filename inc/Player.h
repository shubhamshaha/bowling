#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>

class Frame;

class Player {
public:
    Player(const std::string& name);
    
    const std::string& getName() const;
    void addFrame(std::shared_ptr<Frame> frame);
    const std::vector<std::shared_ptr<Frame>>& getFrames() const;

private:
    std::string name;
    std::vector<std::shared_ptr<Frame>> frames;
};

#endif // PLAYER_H
