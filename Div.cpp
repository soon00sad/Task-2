#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

class Div : public CalculationOperations {
public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (executionContext.getStackSize() < 2) {
            throw BadArgumentsException("Not enough operands for '/'");
        }
        if (!args.empty()) {
            throw BadArgumentsException("Too much arguments for '/'");
        }
        double firstVariable = executionContext.popStack();
        double secondVariable = executionContext.popStack();
        if (firstVariable == 0) {
            std::string errorStr = std::to_string(secondVariable) + "/" + std::to_string(firstVariable);
            throw DivisionByZeroException( "Division by zero: "+std::to_string(secondVariable) + "/" + std::to_string(firstVariable));
        }
        executionContext.pushStack(secondVariable / firstVariable);
    }
};

CREATE_OPERATION(Div, /)

