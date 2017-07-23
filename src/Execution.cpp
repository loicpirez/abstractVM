//
// Execution.cpp for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Sat Jul 22 16:36:13 2017 Loïc Pirez
// Last update Sat Jul 22 16:36:13 2017 Loïc Pirez
//

#include <IOperand.hh>
#include <Factory.hpp>
#include <Execution.hpp>
#include <iostream>
#include <Exceptions.hh>

Execution::Execution() {
    this->initializeStack();
}

void Execution::initializeStack(void) {
    IOperand *empty = 0;

    for (size_t i = 0; i != MAX_REGISTERS; i++) {
        this->stack.push_back(empty);
    }
}

std::map<std::string, eOperandType> Execution::createOperandPointer() {
    return {
            {"int8",       eOperandType::Int8},
            {"int16",      eOperandType::Int16},
            {"int32",      eOperandType::Int32},
            {"float",      eOperandType::Float},
            {"double",     eOperandType::Double},
            {"bigdecimal", eOperandType::BigDecimal}
    };
}

void Execution::executeDoubleInstruction(Instructions *i, std::smatch match) {
    std::string instruction = match[2];
    std::string number = match[4];
    std::string type = match[3];

    std::map<std::string, std::function<std::list<IOperand *>(std::list<IOperand *>, eOperandType,
                                                              std::string)>> function_pointer = i->createFunctionPointerDoubleType();
    std::map<std::string, eOperandType> operand_pointer = createOperandPointer();

    this->stack = function_pointer.at(instruction)(this->stack, createOperandPointer().at(type), number);
}

void Execution::executeSimpleInstruction(Instructions *i, std::string line) {
    std::string instruction = line;

    std::map<std::string, std::function<std::list<IOperand *>(std::list<IOperand *>)>> function_pointer =
            i->createFunctionPointerSingleType();
    this->stack = function_pointer.at(instruction)(this->stack);
}

void Execution::extractInformationsFromLine(std::string line) {
    Instructions *i = new Instructions;
    std::regex s("(pop|clear|dup|swap|dump|add|sub|mul|div|mod|print|exit)");
    std::regex v(
            "((load|store|push|assert)\\s(int8|int16|int32|float|double|bigdecimal)\\((-?[0-9]\\d*(\\.\\d+)?)\\))");
    std::smatch match;
    try {
        if (std::regex_match(line, s)) {
            executeSimpleInstruction(i, line);
        } else if (std::regex_match(line, match, v)) {
            executeDoubleInstruction(i, match);
        } else {
            std::cerr << line << std::endl;
            fflush(0);
            throw new ExceptionSyntax;
        }
    }
    catch (const ExceptionSyntax *e) {
        e->printErrorFinish();
    };
    delete (i);
}

void Execution::executionFromInput(std::list<std::string> input) {
    for (auto &line : input) {
        extractInformationsFromLine(line);
    }
}