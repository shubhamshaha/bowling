# 🎳 Bowling Game Scoring App (Console-Based)

A C++ console application to simulate a multiplayer bowling game.  
It allows up to 4 players, tracks scores per frame and per throw, handles strike/spare logic, and calculates total scores automatically.

---

## 📂 Folder Structure
BowlingGame/ 
├── inc/ # Header files (Player, Frame, Game, etc.) 
├── src/ # Source files 
├── doc/ # Optional documentation folder 
├── CMakeLists.txt # Build configuration 
├── README.md # Project instructions

---

## ✅ Features

- Supports 2–4 players
- Enter player names at runtime (with validation)
- Enter score after each throw
- Edit last input before confirmation
- Full 10-frame support (with bonus rolls)
- Live score updates after each round
- Unit-tested core components

---

## 🚀 Build & Run Instructions

### Prerequisites

- C++17 compiler
- CMake (>= 3.10)
- Git (to fetch Google Test)

---

### 🛠️ Build

```bash
# Clone gtest inside test/lib if not already
git clone https://github.com/google/googletest.git test/lib/googletest

# Create build directory
mkdir build
cd build

# Configure & compile
cmake ..
make
