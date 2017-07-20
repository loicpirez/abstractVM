//
// Parsing.hh for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 14:16:05 2017 Loïc Pirez
// Last update Thu Jul 20 14:16:05 2017 Loïc Pirez
//

#ifndef         PARSING_HH_
# define        PARSING_HH_

# define STANDARD_INPUT 0

#include "AbstractVM.hh"

class Parsing {
public:
    Parsing(int fd, AbstractVM *vm);

    Parsing(char *filename, AbstractVM *vm);

    ~Parsing();
};

#endif          /* !PARSING_HH_ */
