//
// float.hh for vm in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 16:46:31 2017 Julien Leleu
// Last update Sun Jul 23 21:50:32 2017 Loïc Pirez
//

#ifndef FLOAT_HH
# define FLOAT_HH

#include "IOperand.hh"

namespace operand_float {

    class Float : public IOperand {
    public:
        Float(const std::string &);

        ~Float();

        std::string toString() const;

        eOperandType getType() const;

        IOperand *operator+(const IOperand &rhs) const;

        IOperand *operator-(const IOperand &rhs) const;

        IOperand *operator*(const IOperand &rhs) const;

        IOperand *operator/(const IOperand &rhs) const;

        IOperand *operator%(const IOperand &rhs) const;

        int getPrecision() const;

    protected:
        float operand;
    };
}

#endif
