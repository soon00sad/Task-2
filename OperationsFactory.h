#pragma once

#include "CalculationOperations.h"
#include "OperationInterface.h"
#include "OperationsCreator.h"
#include "CalculationExceptions.h"

class OperationsFactory {
private:
    std::map<std::string, OperationInterface *> operationCreators;
    OperationsFactory() = default;
    ~OperationsFactory() = default;

public:
    static OperationsFactory &getFactory() {
        static OperationsFactory factory;
        return factory;
    }
    [[nodiscard]] std::unique_ptr<CalculationOperations> getOperation(std::string &operationName) const {
        auto i = operationCreators.find(operationName);
        if (i == operationCreators.end()) {
            std::string name = "'" + operationName + "'";
            throw BadOperationException("Unknown operation " + name);
        }
        OperationInterface *operationCreator = i->second;
        return operationCreator->make();
    }
    void addMaker(const std::string &key, OperationInterface *maker) {
        operationCreators[key] = maker;
    }
};
