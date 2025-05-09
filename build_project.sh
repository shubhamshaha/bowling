#!/bin/bash

# Function to display menu
show_menu() {
    echo "Select an option:"
    echo "1. Build project"
    echo "2. Build project with unit tests"
    echo "3. Clean build"
    echo "4. Run the program"
    echo "5. Run unit tests"
    echo "6. Exit"
}

# Function to clean build directory
clean_build() {
    echo "Cleaning build directory..."
    rm -rf build
    echo "Clean complete."
}

# Function to build the project
build_project() {
    echo "Building project..."
    mkdir -p build
    cd build
    cmake -DBUILD_TESTS=OFF ..
    make -j32
    cd ..
    echo "Build complete."
}

# Function to build the project with unit tests
build_with_tests() {
    echo "Building project with unit tests..."
    mkdir -p build
    cd build
    cmake -DBUILD_TESTS=ON ..
    make -j32
    cd ..
    echo "Build with unit tests complete."
}

# Function to run the program
run_program() {
    if [[ -f build/BowlingGame ]]; then
        echo "Running the program..."
        ./build/BowlingGame
    else
        echo "Error: BowlingGame executable not found. Please build the project first."
    fi
}

# Function to run unit tests
run_tests() {
    if [[ -f build/test/BowlingGameTests ]]; then
        echo "Running unit tests..."
        ./build/test/BowlingGameTests
    else
        echo "Error: BowlingGameTests executable not found. Please build the project with unit tests first."
    fi
}

# Main script logic
while true; do
    show_menu
    read -p "Enter your choice: " choice

    case $choice in
        1)
            build_project
            ;;
        2)
            build_with_tests
            ;;
        3)
            clean_build
            ;;
        4)
            run_program
            ;;
        5)
            run_tests
            ;;
        6)
            echo "Exiting."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please try again."
            ;;
    esac
done
