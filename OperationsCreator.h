#pragma once

#include "OperationInterface.h"
#include "OperationsFactory.h"

#define CREATE_OPERATION(T, NAME) static OperationsCreator<T> maker(#NAME);

template<typename T>
class OperationsCreator : public OperationInterface {
public:
    [[nodiscard]] std::unique_ptr<CalculationOperations> make() const override {
        std::unique_ptr<CalculationOperations> ptr(new T());
        return ptr;
    }

    explicit OperationsCreator(const std::string &name) {
        OperationsFactory::getFactory().addMaker(name, this);
    }
};
