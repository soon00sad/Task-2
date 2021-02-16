#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

class Pop : public CalculationOperations {
public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (!args.empty()) {
            throw BadArgumentsException("Too much arguments for 'POP'");
        }
        if (executionContext.stackIsEmpty()) {
            throw EmptyStackException("Stack is empty");
        }
        executionContext.popStack();
    }
};

CREATE_OPERATION(Pop, POP)

