# 🧪 Unit Test Details

This document provides detailed information about the unit tests written for the Bowling Game Scoring App.

---

## 📋 Test Cases

### 1. **Score Calculation**

- **Perfect Game**: Verifies that a perfect game (all strikes) results in a score of 300.
- **Spare Game**: Verifies that a game with all spares results in a score of 150.

### 2. **Player Management**

- **Add Players**: Ensures players can be added without errors.
- **Duplicate Names**: Ensures duplicate player names are not allowed.

### 3. **Frame Logic**

- **Strike Logic**: Verifies that a frame with a strike is marked correctly.
- **Spare Logic**: Verifies that a frame with a spare is marked correctly.
- **Frame Completion**: Ensures frames are marked complete based on the rules.

### 4. **Exception Handling**

- **Invalid Input**: Ensures invalid inputs throw the appropriate exception.
- **Duplicate Player**: Ensures duplicate player names throw the appropriate exception.

---

## 🛠️ Running Tests

1. Build the project as described in the [README](../README.md).
2. Run the test executable:
   ```bash
   ./BowlingGameTests
   ```

3. The test results will be displayed in the console.

---

## 🧪 Example Output

```plaintext
[==========] Running 8 tests from 4 test cases.
[----------] Global test environment set-up.
[----------] 2 tests from ScoreCalculatorTest
[ RUN      ] ScoreCalculatorTest.PerfectGame
[       OK ] ScoreCalculatorTest.PerfectGame (0 ms)
[ RUN      ] ScoreCalculatorTest.SpareGame
[       OK ] ScoreCalculatorTest.SpareGame (0 ms)
[----------] 2 tests from ScoreCalculatorTest (0 ms total)

[----------] 1 test from GameTest
[ RUN      ] GameTest.AddPlayers
[       OK ] GameTest.AddPlayers (0 ms)
[----------] 1 test from GameTest (0 ms total)

[----------] 2 tests from FrameTest
[ RUN      ] FrameTest.StrikeLogic
[       OK ] FrameTest.StrikeLogic (0 ms)
[ RUN      ] FrameTest.SpareLogic
[       OK ] FrameTest.SpareLogic (0 ms)
[----------] 2 tests from FrameTest (0 ms total)

[----------] 2 tests from ExceptionTest
[ RUN      ] ExceptionTest.InvalidInput
[       OK ] ExceptionTest.InvalidInput (0 ms)
[ RUN      ] ExceptionTest.DuplicatePlayer
[       OK ] ExceptionTest.DuplicatePlayer (0 ms)
[----------] 2 tests from ExceptionTest (0 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 4 test cases ran. (0 ms total)
[  PASSED  ] 8 tests.
```
