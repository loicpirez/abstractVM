//
// bigdecimal.hh for vm in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:55:45 2017 Julien Leleu
// Last update Fri Jul 21 18:27:18 2017 Julien Leleu
//

#ifndef BIGDECIMAL_HH
# define BIGDECIMAL_HH

#include "IOperand.hh"

class BigDecimal : public IOperand {
public:
    BigDecimal(const std::string &);

    ~BigDecimal();

    std::string toString() const;

    eOperandType getType() const;

    IOperand *operator+(const IOperand &rhs) const;

    IOperand *operator-(const IOperand &rhs) const;

    IOperand *operator*(const IOperand &rhs) const;

    IOperand *operator/(const IOperand &rhs) const;

    IOperand *operator%(const IOperand &rhs) const;

protected:
    long double operand;
};

#endif          /* !BIGDECIMAL_HH_ */
