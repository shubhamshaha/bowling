#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class BowlingException : public std::runtime_error {
public:
    explicit BowlingException(const std::string& message) : std::runtime_error(message) {}
};

class InvalidInputException : public BowlingException {
public:
    explicit InvalidInputException(const std::string& message) : BowlingException(message) {}
};

class DuplicatePlayerException : public BowlingException {
public:
    explicit DuplicatePlayerException(const std::string& message) : BowlingException(message) {}
};

#endif // EXCEPTIONS_H
