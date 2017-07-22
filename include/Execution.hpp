//
// EXECUTION.hh for vm in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:55:45 2017 Julien Leleu
// Last update Fri Jul 21 18:27:18 2017 Julien Leleu
//

#ifndef EXECUTION_HH
# define EXECUTION_HH

#include "IOperand.hh"
#include <list>
#include <map>
#include <regex>

class Execution {
public:
    Execution();

    ~Execution() {};

    void printStack();

    void printInstructions();

    void extractInformationsFromLine(std::string line);

    void extractDoubleInstruction(std::string line, std::smatch match);

    void assert(eOperandType type, std::string line);

    void push(eOperandType type, std::string line);


    std::map<std::string, eOperandType> createOperandPointer();

    std::map<std::string, std::function<void(eOperandType, std::string)>> createFunctionPointer();

    std::map<eOperandType, std::string> getOperandToStringPointer();

    std::list<IOperand *> getStack();

    std::list<std::string> getInstructionsList();

    void executionFromInput(std::list<std::string> input);

    void initializeStack();

private:
    std::list<IOperand *> stack;
};

#endif          /* !EXECUTION_HH_ */
