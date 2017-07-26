//
// EXECUTION.hh for vm in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:55:45 2017 Julien Leleu
// Last update Wed Jul 26 16:42:43 2017 Julien Leleu
//

#ifndef EXECUTION_HH
# define EXECUTION_HH

#include "IOperand.hh"
#include "Instructions.hh"
#include <list>
#include <map>
#include <regex>

class Execution {
public:
    Execution() {};

    ~Execution() {};

    void printStack();

    void printInstructions();

    void extractInformationsFromLine(const std::string &line);

    void assert(eOperandType type, std::string line);

    void push(eOperandType type, std::string line);

    void executeSimpleInstruction(Instructions *i, const std::string &line);

    void executeDoubleInstruction(Instructions *i, const std::smatch &match);

    std::map<std::string, eOperandType> createOperandPointer();

    std::map<std::string, std::function<std::list<IOperand *>(std::list<IOperand *>, eOperandType, std::string)>>
    createFunctionPointerFromMultiplesArgs();

    std::map<eOperandType, std::string> getOperandToStringPointer();

    std::list<IOperand *> getStack();

    std::list<std::string> getInstructionsList();

    void executionFromInput(std::list<std::string> input);

    void initializeStack();

private:
    std::list<IOperand *> stack;
};

#endif          /* !EXECUTION_HH_ */
