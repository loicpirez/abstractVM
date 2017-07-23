//
// Parser.hh for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 14:16:05 2017 Loïc Pirez
// Last update Sun Jul 23 21:51:12 2017 Loïc Pirez
//

#ifndef         PARSER_HH_
# define        PARSER_HH_

# define STANDARD_INPUT 0

#include "IOperand.hh"
#include <list>
#include <map>
#include <regex>

class Parser {
public:
    Parser(int fd);

    Parser(std::string filename);

    ~Parser() {};

    std::string checkLine(std::string line);

    std::list<std::string> readContentFromStandardInput();

    std::list<std::string> readContentFromFile();

    std::string getInput(std::string str);

private:
    bool source_is_file_descriptor;
    std::list<std::string> input;
    std::string filename;

};

#endif          /* !PARSER_HH_ */
