#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

class Sum : public CalculationOperations {
public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (executionContext.getStackSize() < 2) {
            throw BadArgumentsException("Not enough operands for '+'");
        }
        if (!args.empty()) {
            throw BadArgumentsException("Too much arguments for '+'");
        }
        double sumVariables = executionContext.popStack() + executionContext.popStack();
        executionContext.pushStack(sumVariables);
    }
};

CREATE_OPERATION(Sum, +)
