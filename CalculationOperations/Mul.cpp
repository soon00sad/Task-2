#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

class Mul : public CalculationOperations {
public:
    void run(std::list<std::string> &args, ExecutionContext &context) override {
        if (context.getStackSize() < 2) {
            throw BadArgumentsException("Not enough operands for '*'");
        }
        if (!args.empty()) {
            throw BadArgumentsException("Too much arguments for '*'");
        }
        context.pushStack(context.popStack() * context.popStack());
    }
};

CREATE_OPERATION(Mul, *)
