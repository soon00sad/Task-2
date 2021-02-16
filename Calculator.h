#pragma once

#include "ExecutionContext.h"

class Calculator {
private:
    ExecutionContext executionContext;
public:
    Calculator() = default;
    ~Calculator() = default;
    void calculate(std::istream &stream);
};
