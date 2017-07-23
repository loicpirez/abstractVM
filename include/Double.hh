//
// double.hh for vm in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:44:01 2017 Julien Leleu
// Last update Sun Jul 23 21:50:21 2017 Loïc Pirez
//

#ifndef DOUBLE_HH
# define DOUBLE_HH

#include "IOperand.hh"

namespace operand_double {

    class Double : public IOperand {
    public:
        Double(const std::string &);

        ~Double();

        std::string toString() const;

        eOperandType getType() const;

        IOperand *operator+(const IOperand &rhs) const;

        IOperand *operator-(const IOperand &rhs) const;

        IOperand *operator*(const IOperand &rhs) const;

        IOperand *operator/(const IOperand &rhs) const;

        IOperand *operator%(const IOperand &rhs) const;

    protected:
        double operand;
    };
}

#endif        /* !DOUBLE_HH_ */
