//
// Int16.hh for Int16 in /Users/romain/Epitech/Synthesis/abstractVM_2016
//
// Made by Romain Dick
// Login   <romain.dick@epitech.eu>
//
// Started on  Fri Jul 21 10:45:08 2017 Romain Dick
// Last update Fri Jul 21 20:07:46 2017 Julien Leleu
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

    protected:
        short operand;
    };
}

#endif        /* !INT16_HH_ */
