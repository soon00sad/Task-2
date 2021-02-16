#pragma once

#include <exception>
#include <utility>

class CalculatorException : public std::exception {
private:
    std::string errorString;

public:
    explicit CalculatorException(std::string errStr) {
        errorString = std::move(errStr);
    }
    [[nodiscard]] const char *what() const noexcept override {
        return errorString.c_str();
    }
};

class InputException : public CalculatorException {
public:
    explicit InputException(std::string errStr) : CalculatorException(std::move(errStr)) {}
};

class BadArgumentsException: public InputException{
public:
    explicit BadArgumentsException(std::string errStr) : InputException(std::move(errStr)) {}
};

class BadOperationException: public InputException{
public:
    explicit BadOperationException(std::string errStr) : InputException(std::move(errStr)) {}
};

class RuntimeException : public CalculatorException {
public:
    explicit RuntimeException(std::string errStr) : CalculatorException(std::move(errStr)) {}
};

class DivisionByZeroException: public RuntimeException{
public:
    explicit DivisionByZeroException(std::string errStr) : RuntimeException(std::move(errStr)) {}
};

class EmptyStackException: public RuntimeException{
public:
    explicit EmptyStackException(std::string errStr) : RuntimeException(std::move(errStr)) {}
};
