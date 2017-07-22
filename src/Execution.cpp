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

void Execution::push(eOperandType type, std::string number) {
    std::map<eOperandType, std::string> get = getOperandToStringPointer();
    IOperand *op = Factory::createOperand(type, number);
    this->stack.push_front(op);
}

std::map<std::string, std::function<void(eOperandType, std::string)>> Execution::createFunctionPointer() {
    return {
            {"push",   std::bind(&Execution::push, this, std::placeholders::_1, std::placeholders::_2)}
    };
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

std::map<eOperandType, std::string> Execution::getOperandToStringPointer() {
    return {
            {eOperandType::Int8,       "int8"},
            {eOperandType::Int16,      "int16"},
            {eOperandType::Int32,      "int32"},
            {eOperandType::Float,      "float"},
            {eOperandType::Double,     "double"},
            {eOperandType::BigDecimal, "bigdecimal"}
    };
}

void Execution::extractDoubleInstruction(std::string line, std::smatch match) {
    std::string instruction = match[2];
    std::string number = match[4];
    std::string type = match[3];

    std::map<std::string, std::function<void(eOperandType, std::string)>> function_pointer = createFunctionPointer();
    std::map<std::string, eOperandType> operand_pointer = createOperandPointer();
//    function_pointer.at(instruction)(operand_pointer[type], number);
// to assign avec la classe Operand
    (void) line;
}

void Execution::extractInformationsFromLine(std::string line) {
    std::regex s("(pop|clear|dup|swap|dump|add|sub|mul|div|mod|print|exit)");
    std::regex v("((load|store|push|assert)\\s(int8|int16|int32|float|double|bigdecimal)\\(([1-9]\\d*(\\.\\d+)?)\\))");
    std::smatch match;

    try {
        if (std::regex_match(line, s)) {
//            simpleInstruction(line);  TODO
        } else if (std::regex_match(line, match, v)) {
            extractDoubleInstruction(line, match);
        } else {
            std::cerr << line << std::endl;
            fflush(0);
            throw new ExceptionSyntax;
        }
    }
    catch (const ExceptionSyntax *e) {
        e->printErrorFinish();
    };
}

void Execution::executionFromInput(std::list<std::string> input) {
    for (auto &line : input) {
        extractInformationsFromLine(line);
    }
}

void Execution::printStack() {
    std::cout << "** STACK **" << std::endl;
    for (auto &t : this->stack) {
        std::cout << (t == 0 ? "(empty)" : t->toString()) << std::endl;
    }
}