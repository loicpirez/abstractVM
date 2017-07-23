//
// Int8.hh for vm in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 09:38:23 2017 Julien Leleu
// Last update Sun Jul 23 21:50:36 2017 Loïc Pirez
//

#ifndef INT8_HH
# define INT8_HH

#include "IOperand.hh"

namespace operand_int8 {

    class Int8 : public IOperand {
    public:
        Int8(const std::string &);

        ~Int8();

        std::string toString() const;

        eOperandType getType() const;

        IOperand *operator+(const IOperand &rhs) const;

        IOperand *operator-(const IOperand &rhs) const;

        IOperand *operator*(const IOperand &rhs) const;

        IOperand *operator/(const IOperand &rhs) const;

        IOperand *operator%(const IOperand &rhs) const;

    protected:
        char operand;
    };
}

#endif
