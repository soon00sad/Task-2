#include <cmath>
#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

class Sqrt : public CalculationOperations {
public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (executionContext.stackIsEmpty()) {
            throw BadArgumentsException("No operand for 'SQRT'");
        }
        if (!args.empty()) {
            throw BadArgumentsException("Too much arguments for 'SQRT'");
        }
        executionContext.pushStack(sqrt(executionContext.popStack()));
    }
};

CREATE_OPERATION(Sqrt, SQRT)
