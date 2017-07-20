//
// main.cpp for main in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
// 
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
// 
// Started on  Thu Jul 20 13:43:13 2017 Loïc Pirez
// Last update Thu Jul 20 13:43:26 2017 Loïc Pirez
//

#include <AbstractVM.hh>
#include <Parsing.hh>
#include <map>

int main(int argc, char *argv[]) {
    AbstractVM vm;

    std::map<std::string, size_t> instructions_list = {
            {"push",   1},
            {"pop",    0},
            {"clear",  0},
            {"dup",    0},
            {"swap",   0},
            {"dump",   0},
            {"assert", 1},
            {"add",    0},
            {"sub",    0},
            {"mul",    0},
            {"div",    0},
            {"mod",    0},
            {"load",   1},
            {"store",  1},
            {"print",  0},
            {"exit",   0}
    };
    vm.setInstructionsList(instructions_list);
    if (argc == 1)
        Parsing p(STANDARD_INPUT, &vm);
    else
        Parsing p(argv[1], &vm);
    return (0);
}