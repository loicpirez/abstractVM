//
// Machine.hh for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 14:16:05 2017 Loïc Pirez
// Last update Sun Jul 23 21:50:43 2017 Loïc Pirez
//

#ifndef         MACHINE_HH_
# define        MACHINE_HH_

#include "IOperand.hh"
#include "Parser.hpp"
#include <iostream>
#include <list>

class Machine {
public:
    Machine() {};

    ~Machine() {};

    void Parse(std::string filename);

    void Parse(int fd);

    std::list<std::string> getInput();

    void Execute();

private:
    std::list<IOperand *> stack;
    std::list<std::string> input;
};

#endif          /* !MACHINE_HH_ */
