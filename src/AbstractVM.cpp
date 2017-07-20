//
// AbstractVM.cpp for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 14:32:06 2017 Loïc Pirez
// Last update Thu Jul 20 14:32:06 2017 Loïc Pirez
//

#include <iostream>
#include "AbstractVM.hh"

AbstractVM::AbstractVM() {

}

AbstractVM::~AbstractVM() {

}

void AbstractVM::setInstructionsList(std::map<std::string, size_t> instructions_list) {
    this->instructions_list = instructions_list;
}