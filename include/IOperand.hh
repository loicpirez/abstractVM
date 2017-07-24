//
// IOperand.hh for abstractVM in /home/loicpirez/Développement/CLionProjects/abstractVM_2016
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jul 20 20:23:29 2017 Loïc Pirez
// Last update Sun Jul 23 21:50:41 2017 Loïc Pirez
//

#ifndef         IOPERAND_HH_
# define        IOPERAND_HH_

#include <string>

# define MAX_REGISTERS 16

enum eOperandType {
    Int8, Int16, Int32, Float, Double, BigDecimal
};

class IOperand {
public:
    virtual std::string toString() const = 0;

    virtual eOperandType getType() const = 0;

    virtual IOperand *operator+(const IOperand &rhs) const = 0;

    virtual IOperand *operator-(const IOperand &rhs) const = 0;

    virtual IOperand *operator*(const IOperand &rhs) const = 0;

    virtual IOperand *operator/(const IOperand &rhs) const = 0;

    virtual IOperand *operator%(const IOperand &rhs) const = 0;

    virtual ~IOperand() {};

protected:
    int precision = 0;
};

#endif          /* !IOPERAND_HH_ */
