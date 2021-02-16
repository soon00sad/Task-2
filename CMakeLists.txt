cmake_minimum_required(VERSION 3.14)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab2 main.cpp
        Calculator.cpp Calculator.h
        ExecutionContext.h CalculationOperations.h OperationInterface.h
        OperationsCreator.h OperationsFactory.h
        CalculationOperations/Push.cpp CalculationOperations/Define.cpp
        CalculationOperations/Div.cpp CalculationOperations/Mul.cpp
        CalculationOperations/Pop.cpp CalculationOperations/Print.cpp
        CalculationOperations/Sqrt.cpp CalculationOperations/Sub.cpp
        CalculationOperations/Sum.cpp CalculationExceptions.h)