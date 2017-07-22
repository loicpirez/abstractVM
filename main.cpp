//
// main.cpp for main in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
// 
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
// 
// Started on  Thu Jul 20 13:43:13 2017 Loïc Pirez
// Last update Thu Jul 20 13:43:26 2017 Loïc Pirez
//

#include <map>
#include <Machine.hpp>
#include <Execution.hpp>

int main(int argc, char *argv[]) {
    Machine machine;

    if (argc == 1)
        machine.Parse(STANDARD_INPUT);
    else
        machine.Parse(argv[1]);
    machine.Execute();
    return (0);
}