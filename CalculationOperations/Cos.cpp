#include <cmath>
#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

class Cos : public CalculationOperations {
public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (executionContext.stackIsEmpty()) {
            throw BadArgumentsException("No operand for 'COS'");
        }
        if (!args.empty()) {
            throw BadArgumentsException("Too much arguments for 'COS'");
        }
        double num = (M_PI * executionContext.popStack())/180;
        executionContext.pushStack(cos(num));
    }
};

CREATE_OPERATION(Cos, COS)
