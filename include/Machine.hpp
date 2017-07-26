//
// Machine.hh for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 14:16:05 2017 Loïc Pirez
// Last update Wed Jul 26 16:17:31 2017 Julien Leleu
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

    void Parse(const std::string &filename);

    void Parse(const int &fd);

    std::list<std::string> getInput();

    void Execute();

private:
    std::list<IOperand *> stack;
    std::list<std::string> input;
};

#endif          /* !MACHINE_HH_ */
