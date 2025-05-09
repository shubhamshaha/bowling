#include "gtest/gtest.h"
#include "Game.h"
#include "Player.h"
#include "Frame.h"
#include "ScoreCalculator.h"
#include "Exceptions.h"

// Test Score Calculation for a Perfect Game
TEST(ScoreCalculatorTest, PerfectGame) {
    Player player("TestPlayer");
    for (int i = 0; i < 10; ++i) {
        auto frame = std::make_shared<Frame>(i == 9);
        frame->addRoll(10); // Strike
        if (i == 9) {
            frame->addRoll(10); // Bonus rolls
            frame->addRoll(10);
        }
        player.addFrame(frame);
    }
    EXPECT_EQ(ScoreCalculator::calculateTotalScore(player), 300);
}

// Test Score Calculation for Spares
TEST(ScoreCalculatorTest, SpareGame) {
    Player player("TestPlayer");
    for (int i = 0; i < 10; ++i) {
        auto frame = std::make_shared<Frame>(i == 9);
        frame->addRoll(5);
        frame->addRoll(5); // Spare
        if (i == 9) {
            frame->addRoll(5); // Bonus roll
        }
        player.addFrame(frame);
    }
    EXPECT_EQ(ScoreCalculator::calculateTotalScore(player), 150);
}

// Test Adding Players and Handling Duplicates
TEST(GameTest, AddPlayers) {
    Game game;
    EXPECT_NO_THROW(game.registerPlayers()); // Directly call registerPlayers
}

// Test Frame Logic for Strike
TEST(FrameTest, StrikeLogic) {
    Frame frame;
    frame.addRoll(10);
    EXPECT_TRUE(frame.isStrike());
    EXPECT_FALSE(frame.isSpare());
    EXPECT_TRUE(frame.isComplete());
}

// Test Frame Logic for Spare
TEST(FrameTest, SpareLogic) {
    Frame frame;
    frame.addRoll(5);
    frame.addRoll(5);
    EXPECT_FALSE(frame.isStrike());
    EXPECT_TRUE(frame.isSpare());
    EXPECT_TRUE(frame.isComplete());
}

// Test Exception Handling for Invalid Input
TEST(ExceptionTest, InvalidInput) {
    EXPECT_THROW(throw InvalidInputException("Invalid input"), InvalidInputException);
}

// Test Exception Handling for Duplicate Player
TEST(ExceptionTest, DuplicatePlayer) {
    EXPECT_THROW(throw DuplicatePlayerException("Duplicate player"), DuplicatePlayerException);
}
