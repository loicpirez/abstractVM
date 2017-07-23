//
// Parser.cpp for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Sat Jul 22 16:38:01 2017 Loïc Pirez
// Last update Sat Jul 22 16:38:01 2017 Loïc Pirez
//

#include "Parser.hpp"
#include <iostream>
#include <regex>
#include <Exceptions.hh>
#include <fstream>

Parser::Parser(int fd) {
    this->source_is_file_descriptor = true;
    (void) fd;
}

Parser::Parser(std::string filename) {
    this->source_is_file_descriptor = false;
    this->filename = filename;
}

bool testSpaces(char lhs, char rhs) {
    return (lhs == rhs) && (lhs == ' ');
}

std::string Parser::checkLine(std::string line) {
    std::replace(line.begin(), line.end(), '\t', ' ');
    std::string::iterator new_end;
    std::string empty = "";

    new_end = std::unique(line.begin(), line.end(), testSpaces);
    line.erase(new_end, line.end());
    if (line.at(0) == ' ')
        line.erase(0, 1);
    auto pos = line.rfind(';');
    if (pos != std::string::npos)
        line.erase(pos);
    if (line.size() == 0)
        return (line);
    if (line.at(line.size() - 1) == ' ')
        line.erase(line.size() - 1);
    if (line.size() == 1 && line.at(0) == ';')
        return (empty);
    return (line);
}

std::string Parser::getInput(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    std::string empty = "";

    if (str.size() != 0 && checkLine(str).size() != 0)
        return (checkLine(str));
    return (empty);
}

std::list<std::string> Parser::readContentFromStandardInput() {
    std::list<std::string> content;

    for (std::string line; std::getline(std::cin, line) && line.compare(";;") != 0;) {
        if (getInput(line).size() != 0)
            content.push_front(checkLine(line));
    }
    return (content);
}

std::list<std::string> Parser::readContentFromFile() {
    std::list<std::string> content;
    std::string line;
    std::ifstream in(this->filename);

    try {
        if (!in)
            throw new ExceptionFile;
        while (std::getline(in, line)) {
            if (line.compare(";;") == 0) {
                break;
            } else {
                if (getInput(line).size() != 0)
                    content.push_front(getInput(line));
            }
        }
        return (content);
    }
    catch (const ExceptionFile *e) {
        e->printErrorFinish();
    }
    return (content);
}