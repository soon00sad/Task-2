#pragma once

#include <cmath>
#include <iostream>
#include <utility>
#include <list>
#include "ExecutionContext.h"

class CalculationOperations {
public:
    virtual void run(std::list<std::string> &args, ExecutionContext &executionContext) = 0;
    virtual ~CalculationOperations() = default;
};
