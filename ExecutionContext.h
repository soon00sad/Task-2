#pragma once

#include <stack>
#include <string>
#include <map>

class ExecutionContext {
    std::stack<double> stack;
    std::map<std::string, double> variables;
public:
    double getVariable(const std::string &variable) {
        return variables.at(variable);
    }
    double getStackTop() {
        return stack.top();
    }
    int getStackSize() {
        return stack.size();
    }
    double popStack() {
        double num = stack.top();
        stack.pop();
        return num;
    }
    void pushStack(double num) {
        stack.push(num);
    }
    void addVariable(const std::string &key, double num) {
        variables[key] = num;
    }
    bool isVariableExist(const std::string &key) {
        return variables.find(key) != variables.end();
    }
    bool stackIsEmpty() {
        return stack.empty();
    }
};
