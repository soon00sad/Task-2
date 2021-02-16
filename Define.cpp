#include "../CalculationOperations.h"
#include "../OperationsCreator.h"
#include "../CalculationExceptions.h"

class Define : public CalculationOperations {
private:
    static bool isVariableNumber(const std::string &str) {
        for (auto element : str) {
            if (!(isdigit(element) || element == '.' || element == ',')) {
                return false;
            }
        }
        return true;
    }

public:
    void run(std::list<std::string> &args, ExecutionContext &executionContext) override {
        if (args.size() < 2) {
            throw BadArgumentsException("Not enough arguments for 'DEFINE'");
        }
        if (args.size() > 2) {
            throw BadArgumentsException("Too much arguments for 'DEFINE'");
        }
        std::string variable = args.front();
        if (isVariableNumber(args.back())) {
            double value = std::stod(args.back());
            executionContext.addVariable(variable, value);
        } else {
            throw BadArgumentsException(args.back() + "is not a number");
        }

    }
};

CREATE_OPERATION(Define, DEFINE)
