#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

class Print : public CalculationOperations {
public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (args.empty()) {
            if (executionContext.getStackSize() == 0) {
                throw EmptyStackException("Stack is empty");
            }
            double variable = executionContext.getStackTop();
            std::cout << variable << std::endl;
        } else {
            for (const auto &arg : args) {
                if (arg == "\\n") {
                    std::cout << std::endl;
                } else {
                    std::cout << arg << " ";
                }
            }
        }
    }
};

CREATE_OPERATION(Print, PRINT)
