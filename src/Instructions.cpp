//
// Instructions.cpp for vm in /home/julien/abstractVM_2016/src/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Sat Jul 22 17:14:27 2017 Julien Leleu
// Last update Mon Jul 24 14:40:43 2017 Julien Leleu
//

#include <iostream>
#include <Execution.hpp>
#include "Exceptions.hh"
#include <Factory.hpp>

std::list<IOperand *> Instructions::pop(std::list<IOperand *> stack) {
    try {
        if (stack.size() == 0)
            throw new ExceptionPopEmptyStack;
        stack.pop_front();
    } catch (const ExceptionPopEmptyStack *e) {
        e->printErrorFinish();
    }
    return (stack);
}

std::list<IOperand *> Instructions::clear(std::list<IOperand *> stack) {
    stack.clear();
    return (stack);
}

std::list<IOperand *> Instructions::dup(std::list<IOperand *> stack) {
    try {
        if (stack.size() == 0)
            throw new ExceptionStack;
        stack.push_front(stack.front());
    } catch (const ExceptionStack *e) {
        std::cout << e->what() << std::endl;
        std::exit(84);
    }
    return (stack);
}

std::list<IOperand *> Instructions::swap(std::list<IOperand *> stack) {
    try {
        if (stack.size() < 2)
            throw new ExceptionStack;
        auto it2 = stack.begin();
        auto it1 = it2++;
        std::swap(*it1, *it2);
    } catch (const ExceptionStack *e) {
        std::cout << e->what() << std::endl;
        std::exit(84);
    }
    return (stack);
}

std::list<IOperand *> Instructions::dump(std::list<IOperand *> stack) {
    for (auto &t : stack) {
        if (t) {
            std::cout << t->toString() << std::endl;
            fflush(0);
        }
    }
    return (stack);
}

std::list<IOperand *> Instructions::add(std::list<IOperand *> stack) {
    try {
        checkNumberCalc(stack);
        if (stack.size() < 2)
            throw new ExceptionStack;
        IOperand *i = stack.front();
        stack.pop_front();
        IOperand *k = stack.front();
        stack.pop_front();
        IOperand *ret = *i + *k;
        stack.push_front(ret);
        delete i;
        delete k;
    } catch (ExceptionStack *e) {
        std::cout << e->what() << std::endl;
        std::exit(84);
    }
    return (stack);
}

std::list<IOperand *> Instructions::sub(std::list<IOperand *> stack) {
    try {
        checkNumberCalc(stack);
        if (stack.size() < 2)
            throw new ExceptionStack;
        IOperand *i = stack.front();
        stack.pop_front();
        IOperand *k = stack.front();
        stack.pop_front();
        IOperand *ret = *k - *i;
        stack.push_front(ret);
        delete i;
        delete k;
    } catch (ExceptionStack *e) {
        std::cout << e->what() << std::endl;
        std::exit(84);
    }
    return (stack);
}

std::list<IOperand *> Instructions::mul(std::list<IOperand *> stack) {
    try {
        checkNumberCalc(stack);
        if (stack.size() < 2)
            throw new ExceptionStack;
        IOperand *i = stack.front();
        stack.pop_front();
        IOperand *k = stack.front();
        stack.pop_front();
        IOperand *ret = *i * *k;
        stack.push_front(ret);
        delete i;
        delete k;
    } catch (ExceptionStack *e) {
        std::cout << e->what() << std::endl;
        std::exit(84);
    }
    return (stack);
}

std::list<IOperand *> Instructions::div(std::list<IOperand *> stack) {
    try {
        checkNumberCalc(stack);
        if (stack.size() < 2)
            throw new ExceptionStack;
        IOperand *i = stack.front();
        stack.pop_front();
        IOperand *k = stack.front();
        stack.pop_front();
        IOperand *ret = *k / *i;
        stack.push_front(ret);
        delete i;
        delete k;
    } catch (ExceptionStack *e) {
        std::cout << e->what() << std::endl;
        std::exit(84);
    }
    return (stack);
}

std::list<IOperand *> Instructions::mod(std::list<IOperand *> stack) {
    try {
        checkNumberCalc(stack);
        if (stack.size() < 2)
            throw new ExceptionStack;
        IOperand *i = stack.front();
        stack.pop_front();
        IOperand *k = stack.front();
        stack.pop_front();
        IOperand *ret = *k % *i;
        stack.push_front(ret);
        delete i;
        delete k;
    } catch (ExceptionStack *e) {
        std::cout << e->what() << std::endl;
        std::exit(84);
    }
    return (stack);
}

