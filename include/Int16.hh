//
// Int16.hh for Int16 in /Users/romain/Epitech/Synthesis/abstractVM_2016
//
// Made by Romain Dick
// Login   <romain.dick@epitech.eu>
//
// Started on  Fri Jul 21 10:45:08 2017 Romain Dick
// Last update Sun Jul 23 21:50:38 2017 Loïc Pirez
//

#ifndef        INT16_HH_
# define    INT16_HH_

# include "IOperand.hh"

namespace operand_int16 {
    class Int16 : public ::IOperand {
    public:
        Int16(const std::string &);

        ~Int16();

        std::string toString() const;

        eOperandType getType() const;

        IOperand *operator+(const IOperand &rhs) const;

        IOperand *operator-(const IOperand &rhs) const;

        IOperand *operator*(const IOperand &rhs) const;

        IOperand *operator/(const IOperand &rhs) const;

        IOperand *operator%(const IOperand &rhs) const;

        int getPrecision() const;

    protected:
        short operand;
    };
}

#endif        /* !INT16_HH_ */
