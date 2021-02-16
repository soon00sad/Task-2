#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"


class Push : public CalculationOperations {
private:
    bool isVariableNumber (const std::string &str) {
        for (auto element : str) {
            if (!(isdigit(element) || element == '.' || element == ',')) {
                return false;
            }
        }
        return true;
    }

public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (args.empty()) {
            throw BadArgumentsException("Not enough arguments for 'PUSH'");
        }
        if (args.size() > 1) {
            throw BadArgumentsException("Too much arguments for 'PUSH'");
        }
        std::string variable = args.back();
        if (executionContext.isVariableExist(variable)) {
            executionContext.pushStack(executionContext.getVariable(variable));
        } else if (isVariableNumber(variable)) {
            executionContext.pushStack(stod(variable));
        } else {
            throw BadArgumentsException("'" + variable + "'" + " variable not exists");
        }

    }
};

CREATE_OPERATION(Push, PUSH)
