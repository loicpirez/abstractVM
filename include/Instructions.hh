//
// Instructions.hh for vm in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Sat Jul 22 17:14:16 2017 Julien Leleu
// Last update Wed Jul 26 16:30:47 2017 Julien Leleu
//

#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <list>
#include "IOperand.hh"
#include <map>
#include <functional>


class Instructions {
public:
    Instructions() {}

    ~Instructions() {}

    std::list<IOperand *> pop(std::list<IOperand *> &stack);

    std::list<IOperand *> clear(std::list<IOperand *> &stack);

    std::list<IOperand *> dup(std::list<IOperand *> &stack);

    std::list<IOperand *> swap(std::list<IOperand *> &stack);

    std::list<IOperand *> dump(std::list<IOperand *> &stack);

    std::list<IOperand *> add(std::list<IOperand *> &stack);

    std::list<IOperand *> sub(std::list<IOperand *> &stack);

    std::list<IOperand *> mul(std::list<IOperand *> &stack);

    std::list<IOperand *> div(std::list<IOperand *> &stack);

    std::list<IOperand *> mod(std::list<IOperand *> &stack);

    std::list<IOperand *> print(std::list<IOperand *> &stack);

    std::list<IOperand *> exit(std::list<IOperand *> &stack);

    std::list<IOperand *> load(std::list<IOperand *> &stack, eOperandType &type, std::string &value);

    std::list<IOperand *> store(std::list<IOperand *> &stack, eOperandType &type, std::string &value);

    std::list<IOperand *> push(std::list<IOperand *> &stack, eOperandType &type, std::string &value);

    std::list<IOperand *> assert(std::list<IOperand *> &stack, eOperandType &type, std::string &value);

    std::map<std::string, std::function<std::list<IOperand *>(std::list<IOperand *>&, eOperandType&, std::string&)>>
    createFunctionPointerDoubleType();

    std::map<std::string, std::function<std::list<IOperand *>(std::list<IOperand *>&)>>
    createFunctionPointerSingleType();

    void checkNumberCalc(std::list<IOperand *> &stack);
};


#endif
