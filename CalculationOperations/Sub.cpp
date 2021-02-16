#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

class Sub : public CalculationOperations {
public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (executionContext.getStackSize() < 2) {
            throw BadArgumentsException("Not enough operands for '-'");
        }
        if (!args.empty()) {
            throw BadArgumentsException("Too much arguments for '-'");
        }
        double firstVariable = executionContext.popStack();
        double secondVariable = executionContext.popStack();
        double subVariables = secondVariable - firstVariable;
        executionContext.pushStack(subVariables);
    }
};

CREATE_OPERATION(Sub, -)
