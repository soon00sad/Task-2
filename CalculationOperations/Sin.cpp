#include <cmath>
#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

#define _USE_MATH_DEFINES

class Sin : public CalculationOperations {
public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (executionContext.stackIsEmpty()) {
            throw BadArgumentsException("No operand for 'SIN'");
        }
        if (!args.empty()) {
            throw BadArgumentsException("Too much arguments for 'SIN'");
        }
        double num = (M_PI * executionContext.popStack())/180;
        executionContext.pushStack(sin(num));
    }
};

CREATE_OPERATION(Sin, SIN)

