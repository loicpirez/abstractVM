//
// Parsing.cpp for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 14:15:10 2017 Loïc Pirez
// Last update Thu Jul 20 14:15:10 2017 Loïc Pirez
//

#include <iostream>
#include <AbstractVM.hh>
#include <fstream>
#include "Parsing.hh"

Parsing::Parsing(int fd, AbstractVM *vm) {
    std::cout << "(fd)" << std::endl;
    (void)fd;
    (void)vm;
}

Parsing::Parsing(char *filename, AbstractVM *vm) {
    std::cout << "(filename)" << std::endl;
    (void)filename;
    (void)vm;
}


Parsing::~Parsing() {
}
