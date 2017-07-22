//
// Factory.hh for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 20:28:06 2017 Loïc Pirez
// Last update Thu Jul 20 20:28:06 2017 Loïc Pirez
//

#ifndef FACTORY_HH
# define FACTORY_HH

#include "IOperand.hh"
#include <map>
#include <functional>


class Factory {
public:
    Factory() {};

    ~Factory() {};

    static IOperand *createOperand(eOperandType type, const std::string &value);

    std::map<eOperandType, std::function<IOperand *(std::string const &)>> createFunctionPointer();

private:
    IOperand *createInt8(std::string const &value) const;

    IOperand *createInt16(std::string const &value) const;

    IOperand *createInt32(std::string const &value) const;

    IOperand *createFloat(std::string const &value) const;

    IOperand *createDouble(std::string const &value) const;

    IOperand *createBigDecimal(std::string const &value) const;
};

#endif        /* !FACTORY_HH_ */
