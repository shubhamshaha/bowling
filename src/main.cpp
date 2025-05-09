#include "Game.h"
#include "Exceptions.h"
#include <iostream>

int main() {
    try {
        Game game;
        game.start();
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
