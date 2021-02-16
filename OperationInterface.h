#pragma once

#include "CalculationOperations.h"
#include <memory>

class OperationInterface {
public:
    [[nodiscard]] virtual std::unique_ptr<CalculationOperations> make() const = 0;
    virtual ~OperationInterface() = default;
};