std::list<IOperand *> Instructions::print(std::list<IOperand *> stack) {
    try {
        if (stack.size() < 1)
            throw new ExceptionStack;
        IOperand *c = stack.front();
        if (c->getType() != eOperandType::Int8)
            throw new ExceptionOperand;
        std::cout << (char) stoi(c->toString());
        std::cout << std::endl;
    } catch (ExceptionStack *e) {
        std::cout << e->what() << std::endl;
        std::exit(84);
    } catch (ExceptionOperand *e) {
        std::cout << e->what() << std::endl;
        std::exit(84);
    }
    return (stack);
}

std::list<IOperand *> Instructions::exit(std::list<IOperand *> stack) {
    std::exit(0);
    (void) stack;
}

std::map<std::string, std::function<std::list<IOperand *>(std::list<IOperand *>)>>
Instructions::createFunctionPointerSingleType() {
    return
            {
                    {
                            "pop",
                            std::bind(&Instructions::pop, this, std::placeholders::_1)
                    },
                    {
                            "clear",
                            std::bind(&Instructions::clear, this, std::placeholders::_1)
                    },
                    {
                            "dup",
                            std::bind(&Instructions::dup, this, std::placeholders::_1)
                    },
                    {
                            "swap",
                            std::bind(&Instructions::swap, this, std::placeholders::_1)
                    },
                    {
                            "dump",
                            std::bind(&Instructions::dump, this, std::placeholders::_1)
                    },
                    {
                            "add",
                            std::bind(&Instructions::add, this, std::placeholders::_1)
                    },
                    {
                            "sub",
                            std::bind(&Instructions::sub, this, std::placeholders::_1)
                    },
                    {
                            "mul",
                            std::bind(&Instructions::mul, this, std::placeholders::_1)
                    },
                    {
                            "div",
                            std::bind(&Instructions::div, this, std::placeholders::_1)
                    },
                    {
                            "mod",
                            std::bind(&Instructions::mod, this, std::placeholders::_1)
                    },
                    {
                            "print",
                            std::bind(&Instructions::print, this, std::placeholders::_1)
                    },
                    {
                            "exit",
                            std::bind(&Instructions::exit, this, std::placeholders::_1)
                    }
            };
}

std::list<IOperand *> Instructions::load(std::list<IOperand *> stack, eOperandType type, std::string value) {
    (void) value;
    (void) type;
    return (stack);
}

std::list<IOperand *> Instructions::store(std::list<IOperand *> stack, eOperandType type, std::string value) {
    (void) value;
    (void) type;
    return (stack);
}

std::list<IOperand *> Instructions::push(std::list<IOperand *> stack, eOperandType type, std::string value) {
    (void) value;
    (void) type;
    IOperand *tmp = Factory::createOperand(type, value);
    stack.push_front(tmp);
    return (stack);
}

std::list<IOperand *> Instructions::assert(std::list<IOperand *> stack, eOperandType type, std::string value) {
    (void) value;
    (void) type;
    return (stack);
}

std::map<std::string, std::function<std::list<IOperand *>(std::list<IOperand *>, eOperandType, std::string)>>
Instructions::createFunctionPointerDoubleType() {
    return
            {
                    {
                            "assert",
                            std::bind(&Instructions::assert, this, std::placeholders::_1, std::placeholders::_2,
                                      std::placeholders::_3)
                    },
                    {
                            "load",
                            std::bind(&Instructions::load, this, std::placeholders::_1, std::placeholders::_2,
                                      std::placeholders::_3)
                    },
                    {
                            "push",
                            std::bind(&Instructions::push, this, std::placeholders::_1, std::placeholders::_2,
                                      std::placeholders::_3)
                    },
                    {
                            "store",
                            std::bind(&Instructions::store, this, std::placeholders::_1, std::placeholders::_2,
                                      std::placeholders::_3)
                    },
            };
}

void Instructions::checkNumberCalc(std::list<IOperand *> stack) {
    try {
        if (stack.size() < 2) {
            throw new ExceptionNotEnoughNumber;
        }
    }
    catch (ExceptionNotEnoughNumber *e) {
        e->printErrorFinish();
    }

}
