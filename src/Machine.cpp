//
// Machine.cpp for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 16:12:40 2017 Loïc Pirez
// Last update Wed Jul 26 16:17:14 2017 Julien Leleu
//

#include <Parser.hpp>
#include <Execution.hpp>
#include "Machine.hpp"

void Machine::Parse(const std::string &filename) {
    Parser p(filename);

    this->input = p.readContentFromFile();
}

void Machine::Parse(const int &fd) {
    Parser p(fd);
    std::list<std::string> input;

    this->input = p.readContentFromStandardInput();
}

std::list<std::string> Machine::getInput() {
    return (this->input);
}

void Machine::Execute() {
    Execution execution;

    execution.executionFromInput(this->getInput());
}
