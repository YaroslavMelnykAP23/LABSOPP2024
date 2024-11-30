#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

// Клас виключення для помилок валідації вводу
class InputValidationException : public std::runtime_error {
public:
    explicit InputValidationException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif // EXCEPTIONS_H
