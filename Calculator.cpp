#include "Calculator.h"
#include "CalculationOperations.h"
#include "OperationsCreator.h"
#include <sstream>

void Calculator::calculate(std::istream &stream) {
    for (std::string line; !stream.eof(); std::getline(stream, line)) {
        std::stringstream lineStream(line);
        std::string command;
        lineStream >> command;
        if (command[0] == '#' || command.empty()) {
            continue;
        } else if (command == "EXIT") {
            break;
        }
        std::list<std::string> args;
        while (!lineStream.eof()) {
            std::string variable;
            lineStream >> variable;
            if (variable[0] == '#') {
                break;
            }
            args.push_back(variable);
        }
        try {
            std::unique_ptr<CalculationOperations> operation = OperationsFactory::getFactory().getOperation(command);
            operation->run(args, executionContext);
        }
        catch (CalculatorException &exception) {
            std::cout << "Exception: " << exception.what() << std::endl;
        }
    }
}
