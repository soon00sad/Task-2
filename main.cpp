#include <fstream>
#include <iostream>
#include "Calculator.h"

int main(int argc, char *argv[]) {
    Calculator calculator;
    if (argc == 2) {
        std::ifstream input(argv[1]);
        if (!input) {
            std::cout << "Cannot open input file." << std::endl;
            return 0;
        }
        calculator.calculate(input);
    } else {
        std::cout << "Write commands to calculation" << std::endl;
        calculator.calculate(std::cin);
    }
}
