# Add Google Test
add_subdirectory(lib/googletest)
include_directories(lib/googletest/include)

# Add test files
file(GLOB TEST_SOURCES "*.cpp")

# Add source files for the main project
file(GLOB PROJECT_SOURCES "../src/*.cpp")
list(REMOVE_ITEM PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp") # Exclude main.cpp

# Define the test executable
add_executable(BowlingGameTests ${TEST_SOURCES} ${PROJECT_SOURCES})

# Link Google Test and other required libraries
target_link_libraries(BowlingGameTests gtest gtest_main)

# Add the test target
add_test(NAME BowlingGameTests COMMAND BowlingGameTests)
