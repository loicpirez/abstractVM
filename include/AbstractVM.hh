//
// AbstractVM.hh for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 14:16:05 2017 Loïc Pirez
// Last update Thu Jul 20 14:16:05 2017 Loïc Pirez
//

#ifndef         ABSTRACTVM_HH_
# define        ABSTRACTVM_HH_

#include <string>
#include <map>

class AbstractVM {
public:
    AbstractVM();

    ~AbstractVM();

    void setInstructionsList(std::map<std::string, size_t> instructions_list);

private:
    std::map<std::string, size_t> instructions_list;
};

#endif          /* !ABSTRACTVM_HH_ */
