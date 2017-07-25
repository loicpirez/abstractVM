//
// bigdecimal.hh for vm in /home/julien/abstractVM_2016/include/
//
// Made by Julien Leleu
// Login   <julien.leleu@epitech.eu>
//
// Started on  Fri Jul 21 17:55:45 2017 Julien Leleu
// Last update Sun Jul 23 21:50:19 2017 Loïc Pirez
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

    int getPrecision() const;

    void findReplace(std::string &source, std::string const &find, std::string const &replace) const;

protected:
    std::string operand;
};

#endif          /* !BIGDECIMAL_HH_ */
